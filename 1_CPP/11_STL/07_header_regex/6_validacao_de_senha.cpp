#include <iostream>
#include <string>
#include <regex>

/**
 * @brief Verifica se uma senha atende aos critérios de segurança.
 *
 * Critérios:
 * - A senha deve ter no mínimo 7 caracteres.
 * - Deve conter pelo menos dois caracteres não alfanuméricos.
 * - Deve conter pelo menos dois dígitos.
 *
 * @param senha A senha a ser validada.
 * @return true Se a senha for válida.
 * @return false Se a senha não atender aos critérios.
 */
bool senhaValida(const std::string &senha)
{
    if (senha.length() < 7)
        return false;

    std::regex nonWordPattern(R"(\W{2,})"); // Dois ou mais caracteres não alfanuméricos
    if (!std::regex_search(senha, nonWordPattern))
        return false;

    std::regex digitPattern(R"(\d{2,})"); // Dois ou mais dígitos
    if (!std::regex_search(senha, digitPattern))
        return false;

    return true;
}

int main(int argc, char **argv)
{
    std::string senha = "gO&EROID123";

    if (senhaValida(senha))
    {
        std::cout << "Senha válida!" << '\n';
    }
    else
    {
        std::cout << "Senha inválida!" << '\n';
    }
    return 0;
}
