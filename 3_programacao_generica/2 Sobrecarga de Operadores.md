<!-- @format -->

# 🧮 Sobrecarga de Operadores em C++

## O que é?

Uma visão importante antes de começar, C++ oferece uma enorme quantidade de abstrações poderosas:
**classes**, **herança**, **templates**, **structs**, **métodos**, etc. É fácil se perder em meio a essa complexidade:

> **No fundo, tudo em C++ (e na maioria das linguagens) se resume a funções que recebem entradas, processam dados e retornam um resultado ou modificam algum estado.**

Esse princípio é universal e não muda, independentemente do recurso da linguagem utilizada:

- funções comuns
- métodos de classes
- funções template
- structs ou classes
- **operadores**

Em qualquer paradigma ou linguagem, toda operação em um programa envolve processamento de dados — com ou sem retorno de valores.

> Essa visão é especialmente útil aqui porque: **operadores em C++ nada mais são do que funções com uma sintaxe especial.**

---

## Onde isso se conecta com a sobrecarga de operadores?

Em C++, **operadores também são funções**, apenas com uma sintaxe especial.  
A **sobrecarga de operadores** permite redefinir esses operadores usando a palavra-chave `operator`
seguida do operador desejado. Com isso, você pode fazer com que operadores como `+`, `-`, `==`, `[]`, `()`, `<<`
e muitos outros funcionem de forma personalizada para seus tipos.

---

## Por que isso é útil?

Porque você pode escrever código mais claro e natural. Compare:

```cpp
// Mais verboso
ObjetoA.soma(ObjetoB);
objetoA.adicionar(objetoB).multiplicar(objetoC)

// Mais natural e menos verboso
ObjetoA + ObjetoB;
(objetoA + objetoB) * objetoC;
```

---

### Operadores que podem ser sobrecarregados

| Categoria                                        | Exemplos                                   | Pode ser sobrecarregado?  |
| ------------------------------------------------ | ------------------------------------------ | ------------------------- |
| Aritméticos                                      | `+`, `-`, `*`, `/`, `%`                    | ✅                        |
| Relacionais                                      | `==`, `!=`, `<`, `>`, `<=`, `>=`           | ✅                        |
| Lógicos                                          | `&&`,                                      |                           |
| Bitwise                                          | `&`,                                       | `<<` , `>>` , `^`, `~`    |
| Incremento/Decremento                            | `++`, `--`                                 | ✅                        |
| Atribuição                                       | `=`, `+=`, `-=`, `*=` etc.                 | ✅                        |
| Indexação                                        | `[]`                                       | ✅                        |
| Chamada de função                                | `()`                                       | ✅                        |
| Acesso a membro                                  | `->`                                       | ✅ (em casos específicos) |
| Alocação de memória                              | `new`, `delete`                            | ✅                        |
| Operadores que **não podem** ser sobrecarregados | `::`, `.?`, `sizeof`, `typeid`, `.*`, `?:` | ❌                        |

---

### Exemplo prático

```cpp
class Vetor
{
public:
    int x, y;
    Vetor(int x, int y) : x(x), y(y) {}

    // Sobrecarga do operador +
    Vetor operator+(const Vetor& outro) const
    {
        return Vetor(x + outro.x, y + outro.y);
    }
};

// Uso:
Vetor vetor1(1, 2), vetor2(3, 4);
Vetor resultado = vetor1 + vetor2; // c será (4, 6)
```

---

### OBSERVAÇÕES SOBRE AS SOBRECARGAS

Como visto no exemplo, com as sobrecargas de operadores percebemos o quão melhor
fica visualmente o nosso código no quesito de sintaxe, onde sem o uso

### ❌ Exemplo sem sobrecarga de operador

```cpp
class Vetor
{
public:
    int x, y;
    Vetor(int x, int y) : x(x), y(y) {}

    Vetor somar(const Vetor& outro) const
    {
        return Vetor(x + outro.x, y + outro.y);
    }
};

// Uso mais verboso:
Vetor a(1, 2), b(3, 4);
Vetor c = a.somar(b);
```

---

### ✅ Exemplo com sobrecarga de operador

```cpp
class Vetor
{
public:
    int x, y;
    Vetor(int x, int y) : x(x), y(y) {}

    // Sobrecarga do operador +
    Vetor operator+(const Vetor& outro) const
    {
        return Vetor(x + outro.x, y + outro.y);
    }
};

// Uso :
Vetor a(1, 2), b(3, 4);
Vetor c = a + b; // c será (4, 6)
```

---

## Uso comum de cada categoria

| Categoria                 | Propósito                         | Tipo de retorno típico       | Exemplo                        |
| ------------------------- | --------------------------------- | ---------------------------- | ------------------------------ |
| Aritméticos               | Operações matemáticas             | Novo objeto                  | `c = a + b;`                   |
| Relacionais               | Comparação entre objetos          | `bool`                       | `if (a == b)`                  |
| Lógicos                   | Combinação de condições           | `bool`                       | `a && b` (evite sobrecarregar) |
| Bitwise                   | Manipulação bit a bit             | Objeto modificado ou novo    | `c = a & b;`                   |
| Incremento/Decremento     | Alteração incremental             | `*this` (pré) ou cópia (pós) | `++v; v++;`                    |
| Atribuição composta       | Modificar objeto existente        | `*this`                      | `a += b;`                      |
| Indexação                 | Acesso/modificação de elementos   | Referência                   | `v[0] = 5;`                    |
| Chamada de função         | Objeto como função (functors)     | Qualquer tipo                | `comparador(a, b);`            |
| Acesso a membro (`->`)    | Smart pointers                    | Ponteiro ou objeto com `->`  | `ptr->funcao();`               |
| Alocação (`new`/`delete`) | Controle personalizado de memória | `void*` ou exceção           | Custom allocator               |

---

## Boas práticas na sobrecarga de operadores

- **Mantenha a semântica esperada**: `+` deve fazer algo parecido com adição, `==` deve ser equivalência, etc.
- **Sobrecarregue como função membro quando possível**, exceto:
  - Operadores que modificam o lado esquerdo (ex: `<<`, `>>` para streams) → melhor como funções friend.
  - Operadores de atribuição composta (`+=`, etc.) geralmente como membros.
- **Retorne `const` quando não modifica o objeto** (ex: operador `+`).
- **Implemente `==` e `!=` juntos**, e se possível forneça `operator<=>` (C++20 spaceship operator) para ganhar os outros automaticamente.
- **Evite sobrecarregar `&&` e `||`**: eles usam short-circuit evaluation que não pode ser replicado em funções.
- **Para `[]`**, forneça versão **const** e **não-const** quando fizer sentido.

---

> **Dica final**: Sobrecarregue **apenas o necessário** e **mantenha a intuição do operador**.
