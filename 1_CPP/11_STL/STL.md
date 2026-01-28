<!-- @format -->

# STL (Standard Template Library)

A STL é um conjunto de headers com templates de classes, projetados para fornecer
implementações eficientes de algoritmos e containers.
Ela facilita o uso de estruturas de dados e algoritmos já prontos(para não ficar reiventando a roda),
permitindo ao programador focar mais na lógica do programa.

---

## CONTAINERS

São coleções de dados categorizadas em quatro tipos principais:

### 1º Adaptadores de Containers

> Não permitem acesso sequencial direto aos dados, mas fornecem uma interface especializada para manipulação dos dados.

**Exemplos:**

- `std::stack<T>`: Pilha (LIFO).
- `std::queue<T>`: Fila (FIFO).
- `std::priority_queue<T>`: Fila de prioridade.

---

### 2º Containers de Sequências

Permitem o acesso sequencial aos dados.

**Exemplos:**

- `std::vector<T>`: Vetor dinâmico com acesso rápido por índice.
- `std::deque<T>`: Fila de acesso eficiente nas duas extremidades.
- `std::list<T>`: Lista duplamente encadeada (acesso sequencial).

---

### 3º Containers Associativos

> Armazenam dados em pares chave-valor, geralmente em árvores binárias balanceadas.

**Exemplos:**

- `std::map<T>`: Mapa ordenado de chave-valor (chaves únicas).
- `std::multimap<T>`: Mapa ordenado permitindo chaves duplicadas.
- `std::set<T>`: Conjunto ordenado de elementos únicos.
- `std::multiset<T>`: Conjunto ordenado permitindo elementos duplicados.

---

### 4º Containers Desordenados

> Usam tabelas hash para armazenar dados, proporcionando busca rápida (em média O(1)).

**Exemplos:**

- `std::unordered_map<T>`: Mapa de chave-valor desordenado.
- `std::unordered_set<T>`: Conjunto desordenado de elementos únicos.

---

## Diferenças da Inicialização Entre `{}` E `()` Em STL

A escolha entre {} (uniform initialization) e () (inicialização tradicional) pode afetar
significativamente o comportamento do seu código em C++, especialmente com containers STL
que têm construtores sobrecarregados.

### Características da inicialização `{}`

1. Introduzida no C++11 como "uniform initialization".
2. Previne narrowing conversions (conversões que perdem informação).
3. Tem prioridade para construtores que aceitam std::initializer_list.

```cpp
std::vector<int> v1{1, 2, 3};                             // Inicializa um vector com 3 elementos: 1, 2, 3
std::map<std::string, int> m1{{"key1", 1}, {"key2", 2}}; // Inicializa um map com dois pares chave-valor
std::set<int> s1{10, 20, 30};                           // Inicializa um set com 3 elementos
```

---

### Características da inicialização `()`

1. Sintaxe tradicional do C++.
2. Pode permitir narrowing conversions.
3. Chama os construtores normais da classe.

```cpp
std::vector<int> v2(5);      // Cria um vector com 5 elementos, todos 0 (chama construtor com tamanho)
std::vector<int> v3(5, 100); // Cria um vector com 5 elementos, todos sendo 100
std::set<int> s2();          // Declaração de função! (não de um set!)
```

> Nota: `std::set<int> s2();` é interpretado como declaração de função, conhecido como `Most Vexing Parse`.

---

## STL NÃO SE TRATA SOMENTE DE CONTAINERS

Lembrando, a **STL (Standard Template Library)** não se limita apenas a contêineres de dados.
Ela é composta por um ecossistema de componentes genéricos que trabalham em conjunto, incluindo:

- **Iteradores**, responsáveis por abstrair a navegação entre os elementos dos contêineres;
- **Algoritmos**, que realizam operações como busca, ordenação e transformação de dados;
- **Function Objects (Functors)**, que permitem encapsular comportamento e lógica como objetos;
- **Bibliotecas utilitárias**, como **`<chrono>`**, para medição e manipulação de tempo;
- **Bibliotecas de alocações**, a header **`<memory>`** para alocações de memória seguras,
- Entre outros recursos que promovem reutilização, eficiência e expressividade no código C++.

---

## ✅ Recomendações

📌 Prefira `{}` porque:

- Deseja consistência e segurança (evita conversões implícitas perigosas).
- Trabalha com containers que têm overload para initializer_list.
- Funciona em quase todos os casos.

📌 Use `()` quando:

- Precisa chamar um construtor específico que não aceita initializer_list.
- Necessita de conversões explícitas ou intencionais (ex: double → int).
- Deseja inicialização por tamanho e valor em containers como vector.
