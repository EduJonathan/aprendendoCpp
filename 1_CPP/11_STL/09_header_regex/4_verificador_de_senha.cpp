#include <iostream>
#include <vector>
#include <string>
#include <regex>

/**
 * @brief Verifica se a senha atende aos critérios de segurança.
 *
 * A função valida a senha com base em diferentes padrões:
 * - Comprimento mínimo de 8 caracteres
 * - Inclusão de letras minúsculas
 * - Inclusão de letras maiúsculas
 * - Inclusão de números
 * - Inclusão de caracteres especiais
 *
 * Em caso de falha, exibe mensagens explicando cada critério não atendido.
 *
 * @param senha A senha a ser verificada.
 * @return true Se todos os critérios forem atendidos.
 * @return false Se um ou mais critérios não forem atendidos.
 */
bool verificarSenha(const std::string &senha)
{
    // Lista de padrões regex para validar a senha
    std::vector<std::regex> padroes_de_senha = {
        std::regex(".{8,}"),                                   // Pelo menos 8 caracteres
        std::regex("[a-z]"),                                   // Pelo menos uma letra minúscula
        std::regex("[A-Z]"),                                   // Pelo menos uma letra maiúscula
        std::regex("[0-9]"),                                   // Pelo menos um dígito
        std::regex(R"([!@#$%^&*()_+\-=\[\]{};':"\\|,.<>\/?])") // Pelo menos um caractere especial
    };

    // Mensagens de erro correspondentes aos padrões
    std::vector<std::string> mensagens_erros = {
        "A senha deve ter pelo menos 8 caracteres.",
        "A senha deve conter pelo menos uma letra minúscula.",
        "A senha deve conter pelo menos uma letra maiúscula.",
        "A senha deve conter pelo menos um dígito.",
        "A senha deve conter pelo menos um caractere especial."};

    bool valida = true;

    // Validação de cada padrão
    for (std::size_t i = 0; i < padroes_de_senha.size(); ++i)
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
