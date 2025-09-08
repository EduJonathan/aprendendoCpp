#include <iostream>
#include <string>
#include <regex>

bool senhaValida(const std::string &senha)
{
    if (senha.length() < 7)
        return false;

    std::regex nonWordPattern(R"(\W{2,})");
    if (!std::regex_search(senha, nonWordPattern))
        return false;

    std::regex digitPattern(R"(\d{2,})");
    if (!std::regex_search(senha, nonWordPattern))
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
