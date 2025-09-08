# Expressões Regulares (Regex)

- As expressões regulares (Regex) são poderosas ferramentas usadas para representar padrões em strings.
  Elas permitem que você faça validação, substituição e manipulação de dados de forma eficiente.

- Regex é uma linguagem compacta, mas flexível, e é amplamente utilizada
  em programação, validação de dados e processamento de texto.

## O Que São Expressões Regulares?

As expressões regulares são uma sequência de caracteres que formam um padrão de busca.
Elas são usadas para procurar e manipular strings com base em regras específicas, e podem
ser usadas em diversos cenários, como:

- Validação: Verificar se um dado corresponde a um formato específico (como um e-mail, telefone, etc.).
- Substituição: Trocar partes do texto de acordo com um padrão.
- Extração: Encontrar e extrair partes específicas de uma string.

---

## 🔤 Componentes Para Sequências Regexs

## Literais

Caracteres simples que representam exatamente o que aparece.

Exemplo: a corresponde ao caractere 'a'.
Exemplo: 1 corresponde ao dígito '1'.

---

## Metacaracteres

Caracteres especiais com significados específicos em Regex.

Ponto (.): Corresponde a qualquer caractere, exceto quebras de linha.  
Exemplo: a.c casa com abc, axc, a1c, etc.

Cifrão ($): Indica o final da string.  
Exemplo: abc$ casa com strings que terminam com "abc".

Circunflexo (^): Indica o início da string.  
Exemplo: ^abc casa com strings que começam com "abc".

---

## Quantificadores

Definem a quantidade de vezes que um caractere ou grupo deve aparecer.

Asterisco (_): Zero ou mais ocorrências.
Exemplo: a_ casa com "", "a", "aa", "aaa", etc.

Mais (+): Uma ou mais ocorrências.
Exemplo: a+ casa com "a", "aa", "aaa", etc.

Interrogação (?): Zero ou uma ocorrência.
Exemplo: a? casa com "" ou "a".

---

## Agrupamentos e Classes

Parênteses (( )): Agrupam partes da expressão para capturar ou aplicar quantificadores.
Exemplo: (ab)+ casa com "ab", "abab", "ababab".

Colchetes ([ ]): Definem um conjunto de caracteres possíveis.
Exemplo: [aeiou] casa com qualquer vogal.
Exemplo: [a-z] casa com qualquer letra minúscula.

Barra invertida (\): Escapa metacaracteres ou invoca sequências especiais.
Exemplo: \. corresponde ao caractere literal ponto.
Exemplo: \d corresponde a qualquer dígito ([0-9]).

---

Exemplo da extração de um número de telefone: ^\(\d{2}\)\s\d{4}-\d{4}$ no formato (xx) xxxx-xxxx.

\d{2} → dois dígitos
\s → espaço
\d{4}-\d{4} → quatro dígitos, hífen e mais quatro dígitos

Pode parecer um pouco complexa à primeira vista, mas com uma boa compreensão
de seus fundamentos, elas se tornam uma ferramenta extremamente poderosa.

---

## 🌐 Sites Para Testar Expressões Regulares

1. [regextester](https://www.regextester.com/)
2. [regexr](https://regexr.com/)
3. [regex101](https://regex101.com/)

Esses sites permitem testar, depurar e entender expressões regulares interativamente, com explicações detalhadas.

---

## 📚 Assuntos Bases Para Entender Regex

Para aprofundar seu conhecimento, é útil entender os fundamentos teóricos por trás das expressões regulares:

- Autômatos: Máquinas abstratas que reconhecem padrões em linguagens formais.
- Autômatos Finitos: Determinísticos e Não Determinísticos (DFA / NFA).
- Gramáticas Regulares.
- Padrões de Linguagem: Como linguagens formais são definidas e reconhecidas.
- Hierarquia de Chomsky: Classificação das linguagens formais que ajuda a entender onde as regex
  se encaixam (linguagens regulares).
- Teoria da Computação: Linguagens formais, autômatos, máquinas de Turing e problemas computáveis
