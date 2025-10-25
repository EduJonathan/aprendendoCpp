# 📂 ARQUIVOS E STREAMS

## 🗃️ ARQUIVOS

- **Arquivos(📄):** São objetos que permitem armazenar e agrupar diferentes tipos de dados (textos, números, tabelas,
  registros, logs etc.) de forma persistente em um espaço físico (como o disco rígido).
  São usados para guardar informações que podem ser recuperadas, lidas ou alteradas posteriormente pelo programa.
- Cada arquivo possui uma extensão, que indica seu tipo ou formato. Exemplos:

  - `.txt` → Arquivos de texto simples
  - `.csv` → Planilhas ou dados separados por vírgula
  - `.json` → Arquivos de dados estruturados
  - `.db`, `.sqlite` → Bancos de dados
  - `.docx,`,`.xls,`,`.pdf` → Documentos de escritório
  - `.cpp,`, `.py`, `.html`, `.css`, `.js` → Códigos-fonte de programação

- **Streams(🌊)** A palavra stream significa **fluxo**. Em C++, as streams definem como os dados fluem entre o programa
  e o meio externo (teclado, tela, arquivos, etc.). Elas permitem ler e escrever dados de forma sequencial ou controlada,
  como uma "onda" de bytes.

- Exemplos:

| **Stream**        | **Função**        | **Direção do fluxo**      |
| ----------------- | ----------------- | ------------------------- |
| `std::ifstream()` | Entrada (leitura) | Arquivo → Programa        |
| `std::ofstream()` | Saída (escrita)   | Programa → Arquivo        |
| `std::fstream()`  | Entrada e saída   | Duplo (Leitura e Escrita) |

---

## Tratamentos Arquivos em C++

O tratamento de arquivos em C++ diferentemente do tradicional da linguagem C que se utilizava-se `FILE *`, `fopen()`, `fread()`,
temos a header **`<fstream>`** que facilita o tratamento com o uso das streams para o gerenciamento dos arquivos

---

## 🧩 HEADER SSTREAMS

- A header **`<sstream>`** permite manipular strings como se fossem arquivos, usando streams internas.
  É uma ferramenta poderosa para processar texto dinamicamente, converter dados entre tipos
  (como números para strings e vice-versa) ou construir strings complexas na memória.
  Pense no stringstream como um "arquivo temporário" na memória, onde você pode ler e escrever dados de
  forma sequencial, sem precisar de um arquivo físico.

| **Classe**           | **Função**                   | **Direção do Fluxo**      |
| -------------------- | ---------------------------- | ------------------------- |
| `std::stringstream`  | Leitura e escrita de strings | Duplo (leitura e escrita) |
| `std::istringstream` | Apenas leitura de strings    | String → Programa         |
| `std::ostringstream` | Apenas escrita em strings    | Programa → String         |

## Casos de Uso Comuns

A **`<sstream>`** é amplamente utilizada em situações como:

- Conversão de tipos: Transformar números em strings ou strings em números.
- Parseamento de dados: Extrair informações de uma string, como valores separados por vírgulas.
- Formatação de strings: Criar strings formatadas para exibição ou armazenamento.
- Testes e manipulação temporária: Processar dados na memória sem gravar em arquivos.

## Vantagens da **`<sstream>`**

- **Flexibilidade:** Permite manipular dados como se fossem fluxos, sem a necessidade de arquivos físicos.
- **Segurança:** Evita erros comuns de manipulação de strings em C (como estouro de buffer).
- **Integração com C++:** Funciona bem com outros recursos da linguagem, como manipulação de objetos e classes.

## Limitações

- **Desempenho:** Para strings muito grandes ou operações intensivas, a manipulação direta de `std::string` pode ser mais eficiente.
- **Complexidade em Parseamento:** Para parseamento avançado (como JSON ou XML), bibliotecas específicas podem ser mais adequadas.

---

## 🧭 HEADER FILESYSTEM

A header **`<filesystem>`** (disponível a partir do C++17) permite interagir com o sistema de arquivos(diretórios),
facilitando operações como:

- Criar, mover e remover arquivos/pastas.
- Verificar se um arquivo existe.
- Obter informações como tamanho e caminho absoluto.
