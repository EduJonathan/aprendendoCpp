<!-- @format -->

# Templates em C++

Em C++, **templates** são um mecanismo da linguagem que permite escrever código genérico —
ou seja, código capaz de operar sobre diferentes tipos de dados, como:

- tipos primitivos (`int`, `float`, `double`)
- tipos da biblioteca padrão (`std::string`, `std::vector`)
- tipos definidos pelo usuário (`classes` e `structs`)

Com templates, é possível criar **funções** e **classes genéricas**, evitando a repetição de código
e permitindo que uma única implementação seja reutilizada para múltiplos tipos,
com **verificação de tipos realizada em tempo de compilação**.

---

## Por que templates existem?

Sem templates, seria necessário criar várias versões da mesma função ou classe,
mudando apenas o tipo dos parâmetros. Templates resolvem esse problema ao permitir que o **tipo seja um parâmetro**.

Isso torna o código mais **expressivo**, **seguro** e **eficiente**.

---

## Vantagens

A programação genérica oferece diversos benefícios importantes:

1. **Reutilização de código**  
   Um único template pode ser instanciado para diferentes tipos, evitando duplicação.

2. **Evita sobrecarga excessiva de funções**  
   Elimina a necessidade de criar múltiplas funções com o mesmo comportamento, alterando apenas os tipos dos parâmetros.

3. **Verificação em tempo de compilação**  
   Erros de tipo são detectados antes da execução, aumentando a segurança do código.

4. **Desempenho**  
   O código é gerado em tempo de compilação, sem custos adicionais em tempo de execução (não há runtime dispatch).

---

## Desvantagens

Apesar de poderosos, templates também apresentam alguns pontos negativos:

1. **Mensagens de erro complexas**  
   Erros envolvendo templates podem gerar mensagens longas e difíceis de interpretar, especialmente em código genérico avançado.

2. **Aumento do tempo de compilação**  
   Cada instância do template gera código específico, o que pode impactar o tempo de build.

3. **Aumento do tamanho do binário**  
   O mesmo template pode ser instanciado várias vezes para tipos diferentes, aumentando o tamanho final do executável.

4. **Curva de aprendizado elevada**  
   Conceitos como especialização, **metaprogramação**, **SFINAE** e **constraints** exigem maior maturidade técnica.

---

## Dedução de parâmetros de template

Em muitos casos, o compilador consegue **deduzir automaticamente** os tipos de um template a partir dos argumentos fornecidos.
Esse processo é conhecido como **dedução de parâmetros de template** (template argument deduction).

Isso melhora significativamente a **legibilidade** do código,
evitando a necessidade de especificar tipos explicitamente em todas as situações.

---

## Conceitos Avançados em Templates

### Templates Variádicos (Variadic Templates)

**Templates variádicos** permitem que um template aceite um **número arbitrário de parâmetros de template** ou
um **número arbitrário de argumentos de função**, potencialmente de **tipos diferentes**.

Eles foram introduzidos no **C++11** e são fundamentais para a implementação de interfaces genéricas e flexíveis.

Essa técnica é usada quando:

- A quantidade de parâmetros não é conhecida em tempo de escrita
- É necessário aceitar múltiplos tipos diferentes em uma única interface
- Deseja-se criar APIs altamente genéricas e reutilizáveis

---

### Funcionamento básico

Um template variádico utiliza um parameter pack, representado por `...`. Exemplo conceitual:

```cpp
template <typename... Args>
void func(Args... args);
```

- `Args...` → parameter pack de tipos
- `args...` → parameter pack de valores

---

### Expansão de parameter packs

Para usar os parâmetros, é necessário **expandir** o parameter pack.
Historicamente isso era feito via **recursão**, mas desde o **C++17** existe uma forma mais simples
com **fold expressions**. Exemplo moderno:

```cpp
template <typename... Args>
auto sum(Args... args)
{
   return (args + ...);
}
```

- Nesse caso: `(args + ...)` soma todos os argumentos.
- A expressão é expandida pelo compilador em tempo de compilação.

---

### Vantagens dos templates variádicos

- Permitem APIs extremamente flexíveis
- Eliminam a necessidade de múltiplas sobrecargas
- Mantêm verificação de tipos em tempo de compilação
- Não introduzem custo em tempo de execução

---

### Desvantagens dos templates variádicos

- Sintaxe inicialmente difícil de compreender
- Mensagens de erro ainda mais complexas
- Podem levar a código excessivamente genérico se mal utilizados

---

### Regra mental

> 🔑 Templates variádicos tratam `quantidade` como um parâmetro de template.

Eles permitem escrever código que se adapta não só ao tipo, mas também ao número de argumentos.

---

### Type Erasure

**Type Erasure** é uma técnica que permite **ocultar o tipo concreto** de um objeto,
expondo apenas uma **interface comum**, mesmo quando templates estão envolvidos.

> Ela troca informação de tipo em tempo de compilação por flexibilidade em tempo de execução.

---

Essa abordagem é usada quando:

- O tipo exato não importa para o usuário da API
- Deseja-se reduzir a exposição de templates em interfaces públicas
- Busca-se diminuir dependências e tempos de compilação

**Exemplos clássicos na STL:**

- `std::function`
- `std::any`
- `std::shared_ptr` (em certos aspectos)

O _type erasure_ geralmente envolve:

- Polimorfismo
- Ponteiros
- Alocação dinâmica
- Perda parcial de informações de tipo em tempo de compilação

---

### ✅ Vantagens do Type Erasure

#### 1. Interfaces públicas mais simples e estáveis

O usuário da API não precisa conhecer templates nem tipos complexos. Exemplo conceitual:

- Interface expõe `std::function<void()>`
- Implementação interna pode ser `lambda`, `função`, `functor`, etc.

Isso reduz o acoplamento e torna a API mais fácil de usar.

#### 2. Redução de dependência de templates

Type erasure evita que headers propaguem templates por toda a base de código. Benefícios diretos:

- Menor tempo de compilação
- Menos código gerado
- Headers mais limpos

#### 3. Flexibilidade em tempo de execução

Diferente de templates, o tipo concreto pode variar em runtime. Isso permite:

- Armazenar objetos de tipos diferentes em uma mesma estrutura
- Trocar implementações dinamicamente
- Criar sistemas de plugins ou callbacks genéricos

#### 4. Melhor isolamento de implementação

A implementação concreta pode mudar sem quebrar código cliente. Isso favorece:

- Encapsulamento
- Evolução de bibliotecas
- Compatibilidade binária (ABI) em certos contextos

#### 5. Facilita integração entre módulos

Type erasure funciona bem como fronteira entre sistemas:

- módulos
- bibliotecas
- camadas de arquitetura

Especialmente quando nem todos usam templates internamente.

---

### Desvantagens do Type Erasure

#### 1. Perda de verificação de tipo em tempo de compilação

O compilador não conhece mais o tipo concreto. Consequências:

- Erros que seriam detectados em compile-time podem virar erros de runtime
- Necessidade de verificações adicionais

> Exemplo: `std::any` exige `any_cast`, que pode falhar em runtime

#### 2. Overhead em tempo de execução

Type erasure normalmente envolve:

- Polimorfismo virtual
- Ponteiros
- Possível alocação dinâmica

Isso pode introduzir:

- indireção
- menor desempenho em _hot paths_
- impacto em cache

#### 3. Maior complexidade de implementação

Embora a interface fique simples, a **implementação interna é mais complexa**. Envolve:

- classes base abstratas
- wrappers
- gerenciamento de vida útil
- `copy/move` customizados

> É fácil errar se não for bem projetado.

#### 4. Debug mais difícil

Como o tipo real está oculto:

- stack traces podem ser menos claros
- mensagens de erro ficam mais genéricas
- ferramentas estáticas têm menos informação

#### 5. Não substitui templates em todos os casos

Type erasure não é um replacement de templates. Ele é ruim quando:

- desempenho máximo é crítico
- o tipo precisa ser conhecido em `compile-time`
- expressividade genérica é necessária (ex: `constexpr`, `concepts`)

### Regra

> 🔑 Templates otimizam desempenho e segurança.  
> Type erasure otimiza flexibilidade e interfaces.

C++ moderno usa ambos, cada um onde faz mais sentido.

---

## Conclusão

Além de funções e classes genéricas tradicionais, **templates variádicos** ampliam significativamente
o poder da programação genérica em C++, permitindo interfaces que se adaptam tanto aos **tipos**
quanto à **quantidade de parâmetros**, tudo com verificação em tempo de compilação.

Dominar variadic templates é um passo importante para compreender a STL,
bibliotecas modernas e técnicas avançadas de design em C++.
