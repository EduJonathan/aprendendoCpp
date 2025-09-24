# COMPLEXIDADE DE ALGUNS ALGORITMOS DO HEADER `<algorithm>`

| **Função/Algoritmo**    | **Melhor Caso/Pior**                        | **Descrição**                                                                 |
| ----------------------- | ------------------------------------------- | ----------------------------------------------------------------------------- | ---------------------------------------------------- |
| `std::begin` / `end`    | **O(1)**                                    | Apenas obtêm iteradores.                                                      |
| `std::find`             | **O(1)–O(n)**                               | Para se encontrar cedo, mas pior caso percorre todo intervalo.                |
| `std::find_if`          | **O(1)–O(n)**                               | Idem `find`, depende do predicado.                                            |
| `std::count`            | **Θ(n)**                                    | Sempre examina todos os elementos.                                            |
| `std::copy`             | **Θ(n)**                                    | Copia todos os elementos.                                                     |
| `std::accumulate`       | **Θ(n)**                                    | Soma ou aplica função a todos os elementos.                                   |
| `std::sort`             | Média/pior: **O(n log n)**; melhor: _impl._ | Implementações (Introsort) podem ser `O(n)` se já ordenado, não é garantido.  |
| `std::reverse`          | **Θ(n)**                                    | Troca pares até o centro.                                                     |
| `std::lower_bound`      | **O(log n)**                                | Requer intervalo ordenado.                                                    |
| `std::upper_bound`      | **O(log n)**                                | Requer intervalo ordenado.                                                    |
| `std::binary_search`    | **O(log n)**                                | Requer intervalo ordenado.                                                    |
| `std::merge`            | **Θ(n + m)**                                | `n` e `m` = tamanhos dos dois intervalos.                                     |
| `std::partition`        | **Θ(n)**                                    | Reorganiza elementos segundo predicado.                                       |
| `std::remove`           | **Θ(n)**                                    | “Remove” movendo elementos.                                                   |
| `std::unique`           | **Θ(n)**                                    | Remove duplicatas consecutivas.                                               |
| `std::swap`             | **O(1)**                                    | Troca dois objetos.                                                           |
| `std::adjacent_find`    | **O(1)–O(n)**                               | Para ao encontrar o primeiro par.                                             |
| `std::all_of`           | **O(1)–O(n)**                               | Para se encontrar violação logo.                                              |
| `std::any_of`           | **O(1)–O(n)**                               | Para se encontrar elemento válido logo.                                       |
| `std::equal`            | **O(1)–O(n)**                               | `O(1)` se tamanhos diferentes; caso contrário, compara até diferir ou acabar. |
| `std::fill`             | **Θ(n)**                                    | Preenche todo o intervalo.                                                    |
| `std::for_each`         | **Θ(n)**                                    | Executa função em todos os elementos.                                         |
| `std::generate`         | **Θ(n)**                                    | Gera valores para todo o intervalo.                                           |
| `std::max_element`      | **Θ(n)**                                    | Percorre para achar o maior.                                                  |
| `std::min_element`      | **Θ(n)**                                    | Percorre para achar o menor.                                                  |
| `std::mismatch`         | **O(1)–O(n)**                               | Para no primeiro par diferente.                                               |
| `std::next_permutation` | **O(1)–O(n)**                               | `O(1)` se já é a última permutação (faz só reverse).                          |
| `std::rotate`           | **Θ(n)** (melhor `O(1)` se nenhuma rotação) | Casos triviais: middle==first ou last.                                        |
| `std::shuffle`          | **Θ(n)**                                    | Fisher–Yates embaralha todos os elementos.                                    |
| `std::transform`        | **Θ(n)**                                    | Aplica operação e grava resultado.                                            |
| `std::unique`           | `O(n)`                                      | `O(n)`                                                                        | Remove duplicatas consecutivas.                      |
| `std::upper_bound`      | `O(log n)`                                  | `O(log n)`                                                                    | Primeiro elemento > valor dado (intervalo ordenado). |

## Como Interpretar

- `Θ(n)` – Sempre percorre `n` elementos (melhor e pior caso idênticos).
- `O(1)` – `O(n)` – pode terminar antes, mas o padrão só garante `O(n)` no pior caso.
- `O(log n)` – busca binária em intervalo ordenado.
