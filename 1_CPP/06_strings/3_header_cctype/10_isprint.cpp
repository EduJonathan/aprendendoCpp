#include <iostream>
#include <string>
#include <cctype>

// Função para verificar se o caractere é imprimível (qualquer caractere visível)
void isPrint(char caractere)
{
    if (std::isprint(caractere))
    {
        std::cout << "O caractere '" << caractere << "' é imprimível." << '\n';
    }
    else
    {
        std::cout << "O caractere '" << caractere << "' NÃO é imprimível." << '\n';
    }
}

// Função para verificar se a string contém apenas caracteres imprimíveis
void isPrintString(const std::string &str)
{
    for (char c : str)
    {
        if (!std::isprint(c))
        {
            std::cout << "A string \"" << str << "\" NÃO contém apenas caracteres imprimíveis." << '\n';
            return;
        }
    }
    std::cout << "A string \"" << str << "\" contém apenas caracteres imprimíveis." << '\n';
}

int main(int argc, char **argv)
{
    isPrint('a');
    isPrint('1');
    isPrint('\t');
    isPrint('\n');

    std::string testStr = "12345";
    std::string testStr2 = "ABCDE";
    std::string testStr3 = "1234\tA";
    std::string testStr4 = "123\v4A";

    isPrintString(testStr);
    isPrintString(testStr2);
    isPrintString(testStr3);
    isPrintString(testStr4);
    return 0;
}
