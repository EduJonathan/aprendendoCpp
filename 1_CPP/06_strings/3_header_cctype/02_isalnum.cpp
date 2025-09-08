#include <iostream>
#include <string>
#include <cctype>

// Função para verificar se o caractere é alfanumérico
void isAlnum(char caractere)
{
    if (std::isalnum(caractere))
    {
        std::cout << "O caractere '" << caractere << "' é alfanumérico." << '\n';
    }
    else
    {
        std::cout << "O caractere '" << caractere << "' NÃO é alfanumérico." << '\n';
    }
}

// Função para verificar se a string é alfanumérica (somente letras e dígitos)
void isAlnumString(const std::string &str)
{
    for (char c : str)
    {
        if (!std::isalnum(c))
        {
            std::cout << "A string \"" << str << "\" NÃO é alfanumérica." << '\n';
            return;
        }
    }
    std::cout << "A string \"" << str << "\" é alfanumérica." << '\n';
}

int main(int argc, char **argv)
{
    isAlnum('a');
    isAlnum('1');
    isAlnum('#');

    std::string testStr = "12345";
    std::string testStr2 = "1234A";
    std::string testStr3 = "123_4A";

    isAlnumString(testStr);
    isAlnumString(testStr2);
    isAlnumString(testStr3);
    return 0;
}
