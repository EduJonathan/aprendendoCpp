#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <stdexcept>
#include <fstream>
#include <filesystem>

/**
 * O programa lê linha por linha do arquivo "expressoes.txt" e determina se cada expressão aritmética
 * é sintaticamente válida, considerando, e através do include <filesystem> irá obter o
 * caminho até o arquivo(3_checar_expressoes.cpp):
 *
 * - Números inteiros
 * - Operadores +, -, *, /
 * - Parênteses corretamente balanceados
 * - Regras básicas de sequência de tokens (ex.: não permite "2(3)", ")5", operador no início/fim etc.)
 */

/**
 * @enum TokenTipo
 * @brief Tipos possíveis de tokens na expressão aritmética.
 */
enum class TokenTipo
{
    NUMERO,   ///< Token representando um número inteiro
    OPERADOR, ///< Token representando um operador (+, -, *, /)
    ABRE_PAR, ///< Token de abertura de parênteses '('
    FECHA_PAR ///< Token de fechamento de parênteses ')'
};

/**
 * @struct Token
 * @brief Representa um token lexico extraído da expressão.
 */
struct Token
{
    TokenTipo tipo;    ///< Tipo do token
    std::string valor; ///< Valor literal do token (ex.: "42", "+", "(")
};

/**
 * @brief Converte uma string em uma sequência de tokens.
 *
 * @param s A expressão aritmética como string.
 * @return std::vector<Token> Vetor com os tokens identificados.
 * @throw std::runtime_error Se encontrar um caractere inválido.
 */
std::vector<Token> tokenize(const std::string &s)
{
    std::vector<Token> tokens;
    std::size_t i = 0;

    while (i < s.size())
    {
        char c = s[i];

        if (std::isspace(c))
        {
            i++;
            continue;
        }

        if (std::isdigit(c))
        {
            std::string numero;
            while (i < s.size() && std::isdigit(s[i]))
            {
                numero.push_back(s[i]);
                i++;
            }
            tokens.push_back({TokenTipo::NUMERO, numero});
            continue;
        }

        if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            tokens.push_back({TokenTipo::OPERADOR, std::string(1, c)});
            i++;
            continue;
        }

        if (c == '(')
        {
            tokens.push_back({TokenTipo::ABRE_PAR, "("});
            i++;
            continue;
        }

        if (c == ')')
        {
            tokens.push_back({TokenTipo::FECHA_PAR, ")"});
            i++;
            continue;
        }

        throw std::runtime_error("Caractere inválido na expressão: " + std::string(1, c));
    }

    return tokens;
}

/**
 * @brief Verifica se uma expressão aritmética é sintaticamente válida.
 *
 * A validação inclui:
 * - Balanceamento correto de parênteses
 * - Sequências válidas de tokens (ex.: não permite operador no início/fim, número seguido de '(', etc.)
 * - Ausência de caracteres inválidos
 *
 * @param expr A expressão a ser validada.
 * @return true Se a expressão for válida.
 * @return false Caso contrário.
 */
bool expressaoValida(const std::string &expr)
{
    std::vector<Token> tokens;

    try
    {
        tokens = tokenize(expr);
    }
    catch (...)
    {
        return false;
    }

    if (tokens.empty())
        return false;

    int parenteses = 0;

    for (std::size_t i = 0; i < tokens.size(); ++i)
    {
        Token atual = tokens[i];
        Token *prox = (i + 1 < tokens.size()) ? &tokens[i + 1] : nullptr;

        // Contagem de parênteses
        if (atual.tipo == TokenTipo::ABRE_PAR)
            parenteses++;
        if (atual.tipo == TokenTipo::FECHA_PAR)
        {
            parenteses--;
            if (parenteses < 0)
                return false; // fecha sem abrir
        }

        // Regras de sequência
        if (atual.tipo == TokenTipo::OPERADOR)
        {
            // Não pode ser o primeiro
            if (i == 0)
                return false;

            // Não pode ser o último
            if (!prox)
                return false;

            // Depois de operador não pode vir outro operador ou fechar parênteses
            if (prox->tipo == TokenTipo::OPERADOR || prox->tipo == TokenTipo::FECHA_PAR)
                return false;
        }

        if (atual.tipo == TokenTipo::ABRE_PAR)
        {
            if (prox && prox->tipo == TokenTipo::OPERADOR && prox->valor != "-")
                return false; // "(" seguido de +,*,/ inválido (exceto menos unário se quiser permitir)
        }

        if (atual.tipo == TokenTipo::NUMERO)
        {
            if (prox && prox->tipo == TokenTipo::ABRE_PAR)
                return false; // 2(3)
        }

        if (atual.tipo == TokenTipo::FECHA_PAR)
        {
            if (prox && prox->tipo == TokenTipo::NUMERO)
                return false; // )3
        }
    }

    return parenteses == 0;
}

/**
 * @brief Verifica se um caminho aponta para um arquivo regular existente.
 *
 * @param caminho O caminho do arquivo a ser verificado.
 * @return true Se o arquivo existe e é regular.
 * @return false Caso contrário.
 */
bool arquivoExiste(const std::filesystem::path &caminho)
{
    return std::filesystem::exists(caminho) && std::filesystem::is_regular_file(caminho);
}

int main(int argc, char **argv)
{
    std::filesystem::path caminho{"expressoes.txt"};

    if (!arquivoExiste(caminho))
    {
        std::cout << "Arquivo não encontrado!\n";
        return 1;
    }

    std::ifstream arquivo(caminho);
    std::string linha;

    while (std::getline(arquivo, linha))
    {
        if (expressaoValida(linha))
        {
            std::cout << linha << " -> válida\n";
        }
        else
        {
            std::cout << linha << " -> inválida\n";
        }
    }

    return 0;
}
