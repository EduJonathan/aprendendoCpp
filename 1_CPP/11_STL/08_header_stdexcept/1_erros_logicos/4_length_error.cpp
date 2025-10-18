#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

/**
 * std::length_error(): O length_error é uma exceção que indica que uma operação
 * tentou criar um objeto com um tamanho inválido.
 * 
 * Isso pode ocorrer, por exemplo, quando se tenta criar um vetor com um tamanho
 * negativo ou muito grande. Quando um objeto (ex: vetor, string) excede o tamanho
 * permitido por sua definição. Usado quando se tenta construir um objeto com tamanho
 * absurdo ou que logicamente não pode existir.
 */

constexpr int MIN_SIZE = 3;
constexpr int MAX_SIZE = 10;

/**
 * @brief Valida a string com base em tamanho mínimo e máximo.
 *
 * @param str A string a ser validada.
 * @throws std::invalid_argument Se a string for muito curta.
 * @throws std::length_error Se a string for muito longa.
 */
void validarString(const std::string &str)
{
    if (str.size() < MIN_SIZE)
    {
        throw std::invalid_argument("A string é muito curta! Mínimo de " + std::to_string(MIN_SIZE) + " caracteres.");
    }
    else if (str.size() > MAX_SIZE)
    {
        throw std::length_error("A string é muito longa! Máximo de " + std::to_string(MAX_SIZE) + " caracteres.");
    }
}

constexpr std::size_t MAX_VECTOR_SIZE = 1000; // Limite fictício seguro

/**
 * @brief Cria um vetor de inteiros com o tamanho especificado.
 *
 * @param size O tamanho do vetor a ser criado.
 * @return std::vector<int> O vetor criado.
 * @throws std::length_error Se o tamanho do vetor exceder o limite permitido.
 */
auto criarVetor(std::size_t size) -> std::vector<int>
{
    if (size > MAX_VECTOR_SIZE)
    {
        throw std::length_error("Erro ao criar vetor: tamanho excede o limite permitido.");
    }

    return std::vector<int>(size);
}

int main(int argc, char **argv)
{
    std::string str;

    while (true)
    {
        std::cout << "\nDigite uma string (ou 'sair' para encerrar): ";
        std::getline(std::cin, str);

        if (str == "sair")
        {
            break;
        }

        try
        {
            validarString(str);
            std::cout << "String válida: \"" << str << "\"\n";
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Erro de argumento: " << e.what() << '\n';
        }
        catch (const std::length_error &e)
        {
            std::cerr << "Erro de comprimento: " << e.what() << '\n';
        }
    }

    std::cout << "--------------------------------------\n";

    try
    {
        auto vetor = criarVetor(10000); // Valor intencionalmente alto para causar erro
        std::cout << "Vetor criado com sucesso! Tamanho: " << vetor.size() << '\n';
    }
    catch (const std::length_error &e)
    {
        std::cerr << "Erro no main: " << e.what() << '\n';
    }

    return 0;
}
