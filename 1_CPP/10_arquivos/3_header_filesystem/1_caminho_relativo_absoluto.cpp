#include <iostream>
#include <string>
#include <filesystem>

int main(int argc, char **argv)
{
    std::string arquivoAtual = "1_caminho_absoluto"; // Nome do arquivo a procurar

    if (std::filesystem::exists(arquivoAtual))
    {
        std::cout << "Arquivo encontrado\n";
        std::cout << "Caminho absoluto: " << std::filesystem::absolute(arquivoAtual) << '\n';
        std::cout << "Caminho relativo: " << std::filesystem::relative(std::filesystem::absolute(arquivoAtual)) << '\n';
    }
    else
    {
        std::cout << "Arquivo não encontrado\n";
    }
    return 0;
}
