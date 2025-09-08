#include <iostream>
#include <fstream>
#include <cstdlib>

// std::system(): Envia comando para o terminal do Sistema Operacional.

int main(int argc, char **argv)
{
    /* Semelhante ao ls -l > test.txt no linux lista arquivos e diretórios no diretório atual. */
    std::system("dir /Q /S > test.txt");
    std::cout << std::ifstream("text.txt").rdbuf();

    // .rdbuf() é usado para obter o buffer de leitura do arquivo
    return 0;
}
