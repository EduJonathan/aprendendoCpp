<!-- @format -->

# 📌 Linguagem C++

## 🕰️ História e Origem

C++ é uma linguagem de programação criada por Bjarne Stroustrup no início da década de 1980,
inicialmente chamada de "C com Classes". Ela surgiu como uma extensão da linguagem C,
adicionando recursos de programação orientada a objetos, com o objetivo de combinar
eficiência e controle de C com abstrações do mais alto nível ainda.

- Baseada em C, mas com foco em abstração e reutilização.
- Projeto inicial na Bell Labs.
- Primeiro padrão ISO publicado em 1998 (C++98).

---

## 🔍 CARACTERÍSTICAS DA LINGUAGEM

| **Característica** | **Descrição**                                                             |
| ------------------ | ------------------------------------------------------------------------- |
| Tipagem            | Estática e forte – verificação rígida em tempo de compilação.             |
| Paradigma          | Multiparadigma – suportando OOP, procedural, genérico e funcional.        |
| Compilada          | Gera código de máquina altamente otimizado.                               |
| Nível de Abstração | Alto, mas com acesso de baixo nível (como C e assembly).                  |
| Portabilidade      | Alta – Compila para múltiplos sistemas com poucas modificações.           |
| Bibliotecas        | STL (Standard Template Library) + bibliotecas externas poderosas.         |
| Performance        | Alta – próxima ao C, com mais funcionalidades.                            |
| Escopo de Uso      | Desenvolvimento de sistemas, jogos, bancos de dados, aplicações robustas. |

---

## 🔎 OBSERVAÇÕES

- C++ não substitui C, ele incrementa/complementa a linguagem, pois é 100% compatível
  com a maioria do código, bibliotecas, e tipos de dados do C, diretivas, e até a
  compilação, só que oferece mais abstrações e muitos recursos poderosos como
  - classes,
  - herança,
  - polimorfismo,
  - templates e exceções.
- Tipagem forte evita muitas conversões implícitas perigosas, ajudando na construção de software robusto.
- C++ é frequentemente usada onde controle de hardware é necessário, para projetos grandes
  exigem organização modular e reutilização de código.

---

## 🔑 Elementos Chave da Linguagem

- **Classes e Objetos**: Estrutura básica da POO.
- **Herança e Polimorfismo**: Reutilização e comportamento dinâmico.
- **Templates**: Programação genérica (ex: std::vector`<T>`).
- **STL**: Containers, algoritmos e iteradores prontos para uso.
- **Exceções**: Tratamento robusto de erros (try, catch, throw).
- **Namespaces**: Organização do código (std::, custom::).
- **Smart Pointers**: Gerenciamento automático de memória (std::unique_ptr, std::shared_ptr).
- **Lambda Expressions**: Funções anônimas e programações funcionais.

---

## ✅ Vantagens

- **Versatilidade**: Combina paradigmas para resolver qualquer tipo de problema.
- **Eficiência**: Performance próxima ao C com mais segurança e abstração.
- **Portabilidade**: Código compila em múltiplas plataformas.
- **STL rica**: Reduz código repetitivo com containers e algoritmos prontos.
- **Modularidade**: Ideal para grandes projetos.

## ⚠️ Desvantagens

- **Complexidade**: Recurso em excesso pode dificultar aprendizado e manutenção.
- **Compilação lenta**: Templates pesados podem aumentar tempo de build.
- **Gerenciamento de memória manual**: Pode causar erros(dependendo do programador).
- **Curva de aprendizado mais acentuada**: Especialmente para iniciantes vindos de linguagens mais simples.

---

## 🛠️ Aplicações Práticas

- Engines de jogos: Unreal Engine (C++).
- Sistemas embarcados: Quando OOP é útil junto ao controle de hardware.
- Desenvolvimento de softwares: Navegadores, editores gráficos, IDEs.
- Programas de alto desempenho: Simulações científicas, trading algorítmico.
- Compiladores e ferramentas de análise de código.
- Inteligência Artificial e Robótica (quando desempenho é crítico).

---

## 📚 Bibliotecas e Ferramentas Essenciais

| **Biblioteca/Ferramenta** | **Função Principal**                       |
| ------------------------- | ------------------------------------------ |
| `<iostream>`              | Entrada e saída padrão                     |
| `<vector>, <map>`         | Containers dinâmicos da STL                |
| `<algorithm>`             | Funções genéricas (sort, find, etc.)       |
| `<memory>`                | Smart pointers e gerenciamento de memória  |
| `<thread>`                | Programação paralela (desde C++11)         |
| `<chrono>`                | Tempo e data moderna                       |
| `Boost`                   | Conjunto poderoso de bibliotecas avançadas |
| `Qt`                      | Framework para GUIs em C++                 |
| `SFML`                    | Framework Desenvolvimento de jogos 2D      |

---

## 🚀 Futuro e Tendências

- C++20 e C++23: Novas funcionalidades modernas (conceitos, ranges, módulos).
- Desempenho com segurança: Uso de smart pointers e RAII.
- Interop com outras linguagens: Especialmente Rust.
- Modernização: Substituindo padrões antigos por C++ moderno (auto, lambdas, move semantics).
- Ferramentas de análise estática: Para garantir segurança e performance.

---

E C++ continua sendo uma das linguagens mais importantes para desenvolvimento de sistemas
de alto desempenho. Em 2024, a linguagem evoluiu significativamente com os padrões
C++20 e C++23, além de está se encaminhando para o C++26, teremos novidades recentes, como:

---

- **Módulos:** Substituir os headers tradicionais(#include <>, por import <>).
- **Ranges:** Operações em containers mais expressivas.
- **Corrotinas:** Programação assíncrona nativa.
- **Reflexão em tempo de compilação (`<reflexpr>`)** permite que o código "inspecione" a si mesmo
  em tempo de compilação, como obter nomes de tipos, membros de classes ou propriedades de funções.
- **Cadeias de caracteres não avaliadas, strings (consteval string)** são usadas em contextos de tempo
  de compilação, permitindo manipulações mais fáceis de texto sem execução em tempo de execução.
- **Suporte a vetores em lugar (`<inplace_vector>`)** Um contêiner semelhante a std::vector,
  mas com capacidade fixa, alocado na pilha, ideal para cenários onde você quer evitar alocações dinâmicas.
- **Contratos (Contracts)** Contratos permitem especificar pré-condições, pós-condições e asserções
  de forma mais robusta. Embora ainda experimental, a ideia é melhorar a verificação de código.
- **Suporte a álgebra linear (`<linalg>`)** Inspirado em bibliotecas como **BLAS**, oferece operações
  como multiplicação de matrizes de forma nativa.

---

## 📚 Recursos para Aprender

### 📕 Livros

- `C++20 - The Complete Guide` - Nicolai Josuttis
- `Programming: Principles and Practice Using C++ (3rd Ed)` - Bjarne Stroustrup

### 🌐 Online

- [cplusplus.com](https://cplusplus.com/)
- [cppreference.com](https://en.cppreference.com/w/)
- [Learn Modern C++](https://learnmoderncpp.com/)

---

## 🔮 Futuro da Linguagem C++

Apesar da concorrência de linguagens mais seguras ou simples (como Rust, Go e Python),
C++ continua essencial para áreas como:

- Desenvolvimento de jogos.
- Sistemas embarcados e de tempo real.
- Soluções onde performance é crítica.
- Projetos de larga escala que exigem modularidade e abstração.

Em desenvolvmento do C++26, Teremos

- Reflexão estática.
- Pattern matching.
- Melhorias em execução paralela.
- Mais suporte a metaprogramação.

C++ permanece como uma das linguagens mais poderosas e influentes da história da computação,
combinando o controle do C com as abstrações modernas da engenharia de software,
continua evoluindo para manter sua relevância, combinando desempenho inigualável com
abstrações modernas que aumentam a produtividade.
