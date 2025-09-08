#include <iostream>
#include <vector>
#include <string>
#include <regex>

/**
 * @brief Verifica se a senha atende aos critérios de segurança.
 *
 * @param senha A senha a ser verificada.
 * @return true se a senha for válida, false caso contrário.
 */
bool verificarSenha(const std::string &senha)
{
    std::vector<std::regex> padroes_de_senha ={
        std::regex(".{8,}"),                                       // pelo menos 8 caracteres de comprimento
        std::regex("[a-z]"),                                       // pelo menos uma letra minúscula
        std::regex("[A-Z]"),                                       // pelo menos uma letra maiúscula
        std::regex("[0-9]"),                                       // pelo menos um dígito
        std::regex("[!@#$%^&*()_+\\-=\\[\\]{};':\"\\\\|,.<>\\/?]") // pelo menos um caractere especial
    };

    std::vector<std::string> mensagens_erros = {
        "A senha deve ter pelo menos 8 caracteres.",
        "A senha deve conter pelo menos uma letra minúscula.",
        "A senha deve conter pelo menos uma letra maiúscula.",
        "A senha deve conter pelo menos um dígito.",
        "A senha deve conter pelo menos um caractere especial."};

    bool valida = true;

    for (std::size_t i{0}; i < padroes_de_senha.size(); ++i)
    {
        if (!std::regex_search(senha, padroes_de_senha[i]))
        {
            std::cout << mensagens_erros[i] << '\n';
            valida = false;
        }
    }
    return valida;
}

int main(int argc, char **argv)
{
    std::string senha;
    std::cout << "Digite a senha: ";
    std::cin >> senha;

    if (verificarSenha(senha))
    {
        std::cout << "Senha válida!" << '\n';
    }
    else
    {
        std::cout << "Senha inválida!" << '\n';
    }
    return 0;
}
