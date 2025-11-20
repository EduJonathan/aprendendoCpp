# 🧮 Sobrecarga de Operadores em C++

## O que é?

Antes de mergulharmos na **sobrecarga de operadores**, vale a pena relembrar um conceito fundamental sobre **funções**:

> **Toda função processa entrada(s) e/ou retorna um resultado.**

Seja em `struct`, `class (POO)` ou `template + class`, esse princípio é universal em C++ ou em quaisquer linguaguem:

> **toda operação envolve processamento e/ou retorno de valores**.

E onde isso se conecta com a **sobrecarga de operadores**?
A **Sobrecarga de operadores permite redefinir o comportamento de operadores (utilizando a keyword `operator` em seguida o operador) para objetos de classes definidas pelo usuário.**
Ou seja, você pode fazer com que operadores como `+`, `-`, `==`, `[]`, `()`, `<<`, entre outros, funcionem de forma
personalizada com seus próprios tipos.

---

### Operadores que podem ser sobrecarregados

| Categoria                                        | Exemplos                                   | Pode ser sobrecarregado?  |
| ------------------------------------------------ | ------------------------------------------ | ------------------------- |
| Aritméticos                                      | `+`, `-`, `*`, `/`, `%`                    | ✅                        |
| Relacionais                                      | `==`, `!=`, `<`, `>`, `<=`, `>=`           | ✅                        |
| Lógicos                                          | `&&`, `                                    |                           |
| Bitwise                                          | `&`, `                                     | ```, `^`, `<<`, `>>`, `~` |
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

Como visto no exemplo, com as sobrecargas de operadores percebemos o quão melhor fica visualmente o nosso código no
quesito de sintaxe, onde sem o uso

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

## Uso de Cada Categoria de Operadores

| Categoria                 | Propósito             | Retorno             | Exemplo                       |
| ------------------------- | --------------------- | ------------------- | ----------------------------- |
| **Operacionais**          | Operações matemáticas | Novo objeto         | `c = a + b;`                  |
| **Condicionais**          | Comparação            | `bool`              | `a == b`                      |
| **Lógicos**               | Condições             | `bool`              | `a && b` _(evite sobrecarga)_ |
| **Bitwise**               | Manipulação de bits   | Objeto modificado   | `c = a & b;`                  |
| **Incremento/Decremento** | Alteração incremental | `*this` ou cópia    | `++v; v++;`                   |
| **Atribuição**            | Modificar objeto      | `*this`             | `a += b;`                     |
| **Indexação**             | Acesso a elementos    | Referência          | `v[0] = 5;`                   |
| **Chamada de função**     | Objeto como função    | Qualquer tipo       | `comp(a, b);`                 |
| **Acesso a membro**       | Smart pointers        | Ponteiro/referência | `ptr->f();`                   |
| **Alocação**              | Controle de memória   | `void*`             | Custom `new`                  |

> **Dica final**: Sobrecarregue **apenas o necessário** e **mantenha a intuição do operador**.
