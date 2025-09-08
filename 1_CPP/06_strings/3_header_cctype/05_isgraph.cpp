#include <iostream>
#include <string>
#include <cctype>

// Função para verificar se o caractere é imprimível (não espaço)
void isGraph(char caractere)
{
    if (std::isgraph(caractere))
    {
        std::cout << "O caractere '" << caractere << "' é um caractere gráfico (imprimível)." << '\n';
    }
    else
    {
        std::cout << "O caractere '" << caractere << "' NÃO é um caractere gráfico." << '\n';
    }
}

// Função para verificar se a string contém apenas caracteres gráficos (não espaços)
void isGraphString(const std::string &str)
{
    for (char c : str)
    {
        if (!std::isgraph(c))
        {
            std::cout << "A string \"" << str << "\" NÃO contém apenas caracteres gráficos." << '\n';
            return;
        }
    }
    std::cout << "A string \"" << str << "\" contém apenas caracteres gráficos." << '\n';
}

int main(int argc, char **argv)
{
    isGraph('a');
    isGraph('1');
    isGraph('#');
    isGraph(' ');

    std::string testStr = "12345";
    std::string testStr2 = "ABCDE";
    std::string testStr3 = "1234A";
    std::string testStr4 = "123 4A";

    isGraphString(testStr);
    isGraphString(testStr2);
    isGraphString(testStr3);
    isGraphString(testStr4);
    return 0;
}
