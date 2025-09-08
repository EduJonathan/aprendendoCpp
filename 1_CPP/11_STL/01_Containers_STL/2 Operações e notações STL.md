# OPERAÇÕES E COMPLEXIDADE DE ESTRUTRURA DE DADOS STL

## Adaptadores de Containers

> `std::Stack<T>` - Pilha

| **Operação** | **Descrição**                          | **Complexidade** |
| ------------ | -------------------------------------- | ---------------- |
| `.push(x)`   | Adiciona elemento x no topo            | O(1)             |
| `.pop()`     | Remove elemento do topo                | O(1)             |
| `.top()`     | Retorna elemento do topo (sem remover) | O(1)             |
| `.empty()`   | Retorna true se vazia                  | O(1)             |
| `.size()`    | Retorna número de elementos            | O(1)             |

---

> `std::queue<T>` - Fila

| **Operação** | **Descrição**                | **Complexidade** |
| ------------ | ---------------------------- | ---------------- |
| `.push(x)`   | Adiciona elemento x no final | O(1)             |
| `.pop()`     | Remove elemento do início    | O(1)             |
| `.front()`   | Retorna primeiro elemento    | O(1)             |
| `.back()`    | Retorna último elemento      | O(1)             |
| `.empty()`   | Retorna true se vazia        | O(1)             |
| `.size()`    | Retorna número de elementos  | O(1)             |

---

> `std::priority_queue<T>` - Fila de prioridade

| **Operação** | **Descrição**                                           | **Complexidade** |
| ------------ | ------------------------------------------------------- | ---------------- |
| `.push(x)`   | Insere elemento x mantendo a propriedade de heap máximo | O(log n)         |
| `.pop()`     | Remove elemento de maior prioridade                     | O(log n)         |
| `.top()`     | Retorna elemento de maior prioridade                    | O(1)             |
| `.empty()`   | Retorna true se vazia                                   | O(1)             |
| `.size()`    | Retorna número de elementos                             | O(1)             |

---

## CONTAINERS DE SEQUÊNCIA

> `std::vector<T>` - Vetor dinâmico com acesso rápido por índice

| **Operação**      | **Descrição**                                | **Complexidade** |
| ----------------- | -------------------------------------------- | ---------------- |
| `.push_back(x)`   | Adiciona elemento no final                   | O(1)             |
| `.pop_back()`     | Remove o último elemento                     | O(1)             |
| `.insert(pos, x)` | Insere elemento na posição                   | O(n)             |
| `.erase(pos)`     | Remove elemento na posição                   | O(n)             |
| `.at(i)`          | Acessa o elemento na posição com verificação | O(1)             |
| `.operator[i]`    | Acessa o elemento na posição sem verificação | O(1)             |
| `.resize(n)`      | Redimensiona o vetor                         | O(n)             |
| `.clear()`        | Remove todos os elementos                    | O(n)             |
| `.size()`         | Número de elementos                          | O(1)             |
| `.capacity()`     | Capacidade alocada                           | O(1)             |
| `.empty()`        | Verifica se está vazio                       | O(1)             |
| `.front()`        | Retorna o primeiro elemento                  | O(1)             |
| `.back()`         | Retorna o último elemento                    | O(1)             |

---

> `std::deque<T>` - Fila dupla com acesso eficiente nas extremidades

| **Operação**      | **Descrição**                    | **Complexidade** |
| ----------------- | -------------------------------- | ---------------- |
| `.push_back(x)`   | Adiciona no final                | O(1)             |
| `.push_front(x)`  | Adiciona no início               | O(1)             |
| `.pop_back()`     | Remove do final                  | O(1)             |
| `.pop_front()`    | Remove do início                 | O(1)             |
| `.insert(pos, x)` | Insere na posição                | O(n)             |
| `.erase(pos)`     | Remove da posição                | O(n)             |
| `.at(i)`          | Acessa com verificação de limite | O(1)             |
| `.operator[i]`    | Acesso sem verificação           | O(1)             |
| `.clear()`        | Remove todos os elementos        | O(n)             |
| `.size()`         | Número de elementos              | O(1)             |
| `.front()`        | Retorna o primeiro elemento      | O(1)             |
| `.back()`         | Retorna o último elemento        | O(1)             |

---

> `std::list<T>` - Lista duplamente encadeada

| **Operação**      | **Descrição**                            | **Complexidade** |
| ----------------- | ---------------------------------------- | ---------------- |
| `.push_back(x)`   | Adiciona no final                        | O(1)             |
| `.push_front(x)`  | Adiciona no início                       | O(1)             |
| `.pop_back()`     | Remove do final                          | O(1)             |
| `.pop_front()`    | Remove do início                         | O(1)             |
| `.insert(pos, x)` | Insere elemento (com iterador)           | O(1)             |
| `.erase(pos)`     | Remove elemento (com iterador)           | O(1)             |
| `.remove(x)`      | Remove todos os elementos iguais a x     | O(n)             |
| `.unique()`       | Remove elementos duplicados consecutivos | O(n)             |
| `.sort()`         | Ordena os elementos                      | O(n log n)       |
| `.reverse()`      | Inverte a ordem dos elementos            | O(n)             |
| `.size()`         | Número de elementos                      | O(1)             |
| `.clear()`        | Remove todos os elementos                | O(n)             |
| `.empty()`        | Verifica se está vazio                   | O(1)             |
| `.front()`        | Primeiro elemento                        | O(1)             |
| `.back()`         | Último elemento                          | O(1)             |

---

> `std::array<T, N>` - Array de tamanho fixo em tempo de compilação

| **Operação**   | **Descrição**                               | **Complexidade** |
| -------------- | ------------------------------------------- | ---------------- |
| `.at(i)`       | Acessa elemento com verificação de limites  | O(1)             |
| `.operator[i]` | Acesso direto ao elemento (sem verificação) | O(1)             |
| `.fill(x)`     | Preenche todos os elementos com x           | O(n)             |
| `.front()`     | Retorna o primeiro elemento                 | O(1)             |
| `.back()`      | Retorna o último elemento                   | O(1)             |
| `.size()`      | Retorna o número de elementos               | O(1)             |
| `.empty()`     | Verifica se está vazio                      | O(1)             |
| `.begin()`     | Iterador para o primeiro elemento           | O(1)             |
| `.end()`       | Iterador para o final                       | O(1)             |

---

> `std::string` - Cadeia de caracteres (baseado em `std::vector<char>`)

| **Operação**      | **Descrição**                                         | **Complexidade** |
| ----------------- | ----------------------------------------------------- | ---------------- |
| `.push_back(c)`   | Adiciona caractere ao final                           | O(1)             |
| `.pop_back()`     | Remove o último caractere                             | O(1)             |
| `.append(str)`    | Concatena string ao final                             | O(n)             |
| `.insert(pos, s)` | Insere string ou caractere na posição                 | O(n)             |
| `.erase(pos, n)`  | Remove `n` caracteres a partir da posição             | O(n)             |
| `.replace()`      | Substitui trecho da string                            | O(n)             |
| `.substr(pos, n)` | Retorna substring de `n` caracteres a partir de `pos` | O(n)             |
| `.find(s)`        | Retorna posição da substring `s`                      | O(n)             |
| `.size()`         | Tamanho da string                                     | O(1)             |
| `.clear()`        | Esvazia a string                                      | O(1)             |
| `.at(i)`          | Acesso com verificação                                | O(1)             |
| `.operator[i]`    | Acesso sem verificação                                | O(1)             |
| `.c_str()`        | Retorna ponteiro para estilo string C-style           | O(1)             |

---

## CONTAINERS ASSOCIATIVOS

> `std::set<T>` – Conjunto ordenado (sem duplicatas)

| **Operação** | **Descrição**                              | **Complexidade** |
| ------------ | ------------------------------------------ | ---------------- |
| `.insert(x)` | Insere o elemento x (se ainda não existir) | O(log n)         |
| `.erase(x)`  | Remove o elemento x                        | O(log n)         |
| `.find(x)`   | Busca pelo elemento x                      | O(log n)         |
| `.size()`    | Número de elementos                        | O(1)             |
| `.empty()`   | Verifica se está vazio                     | O(1)             |
| `.clear()`   | Remove todos os elementos                  | O(n)             |
| `.begin()`   | Iterador para o primeiro elemento          | O(1)             |
| `.end()`     | Iterador para o após o último elemento     | O(1)             |

> `std::map<KEY, T>` – Mapa ordenado (chave única)

| **Operação**     | **Descrição**                                                | **Complexidade** |
| ---------------- | ------------------------------------------------------------ | ---------------- |
| `.insert({k,v})` | Insere um par chave-valor                                    | O(log n)         |
| `.erase(k)`      | Remove o par com chave `k`                                   | O(log n)         |
| `.find(k)`       | Busca o par com chave `k`                                    | O(log n)         |
| `.operator[k]`   | Acessa o valor associado à chave `k` (insere se não existir) | O(log n)         |
| `.size()`        | Número de pares armazenados                                  | O(1)             |
| `.empty()`       | Verifica se está vazio                                       | O(1)             |
| `.clear()`       | Remove todos os pares                                        | O(n)             |
| `.begin()`       | Iterador para o primeiro par                                 | O(1)             |
| `.end()`         | Iterador após o último par                                   | O(1)             |

---

> `std::multiset<KEY, T>` – Conjunto ordenado com duplicata

| **Operação** | **Descrição**                            | **Complexidade** |
| ------------ | ---------------------------------------- | ---------------- |
| `.insert(x)` | Insere o elemento x (permite duplicatas) | O(log n)         |
| `.erase(x)`  | Remove uma ou todas as ocorrências de x  | O(log n)         |
| `.find(x)`   | Busca pelo elemento x                    | O(log n)         |
| `.count(x)`  | Conta o número de ocorrências de x       | O(log n)         |
| `.size()`    | Número total de elementos                | O(1)             |
| `.empty()`   | Verifica se está vazio                   | O(1)             |
| `.clear()`   | Remove todos os elementos                | O(n)             |
| `.begin()`   | Iterador para o primeiro elemento        | O(1)             |
| `.end()`     | Iterador após o último elemento          | O(1)             |

---

> `std::multimap<KEY, T>` – Mapa ordenado com múltiplas chaves repetidas

| **Operação**      | **Descrição**                                                | **Complexidade** |
| ----------------- | ------------------------------------------------------------ | ---------------- |
| `.insert({k,v})`  | Insere um par chave-valor (permite duplicatas)               | O(log n)         |
| `.erase(k)`       | Remove todos os pares com chave `k`                          | O(log n)         |
| `.find(k)`        | Retorna iterador para a primeira ocorrência de `k`           | O(log n)         |
| `.operator[k]`    | Acessa o valor associado à chave `k` (insere se não existir) | O(1)             |
| `.equal_range(k)` | Retorna intervalo com todos os pares com chave `k`           | O(log n)         |
| `.size()`         | Número total de pares armazenados                            | O(1)             |
| `.empty()`        | Verifica se está vazio                                       | O(1)             |
| `.clear()`        | Remove todos os pares                                        | O(n)             |
| `.begin()`        | Iterador para o primeiro par                                 | O(1)             |
| `.end()`          | Iterador após o último par                                   | O(1)             |

---

## CONTAINERS DESORDENADOS

> `std::unordered_set<T>` – Conjunto não ordenado (sem duplicatas)

| **Operação** | **Descrição**                     | **Complexidade Média** | **Pior Caso** |
| ------------ | --------------------------------- | ---------------------- | ------------- |
| `.insert(x)` | Insere o elemento x               | O(1)                   | O(n)          |
| `.erase(x)`  | Remove o elemento x               | O(1)                   | O(n)          |
| `.find(x)`   | Busca pelo elemento x             | O(1)                   | O(n)          |
| `.size()`    | Número de elementos               | O(1)                   | O(1)          |
| `.empty()`   | Verifica se está vazio            | O(1)                   | O(1)          |
| `.clear()`   | Remove todos os elementos         | O(n)                   | O(n)          |
| `.begin()`   | Iterador para o primeiro elemento | O(1)                   | O(1)          |
| `.end()`     | Iterador após o último elemento   | O(1)                   | O(1)          |

---

> `std::unordered_map<Key, T>` – Mapa não ordenado (chave única)

| **Operação**     | **Descrição**                                         | **Complexidade Média** | **Pior Caso** |
| ---------------- | ----------------------------------------------------- | ---------------------- | ------------- |
| `.insert({k,v})` | Insere par chave-valor                                | O(1)                   | O(n)          |
| `.erase(k)`      | Remove o par com chave `k`                            | O(1)                   | O(n)          |
| `.find(k)`       | Busca par com chave `k`                               | O(1)                   | O(n)          |
| `.operator[k]`   | Acessa valor associado (insere `v` se `k` não existe) | O(1)                   | O(n)          |
| `.size()`        | Número de pares armazenados                           | O(1)                   | O(1)          |
| `.empty()`       | Verifica se está vazio                                | O(1)                   | O(1)          |
| `.clear()`       | Remove todos os pares                                 | O(n)                   | O(n)          |
| `.begin()`       | Iterador para o primeiro par                          | O(1)                   | O(1)          |
| `.end()`         | Iterador após o último par                            | O(1)                   | O(1)          |

---

> `std::unordered_multiset<T>` – Conjunto não ordenado com duplicatas

| **Operação** | **Descrição**                            | **Complexidade Média** | **Pior Caso** |
| ------------ | ---------------------------------------- | ---------------------- | ------------- |
| `.insert(x)` | Insere o elemento x (permite duplicatas) | O(1)                   | O(n)          |
| `.erase(x)`  | Remove uma ou todas as ocorrências de x  | O(1)                   | O(n)          |
| `.find(x)`   | Busca uma ocorrência de x                | O(1)                   | O(n)          |
| `.size()`    | Número de elementos                      | O(1)                   | O(1)          |
| `.empty()`   | Verifica se está vazio                   | O(1)                   | O(1)          |
| `.clear()`   | Remove todos os elementos                | O(n)                   | O(n)          |
| `.begin()`   | Iterador para o primeiro elemento        | O(1)                   | O(1)          |
| `.end()`     | Iterador após o último elemento          | O(1)                   | O(1)          |

---

> `std::unordered_multimap<Key, T>` – Mapa não ordenado com múltiplas chaves repetidas

| **Operação**      | **Descrição**                                           | **Complexidade Média** | **Pior Caso** |
| ----------------- | ------------------------------------------------------- | ---------------------- | ------------- |
| `.insert({k,v})`  | Insere par chave-valor (permite duplicatas)             | O(1)                   | O(n)          |
| `.erase(k)`       | Remove todos os pares com chave `k`                     | O(1)                   | O(n)          |
| `.find(k)`        | Retorna iterador para uma ocorrência da chave `k`       | O(1)                   | O(n)          |
| `.equal_range(k)` | Retorna intervalo com todas as ocorrências da chave `k` | O(1)                   | O(n)          |
| `.size()`         | Número de pares armazenados                             | O(1)                   | O(1)          |
| `.empty()`        | Verifica se está vazio                                  | O(1)                   | O(1)          |
| `.clear()`        | Remove todos os pares                                   | O(n)                   | O(n)          |
| `.begin()`        | Iterador para o primeiro par                            | O(1)                   | O(1)          |
| `.end()`          | Iterador após o último par                              | O(1)                   | O(1)          |

---

## COMPLEXIDADE DE ALGUNS ALGORITMOS DO HEADER `<algorithm>`

| **Função/Algoritmo** | **Melhor Caso** | **Pior Caso** | **Descrição**                              |
| -------------------- | --------------- | ------------- | ------------------------------------------ |
| `std::begin`         | O(1)            | O(1)          | Iterador para o início do contêiner.       |
| `std::end`           | O(1)            | O(1)          | Iterador para o final do contêiner.        |
| `std::find`          | O(1)            | O(n)          | Busca um valor no intervalo.               |
| `std::find_if`       | O(1)            | O(n)          | Busca um valor que satisfaça um predicado. |
| `std::count`         | O(1)            | O(n)          | Conta ocorrências de um valor.             |
| `std::copy`          | O(1)            | O(n)          | Copia elementos de um intervalo.           |
| `std::accumulate`    | O(1)            | O(n)          | Soma os elementos de um intervalo.         |
| `std::sort`          | O(n log n)      | O(n log n)    | Ordena os elementos.                       |
| `std::reverse`       | O(1)            | O(n)          | Inverte a ordem dos elementos.             |
| `std::lower_bound`   | O(log n)        | O(log n)      | Primeiro elemento >= valor dado.           |
| `std::upper_bound`   | O(log n)        | O(log n)      | Primeiro elemento > valor dado.            |
| `std::binary_search` | O(log n)        | O(log n)      | Verifica existência de valor ordenado.     |
| `std::merge`         | O(n)            | O(n)          | Une dois intervalos ordenados.             |
| `std::partition`     | O(n)            | O(n)          | Reorganiza baseado em predicado.           |
| `std::remove`        | O(n)            | O(n)          | Remove valor de um intervalo.              |
| `std::unique`        | O(n)            | O(n)          | Remove duplicatas consecutivas.            |
| `std::swap`          | O(1)            | O(1)          | Troca dois elementos.                      |

---

## Interpretação rápida sobre

- O(1): Muito rápido (constante).
- O(log n): Razoavelmente rápido (estruturas de árvore balanceada).
- O(n): Lento para grandes dados (linear).

## 🔎 Observações de Complexidade de Containers STL

- vector: Rápido no final, lento no meio/início.
- deque: Acesso direto possível, melhor que list.
- list: Inserção/remoção eficientes em qualquer ponto.
- forward_list: Lista ligada simples, sem acesso reverso.
- set: Ordenado, baseado em árvore balanceada.
- unordered_set: Não ordenado, baseado em hash.
- map: Associativo, ordenado.
- unordered_map: Associativo, não ordenado (hash).
