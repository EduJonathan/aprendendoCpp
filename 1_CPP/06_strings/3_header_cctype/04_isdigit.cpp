#include <iostream>
#include <string>
#include <cctype>

// Função para verificar se o caractere é um dígito
void isDigito(char caractere)
{
    if (std::isdigit(caractere))
    {
        std::cout << "O caractere " << caractere << " É um digito" << '\n';
    }
    else
    {
        std::cout << "O caractere \'" << caractere << "\' Não é um digito" << '\n';
    }
}

// Função para verificar se a string contém apenas dígitos
bool stringDeDigitos(const std::string &str)
{
    for (char c : str)
    {
        if (!std::isdigit(c))
        {
            return false; // Return false se os caracteres não é um caractere
        }
    }
    return true; // Return true se todos são caracteres.
}

int main(int argc, char **argv)
{
    isDigito('A');
    isDigito('1');

    // Test stringDeDigitos
    std::string testStr = "12345";
    std::string testStr2 = "1234A";

    if (stringDeDigitos(testStr))
    {
        std::cout << "A string \"" << testStr << "\" contém apenas digitos." << '\n';
    }
    else
    {
        std::cout << "A string \"" << testStr << "\" NÃO contém apenas digitos." << '\n';
    }

    if (stringDeDigitos(testStr2))
    {
        std::cout << "A string \"" << testStr2 << "\" contém apenas digitos." << '\n';
    }
    else
    {
        std::cout << "A string \"" << testStr2 << "\" NÃO contém apenas digitos." << '\n';
    }
    return 0;
}
