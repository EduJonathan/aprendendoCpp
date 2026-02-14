#include <iostream>
#include <regex>
#include <string>

/**
 * Este programa analisa um nome de arquivo fornecido pelo usuário, extrai o nome e a extensão,]
 * e identifica o tipo do arquivo (imagem, documento ou outro) usando expressões regulares.
 *
 * @param filename O nome do arquivo a ser analisado.
 */
void analyzeFilename(const std::string &filename)
{
    // Padrão para extrair nome, extensão, e verificar tipo
    std::regex pattern(R"(^(.+?)\.([a-zA-Z0-9]+)$)");
    std::smatch matches;

    if (std::regex_match(filename, matches, pattern))
    {
        std::string name = matches[1];
        std::string ext = matches[2];

        std::cout << "Nome do arquivo: " << name << '\n';
        std::cout << "Extensão: " << ext << '\n';

        // Converter extensão para minúsculas para comparação
        std::string ext_lower = ext;
        std::transform(ext_lower.begin(), ext_lower.end(), ext_lower.begin(), ::tolower);

        // Verificar tipo
        std::regex image_regex("^(jpg|jpeg|png|gif|bmp)$");
        if (std::regex_match(ext_lower, image_regex))
        {
            std::cout << "Tipo: Imagem" << '\n';
        }
        else if (std::regex_match(ext_lower, std::regex("^(pdf|docx?)$")))
        {
            std::cout << "Tipo: Documento" << '\n';
        }
        else
        {
            std::cout << "Tipo: Desconhecido/Outro" << '\n';
        }
    }
    else
    {
        std::cout << "Formato de arquivo inválido" << '\n';
    }
}

int main(int argc, char const *argv[])
{
    std::string filename;
    std::cout << "Digite o nome do arquivo (ex: foto.jpg): ";
    std::getline(std::cin, filename);
    analyzeFilename(filename);
    return 0;
}
