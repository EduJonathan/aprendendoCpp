#include <iostream>
#include <string>
#include <stdexcept>
#include <new>

class String
{
private:
    std::string str; // Armazena a string

public:
    // Construtor que inicializa a string
    String(const std::string &s) : str(s) {}

    // Sobrecarga do operador -- para decrementar cada caractere da string
    String &operator--()
    {
        for (std::size_t i{0}; i < str.size(); ++i)
        {
            --str[i]; // Decrementa o código ASCII de cada caractere
        }
        return *this;
    }

    // Função para imprimir a string
    void imprimir() const
    {
        std::cout << str << '\n';
    }
};

int main(int argc, char **argv)
{
    try
    {
        String *string = new String("Bc");

        std::cout << "String original: ";
        string->imprimir();

        // Decrementando os caracteres da string
        --(*string);

        std::cout << "Após decremento: ";
        string->imprimir();
        delete string;
    }
    catch (const std::exception &e)
    {
        std::cout << "Erro: " << e.what() << '\n';
    }

    return 0;
}
