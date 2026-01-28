#include <iostream>
#include <cstring>
#include <cstddef>

/**
 * Estes conceitos é mais explorado em POO (Programação Orientada a Objetos), mas que pode se aplicar em structs também.
 *
 * Encapsulamento é o conceito de esconder os detalhes internos de uma estrutura de dados ou objeto, expondo apenas
 * o que é necessário para o uso externo. Isso ajuda a proteger a integridade dos dados e a evitar acessos indevidos.
 *
 * Existem ao todo três níveis de encapsulamento em C++:
 * 1. private: Apenas membros da própria classe podem acessar.
 * 2. protected: Apenas membros da própria classe e classes derivadas podem acessar.
 * 3. public: Todos podem acessar.
 */

struct Palindromo
{
    // Este é o private, ou seja, não pode ser acessado diretamente fora da struct.
private:
    char *data;
    std::size_t length;

    // Método privado
    const char *getString() const
    {
        return data;
    }

    // Estes são os métodos públicos, ou seja, podem ser acessados fora da struct.
public:
    // Construtor
    Palindromo(const char *str)
    {
        length = std::strlen(str);
        data = new char[length + 1];
        std::strcpy(data, str);
    }

    // Destrutor, ele serve para liberar a memória alocada, veremos mais com detalhes posteriormente em POO.
    ~Palindromo()
    {
        delete[] data;
    }

    // Método público para verificar se a string(data) é palíndromo
    bool ehPalindromo() const
    {
        std::size_t inicio = 0;                    // índice inicial
        std::size_t fim = length ? length - 1 : 0; // índice final

        while (inicio < fim)
        {
            if (data[inicio] != data[fim])
                return false;

            ++inicio;
            --fim;
        }
        return true;
    }
};

int main(int argc, char **argv)
{
    Palindromo p1("ana");
    Palindromo p2("casa");

    // ERRO: método privado
    // std::cout << p.getString();

    // ERRO: atributo privado
    // std::cout << p.data;

    std::cout << "ana é palindromo? " << (p1.ehPalindromo() ? "sim" : "nao") << '\n';
    std::cout << "casa é palindromo? " << (p2.ehPalindromo() ? "sim" : "nao") << '\n';

    return 0;
}
