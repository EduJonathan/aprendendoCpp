# OPERAÇÕES E COMPLEXIDADE DE ESTRUTRURA DE DADOS STL

## Adaptadores de Containers

> `std::Stack<T>` - Pilha

| **Operação** | **Descrição**                          | **Complexidade** |
| ------------ | -------------------------------------- | ---------------- |
| `.push(x)`   | Adiciona elemento x no topo            | `O(1)`           |
| `.pop()`     | Remove elemento do topo                | `O(1)`           |
| `.top()`     | Retorna elemento do topo (sem remover) | `O(1)`           |
| `.empty()`   | Retorna true se vazia                  | `O(1)`           |
| `.size()`    | Retorna número de elementos            | `O(1)`           |

## Alocação de Memória Da Stack

> Baseada em um container subjacente (por padrão, `std::deque<T>`).
> A alocação depende do container escolhido (`std::vector`, std::deque ou `std::list`).
> A memória é alocada dinamicamente conforme elementos são adicionados (e.g., `push`),
> e desalocada automaticamente quando elementos são removidos (`pop`) ou o objeto stack é destruído.
> Não há realocação explícita, mas o container subjacente gerencia a memória
> (e.g., `std::vector` pode realocar ao atingir a capacidade).

---

> `std::queue<T>` - Fila

| **Operação** | **Descrição**                | **Complexidade** |
| ------------ | ---------------------------- | ---------------- |
| `.push(x)`   | Adiciona elemento x no final | `O(1)`           |
| `.pop()`     | Remove elemento do início    | `O(1)`           |
| `.front()`   | Retorna primeiro elemento    | `O(1)`           |
| `.back()`    | Retorna último elemento      | `O(1)`           |
| `.empty()`   | Retorna true se vazia        | `O(1)`           |
| `.size()`    | Retorna número de elementos  | `O(1)`           |

## Alocação de Memória De Queue

> Também usa um container subjacente (por padrão, `std::deque<T>`).
> A memória é alocada dinamicamente para novos elementos no final (`push`) e desalocada do início (`pop`).
> Como no `std::stack`, a gestão de memória depende do container subjacente, que pode realocar
> (e.g., `std::vector`) ou gerenciar blocos de memória (e.g., `std::deque`).

---

> `std::priority_queue<T>` - Fila de prioridade

| **Operação** | **Descrição**                                           | **Complexidade** |
| ------------ | ------------------------------------------------------- | ---------------- |
| `.push(x)`   | Insere elemento x mantendo a propriedade de heap máximo | `O(log n)`       |
| `.pop()`     | Remove elemento de maior prioridade                     | `O(log n)`       |
| `.top()`     | Retorna elemento de maior prioridade                    | `O(1)`           |
| `.empty()`   | Retorna true se vazia                                   | `O(1)`           |
| `.size()`    | Retorna número de elementos                             | `O(1)`           |

## Alocação de Memória De Priority Queue

> Baseada em um `std::vector<T>` por padrão, que atua como o heap subjacente.
> A memória é alocada dinamicamente à medida que elementos são inseridos `(push)`, com realocações
> potenciais quando a capacidade do vetor é excedida (`O(n)` em caso de realocação).
> A desalocação ocorre automaticamente ao remover elementos `(pop)` ou destruir o objeto.
> A propriedade do heap é mantida via algoritmos como `std::push_heap` e `std::pop_heap`.

---

## CONTAINERS DE SEQUÊNCIA

> `std::vector<T>` - Vetor dinâmico com acesso rápido por índice

| **Operação**      | **Descrição**                                | **Complexidade** |
| ----------------- | -------------------------------------------- | ---------------- |
| `.push_back(x)`   | Adiciona elemento no final                   | `O(1)`           |
| `.pop_back()`     | Remove o último elemento                     | `O(1)`           |
| `.insert(pos, x)` | Insere elemento na posição                   | `O(n)`           |
| `.erase(pos)`     | Remove elemento na posição                   | `O(n)`           |
| `.at(i)`          | Acessa o elemento na posição com verificação | `O(1)`           |
| `.operator[i]`    | Acessa o elemento na posição sem verificação | `O(1)`           |
| `.resize(n)`      | Redimensiona o vetor                         | `O(n)`           |
| `.clear()`        | Remove todos os elementos                    | `O(n)`           |
| `.size()`         | Número de elementos                          | `O(1)`           |
| `.capacity()`     | Capacidade alocada                           | `O(1)`           |
| `.empty()`        | Verifica se está vazio                       | `O(1)`           |
| `.front()`        | Retorna o primeiro elemento                  | `O(1)`           |
| `.back()`         | Retorna o último elemento                    | `O(1)`           |

## Alocação de Memória De Vector

> Aloca um bloco contíguo de memória dinamicamente.
> Quando a capacidade é excedida (em `push_back` ou `insert`),
> realoca um novo bloco maior (tipicamente dobrando a capacidade)
> copia/move os elementos existentes e desaloca o bloco antigo, resultando em `O(n)` para realocação.
> A desalocação total ocorre em clear ou na destruição do objeto.
> Reserve(n) pode evitar realocações ao pré-alocar capacidade.

---

> `std::deque<T>` - Fila dupla com acesso eficiente nas extremidades

| **Operação**      | **Descrição**                    | **Complexidade** |
| ----------------- | -------------------------------- | ---------------- |
| `.push_back(x)`   | Adiciona no final                | `O(1)`           |
| `.push_front(x)`  | Adiciona no início               | `O(1)`           |
| `.pop_back()`     | Remove do final                  | `O(1)`           |
| `.pop_front()`    | Remove do início                 | `O(1)`           |
| `.insert(pos, x)` | Insere na posição                | `O(n)`           |
| `.erase(pos)`     | Remove da posição                | `O(n)`           |
| `.at(i)`          | Acessa com verificação de limite | `O(1)`           |
| `.operator[i]`    | Acesso sem verificação           | `O(1)`           |
| `.clear()`        | Remove todos os elementos        | `O(n)`           |
| `.size()`         | Número de elementos              | `O(1)`           |
| `.front()`        | Retorna o primeiro elemento      | `O(1)`           |
| `.back()`         | Retorna o último elemento        | `O(1)`           |

## Alocação de Memória De Deque

> Usa blocos de memória não contíguos (geralmente arrays fixos) conectados dinamicamente.
> Cada bloco tem tamanho fixo, e novos blocos são alocados quando necessário (em `push_back` ou `push_front`), com custo P`O(1)` amortizado.
> A desalocação ocorre ao remover elementos (`pop_front`, `pop_back`) ou destruir o objeto.
> Não requer realocação completa como o `std::vector`.

---

> `std::list<T>` - Lista duplamente encadeada

| **Operação**      | **Descrição**                            | **Complexidade** |
| ----------------- | ---------------------------------------- | ---------------- |
| `.push_back(x)`   | Adiciona no final                        | `O(1)`           |
| `.push_front(x)`  | Adiciona no início                       | `O(1)`           |
| `.pop_back()`     | Remove do final                          | `O(1)`           |
| `.pop_front()`    | Remove do início                         | `O(1)`           |
| `.insert(pos, x)` | Insere elemento (com iterador)           | `O(1)`           |
| `.erase(pos)`     | Remove elemento (com iterador)           | `O(1)`           |
| `.remove(x)`      | Remove todos os elementos iguais a x     | `O(n)`           |
| `.unique()`       | Remove elementos duplicados consecutivos | `O(n)`           |
| `.sort()`         | Ordena os elementos                      | `O(n log n)`     |
| `.reverse()`      | Inverte a ordem dos elementos            | `O(n)`           |
| `.size()`         | Número de elementos                      | `O(1)`           |
| `.clear()`        | Remove todos os elementos                | `O(n)`           |
| `.empty()`        | Verifica se está vazio                   | `O(1)`           |
| `.front()`        | Primeiro elemento                        | `O(1)`           |
| `.back()`         | Último elemento                          | `O(1)`           |

## Alocação de Memória Para List

> Cada elemento é alocado individualmente como um nó dinâmico contendo o valor e ponteiros para o próximo/anterior.
> Inserções (`push_back`, `push_front`, `insert`) alocam um novo nó (`O(1)`),
> e remoções (`pop_back`, `pop_front`, `erase`) desalocam o nó correspondente (`O(1)`).
> A desalocação total ocorre em clear ou na destruição do objeto.
> Não há realocações, mas o uso de memória é menos eficiente devido aos ponteiros.

---

> `std::foward_list<T>` - Lista simplesmente encadeada

| **Operação**            | **Descrição**                               | **Complexidade** |
| ----------------------- | ------------------------------------------- | ---------------- |
| `.push_front(x)`        | Adiciona elemento no início.                | `O(1)`           |
| `.pop_front()`          | Remove elemento do início.                  | `O(1)`           |
| `.insert_after(pos, x)` | Insere elemento após a posição do iterador. | `O(1)`           |
| `.erase_after(pos)`     | Remove elemento após a posição do iterador. | `O(1)`           |
| `.remove(x)`            | Remove todos os elementos iguais a x.       | `O(n)`           |
| `.unique()`             | Remove elementos duplicados consecutivos.   | `O(n)`           |
| `.sort()`               | Ordena os elementos.                        | `O(n log n)`     |
| `.reverse()`            | Inverte a ordem dos elementos.              | `O(n)`           |
| `.size()`               | Número de elementos.                        | `O(n)`           |
| `.clear()`              | Remove todos os elementos.                  | `O(n)`           |
| `.empty()`              | Verifica se está vazio.                     | `O(1)`           |
| `.front()`              | Retorna o primeiro elemento.                | `O(1)`           |
| `.back()`               | Retorna o último elemento.                  | `O(1)`           |
| `.push_back(x)`         | diciona elemento no final.                  | `O(1)`           |
| `.pop_back()`           | Remove elemento do final.                   | `O(1)`           |

## Alocação de Memória Para FowardList

> `std::forward_list` aloca memória dinamicamente para cada nó, com um único ponteiro por nó, reduzindo o overhead em comparação com a std::list.
> Inserções e remoções são `O(1)` quando o iterador é fornecido, mas operações no final da lista não são suportadas.
> Não mantém um contador de tamanho, o que economiza memória, mas torna `.size()` `O(n)`.
> A desalocação é automática e eficiente, com `O(n)` para liberar toda a lista.
> Comparada à `std::list`, é mais econômica em memória, mas menos versátil devido à falta de acesso ao final.

---

> `std::array<T, N>` - Array de tamanho fixo em tempo de compilação

| **Operação**   | **Descrição**                               | **Complexidade** |
| -------------- | ------------------------------------------- | ---------------- |
| `.at(i)`       | Acessa elemento com verificação de limites  | `O(1)`           |
| `.operator[i]` | Acesso direto ao elemento (sem verificação) | `O(1)`           |
| `.fill(x)`     | Preenche todos os elementos com x           | `O(n)`           |
| `.front()`     | Retorna o primeiro elemento                 | `O(1)`           |
| `.back()`      | Retorna o último elemento                   | `O(1)`           |
| `.size()`      | Retorna o número de elementos               | `O(1)`           |
| `.empty()`     | Verifica se está vazio                      | `O(1)`           |
| `.begin()`     | Iterador para o primeiro elemento           | `O(1)`           |
| `.end()`       | Iterador para o final                       | `O(1)`           |

## Alocação de Memória Para Array

> A memória é alocada estaticamente em tempo de compilação, com tamanho fixo `N`.
> Não há alocação dinâmica, realocação ou desalocação durante a execução, pois o tamanho é fixo.
> A memória é liberada automaticamente quando o objeto sai de escopo.
> Oferece eficiência máxima, mas não permite redimensionamento.

---

> `std::string` - Cadeia de caracteres (baseado em `std::vector<char>`)

| **Operação**      | **Descrição**                                         | **Complexidade** |
| ----------------- | ----------------------------------------------------- | ---------------- |
| `.push_back(c)`   | Adiciona caractere ao final                           | `O(1)`           |
| `.pop_back()`     | Remove o último caractere                             | `O(1)`           |
| `.append(str)`    | Concatena string ao final                             | `O(n)`           |
| `.insert(pos, s)` | Insere string ou caractere na posição                 | `O(n)`           |
| `.erase(pos, n)`  | Remove `n` caracteres a partir da posição             | `O(n)`           |
| `.replace()`      | Substitui trecho da string                            | `O(n)`           |
| `.substr(pos, n)` | Retorna substring de `n` caracteres a partir de `pos` | `O(n)`           |
| `.find(s)`        | Retorna posição da substring `s`                      | `O(n)`           |
| `.size()`         | Tamanho da string                                     | `O(1)`           |
| `.clear()`        | Esvazia a string                                      | `O(1)`           |
| `.at(i)`          | Acesso com verificação                                | `O(1)`           |
| `.operator[i]`    | Acesso sem verificação                                | `O(1)`           |
| `.c_str()`        | Retorna ponteiro para estilo string C-style           | `O(1)`           |

## Alocação de Memória Para String

> Baseada em `std::vector<char>` (com otimizações como `Small String Optimization - SSO`).
> Para strings pequenas, usa um buffer interno estático (sem alocação dinâmica).
> Para strings maiores, aloca memória dinamicamente em um bloco contíguo, com realocações em operações como `push_back`, `append` ou insert quando a capacidade é excedida (`O(n)` em caso de realocação).
> A desalocação ocorre em clear ou na destruição.

---

## CONTAINERS ASSOCIATIVOS

> `std::set<T>` – Conjunto ordenado (sem duplicatas)

| **Operação** | **Descrição**                              | **Complexidade** |
| ------------ | ------------------------------------------ | ---------------- |
| `.insert(x)` | Insere o elemento x (se ainda não existir) | `O(log n)`       |
| `.erase(x)`  | Remove o elemento x                        | `O(log n)`       |
| `.find(x)`   | Busca pelo elemento x                      | `O(log n)`       |
| `.size()`    | Número de elementos                        | `O(1)`           |
| `.empty()`   | Verifica se está vazio                     | `O(1)`           |
| `.clear()`   | Remove todos os elementos                  | `O(n)`           |
| `.begin()`   | Iterador para o primeiro elemento          | `O(1)`           |
| `.end()`     | Iterador para o após o último elemento     | `O(1)`           |

## Alocação de Memória Para Set

> Implementado como uma árvore binária balanceada (geralmente uma árvore rubro-negra).
> Cada elemento é alocado como um nó dinâmico contendo o valor e ponteiros para filhos/pai.
> Inserções (`insert`) e remoções (`erase`) alocam/desalocam nós individualmente (`O(log n)` devido ao balanceamento).
> A desalocação total ocorre em clear ou na destruição do objeto.

---

> `std::map<KEY, T>` – Mapa ordenado (chave única)

| **Operação**     | **Descrição**                                                | **Complexidade** |
| ---------------- | ------------------------------------------------------------ | ---------------- |
| `.insert({k,v})` | Insere um par chave-valor                                    | `O(log n)`       |
| `.erase(k)`      | Remove o par com chave `k`                                   | `O(log n)`       |
| `.find(k)`       | Busca o par com chave `k`                                    | `O(log n)`       |
| `.operator[k]`   | Acessa o valor associado à chave `k` (insere se não existir) | `O(log n)`       |
| `.size()`        | Número de pares armazenados                                  | `O(1)`           |
| `.empty()`       | Verifica se está vazio                                       | `O(1)`           |
| `.clear()`       | Remove todos os pares                                        | `O(n)`           |
| `.begin()`       | Iterador para o primeiro par                                 | `O(1)`           |
| `.end()`         | Iterador após o último par                                   | `O(1)`           |

## Alocação de Memória Para Map

> Similar ao `std::set`, usa uma árvore rubro-negra, com cada nó armazenando um par `std::pair<Key, T>`.
> A alocação/desalocação de nós ocorre em `insert` e `erase` (`O(log n)`).
> `operator[]` pode alocar um novo nó se a chave não existir.
> A memória é liberada em clear ou na destruição.

---

> `std::multiset<KEY, T>` – Conjunto ordenado com duplicata

| **Operação** | **Descrição**                            | **Complexidade** |
| ------------ | ---------------------------------------- | ---------------- |
| `.insert(x)` | Insere o elemento x (permite duplicatas) | `O(log n)`       |
| `.erase(x)`  | Remove uma ou todas as ocorrências de x  | `O(log n)`       |
| `.find(x)`   | Busca pelo elemento x                    | `O(log n)`       |
| `.count(x)`  | Conta o número de ocorrências de x       | `O(log n)`       |
| `.size()`    | Número total de elementos                | `O(1)`           |
| `.empty()`   | Verifica se está vazio                   | `O(1)`           |
| `.clear()`   | Remove todos os elementos                | `O(n)`           |
| `.begin()`   | Iterador para o primeiro elemento        | `O(1)`           |
| `.end()`     | Iterador após o último elemento          | `O(1)`           |

## Alocação de Memória Para MultiSet

> Igual ao `std::set`, mas permite múltiplos nós com o mesmo valor.
> Cada inserção aloca um novo nó (`O(log n)`), e remoções podem desalocar um ou todos os nós correspondentes.
> A desalocação total ocorre em clear ou na destruição.

---

> `std::multimap<KEY, T>` – Mapa ordenado com múltiplas chaves repetidas

| **Operação**      | **Descrição**                                                | **Complexidade** |
| ----------------- | ------------------------------------------------------------ | ---------------- |
| `.insert({k,v})`  | Insere um par chave-valor (permite duplicatas)               | `O(log n)`       |
| `.erase(k)`       | Remove todos os pares com chave `k`                          | `O(log n)`       |
| `.find(k)`        | Retorna iterador para a primeira ocorrência de `k`           | `O(log n)`       |
| `.operator[k]`    | Acessa o valor associado à chave `k` (insere se não existir) | `O(1)`           |
| `.equal_range(k)` | Retorna intervalo com todos os pares com chave `k`           | `O(log n)`       |
| `.size()`         | Número total de pares armazenados                            | `O(1)`           |
| `.empty()`        | Verifica se está vazio                                       | `O(1)`           |
| `.clear()`        | Remove todos os pares                                        | `O(n)`           |
| `.begin()`        | Iterador para o primeiro par                                 | `O(1)`           |
| `.end()`          | Iterador após o último par                                   | `O(1)`           |

## Alocação de Memória Para MultiMap

> Similar ao `std::map`, mas permite múltiplos pares com a mesma chave.
> Cada `insert` aloca um novo nó (`O(log n)`), e `erase` pode desalocar múltiplos nós.
> A memória é gerenciada pela árvore rubro-negra, com desalocação total em clear ou na destruição.

---

## CONTAINERS DESORDENADOS

> `std::unordered_set<T>` – Conjunto não ordenado (sem duplicatas)

| **Operação** | **Descrição**                     | **Complexidade Média** | **Pior Caso** |
| ------------ | --------------------------------- | ---------------------- | ------------- |
| `.insert(x)` | Insere o elemento x               | `O(1)`                 | `O(n)`        |
| `.erase(x)`  | Remove o elemento x               | `O(1)`                 | `O(n)`        |
| `.find(x)`   | Busca pelo elemento x             | `O(1)`                 | `O(n)`        |
| `.size()`    | Número de elementos               | `O(1)`                 | `O(1)`        |
| `.empty()`   | Verifica se está vazio            | `O(1)`                 | `O(1)`        |
| `.clear()`   | Remove todos os elementos         | `O(n)`                 | `O(n)`        |
| `.begin()`   | Iterador para o primeiro elemento | `O(1)`                 | `O(1)`        |
| `.end()`     | Iterador após o último elemento   | `O(1)`                 | `O(1)`        |

## Alocação de Memória Para UnorderedSet

> Implementado como uma tabela de dispersão (hash table).
> A memória é alocada para **buckets** (geralmente um array dinâmico) e nós individuais para cada elemento.
> Inserções (`insert`) alocam nós (`O(1)` médio), mas podem desencadear redimensionamento da tabela (`O(n)` no pior caso).
> Remoções (`erase`) desalocam nós. A desalocação total ocorre em clear ou na destruição.

---

> `std::unordered_map<Key, T>` – Mapa não ordenado (chave única)

| **Operação**     | **Descrição**                                         | **Complexidade Média** | **Pior Caso** |
| ---------------- | ----------------------------------------------------- | ---------------------- | ------------- |
| `.insert({k,v})` | Insere par chave-valor                                | `O(1)`                 | `O(n)`        |
| `.erase(k)`      | Remove o par com chave `k`                            | `O(1)`                 | `O(n)`        |
| `.find(k)`       | Busca par com chave `k`                               | `O(1)`                 | `O(n)`        |
| `.operator[k]`   | Acessa valor associado (insere `v` se `k` não existe) | `O(1)`                 | `O(n)`        |
| `.size()`        | Número de pares armazenados                           | `O(1)`                 | `O(1)`        |
| `.empty()`       | Verifica se está vazio                                | `O(1)`                 | `O(1)`        |
| `.clear()`       | Remove todos os pares                                 | `O(n)`                 | `O(n)`        |
| `.begin()`       | Iterador para o primeiro par                          | `O(1)`                 | `O(1)`        |
| `.end()`         | Iterador após o último par                            | `O(1)`                 | `O(1)`        |

## Alocação de Memória Para UnorderedMap

> Similar ao `std::unordered_set`, mas armazena pares `std::pair<Key, T>`.
> Inserções alocam nós para novos pares, com redimensionamento da tabela de hash quando o fator de carga é excedido (`O(n)` no pior caso).
> `operator[]` pode alocar um novo nó. A desalocação ocorre em erase, clear ou na destruição.

---

> `std::unordered_multiset<T>` – Conjunto não ordenado com duplicatas

| **Operação** | **Descrição**                            | **Complexidade Média** | **Pior Caso** |
| ------------ | ---------------------------------------- | ---------------------- | ------------- |
| `.insert(x)` | Insere o elemento x (permite duplicatas) | `O(1)`                 | `O(n)`        |
| `.erase(x)`  | Remove uma ou todas as ocorrências de x  | `O(1)`                 | `O(n)`        |
| `.find(x)`   | Busca uma ocorrência de x                | `O(1)`                 | `O(n)`        |
| `.size()`    | Número de elementos                      | `O(1)`                 | `O(1)`        |
| `.empty()`   | Verifica se está vazio                   | `O(1)`                 | `O(1)`        |
| `.clear()`   | Remove todos os elementos                | `O(n)`                 | `O(n)`        |
| `.begin()`   | Iterador para o primeiro elemento        | `O(1)`                 | `O(1)`        |
| `.end()`     | Iterador após o último elemento          | `O(1)`                 | `O(1)`        |

## Alocação de Memória Para UnorderedMultiset

> Similar ao `std::unordered_set`, mas permite múltiplos elementos iguais.
> Cada inserção aloca um novo nó, e remoções podem desalocar um ou mais nós.
> Redimensionamento da tabela de hash pode ocorrer (`O(n)` no pior caso).
> A memória é liberada em clear ou na destruição.

---

> `std::unordered_multimap<Key, T>` – Mapa não ordenado com múltiplas chaves repetidas

| **Operação**      | **Descrição**                                           | **Complexidade Média** | **Pior Caso** |
| ----------------- | ------------------------------------------------------- | ---------------------- | ------------- |
| `.insert({k,v})`  | Insere par chave-valor (permite duplicatas)             | `O(1)`                 | `O(n)`        |
| `.erase(k)`       | Remove todos os pares com chave `k`                     | `O(1)`                 | `O(n)`        |
| `.find(k)`        | Retorna iterador para uma ocorrência da chave `k`       | `O(1)`                 | `O(n)`        |
| `.equal_range(k)` | Retorna intervalo com todas as ocorrências da chave `k` | `O(1)`                 | `O(n)`        |
| `.size()`         | Número de pares armazenados                             | `O(1)`                 | `O(1)`        |
| `.empty()`        | Verifica se está vazio                                  | `O(1)`                 | `O(1)`        |
| `.clear()`        | Remove todos os pares                                   | `O(n)`                 | `O(n)`        |
| `.begin()`        | Iterador para o primeiro par                            | `O(1)`                 | `O(1)`        |
| `.end()`          | Iterador após o último par                              | `O(1)`                 | `O(1)`        |

## Alocação de Memória Para UnorderedMultimap

> Igual ao `std::unordered_map`, mas suporta múltiplos pares com a mesma chave.
> Inserções alocam nós individuais, com possível redimensionamento da tabela (`O(n)` no pior caso).
> A desalocação ocorre em `erase`, `clear` ou na destruição.

---

## Interpretação rápida sobre

- `O(1)`: Muito rápido (constante).
- `O(log n)`: Razoavelmente rápido (estruturas de árvore balanceada).
- `O(n)`: Lento para grandes dados (linear).

## 🔎 Observações de Complexidade de Containers STL

- vector: Rápido no final, lento no meio/início.
- deque: Acesso direto possível, melhor que list.
- list: Inserção/remoção eficientes em qualquer ponto.
- forward_list: Lista ligada simples, sem acesso reverso.
- set: Ordenado, baseado em árvore balanceada.
- unordered_set: Não ordenado, baseado em hash.
- map: Associativo, ordenado.
- unordered_map: Associativo, não ordenado (hash).
