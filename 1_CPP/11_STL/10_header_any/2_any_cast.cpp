#include <iostream>
#include <string>
#include <limits>
#include <typeinfo>
#include <stdexcept>
#include <any>

/**
 * @brief Este programa demonstra o uso de `std::any` para armazenar diferentes tipos
 * de dados em um único objeto. Ele inclui um menu interativo que permite ao
 * usuário escolher o tipo de dado a ser armazenado (int, double, string),
 * exibir o valor armazenado e limpar o valor.
 *
 * O programa utiliza `std::any_cast` para acessar o valor armazenado e exibir mensagens apropriadas.
 *
 * @param a Referência para o objeto std::any a ser exibido
 */
void printAny(const std::any &a)
{
    if (!a.has_value())
    {
        std::cout << "[INFO] Any está vazio.\n";
        return;
    }

    std::cout << "[INFO] Tipo armazenado: " << a.type().name() << '\n';

    try
    {
        if (a.type() == typeid(int))
        {
            std::cout << "[VALOR] int: " << std::any_cast<int>(a) << '\n';
        }
        else if (a.type() == typeid(double))
        {
            std::cout << "[VALOR] double: " << std::any_cast<double>(a) << '\n';
        }
        else if (a.type() == typeid(std::string))
        {
            std::cout << "[VALOR] string: " << std::any_cast<std::string>(a) << '\n';
        }
        else
        {
            std::cout << "[AVISO] Tipo não suportado para exibição.\n";
        }
    }
    catch (const std::bad_any_cast &e)
    {
        std::cerr << "[ERRO] Erro ao fazer any_cast: " << e.what() << '\n';
    }
}

/**
 * @brief Limpa o buffer de entrada para evitar problemas com entradas inválidas.
 */
void limparBufferEntrada(void)
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main(int argc, char **argv)
{
    std::any anyValor;
    int opcao = 0;

    do
    {
        std::cout << "\n===== MENU INTERATIVO COM std::any =====\n";
        std::cout << "1. Armazenar um int\n";
        std::cout << "2. Armazenar um double\n";
        std::cout << "3. Armazenar uma string\n";
        std::cout << "4. Exibir valor armazenado\n";
        std::cout << "5. Limpar valor\n";
        std::cout << "0. Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch (opcao)
        {
        case 1:
        {
            int valor = 0;
            std::cout << "Digite um inteiro: ";
            std::cin >> valor;

            if (std::cin.fail())
            {
                std::cout << "[ERRO] Entrada inválida.\n";
                limparBufferEntrada();
                break;
            }

            anyValor = valor;
            break;
        }
        case 2:
        {
            double valor = 0.0;
            std::cout << "Digite um número real: ";
            std::cin >> valor;

            if (std::cin.fail())
            {
                std::cout << "[ERRO] Entrada inválida.\n";
                limparBufferEntrada();
                break;
            }

            anyValor = valor;
            break;
        }
        case 3:
        {
            limparBufferEntrada(); // Limpa antes de getline
            std::string texto;

            std::cout << "Digite uma string: ";
            std::getline(std::cin, texto);
            anyValor = texto;
            break;
        }
        case 4:
            printAny(anyValor);
            break;

        case 5:
            anyValor.reset();
            std::cout << "[INFO] Valor foi limpo.\n";
            break;

        case 0:
            std::cout << "Encerrando...\n";
            break;

        default:
            std::cout << "[ERRO] Opção inválida.\n";
            break;
        }
    } while (opcao != 0);

    return 0;
}
