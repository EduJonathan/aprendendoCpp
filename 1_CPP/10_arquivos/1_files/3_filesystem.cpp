#include <iostream>
#include <filesystem>

/**
 * @brief Verifica se um arquivo existe.
 *
 * @param caminho Caminho relativo ou absoluto do arquivo a ser verificado.
 *
 * @return true se o arquivo existe, false caso contrário.
 *
 * @note o <filesystem>: Biblioteca moderna e poderosa que facilita bastante o trabalho
 * com arquivos e diretórios em C++, oferecendo uma interface de alto nível para manipulação
 * de arquivos de maneira segura e eficiente.
 */
bool existeArquivo(const std::string &caminho)
{
    return std::filesystem::exists(caminho);
}

int main(int argc, char **argv)
{
    std::string caminhoHome = getenv("HOME");
    caminhoHome = caminhoHome + '/';

    std::cout << (existeArquivo(caminhoHome + "Documents") ? "Existe" : "Nao Existe") << '\n';
    return 0;
}
