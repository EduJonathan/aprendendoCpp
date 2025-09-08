#include <iostream>
#include <string>

/**
 * Strings: Strings em C++ são representadas por objetos da classe std::string,
 * com a utilização ainda da tabela ASCII como padrão, podendo ser trabalhadas
 * como arrays de caracteres. A classe facilita a manipulação de strings e também
 * permitindo o uso de funções(métodos) prontas.
 */

int main(int argc, char **argv)
{
    // Declarando uma string em C++, que podem ser acessadas usando o operador
    // de colchetes("[]") como um conjunto contíguo de caracteres em um array.
    std::string str{"Hello, World!"};
    std::cout << "Imprimindo caractere na posição 0: " << str[0] << '\n';
    std::cout << str << '\n';

    std::cout << "---------------------------------------\n";

    // Conversão de char* para std::string
    const char *string{"12345678910"};
    std::string String = string;        // Conversão de char* para std::string.
    std::cout << String.size() << '\n'; // ou String.length(), ambos retornam o tamanho da string

    std::cout << "---------------------------------------\n";

    std::string email("Eduardo123@gmail.com");

    int carateresMaiusculas{0};
    int carateresMinusculas{0};
    int caracteresEspeciais{0};
    int digitos{0};

    for (std::size_t index{0}; index < email.length(); ++index)
    {
        if (email[index] >= 65 && email[index] <= 90)
        {
            /**
             * Caracteres ASCII que pertencem ao intervalo 65 a 90 correspondem aos
             * caracteres maiúsculos('A' a 'Z')
             */
            carateresMaiusculas++;
        }
        else if (email[index] >= 97 && email[index] <= 122)
        {
            /**
             * Caracteres ASCII que pertencem ao intervalo 97 a 122 correspondem aos
             * caracteres minúsculos('a' a 'z')
             */
            carateresMinusculas++;
        }
        else if (email[index] >= 48 && email[index] <= 57)
        {
            // Caracteres ASCII que pertencem ao intervalo 48 a 57 correspondem aos dígitos(0 a 9)
            digitos++;
        }
        else
        {
            /**
             * Os caracteres ASCII que não pertencem ao intervalo 48 a 57 correspondem aos
             * caracteres especiais('!', '@', '#', '$', '%', '.', etc...).
             */
            caracteresEspeciais++;
        }
    }

    std::cout << "Caracteres Maiusculas: " << carateresMaiusculas << '\n';
    std::cout << "Caracteres Minusculas: " << carateresMinusculas << '\n';
    std::cout << "Caracteres Especiais: " << caracteresEspeciais << '\n';
    std::cout << "Quantidade de Digitos: " << digitos << '\n';
    return 0;
}
