#include <iostream>
#include <string>
#include <cstdlib>
#include <regex>

/**
 * @brief Converte uma data do formato YYYY-MM-DD para DD/MM/YYYY.
 *
 * Usa expressão regular para capturar ano, mês e dia e reorganizar os grupos.
 *
 * @param date String contendo a data no formato YYYY-MM-DD.
 * @return std::string Data convertida no formato DD/MM/YYYY.
 */
std::string alterarFormatoData(const std::string &date)
{
    std::regex pattern(R"((\d{4})-(\d{1,2})-(\d{1,2}))");
    return std::regex_replace(date, pattern, "$3/$2/$1");
}

/**
 * @brief Valida se a string está no formato de data ISO (YYYY-MM-DD).
 *
 * Também realiza validações básicas de valores válidos para mês e dia.
 *
 * @param date String contendo a data a ser validada.
 * @return true Se a data está no formato e valores corretos.
 * @return false Caso contrário.
 */
bool dataValida(const std::string &date)
{
    std::regex pattern(R"(^(\d{4})-(\d{1,2})-(\d{1,2})$)");

    // Variável para armazenar os resultados da correspondência, std::smatch é utilizada
    // para capturar grupos que correspondem à expressão regular.
    std::smatch match;

    if (std::regex_match(date, match, pattern))
    {
        int year = std::stoi(match[1]);
        int month = std::stoi(match[2]);
        int day = std::stoi(match[3]);

        if (month < 1 || month > 12 || day < 1 || day > 31)
            return false;

        // Você pode refinar ainda mais validando fevereiro, meses com 30 dias etc.
        return true;
    }

    return false;
}

int main(int argc, char **argv)
{
    std::string email = "exemplo@email.com";
    std::regex pattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");

    // Validação de e-mail usando std::regex_match.
    if (std::regex_match(email, pattern))
    {
        std::cout << "E-mail válido!\n";
    }
    else
    {
        std::cout << "E-mail inválido!\n";
    }

    std::cout << "================================" << '\n';

    std::string data = "2026-01-02";
    std::cout << "Data original no formato YYYY-MM-DD: " << data << '\n';

    // Verificação e conversão do formato da data.
    if (dataValida(data))
    {
        std::cout << "Nova data no formato DD/MM/YYYY: " << alterarFormatoData(data) << '\n';
    }
    else
    {
        std::cout << "Formato de data inválida!" << '\n';
    }
    return 0;
}
