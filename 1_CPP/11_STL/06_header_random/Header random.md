<!-- @format -->

# Header `<random>`

O header `<random>` é uma biblioteca da **linguagem C++** dedicada à **geração de valores pseudoaleatórios**.
Ela foi introduzida no **C++11** com o objetivo de substituir abordagens antigas e inseguras, como o
`rand()` da **linguagem C** e o `std::rand()` do **C++**.

Diferentemente dessas funções legadas, `<random>` oferece um modelo moderno e flexível baseado em dois
conceitos principais:

- **Motores (engines)** → responsáveis por gerar a sequência de números pseudoaleatórios.
- **Distribuições (distributions)** → responsáveis por transformar esses números em valores com propriedades estatísticas específicas.

> Essa separação permite maior **controle**, **qualidade estatística** e **segurança** na geração de números aleatórios.

---

## Geradores (Engines)

Os **geradores** determinam como os números pseudoaleatórios são produzidos.
Cada engine possui características próprias, como **período**, **desempenho** e **qualidade estatística**.

> Uma engine, por si só, **não define o intervalo nem o comportamento estatístico final** dos valores gerados — isso é papel das distribuições.

---

## Semente (Seed)

Toda engine precisa de uma semente inicial (seed), que define o estado inicial do gerador.

- **Seeds fixas** → produzem sempre a mesma sequência de números (determinismo).
- **Seeds variáveis** → produzem sequências diferentes a cada execução.

Esse comportamento é fundamental para:

- **Testes e depuração** (determinismo)
- **Jogos e simulações** (variedade)
- **Reprodutibilidade científica**

---

## `std::random_device`

O `std::random_device` é uma fonte de entropia, geralmente baseada em hardware ou no sistema operacional.

> ⚠️ **Importante:** `std::random_device` **não é uma engine de uso contínuo**. Seu papel principal é **gerar seeds** para inicializar outras engines.

```cpp
std::random_device rd;
std::mt19937 gen(rd());
```

---

### `std::mt19937`

Implementa o algoritmo **Mersenne Twister (19937)**.

**Características:**

- Período extremamente grande `(2¹⁹⁹³⁷ − 1)`
- Excelente qualidade estatística
- Amplamente utilizado em jogos, simulações e aplicações científicas
- Não é criptograficamente seguro

**Uso recomendado:** aplicações gerais onde qualidade e desempenho são importantes.

---

### `std::ranlux48_base`

Baseado no algoritmo **Ranlux**, que prioriza qualidade estatística em detrimento de desempenho.

**Características:**

- Qualidade estatística muito alta
- Mais lento que `mt19937`
- Útil para simulações científicas rigorosas

**Uso recomendado:** quando a qualidade estatística é mais importante que performance.

---

### `std::default_random_engine`

Engine padrão definida pela implementação da biblioteca padrão.

**Características:**

- Tipo exato depende do compilador
- Portável, mas imprevisível em termos de algoritmo
- Não recomendado quando comportamento determinístico é necessário

**Uso recomendado:** exemplos simples e código didático.

---

## Distribuições (Distributions)

As **distribuições** determinam como os **números gerados pela engine serão interpretados**.
Elas moldam os valores para seguir determinadas regras estatísticas.

> A engine gera números "crus"; a distribuição decide o **significado estatístico** desses números.

---

### Distribuições Uniformes

Geram valores onde todos os resultados possíveis têm a **mesma probabilidade**.

Exemplos:

- `std::uniform_int_distribution`
- `std::uniform_real_distribution`

---

### Distribuições Bernoulli e Binomiais

Usadas para eventos com **sucesso ou falha**.

Exemplos:

- `std::bernoulli_distribution`
- `std::binomial_distribution`
- `std::negative_binomial_distribution`

---

### Distribuições de Poisson e Exponenciais

Usadas para modelar **eventos aleatórios ao longo do tempo**.

**Exemplos:**

- `std::poisson_distribution`
- `std::exponential_distribution`
- `std::geometric_distribution`

---

### Distribuições Contínuas Especiais

Distribuições contínuas com aplicações matemáticas e estatísticas específicas.

**Exemplos:**

- `std::gamma_distribution`
- `std::weibull_distribution`
- `std::extreme_value_distribution`

---

### Distribuições Normais

Modelam fenômenos naturais que seguem a **distribuição normal (gaussiana)**.

**Exemplo:**

- `std::normal_distribution`
- `std::lognormal_distribution`
- `std::chi_squared_distribution`
- `std::student_t_distribution`
- `std::fisher_f_distribution`

---

### Distribuições Discretas Genéricas

Permitem definir **pesos personalizados** para cada valor possível.

**Exemplo:**

- `std::discrete_distribution`
- `std::piecewise_constant_distribution`
- `std::piecewise_linear_distribution`

---

## Conclusão

O header `<random>` fornece uma abordagem **moderna**, **modular** e **segura** para geração de números pseudoaleatórios,
sendo altamente recomendado em substituição às funções legadas como `rand()` e `std::rand()`.
A separação entre **engine**, **seed** e **distribuição** oferece controle preciso sobre comportamento,
reprodutibilidade e qualidade estatística — algo essencial em aplicações profissionais.
