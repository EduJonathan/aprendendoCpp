<!-- @format -->

# ALGORITMOS DO HEADER `<algorithm>`

A biblioteca **`<algorithm>`** é um dos pilares da STL (Standard Template Library) em C++.
Seu objetivo é evitar reinventar a roda, fornecendo um vasto conjunto de algoritmos genéricos prontos para uso,
otimizados e consistentes com o modelo de iteradores da linguagem.

Enquanto os containers (`std::vector`, `std::list`, `std::map` etc.) definem como os dados são armazenados,
o **`<algorithm>`** define como operar sobre eles — permitindo realizar tarefas como
buscas, transformações, ordenações, comparações, remoções e agregações sem depender de um tipo de container específico.

Esses algoritmos são implementados sobre faixas de iteradores, e suas complexidades assintóticas variam conforme o tipo de acesso:

- **Random Access Iterators** (`vector`, `deque`, `array`) → permitem `O(log n)` / `O(n log n)`.
- **Bidirectional / Forward Iterators** (`list`, `forward_list`) → muitas operações ficam em `O(n)`.

> **Observação:** as complexidades abaixo assumem comparações/cópias em tempo constante.

---

## Buscas

| Função               | Descrição                                                                    | Complexidade                 |
| -------------------- | ---------------------------------------------------------------------------- | ---------------------------- |
| `std::find`          | Encontra o primeiro elemento igual ao valor                                  | `O(n)`                       |
| `std::find_if`       | Encontra o primeiro elemento que satisfaz o predicado                        | `O(n)`                       |
| `std::find_if_not`   | Encontra o primeiro que **não** satisfaz o predicado                         | `O(n)`                       |
| `std::find_end`      | Encontra a última ocorrência de uma subsequência                             | `O(n·m)`                     |
| `std::find_first_of` | Encontra o primeiro elemento que pertence a um conjunto                      | `O(n·m)`                     |
| `std::binary_search` | Verifica existência em sequência ordenada                                    | `O(log n)`                   |
| `std::adjacent_find` | Localiza o primeiro par de elementos consecutivos iguais.                    | `O(1)–O(n)`                  |
| `std::lower_bound`   | Busca o primeiro elemento ≥ valor (requer ordenação).                        | `O(log n)`                   |
| `std::upper_bound`   | Busca o primeiro elemento > valor (requer ordenação).                        | `O(log n)`                   |
| `std::mismatch`      | Encontra o primeiro par diferente entre duas faixas.                         | `O(1)–O(n)`                  |
| `std::nth_element`   | Rearranja de modo que o elemento **n-ésimo** esteja em sua posição ordenada. | `Média: O(n)`; `Pior: O(n²)` |

---

## Aplicação

| Função            | Descrição                                 | Complexidade |
| ----------------- | ----------------------------------------- | ------------ |
| `std::for_each`   | Aplica função a cada elemento             | `O(n)`       |
| `std::for_each_n` | Aplica função aos `n` primeiros elementos | `O(n)`       |

---

## Comparação

| Função                         | Descrição                                   | Complexidade |
| ------------------------------ | ------------------------------------------- | ------------ |
| `std::equal`                   | Compara duas sequências elemento a elemento | `O(n)`       |
| `std::lexicographical_compare` | Compara sequências em ordem lexicográfica   | `O(n)`       |

> Nota: `std::equal_to` é um **_functor_** em `<functional>`, não um algoritmo.

---

## Heaps

| Função           | Descrição                       | Complexidade |
| ---------------- | ------------------------------- | ------------ |
| `std::make_heap` | Constrói um heap máximo         | `O(n)`       |
| `std::push_heap` | Insere elemento no heap         | `O(log n)`   |
| `std::pop_heap`  | Remove o maior elemento do heap | `O(log n)`   |
| `std::sort_heap` | Ordena um heap                  | `O(n log n)` |

---

## Intervalos (Predicados)

| Função         | Descrição                                | Complexidade |
| -------------- | ---------------------------------------- | ------------ |
| `std::all_of`  | Verifica se todos satisfazem o predicado | `O(n)`       |
| `std::any_of`  | Verifica se algum satisfaz o predicado   | `O(n)`       |
| `std::none_of` | Verifica se nenhum satisfaz o predicado  | `O(n)`       |

---

## Modificação

| Função                 | Descrição                                    | Complexidade |
| ---------------------- | -------------------------------------------- | ------------ |
| `std::remove`          | Reorganiza removendo valores iguais          | `O(n)`       |
| `std::remove_if`       | Reorganiza removendo por predicado           | `O(n)`       |
| `std::remove_copy`     | Copia sem elementos iguais                   | `O(n)`       |
| `std::remove_copy_if`  | Copia sem elementos que satisfazem predicado | `O(n)`       |
| `std::fill`            | Preenche intervalo com valor                 | `O(n)`       |
| `std::fill_n`          | Preenche `n` elementos                       | `O(n)`       |
| `std::copy`            | Copia intervalo                              | `O(n)`       |
| `std::copy_if`         | Copia elementos que satisfazem predicado     | `O(n)`       |
| `std::copy_n`          | Copia `n` elementos                          | `O(n)`       |
| `std::replace`         | Substitui valores iguais                     | `O(n)`       |
| `std::replace_if`      | Substitui por predicado                      | `O(n)`       |
| `std::replace_copy`    | Copia substituindo valores                   | `O(n)`       |
| `std::replace_copy_if` | Copia substituindo por predicado             | `O(n)`       |
| `std::swap`            | Troca dois valores                           | `O(1)`       |
| `std::swap_ranges`     | Troca dois intervalos                        | `O(n)`       |
| `std::reverse`         | Inverte a ordem do intervalo                 | `O(n)`       |
| `std::reverse_copy`    | Copia intervalo invertido                    | `O(n)`       |
| `std::generate`        | Gera valores usando uma função.              | `Θ(n)`       |

---

## Numéricos

| Função             | Descrição                              | Complexidade |
| ------------------ | -------------------------------------- | ------------ |
| `std::max`         | Retorna o maior entre dois valores     | `O(1)`       |
| `std::min`         | Retorna o menor entre dois valores     | `O(1)`       |
| `std::max_element` | Retorna iterador para o maior elemento | `O(n)`       |
| `std::min_element` | Retorna iterador para o menor elemento | `O(n)`       |
| `std::count`       | Conta ocorrências de um valor          | `O(n)`       |

---

## Ordenação

| Função              | Descrição                       | Complexidade |
| ------------------- | ------------------------------- | ------------ |
| `std::sort`         | Ordena intervalo                | `O(n log n)` |
| `std::stable_sort`  | Ordena preservando estabilidade | `O(n log n)` |
| `std::partial_sort` | Ordena apenas os `k` primeiros  | `O(n log k)` |
| `std::is_sorted`    | Verifica se está ordenado       | `O(n)`       |

---

## Permutação

| Função                  | Descrição                             | Complexidade |
| ----------------------- | ------------------------------------- | ------------ |
| `std::next_permutation` | Gera próxima permutação lexicográfica | `O(n)`       |
| `std::prev_permutation` | Gera permutação anterior              | `O(n)`       |

---

## Mesclagem

| Função               | Descrição                                             | Complexidade |
| -------------------- | ----------------------------------------------------- | ------------ |
| `std::merge`         | Mescla duas sequências ordenadas                      | `O(n + m)`   |
| `std::inplace_merge` | Combina duas subfaixas ordenadas contíguas, in-place. | `Θ(n)`       |

---

## Partição

| Função           | Descrição                        | Complexidade |
| ---------------- | -------------------------------- | ------------ |
| `std::partition` | Reorganiza com base em predicado | `O(n)`       |

---

## Remover duplicatas

| Função        | Descrição                    | Complexidade |
| ------------- | ---------------------------- | ------------ |
| `std::unique` | Remove duplicatas adjacentes | `O(n)`       |

---

## Rotação

| Função        | Descrição                           | Complexidade |
| ------------- | ----------------------------------- | ------------ |
| `std::rotate` | Rotaciona os elementos do intervalo | `O(n)`       |

---

## Shuffle

| Função         | Descrição                             | Complexidade |
| -------------- | ------------------------------------- | ------------ |
| `std::shuffle` | Embaralha os elementos aleatoriamente | `O(n)`       |

---

## Transformação

| Função           | Descrição                         | Complexidade |
| ---------------- | --------------------------------- | ------------ |
| `std::transform` | Aplica função e grava o resultado | `O(n)`       |

---

## Como Interpretar as notações

| **Notação**    | **Significado**                                                     |
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
