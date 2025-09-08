# METAPROGRAMMING (METAPROGRAMAÇÃO)

Uma das grandes invenções e elementos chaves de todo C++ é a metaprogramming(ou metaprogração)
que consiste em trabalhar o código e ver a ação e resultado do código antes de compilar
e executar código, com auxílios e uso de structs, templates, e técnicas de SFINAE
(Substitution Failure Is Not An Error), entre outros.

Metaprogramação em C++ geralmente envolve manipulação de código em tempo de compilação
(usando templates, constexpr, SFINAE, concepts, etc.).

---

## BIBLIOTECAS PARA SE UTILIZAR NA METAPROGRAMAÇÃO

A metaprogramação em C++ é um dos recursos mais poderosos e complexos da linguagem, permitindo
que o próprio código se altere durante a compilação. Com suas biblioteca e recursoa se utilizar
para buscar tais resultados, temos desde já:

**`<functional>`**: pode ser usada em contextos de metaprogramação por causa de sua integração
com templates e tipos genéricos. Mas biblioteca `<functional>` em si não é uma ferramenta
de metaprogramação, pois ela opera principalmente em tempo de execução.

**`<tuple>`**: A biblioteca `<tuple>` fornece suporte para o tipo std::tuple, que permite agrupar
valores de diferentes tipos em uma única estrutura. Isso é útil na metaprogramação, especialmente
ao trabalhar com variáveis e tipos de número arbitrário de elementos em tempo de compilação.

**`<type_traits>`**: A biblioteca `<type_traits>` contém uma série de templates e funções úteis
para realizar manipulações de tipos em tempo de compilação. Ela fornece estruturas que permitem
verificar propriedades de tipos, como se um tipo é inteiro, se é um ponteiro, se é um tipo
const, entre outros.

**`<algorithm>`**: Não é uma biblioteca de metaprogramação por si só, mas sua natureza baseada
em templates e suporte a constexpr a torna relevante em metaprogramação, especialmente para
algoritmos genéricos e cálculos em tempo de compilação.

**`<chrono>`**: Ambas podem ser combinadas com ferramentas como `<concepts>`, templates e
constexpr para criar código que manipula tipos ou executa cálculos em tempo de compilação.

**`<concepts>`**: A biblioteca `<concepts>` foi introduzida no C++20 e fornece uma maneira de
verificar as propriedades de tipos em tempo de compilação, criando restrições mais claras e
legíveis para os templates. Em outras palavras, ela permite que você defina conceitos para os
tipos que são passados para templates, garantindo que certos requisitos sejam atendidos.

Além disso, Podemos Contar Com Bibliotecas Externas

- Boost.Hana: Uma biblioteca moderna para metaprogramação, otimizada para C++14/17,
  que simplifica o trabalho com tuplas e tipos em tempo de compilação.
- Boost.MPL: Biblioteca mais antiga, voltada para metaprogramação em C++03/11, ainda
  usada em projetos legados.

---

## Recursos e Keywords

**Templates** (Templates de Funções e Classes): Templates são a base da metaprogramação em C++.
Eles permitem que você escreva código genérico que pode operar sobre diferentes tipos de dados.

---

**constexpr**: O constexpr permite que você defina funções que são avaliadas em tempo de
compilação, permitindo realizar cálculos, validações ou operações com valores conhecidos
durante a compilação, otimizando o código gerado.

---

**if constexpr**: Permite a ramificação condicional em tempo de compilação com base em
características dos tipos, facilitando a adaptação de funções a diferentes tipos de maneira
eficiente e sem código redundante. Com ele escrevermos código condicional baseado no
tipo de dados em tempo de compilação

---

**noexcept**: A palavra-chave noexcept é usada para marcar uma **função** ou expressão como
garantida para não lançar exceções. Em termos de metaprogramação, ela pode ser usada para otimizar
a análise do código durante a compilação, melhorando a performance e garantindo uma semântica clara
para o comportamento de exceções.

**const noexcept**: E existe a combinação **const noexcept** que em metódos de uma **classe** implica
de não modificar o estado do objeto e não lançar nenhuma exceção.

---

**consteval**: (Introduzido no C++20): A palavra-chave consteval é similar ao constexpr,
mas garante que a função seja sempre avaliada em tempo de compilação. Ela não pode ser chamada
em tempo de execução.

---

**decltype**: O decltype permite que você consulte o tipo de uma expressão sem realmente avaliá-la.
É frequentemente usado para deduzir tipos dentro de templates e pode ser muito útil na
metaprogramação para inferir tipos de variáveis e expressões.

---

**SFINAE**: SFINAE é um princípio fundamental da metaprogramação em C++ que permite criar overloads
de funções ou especializações de templates baseadas em características de tipos. Se uma substituição
de tipo falhar, isso não gera um erro de compilação, mas apenas impede que aquela especialização ou
função seja usada (Ex.: `std::enable_if<std::is_integral<T>::value, void>::type`).

---

**std::conditional**: A classe std::conditional permite a escolha de tipos com base em uma
condição booleana. Isso é útil em metaprogramação para selecionar tipos diferentes com base
em parâmetros de template.

---

**std::is_same e std::is_base_of**: Ferramentas de metaprogramação que permitem verificar
as relações entre tipos em tempo de compilação.

- std::is_same<T, U>::value: Verifica se T e U são o mesmo tipo.
- std::is_base_of<Base, Derived>::value: Verifica se Base é uma classe base de Derived.

---

**std::enable_if e std::disable_if**: Essas classes de metaprogramação são utilizadas para
condicionalmente habilitar ou desabilitar funções, classes ou especializações de templates
com base em propriedades de tipos.

- std::enable_if: Permite a habilitação de uma função, classe ou template dependendo de um
  tipo ser válido ou não.
- std::disable_if: O oposto, desabilita funções ou templates dependendo de condições.

---

**std::tuple e std::apply**: `std::tuple` é uma estrutura de dados que permite armazenar diferentes
tipos de dados em uma única estrutura. Já `std::apply` aplica uma função a todos os elementos de
uma tupla.

---

**std::integral_constant**: A classe `std::integral_constant` é usada para definir constantes
inteiras em tempo de compilação. Ela é muitas vezes usada para criar valores constantes em templates.

---

**std::experimental::metaprogramming (C++14 e versões anteriores)**: Antes de C++17, havia
a std::experimental::metaprogramming, que fazia parte de experimentos da biblioteca padrão.
Esse recurso agora está incorporado em versões mais recentes do C++ (com a introdução dos
conceitos, ranges e outras melhorias).

---

**mutable**: Permite que membros de uma classe sejam modificados dentro de funções const.
Usado quando você deseja manter o estado de algumas variáveis imutáveis, mas precisa alterar outras,
como em caches ou contadores internos.

---

**requires**: Introduzido no C++20, permite criar restrições de tipo claras e expressivas,
usando conceitos. Substitui técnicas como SFINAE e enable_if, facilitando a escrita de templates
mais legíveis e seguros, baseados nas propriedades dos tipos.

---

## Como Aplicar Metaprogramação

A metaprogramação em C++ é usada para:

Otimizar desempenho: Avaliar cálculos complexos em tempo de compilação, como no exemplo do fatorial.
Aumentar reutilização: Criar funções e classes genéricas que funcionam com múltiplos tipos.
Garantir segurança de tipos: Usar `<type_traits>` e `<concepts>` para restringir templates e
evitar erros. Reduzir código repetitivo: Técnicas como if constexpr e SFINAE eliminam a necessidade
de múltiplas implementações.
