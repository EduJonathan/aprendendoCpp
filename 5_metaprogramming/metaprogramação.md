# METAPROGRAMMING (METAPROGRAMAÇÃO)

Uma das grandes invenções e elementos-chave do C++ é a metaprogramação (metaprogramming), que consiste em
**fazer o compilador executar lógica, cálculos e decisões sobre o código antes da execução** - isto é, durante a compilação.

---

## ⏲️ TEMPO DE EXECUÇÃO E TEMPO DE COMPILAÇÃO

**Tempo de Execução (runtime)**
O código roda _depois_ de compilado. Variáveis podem mudar, loops ocorrem,
cálculos acontecem com custo real enquanto o programa está ativo.

**Tempo de Compilação (compile-time)**
O compilador analisa tipos, executa templates, resolve constantes, escolhe
overloads e gera código _antes_ de o programa existir.

---

## 📚 BIBLIOTECAS PARA SE UTILIZAR NA METAPROGRAMAÇÃO

A metaprogramação em C++ é um dos recursos mais poderosos e complexos da linguagem, permitindo
que o próprio código se altere durante a compilação. Com suas biblioteca e recurso se utilizar
para buscar tais resultados, temos desde já:

---

### Header `<functional>`

Embora seja rica em templates, sua atuação é majoritariamente _runtime_.
Pode ser usada dentro de templates, mas `NÃO` é uma biblioteca de metaprogramação.

---

### Header `<tuple>`

O `<tuple>` é fundamental quando se trabalha com coleções heterogêneas de tipos.
Ele suporta:

- Metaprogramação variádica,
- Manipulação estática de sequências de tipos,
- Indexação e transformação de tipos em tempo de compilação.

> Ele permite criar estruturas onde cada posição da tupla possui um tipo diferente,
> algo essencial para metaprogramação avançada, introspecção e compilação incremental de estruturas de dados.

---

### Header `<type_traits>`

Uma das bibliotecas centrais da metaprogramação moderna em C++.
Ela fornece uma vasta coleção de templates que permitem:

- Consultar propriedades de tipos (std::is_integral, std::is_pointer, std::is_same, etc.)
- Modificar tipos (std::remove_const, std::add_pointer, std::decay, ...)
- Validar características durante compilação
- Construir lógica baseada em tipos (via std::conditional, std::enable_if, etc.)

> É essencial para SFINAE, traits, verificação de requisitos de tipos e construção de type-level programming.

---

### Header `<algorithm>`

Embora não seja uma biblioteca pensada para metaprogramação, muitas de suas funções
são templates e podem ser usadas em contextos constexpr, especialmente a partir do C++20.
Assim, ela se torna relevante para:

- Algoritmos avaliáveis em tempo de compilação
- Manipulação de ranges
- Cálculos estáticos que dependem de constexpr

> Importante quando se trabalha com constexpr algorithms

---

### Header `<chrono>`

O `<chrono>` combina conceitos como:

- Tipos fortemente tipados
- Unidades de tempo baseadas em std::ratio
- Cálculos seguros e exatos

É extremamente útil em metaprogramação quando combinada com:

- Constexpr
- Concepts
- Templates baseados em unidades

---

### Header `<concepts>`

A biblioteca `<concepts>`, introduzida no C++20, Introduz um sistema moderno para
expressar restrições em templates de maneira clara e legível.
Com ele, é possível definir requisitos como:

- "O tipo deve ser integral"
- "O tipo deve ser iterável"
- "Deve suportar determinado operador"

---

### Header `<ratio>`

A biblioteca `<ratio>` introduz uma forma de representar números racionais (frações)
em **_tempo de compilação_** através da classe `std::ratio`. Ela é especialmente útil
na metaprogramação e em sistemas que precisam manipular unidades, escalas e proporções
de maneira segura e eficiente.

| Prefixo    | C++   | Definição             | Potência de 10 |
| ---------- | ----- | --------------------- | -------------- |
| **quecto** | C++26 | `std::ratio<1, 10³⁰>` | 10⁻³⁰          |
| **ronto**  | C++26 | `std::ratio<1, 10²⁷>` | 10⁻²⁷          |
| **yocto**  | C++11 | `std::ratio<1, 10²⁴>` | 10⁻²⁴          |
| **zepto**  | C++11 | `std::ratio<1, 10²¹>` | 10⁻²¹          |
| **atto**   | C++11 | `std::ratio<1, 10¹⁸>` | 10⁻¹⁸          |
| **femto**  | C++11 | `std::ratio<1, 10¹⁵>` | 10⁻¹⁵          |
| **pico**   | C++11 | `std::ratio<1, 10¹²>` | 10⁻¹²          |
| **nano**   | C++11 | `std::ratio<1, 10⁹>`  | 10⁻⁹           |
| **micro**  | C++11 | `std::ratio<1, 10⁶>`  | 10⁻⁶           |
| **milli**  | C++11 | `std::ratio<1, 10³>`  | 10⁻³           |
| **centi**  | C++11 | `std::ratio<1, 10²>`  | 10⁻²           |
| **deci**   | C++11 | `std::ratio<1, 10>`   | 10⁻¹           |
| **deca**   | C++11 | `std::ratio<10, 1>`   | 10¹            |
| **hecto**  | C++11 | `std::ratio<100, 1>`  | 10²            |
| **kilo**   | C++11 | `std::ratio<1000, 1>` | 10³            |
| **mega**   | C++11 | `std::ratio<10⁶, 1>`  | 10⁶            |
| **giga**   | C++11 | `std::ratio<10⁹, 1>`  | 10⁹            |
| **tera**   | C++11 | `std::ratio<10¹², 1>` | 10¹²           |
| **peta**   | C++11 | `std::ratio<10¹⁵, 1>` | 10¹⁵           |
| **exa**    | C++11 | `std::ratio<10¹⁸, 1>` | 10¹⁸           |
| **zetta**  | C++11 | `std::ratio<10²¹, 1>` | 10²¹           |
| **yotta**  | C++11 | `std::ratio<10²⁴, 1>` | 10²⁴           |
| **ronna**  | C++26 | `std::ratio<10²⁷, 1>` | 10²⁷           |
| **quetta** | C++26 | `std::ratio<10³⁰, 1>` | 10³⁰           |

**Fonte da tabela:**  
Cppreference — _std::ratio_ (consultado em 2025).  
<https://en.cppreference.com/w/cpp/numeric/ratio/ratio>

---

Além disso, Podemos Contar Com Bibliotecas Externas

- **`Boost.Hana`**: Uma biblioteca moderna para metaprogramação, otimizada para C++14/17,
  que simplifica o trabalho com tuplas e tipos em tempo de compilação.
- **`Boost.MPL`**: Biblioteca mais antiga, voltada para metaprogramação em C++03/11, ainda usada em projetos legados.

---

## 🎛️ Recursos e Keywords Essenciais para Metaprogramação em C++

A metaprogramação em C++ depende fortemente de recursos do compilador, estruturas especiais
e palavras-chave que permitem executar lógica, criar tipos, validar requisitos e gerar código em tempo de compilação.

---

### **structs**

Em metaprogramação, structs (e classes) atuam como espaços de execução em tempo de compilação. Elas servem como “contêineres” para:

- aliases de tipos (using type = ...;)
- Constantes (static constexpr ...)
- Transformações baseadas em parâmetros de template

Em outras palavras, uma struct template funciona como uma função que calcula tipos,
e o compilador usa suas definições para gerar novos tipos antes da execução.

---

### **Templates** (Templates de Funções e Classes)

Templates são o fundamento absoluto da metaprogramação em C++. Permitem escrever:

- Código genérico
- Funções parametrizadas por tipos
- Estruturas que mudam conforme os tipos fornecidos

> Combinando templates com constexpr, conceitos e SFINAE, é possível construir sistemas inteiros avaliados pelo compilador.

---

### **constexpr**

constexpr permite definir funções, variáveis e expressões que podem ser avaliadas em tempo de compilação. É essencial para:

- Validações estáticas
- Cálculos pré-executados
- Inicializações de tabelas constantes
- Estruturas de decisão avaliadas pelo compilador

> A partir do C++20, boa parte da STL se tornou constexpr, ampliando drasticamente esse recurso.

---

### **if constexpr**

Introduzido no C++17, if constexpr permite ramificações condicionais em tempo de compilação,
eliminando código inválido dependendo do tipo.

---

### **noexcept** E **const noexcept**

noexcept indica que uma função garante não lançar exceções. Em metaprogramação, ele auxilia:

- otimizações do compilador
- seleção de overloads baseada em exception guarantees
- construção de traits como std::is_nothrow_invocable

Em métodos de classe isso significa

- **const**: não modifica o estado do objeto.
- **noexcept**: nunca lança exceções.

> Útil para especializações condicionais e funções constexpr.

---

### **consteval**

consteval introduzido no C++20 exige que a função sempre seja executada em tempo de compilação.
Diferente de constexpr, ela não pode ser usada como função de runtime.

Ideal para:

- Validação de parâmetros
- Geração obrigatória de valores computados
- Cálculos de metaprogramação puros

---

### **decltype**

decltype produz o tipo exato de uma expressão sem avaliá-la. É crucial em:

- Dedução de tipos complexos
- auto avançado
- Templates que precisam inspecionar tipos internamente
- Verificação de expressões em SFINAE ou requires

---

### **mutable**

mutable permite que um membro seja modificado mesmo dentro de funções const. Isso é útil em metaprogramação quando:

- Implementando caches internos para cálculos constexpr
- Medindo estatísticas internas de templates
- Armazenando metadados para introspecção
- Funciona como uma “isenção” da regra de imutabilidade interna.

---

### **requires**

requires(C++20) permite expressar restrições sobre tipos, substituindo técnicas complexas como SFINAE e enable_if.
Pode ser usado como:

- Cláusula pós-parâmetros
- Expressão booleana baseada em conceitos
- Bloco completo de requisitos (syntax, type, compound, nested)

---

## Técnicas

### **SFINAE**

SFINAE é um princípio fundamental da metaprogramação em C++ que permite criar overloads de funções ou
especializações de templates baseadas em características de tipos. Se uma substituição de tipo falhar,
isso não gera um erro de compilação, mas apenas impede que aquela especialização ou
função seja usada (Ex.: `std::enable_if<std::is_integral<T>::value, void>::type`).

| Técnica                                | Descrição                                                                                                       | Exemplo                                                            |
| -------------------------------------- | --------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------ |
| **SFINAE**                             | “Substitution Failure Is Not An Error”: falha de substituição não gera erro, apenas remove overloads inválidos. | Habilitar/desabilitar overloads com base em propriedades de tipos. |
| **std::conditional**                   | Seleciona um tipo baseado em uma condição booleana em tempo de compilação.                                      | `std::conditional<flag, int, double>::type`                        |
| **std::is_same**                       | Verifica se dois tipos são exatamente iguais.                                                                   | `std::is_same<T, U>::value`                                        |
| **std::is_base_of**                    | Verifica se uma classe é base de outra classe.                                                                  | `std::is_base_of<Base, Derived>::value`                            |
| **std::enable_if**                     | Habilita funções/classes/templates quando uma condição é verdadeira.                                            | `std::enable_if<std::is_integral<T>::value, void>::type`           |
| **std::disable_if**                    | Desabilita funções/templates quando uma condição é verdadeira (implementação não padrão).                       | Usado como inverso de `enable_if` em bibliotecas específicas.      |
| **std::integral_constant**             | Representa um valor constante em tempo de compilação.                                                           | `std::integral_constant<int, 42>::value`                           |
| **std::experimental::metaprogramming** | Conjunto de utilitários experimentais pré-C++17, antes dos conceitos e melhorias modernas.                      | Usado para metaprogramação avançada em C++14 e anteriores.         |

> E vários outros o SFINAE tem uma vasta gama de variedade

---

**std::tuple e std::apply**: `std::tuple` é uma estrutura de dados que permite armazenar diferentes
tipos de dados em uma única estrutura. Já `std::apply` aplica uma função a todos os elementos de
uma tupla.

---

## Como Aplicar Metaprogramação

A metaprogramação em C++ é usada para:

- Otimizar desempenho: Avaliar cálculos complexos em tempo de compilação, como no exemplo do fatorial.
- Aumentar reutilização: Criar funções e classes genéricas que funcionam com múltiplos tipos.
- Garantir segurança de tipos: Usar `<type_traits>` e `<concepts>` para restringir templates e evitar erros.
- Reduzir código repetitivo: Técnicas como if constexpr e SFINAE eliminam a necessidade de múltiplas implementações.
