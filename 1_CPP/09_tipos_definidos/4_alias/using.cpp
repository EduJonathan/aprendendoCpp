#include <iostream>
#include <string>
#include <functional>
#include <stdexcept>

/**
 * using:
 * ------
 * Cria um **alias (apelido)** para um tipo existente, permitindo simplificar declarações
 * complexas ou tornar o código mais legível.
 *
 * Funciona de forma semelhante ao `typedef`, mas com **sintaxe mais clara e moderna**
 * e maior compatibilidade com templates.
 *
 * Observações importantes:
 *  - Diferente do `typedef`, `using` permite criar aliases **para templates genéricos**,
 *    o que torna seu uso muito mais flexível em C++ moderno.
 *  - `typedef` ainda funciona para tipos concretos (como STL), mas não suporta templates diretamente.
 *
 * Exemplos:
 *
 * // Alias simples
 * using inteiro = int;
 * inteiro x = 10;  // equivalente a int x = 10;
 *
 * // Alias para tipos de template(com using)
 * template <typename T>
 * using vetor = std::vector<T>;
 * vetor<int> v;  // equivalente a std::vector<int> v;
 *
 * // Alias para tipos de template (com typedef)
 * template <typename T>
 * typedef std::vector<T> Vetor; // Isso **não compila**!
 *
 * Em resumo: `using` é a abordagem **moderna recomendada**, especialmente quando se trabalha com templates e STL.
 */

/**
 * @typedef CallbackPreencher
 *
 * @brief Alias para um ponteiro de função que preenche uma string com um tamanho máximo.
 * @param str Referência à string a ser preenchida.
 * @param max Tamanho máximo permitido para a string.
 */
typedef void (*CallbackPreencher)(std::string &, std::size_t);

/**
 * @typedef CallbackPreencherModerno
 *
 * @brief Alias moderno (usando std::function) para uma função callback que preenche uma string.
 * @param str Referência à string a ser preenchida.
 * @param max Tamanho máximo permitido para a string.
 */
using CallbackPreencherModerno = std::function<void(std::string &, std::size_t)>;

/**
 * @brief Preenche uma string usando um callback definido com typedef.
 *
 * @param destino Referência à string que será preenchida.
 * @param tamanhoMax Tamanho máximo permitido para a string.
 * @param callback Função callback que realiza o preenchimento.
 * @throws std::invalid_argument Se tamanhoMax for zero ou callback for nulo.
 */
void preencherString(std::string &destino, std::size_t tamanhoMax, CallbackPreencher callback)
{
    try
    {
        if (tamanhoMax == 0)
        {
            throw std::invalid_argument("Tamanho máximo não pode ser zero.");
        }
        if (!callback)
        {
            throw std::invalid_argument("Callback não pode ser nulo.");
        }
        callback(destino, tamanhoMax);
    }
    catch (const std::exception &e)
    {
        throw; // Propaga a exceção para o chamador
    }
}

/**
 * @brief Preenche uma string usando um callback moderno definido com using.
 *
 * @param destino Referência à string que será preenchida.
 * @param tamanhoMax Tamanho máximo permitido para a string.
 * @param callback Função callback (suporta lambdas, functors, etc.) que realiza o preenchimento.
 * @throws std::invalid_argument Se tamanhoMax for zero ou callback for inválido.
 */
void preencherStringModerna(std::string &destino, std::size_t tamanhoMax, CallbackPreencherModerno callback)
{
    try
    {
        if (tamanhoMax == 0)
        {
            throw std::invalid_argument("Tamanho máximo não pode ser zero.");
        }
        if (!callback)
        {
            throw std::invalid_argument("Callback não pode ser inválido.");
        }
        callback(destino, tamanhoMax);
    }
    catch (const std::exception &e)
    {
        throw; // Propaga a exceção para o chamador
    }
}

/**
 * @brief Função de exemplo que preenche uma string com um texto fixo, respeitando o tamanho máximo.
 *
 * @param str Referência à string a ser preenchida.
 * @param max Tamanho máximo permitido para a string.
 * @throws std::runtime_error Se ocorrer um erro inesperado ao manipular a string.
 */
void preencherComTexto(std::string &str, std::size_t max)
{
    try
    {
        std::string texto = "Exemplo de texto longo";
        if (texto.size() > max)
        {
            str = texto.substr(0, max);
        }
        else
        {
            str = texto;
        }
    }
    catch (const std::exception &e)
    {
        throw std::runtime_error("Erro ao preencher a string: " + std::string(e.what()));
    }
}

int main(int argc, char **argv)
{
    std::string resultado1, resultado2;

    try
    {
        // Usando o callback com typedef
        preencherString(resultado1, 10, preencherComTexto);
        std::cout << "Resultado com typedef: " << resultado1 << '\n';

        // Usando o callback com using (com lambda)
        preencherStringModerna(resultado2, 10, [](std::string &str, std::size_t max)
        {
            try
            {
                std::string texto = "Outro texto exemplo";
                if (texto.size() > max)
                {
                    str = texto.substr(0, max);
                }
                else
                {
                    str = texto;
                }
             }
             catch (const std::exception& e)
             {
                throw std::runtime_error("Erro na lambda: " + std::string(e.what()));
             } 
        });

        std::cout << "Resultado com using: " << resultado2 << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro: " << e.what() << '\n';
        return 1;
    }
    
    return 0;
}
