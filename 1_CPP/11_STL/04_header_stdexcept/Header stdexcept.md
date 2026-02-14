<!-- @format -->

# Header `<stdexcept>`

A **header `<stdexcept>`** fornece classes de **exceções padrão** usadas para sinalizar
**erros em tempo de execução** em programas C++.

Essas exceções permitem que o programa **detecte falhas de lógica ou condições inválidas**
durante a execução, possibilitando o tratamento adequado por meio de `try`, `catch` e `throw`.

As exceções definidas em `<stdexcept>` são organizadas, conceitualmente, em dois grupos:

- **Erros lógicos** → falhas no uso do programa ou da API
- **Erros de execução (runtime)** → falhas que ocorrem durante a execução do programa

---

## Erros Lógicos

Os **erros lógicos** representam situações em que o programa foi utilizado de forma incorreta.
Em geral, **não deveriam acontecer se o código estivesse correto**. Todas essas exceções derivam de `std::logic_error`.

---

### `std::logic_error`

Classe base para exceções que indicam **violação de regras lógicas**.

**Uso típico:**

- Contratos quebrados
- Estados inválidos
- Uso incorreto de uma função

---

### `std::domain_error`

Indica que um argumento está **fora do domínio válido** da função.

**Exemplo conceitual:**

- Raiz quadrada de um número negativo
- Logaritmo de zero ou valor negativo

---

### `std::invalid_argument`

Lançada quando um argumento fornecido é **inválido**, mas não necessariamente fora do domínio matemático.

**Exemplo conceitual:**

- String vazia quando um valor era esperado
- Formato incorreto de entrada

---

### `std::length_error`

Indica que uma operação excedeu um **limite máximo permitido de tamanho**.

**Exemplo conceitual:**

- Tentativa de criar um `std::vector` maior que seu tamanho máximo suportado

---

### `std::out_of_range`

Usada quando há tentativa de acesso a uma posição **fora dos limites válidos**.

**Exemplo conceitual:**

- Acessar um índice inválido de um `std::vector` usando `.at()`

---

## Erros de Execução (Runtime)

Os **erros de execução** representam falhas que podem ocorrer **mesmo que a lógica do programa esteja correta**,
geralmente devido a condições externas ou dados imprevisíveis. Essas exceções derivam de `std::runtime_error`.

---

### `std::runtime_error`

Classe base para exceções que indicam **falhas detectadas apenas em tempo de execução**.

**Uso típico:**

- Falha ao abrir arquivos
- Erros de leitura ou escrita
- Condições externas inesperadas

---

### `std::range_error`

Indica que um resultado numérico está **fora do intervalo representável** pelo tipo.

---

### `std::overflow_error`

Lançada quando ocorre **estouro de capacidade (overflow)** em uma operação aritmética.

---

### `std::underflow_error`

Lançada quando ocorre **perda de precisão extrema (underflow)** em operações numéricas.

---

## Conclusão

A header `<stdexcept>` fornece uma forma padronizada e segura de representar erros em tempo de execução,
permitindo que programas C++ sejam mais **robustos**, **legíveis** e **manuteníveis**.

Ela é parte fundamental do sistema de exceções da linguagem e deve ser preferida em vez de soluções `ad-hoc` para sinalização de erros.
