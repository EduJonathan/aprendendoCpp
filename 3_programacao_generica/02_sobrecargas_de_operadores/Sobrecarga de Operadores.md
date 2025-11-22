# 🧮 Sobrecarga de Operadores em C++

## O que é?

Antes de falar sobre **sobrecarga de operadores**, vale relembrar um ponto fundamental sobre funções:

> **Toda função processa entradas e retorna um resultado ou modifica algum estado.**

Isso vale para `struct`, `class`, `POO`, `templates`… Em qualquer linguagem e em qualquer contexto:

> **Toda operação envolve processamento e/ou retorno de valores**.

---

## Onde isso se conecta com a sobrecarga de operadores?

Em C++, **operadores também são funções**, apenas com uma sintaxe especial.  
A **sobrecarga de operadores** permite redefinir esses operadores usando a palavra-chave `operator` seguida do operador desejado.

Com isso, você pode fazer com que operadores como `+`, `-`, `==`, `[]`, `()`, `<<` e muitos outros funcionem de forma personalizada para seus tipos.

---

## Por que isso é útil?

Porque você pode escrever código mais claro e natural.  
Compare:

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
