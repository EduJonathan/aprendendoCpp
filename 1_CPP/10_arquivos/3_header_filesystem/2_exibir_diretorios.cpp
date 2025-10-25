#include <iostream>
#include <filesystem>

/**
 * @brief Exibe o conteúdo de um diretório e seus subdiretórios em formato de árvore.
 *
 * Esta função percorre recursivamente o diretório especificado, mostrando pastas e arquivos
 * de forma hierárquica (em formato de árvore visual). Cada nível de profundidade adiciona
 * indentação ao nome exibido.
 *
 * @param caminho Caminho inicial do diretório a ser exibido.
 * @param nivel Nível atual da recursão (usado internamente para indentação).
 */
void exibirArvore(const std::filesystem::path &caminho, int nivel = 0)
{
    // Prefixo visual para identar de acordo com o nível
    std::string prefixo(nivel * 2, ' ');

    // Mostra o diretório atual
    std::cout << prefixo << "3_header_filesystem " << caminho.filename().string() << '\n';

    // Percorre os itens dentro do diretório
    for (const auto &entrada : std::filesystem::directory_iterator(caminho))
    {
        try
        {
            if (std::filesystem::is_directory(entrada))
            {
                // Se for diretório, chama recursivamente
                exibirArvore(entrada.path(), nivel + 1);
            }
            else
            {
                // Se for arquivo, exibe normalmente
                std::cout << std::string((nivel + 1) * 2, ' ')
                          << "arquivo " << entrada.path().filename().string() << '\n';
            }
        }
        catch (const std::filesystem::filesystem_error &erro)
        {
            std::cerr << "Erro: " << erro.what() << '\n';
        }
    }
}

int main(int argc, char **argv)
{
    std::filesystem::path caminhoInicial = "."; // diretório atual
    exibirArvore(caminhoInicial);
    return 0;
}
