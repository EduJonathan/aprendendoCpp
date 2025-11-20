#include <iostream>
#include <filesystem>

/**
 * nomeação (ou mais precisamente, um alias de namespace). Você está dando um nome curto e conveniente
 * para um namespace mais longo. namespace define um escopo com nome que faz: Agrupar código
 * (funções, classes, variáveis) sob um nome, para evitar conflitos e organizar melhor.
 */

// `fs` é um apelido (alias) para o namespace std::filesystem, que foi introduzido no C++17 para lidar com arquivos e diretórios.
namespace fs = std::filesystem;

// Namespace original
namespace utilidades
{
    void saudacao()
    {
        std::cout << "Bem-vindo ao programa!\n";
    }

    void despedida()
    {
        std::cout << "Até a próxima!\n";
    }
}

// Alias para o namespace utilidades
namespace util = utilidades;

int main(int argc, char *argv)
{
    util::saudacao();  // Usando o alias
    util::despedida(); // Também com o alias

    fs::path p = "."; // caminho atual
    std::cout << "Caminho absoluto atual: " << fs::absolute(p) << '\n';
    return 0;
}
