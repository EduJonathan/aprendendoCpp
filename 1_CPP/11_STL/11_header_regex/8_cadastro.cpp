#include <iostream>
#include <cstdint>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>
#include <regex>

struct BD
{
    uint16_t id;
    std::string Nome;
    std::string CPF;
};

// === Validação dos dígitos verificadores do CPF (apenas números) ===
bool validarDigitosCPF(const std::string &numeros)
{
    if (numeros.length() != 11)
        return false;

    // Primeiro dígito verificador
    int soma = 0;
    for (int i = 0; i < 9; ++i)
    {
        soma += (numeros[i] - '0') * (10 - i);
    }

    int digito1 = (soma * 10) % 11;
    if (digito1 == 10)
        digito1 = 0;

    if (digito1 != (numeros[9] - '0'))
        return false;

    // Segundo dígito verificador
    soma = 0;
    for (int i = 0; i < 10; ++i)
    {
        soma += (numeros[i] - '0') * (11 - i);
    }

    int digito2 = (soma * 10) % 11;

    if (digito2 == 10)
        digito2 = 0;

    if (digito2 != (numeros[10] - '0'))
        return false;

    return true;
}

std::unique_ptr<BD> cadastro()
{
    static uint16_t proximo_id = 1;

    auto pessoa = std::make_unique<BD>();
    pessoa->id = proximo_id++;

    std::cout << "=== Cadastro de Pessoa (ID: " << pessoa->id << ") ===\n";

    // --- Nome ---
    do
    {
        std::cout << "Nome completo: ";
        std::getline(std::cin, pessoa->Nome);
        if (pessoa->Nome.empty())
        {
            std::cout << "Erro: Nome não pode ser vazio!\n";
        }
    } while (pessoa->Nome.empty());

    // --- CPF com validação e normalização ---
    std::string cpf_input;
    std::string cpf_numeros;
    bool formato_valido = false;

    do
    {
        std::cout << "CPF (000.000.000-00, 00000000000 ou 000-000-000-00): ";
        std::getline(std::cin, cpf_input);

        // Extrai apenas dígitos
        cpf_numeros.clear();
        for (char c : cpf_input)
        {
            if (std::isdigit(c))
            {
                cpf_numeros += c;
            }
        }

        // Verifica quantidade de dígitos
        if (cpf_numeros.length() != 11)
        {
            std::cout << "Erro: CPF deve ter exatamente 11 dígitos!\n";
            continue;
        }

        // Valida dígitos verificadores
        if (!validarDigitosCPF(cpf_numeros))
        {
            std::cout << "Erro: CPF inválido! Verifique os dígitos.\n";
            continue;
        }

        // === Verifica formato de entrada ===
        std::string entrada_limpa = cpf_input;
        entrada_limpa.erase(
            std::remove_if(entrada_limpa.begin(),
                           entrada_limpa.end(),
                           ::isspace), entrada_limpa.end());

        std::regex padrao1(R"(^\d{3}\.\d{3}\.\d{3}-\d{2}$)"); // 000.000.000-00
        std::regex padrao2(R"(^\d{11}$)");                    // 00000000000
        std::regex padrao3(R"(^\d{3}-\d{3}-\d{3}-\d{2}$)");   // 000-000-000-00

        formato_valido = std::regex_match(entrada_limpa, padrao1) ||
                         std::regex_match(entrada_limpa, padrao2) ||
                         std::regex_match(entrada_limpa, padrao3);

        if (!formato_valido)
        {
            std::cout << "Aviso: Formato incorreto! Use:\n";
            std::cout << "   - 000.000.000-00\n";
            std::cout << "   - 00000000000\n";
            std::cout << "   - 000-000-000-00\n";
            std::cout << "Mas o CPF é válido. Continuando...\n\n";
        }

    } while (cpf_numeros.length() != 11 || !validarDigitosCPF(cpf_numeros));

    // === Armazena no formato padrão ===
    pessoa->CPF = cpf_numeros.substr(0, 3) + "." +
                  cpf_numeros.substr(3, 3) + "." +
                  cpf_numeros.substr(6, 3) + "-" +
                  cpf_numeros.substr(9, 2);

    std::cout << "Cadastro realizado com sucesso!\n\n";
    return pessoa;
}

void exibir(const BD &p)
{
    std::cout << "ID: " << p.id << '\n';
    std::cout << "Nome: " << p.Nome << '\n';
    std::cout << "CPF: " << p.CPF << "\n\n";
}

int main(int argc, char **argv)
{
    std::vector<std::unique_ptr<BD>> banco;
    char continuar;

    do
    {
        banco.push_back(cadastro());

        std::cout << "Deseja cadastrar outra pessoa? (s/n): ";
        std::cin >> continuar;
        std::cin.ignore(); // Limpa o buffer do \n

    } while (continuar == 's' || continuar == 'S');

    std::cout << "\n=== TODOS OS CADASTROS ===\n";
    for (const auto &ptr : banco)
    {
        exibir(*ptr);
    }
    return 0;
}
