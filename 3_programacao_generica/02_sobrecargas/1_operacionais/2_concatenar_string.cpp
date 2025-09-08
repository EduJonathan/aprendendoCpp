#include <iostream>
#include <cstring>
#include <string>
#include <new>

constexpr int SIZE = 255;

/**
 * @class String
 * @brief Classe template que simula uma string com operações básicas.
 *
 * A classe `String` é uma implementação simples de uma string com um tamanho fixo.
 * Ela permite inicializar uma string, exibir seu conteúdo e realizar concatenação
 * com outra string utilizando o operador `+`.
 *
 * @tparam T Tipo de dado utilizado para armazenar a string (ex: `char[]`, `std::string`).
 */
template <typename T>
class String
{
private:
    T str[SIZE]; /**< Array de caracteres que armazena a string. */

public:
    /**
     * @brief Construtor padrão.
     *
     * Construtor que inicializa a string com uma string vazia ("").
     */
    String()
    {
        std::strcpy(str, "");
    }

    /**
     * @brief Construtor que inicializa a string com um valor passado como argumento.
     *
     * @param s A string que será copiada para o array `str`.
     */
    String(const T s[])
    {
        std::strcpy(str, s);
    }

    /**
     * @brief Exibe o conteúdo da string na saída padrão (console).
     *
     * Este método exibe o valor da string armazenada no objeto.
     */
    void display() const
    {
        std::cout << str;
    }

    /**
     * @brief Sobrecarga do operador de adição `+` para concatenar duas strings.
     *
     * Este operador permite concatenar dois objetos da classe `String`. O resultado
     * é uma nova instância da classe `String` com a concatenação das duas strings.
     *
     * @param other O objeto `String` que será concatenado com o objeto atual.
     * @return Uma nova instância de `String` com a concatenação.
     */
    String operator+(const String &other) const
    {
        String temp;

        // Verifica se a concatenação não ultrapassa o tamanho máximo permitido (SIZE).
        if (std::strlen(str) + std::strlen(other.str) < SIZE)
        {
            std::strcpy(temp.str, str);       // Copia o conteúdo da string atual.
            std::strcat(temp.str, other.str); // Concatena a string do objeto `other`.
        }
        else
        {
            std::cout << "\nString muito longa."; // Mensagem de erro se o tamanho exceder.
        }

        // Retorna a nova string concatenada.
        return temp;
    }
};

int main(int argc, char **argv)
{
    using string = String<char>;
    string *str1 = new string("Hello "); // Cria o primeiro objeto String com o valor "Hello ".
    string *str2 = new string("C++");    // Cria o segundo objeto String com o valor "C++".

    string *newStr = new string(*str1 + *str2); // Concatena s1 e s2 usando o operador `+` e armazena em s3.
    newStr->display();                          // Exibe a string resultante: "Hello C++".
    return 0;
}
