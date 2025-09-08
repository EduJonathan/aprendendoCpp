#include <iostream>
#include <string>
#include <stack>

/**
 * std::stack<T> Utilizado para aplicar a estrutura de dados Stack (pilha), com
 * a implementação FILO (First In, Last Out - primeiro que entra é o último que sai).
 */

/**
 * @brief Verifica se os parênteses, chaves e colchetes em uma
 * expressão estão balanceados.
 *
 * @param expressao A expressão aritmética a ser verificada.
 * @return `true` se os delimitadores estão balanceados, `false` caso contrário.
 */
bool verificarBalanceamento(const std::string &expressao)
{
    std::stack<char> pilha;

    for (char caractere : expressao)
    {
        // Se for um delimitador de abertura, empilha
        if (caractere == '(' || caractere == '{' || caractere == '[')
        {
            pilha.push(caractere);
        }
        // Se for um delimitador de fechamento, verifica correspondência
        else if (caractere == ')' || caractere == '}' || caractere == ']')
        {
            if (pilha.empty())
                return false;

            char topo = pilha.top();
            pilha.pop();

            if ((caractere == ')' && topo != '(') ||
                (caractere == '}' && topo != '{') ||
                (caractere == ']' && topo != '['))
            {
                return false;
            }
        }
    }

    // Retorna verdadeiro apenas se todos os delimitadores foram fechados corretamente
    return pilha.empty();
}

int main(int argc, char **argv)
{
    std::string expressaoAritmetica;

    std::cout << "Entre com uma expressão aritmética (ex: (5 + 2) - {6 * 9}): ";
    std::getline(std::cin, expressaoAritmetica);

    std::cout << "\nResultado da verificação:\n";

    if (verificarBalanceamento(expressaoAritmetica))
    {
        std::cout << "Os delimitadores estão balanceados.\n";
    }
    else
    {
        std::cout << "Delimitadores desbalanceados!\n";
    }
    return 0;
}
