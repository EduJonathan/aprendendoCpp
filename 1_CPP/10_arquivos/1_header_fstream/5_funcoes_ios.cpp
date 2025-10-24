#include <iostream>
#include <string>
#include <fstream>

/**
 * @brief Modos de abertura da função `open()` em fluxos de arquivo (`std::ifstream`, `std::ofstream`, `std::fstream`).
 *
 * A função `open()` permite abrir arquivos especificando um ou mais modos de operação:
 *
 * ```cpp
 * arquivo.open("<nome_do_arquivo>", <modo>);
 * ```
 *
 * O parâmetro `<modo>` pode ser um único valor ou uma combinação (usando o operador `|`) dos seguintes flags de abertura:
 *
 * | Modo               | Descrição                                                                                                |
 * |--------------------|----------------------------------------------------------------------------------------------------------|
 * | `std::ios::in`     | Abre o arquivo para **leitura** (entrada). Usado por `std::ifstream` ou `std::fstream`.                  |
 * | `std::ios::out`    | Abre o arquivo para **escrita** (saída). Usado por `std::ofstream` ou `std::fstream`.                    |
 * | `std::ios::binary` | Abre o arquivo em **modo binário**, em vez de texto.                                                     |
 * | `std::ios::ate`    | Move o ponteiro de leitura/escrita para o **final do arquivo** imediatamente após abrir.                 |
 * | `std::ios::app`    | Todas as escritas são feitas **no final do arquivo** (modo de **acréscimo**). Usado apenas para escrita. |
 * | `std::ios::trunc`  | Se o arquivo já existir, **apaga o conteúdo** antes de escrever (modo de truncamento).                   |
 *
 * ### Exemplos
 *
 * ```cpp
 * std::ofstream saida;
 * saida.open("dados.txt", std::ios::out | std::ios::trunc);
 *
 * std::ifstream entrada;
 * entrada.open("dados.txt", std::ios::in);
 *
 * std::fstream arquivo;
 * arquivo.open("dados.bin", std::ios::in | std::ios::out | std::ios::binary);
 * ```
 *
 * @note O modo padrão de `std::ofstream` é `std::ios::out | std::ios::trunc`, enquanto o de `std::ifstream` é `std::ios::in`.
 */

bool unirArquivos(std::ifstream &arquivo1, std::ifstream &arquivo2, std::ofstream alvo);

int main(int argc, char **argv);
