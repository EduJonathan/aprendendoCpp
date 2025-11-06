# COMPLEXIDADE DE ALGUNS ALGORITMOS DO HEADER `<algorithm>`

A biblioteca **`<algorithm>`** é um dos pilares da STL (Standard Template Library) em C++.
Seu objetivo é evitar reinventar a roda, fornecendo um vasto conjunto de algoritmos genéricos prontos para uso,
otimizados e consistentes com o modelo de iteradores da linguagem.

Enquanto os containers (`std::vector`, `std::list`, `std::map` etc.) definem como os dados são armazenados,
o **`<algorithm>`** define como operar sobre eles — permitindo realizar tarefas como
buscas, transformações, ordenações, comparações, remoções e agregações sem depender de um tipo de container específico.

Esses algoritmos são implementados sobre faixas de iteradores, e suas complexidades assintóticas `(Big-O, Θ)` variam conforme o tipo de acesso fornecido:

- Random Access Iterators (`vector`, `deque`, `array`) → permitem algoritmos de busca e ordenação em `O(log n)` ou `O(n log n)`.
- Bidirectional / Forward Iterators (`list`, `forward_list`) → limitam algumas operações a `O(n)` ou `O(n²)`.

---

📊 Tabela de Complexidades Com Alguns Algoritmos

| **Função / Algoritmo**    | **Melhor / Pior Caso**              | **Descrição**                                                                                 |
| ------------------------- | ----------------------------------- | --------------------------------------------------------------------------------------------- |
| `std::begin` / `std::end` | **O(1)**                            | Obtêm iteradores para início e fim do container.                                              |
| `std::find`               | **O(1)–O(n)**                       | Procura um valor; pode parar cedo se encontrado.                                              |
| `std::find_if`            | **O(1)–O(n)**                       | Igual a `find`, mas com predicado personalizado.                                              |
| `std::count`              | **Θ(n)**                            | Conta quantas vezes um valor aparece.                                                         |
| `std::copy`               | **Θ(n)**                            | Copia todos os elementos de uma faixa para outra.                                             |
| `std::accumulate`         | **Θ(n)**                            | Aplica soma (ou operação binária) a todos os elementos. Depende do custo da operação.         |
| `std::sort`               | **Média/Pior: O(n log n)**          | Implementado como _Introsort_ (Quick + Heap + Insertion). Garante limite superior O(n log n). |
| `std::stable_sort`        | **O(n log² n)**                     | Ordenação estável baseada em _mergesort_; usa memória auxiliar.                               |
| `std::nth_element`        | **Média: O(n)**; **Pior: O(n²)**    | Rearranja de modo que o elemento n-ésimo esteja em sua posição ordenada.                      |
| `std::reverse`            | **Θ(n)**                            | Inverte a ordem dos elementos, in-place.                                                      |
| `std::lower_bound`        | **O(log n)**                        | Busca o primeiro elemento ≥ valor (requer ordenação).                                         |
| `std::upper_bound`        | **O(log n)**                        | Busca o primeiro elemento > valor (requer ordenação).                                         |
| `std::binary_search`      | **O(log n)**                        | Verifica se um elemento está presente (requer ordenação).                                     |
| `std::merge`              | **Θ(n + m)**                        | Combina duas faixas ordenadas (de tamanhos `n` e `m`).                                        |
| `std::inplace_merge`      | **Θ(n)**                            | Combina duas subfaixas ordenadas contíguas, in-place.                                         |
| `std::partition`          | **Θ(n)**                            | Reorganiza elementos segundo um predicado.                                                    |
| `std::remove`             | **Θ(n)**                            | Move elementos válidos para frente; não reduz tamanho físico.                                 |
| `std::unique`             | **Θ(n)**                            | Remove duplicatas consecutivas (sem alterar tamanho físico).                                  |
| `std::swap`               | **O(1)**                            | Troca dois objetos.                                                                           |
| `std::adjacent_find`      | **O(1)–O(n)**                       | Localiza o primeiro par de elementos consecutivos iguais.                                     |
| `std::all_of`             | **O(1)–O(n)**                       | Retorna falso ao encontrar primeira violação.                                                 |
| `std::any_of`             | **O(1)–O(n)**                       | Retorna verdadeiro ao encontrar o primeiro caso válido.                                       |
| `std::equal`              | **O(1)–O(n)**                       | Compara duas faixas; para na primeira diferença.                                              |
| `std::fill`               | **Θ(n)**                            | Atribui um valor a todos os elementos.                                                        |
| `std::for_each`           | **Θ(n)**                            | Executa uma função em todos os elementos.                                                     |
| `std::generate`           | **Θ(n)**                            | Gera valores usando uma função.                                                               |
| `std::max_element`        | **Θ(n)**                            | Retorna o maior elemento.                                                                     |
| `std::min_element`        | **Θ(n)**                            | Retorna o menor elemento.                                                                     |
| `std::mismatch`           | **O(1)–O(n)**                       | Encontra o primeiro par diferente entre duas faixas.                                          |
| `std::next_permutation`   | **O(1)–O(n)**                       | Gera a próxima permutação lexicográfica (O(1) se já for a última).                            |
| `std::rotate`             | **Θ(n)** _(melhor O(1) se trivial)_ | Rotaciona elementos ao redor de um ponto; in-place.                                           |
| `std::shuffle`            | **Θ(n)**                            | Embaralha (Fisher–Yates), requer acesso aleatório.                                            |
| `std::transform`          | **Θ(n)**                            | Aplica função e grava resultado.                                                              |
| `std::is_sorted`          | **O(1)–O(n)**                       | Verifica se uma faixa está ordenada.                                                          |
| `std::includes`           | **O(n + m)**                        | Testa se um conjunto ordenado contém outro.                                                   |

---

## Como Interpretar

| Notação        | Significado                                                         |
| -------------- | ------------------------------------------------------------------- |
| **O(1)**       | Tempo constante — independe do tamanho dos dados.                   |
| **O(log n)**   | Cresce lentamente; típico de buscas binárias.                       |
| **O(n)**       | Cresce linearmente com o número de elementos.                       |
| **O(n log n)** | Típico de ordenações eficientes (sorts).                            |
| **Θ(n)**       | Tempo garantido linear — sempre percorre toda a faixa.              |
| **O(1)–O(n)**  | Pode parar antecipadamente, mas no pior caso percorre toda a faixa. |

---

## Notas

- **Complexidade**: As complexidades são baseadas em iteradores de acesso aleatório, salvo indicação contrária.
  Para `std::forward_list`, algumas operações (`std::sort`, `std::merge`) podem ter comportamento diferente devido à
  natureza simplesmente encadeada.
- **Pré-requisitos**: Funções como `std::lower_bound`, `std::upper_bound`, e `std::binary_search` exigem intervalos ordenados.
- **Θ(n) vs. O(n)**: `Θ(n)` indica que a operação sempre executa exatamente na ordem de `n`, enquanto `O(n)` permite casos melhores (parada antecipada em `std::find`).
