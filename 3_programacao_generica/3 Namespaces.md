<!-- @format -->

# Namespaces em C++

Em C++, um namespace tem um propósito simples e fundamental:
organizar e agrupar elementos de código relacionados — como variáveis, funções e classes — dentro de um escopo próprio.

Isso ajuda a:

- ✅ Evitar conflitos de nomes
- ✅ Tornar o código mais legível
- ✅ Facilitar a manutenção em projetos médios e grandes

É por isso que vemos escopos como:

- `std::`→ biblioteca padrão
- `qt::` → framework Qt
- `fx::` → namespaces definidos pelo próprio projeto

Todos existem justamente para diferenciar origens de símbolos.

---

```cpp
#include <iostream>
#include <algorithm>

int Count = 10; // Variável global count

namespace count
{
    int count = 20; // Variável count dentro do namespace count
} // namespace count

int main(int argc, char const *argv[])
{
    std::cout << "count (global): " << ::Count << std::endl;               // Acessa a variável global count (10)
    std::cout << "count (namespace count): " << count::count << std::endl; // Acessa a variável count dentro do namespace count (20)

    std::cout << "-----------------------------------" << '\n';
    std::cout << "ESCOPO `::` (Resolução de Ambiguidades)" << '\n';
    std::cout << "-----------------------------------" << '\n';

    // 1. Variável local
    int count = 30;

    // Imprime 30 (local)
    std::cout << "count (local): " << count << '\n';

    // 2. Variável global
    std::cout << "::Count (global): " << ::Count << '\n'; // Imprime 10 (acessa o global explícito)

    // 3. Variável do namespace count
    std::cout << "count::count (namespace count): " << count::count << '\n'; // Imprime 20 (acessa o count dentro do namespace count)

    // 4. Função global (std) - Note que 'std' é um namespace, porém para uma função da header algorithm
    std::string string = "String";
    std::cout << "Resultado (std::count): " << std::count(string.begin(), string.end(), 'a') << '\n';
    return 0;
}
```

---

## O que está acontecendo neste código?

- 1 `Escopo local`

```cpp
int count = 30; // Tem prioridade máxima dentro do bloco (main).
```

---

- 2 `Escopo global`

```cpp
::Count; // O operador :: sem nome antes força o acesso ao escopo global.
```

---

- 3 `Escopo de namespace`

```cpp
count::count // Aqui indicamos explicitamente que queremos o count definido dentro do namespace count.
```

---

- 4 `Namespace da biblioteca padrão`

```cpp
std::count(...) //std é um namespace, não um escopo global. Ele agrupa todas as entidades da biblioteca padrão do C++.
```

---

## Conclusão

Conclusão

Namespaces são essenciais para:

- organizar código
- evitar colisões de nomes
- tornar explícita a origem de símbolos

Em projetos pequenos, eles parecem dispensáveis. Em projetos reais, são obrigatórios.

> O operador :: é a ferramenta que permite resolver ambiguidades de forma clara, segura e intencional.
