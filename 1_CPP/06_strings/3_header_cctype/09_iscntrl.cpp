#include <iostream>
#include <string>
#include <cctype>

// Função para verificar se o caractere é um caractere de controle
void isCntrl(char caractere)
{
    if (std::iscntrl(caractere))
    {
        std::cout << "O caractere '" << caractere << "' é um caractere de controle." << '\n';
    }
    else
    {
        std::cout << "O caractere '" << caractere << "' NÃO é um caractere de controle." << '\n';
    }
}

// Função para verificar se a string contém apenas caracteres de controle
void isCntrlString(const std::string &str)
{
    for (char c : str)
    {
        if (!std::iscntrl(c))
        {
            std::cout << "A string \"" << str << "\" NÃO contém apenas caracteres de controle." << '\n';
            return;
        }
    }
    std::cout << "A string \"" << str << "\" contém apenas caracteres de controle." << '\n';
}

int main(int argc, char **argv)
{
    isCntrl('a');
    isCntrl('1');
    isCntrl('\b');

    std::string testStr = "12345";
    std::string testStr2 = "ABCDE";
    std::string testStr3 = "\n\t";
    std::string testStr4 = "123_4A";

    isCntrlString(testStr);
    isCntrlString(testStr2);
    isCntrlString(testStr3);
    isCntrlString(testStr4);
    return 0;
}
