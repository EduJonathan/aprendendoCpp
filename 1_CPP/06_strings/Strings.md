# STRINGS EM C++

Strings em C++ são tratadas de maneira mais moderna que em C, utilizando tipos e funções
já integrados à linguagem, facilitando o uso do tipo de dado como o própio `std::string`,
dentre outros, seguindo o paradigma orientado a objetos dentre outros paradigma próprio do C++.

O porém de apesar dessa modernidade, é o seu modo de operação que ainda se relaciona
à tabela ASCII, e ao tipo de dado `char[]` e `char*`, assim como em C.

---

## Características Das Strings em C++

- **std::string**: É o tipo mais usado para manipular strings em C++.
  Ele encapsula a gestão de memória e oferece uma interface rica para manipulação de texto.

- **Strings C-style**: São arrays de caracteres terminados por um caractere nulo (`'\0'`).

- **Tabela ASCII**: A representação interna dos caracteres, que cada caractere é mapeado
  por valores numéricos sejam (Binário, Octal, Hexadecimal, Decimal).

---

## Bibliotecas Para Tratamentos De Strings Em C++

### 1. `#include <string>`

Contém a classe `std::string`, que oferece uma manipulação moderna de strings em C++.  
Permitindo operações como concatenação, busca, substituição e análise de texto
(como o tamanho da string(`.lenght()` ou `.size()`), por exemplo).

---

### 2. `#include <cstring>` e `#include <cwchar>`

- `<cstring>`: Biblioteca herdada do C, conhecida como `#include <string.h>` para
  manipulação de strings C-style (`char*` e `char[]`). Fornece funções como `strlen()`,
  `strcpy()`, `strcmp()`, entre outras.

- `<cwchar>`: Similar ao `<cstring>` e herdada do C `#include <wchar.h>`, porém para
  manipulação de strings wide (`wchar_t`), que suportam caracteres mais amplos, útil
  para Unicode em algumas plataformas (como emojis, caracteres mais amplos como Kanjis Japoneses, acentuação).

---

### 3. `#include <cctype>` e `#include <cwctype>`

- `<cctype>`: Funções para classificação e transformação de caracteres simples (`char`),
  herdada do C `#include <ctype.h>` vem funções como `isalpha()`, `isdigit()`, `toupper()`, etc.

- `<cwctype>`: Versão para caracteres wide (`wchar_t`), herdada do C `#include <wctype.h>`
  e com funções equivalentes ao `<cctype>` para manipular caracteres maiores (Unicode).

---

### 4. `#include <string_view>`

Introduzido no C++17, `std::string_view` representa uma visão não modificável e leve
sobre uma sequência de caracteres, sem copiar a string. Ideal para passar strings
de forma eficiente, evitando cópias desnecessárias.

---

## Tipos de Dados Para Manipular Strings

- **`char[]`**  
  Array estático de caracteres, geralmente usado para strings C-style terminadas por `'\0'`.

Quando utilizar:

- Quando for necessário interoperar com código legado em C.
- Em sistemas embarcados ou contextos de baixa memória, onde evitar overhead é essencial.
- Quando o tamanho da string é fixo ou conhecido em tempo de compilação.

---

- **`char*`**  
  Ponteiro para caractere, pode apontar para strings C-style alocadas estática ou dinamicamente.

Quando utilizar:

- Ao lidar com APIs em C que esperam `char*`.
- Quando for preciso manipular diretamente a memória.
- Em casos onde é necessário modificar o conteúdo da string (desde que seja uma string mutável e não literal).

---

- **`std::string`**  
  Classe da biblioteca padrão que aglomera strings de forma segura e eficiente,
  com gerenciamento automático de memória.

Quando utilizar:

- Para a maioria dos usos modernos em C++.
- Quando for necessário modificar, concatenar ou fazer operações com strings de forma segura.
- Ao armazenar ou retornar strings em aplicações C++ modernas.

---

- **`std::string_view`**  
  Introduzido no C++17, é uma visão leve e não proprietária de uma sequência de caracteres.
  Não gerencia memória, ideal para passar strings sem cópia.

Quando utilizar:

- Para funções que recebem apenas leitura de string, evitando cópia de dados.
- Em parsing e manipulação leve de substrings.
- Quando desejar interoperabilidade entre `std::string`, `char*`, `char[]` sem criar cópias temporárias.

---

- **`std::string_view_literals`**  
  Namespace que disponibiliza literais de string view (`"texto"sv`), permitindo
  criar `std::string_view` diretamente a partir de literais de texto.

Quando utilizar:

- Para escrever código mais limpo e direto ao criar `std::string_view` a partir de literais.
- Útil em testes, comparações, buscas rápidas com `std::string_view`.

---

- **`std::literals::string_view_literals`**  
  Namespace padrão para os literais de `std::string_view`, usado geralmente com a
  diretiva `using namespace`.

Quando utilizar:

- Quando quiser usar `"texto"sv` sem qualificar explicitamente o namespace.
- Geralmente combinado com `using namespace std::literals`; ou `std::literals::string_view_literals`.

---

- **`std::literals::string_literals`**  
  Namespace que disponibiliza literais para criar objetos `std::string` diretamente a
  partir de literais de texto (`"texto"s`).

Quando utilizar:

- Quando quiser criar objetos std::string a partir de literais de forma conveniente e explícita.
- Evita confusões com ponteiros (`char*`), especialmente em sobrecargas de função.
