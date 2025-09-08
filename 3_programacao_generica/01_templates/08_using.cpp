#include <iostream>

/**
 * O 'using' em C++ é usado para criar aliases de tipo, ou "apelidos" para tipos.
 * Útil quando trabalhamos com tipos complexos (como templates) e não queremos repetir
 * o tipo completo várias vezes.
 *
 * aliases São especialmente úteis quando lidamos com templates, onde o nome do tipo
 * pode ser longo e complicado. Com o 'using', podemos criar um nome mais curto e fácil
 * de usar para esse tipo.
 *
 * EXEMPLO:
 * - Sem o 'using': Para instanciar Vetor2 com o tipo int, você precisaria escrever Vetor2<int> toda vez.
 *
 * - Com o 'using': Você cria um alias, como Vetor2Inteiro, para Vetor2<int>.
 * Assim, você pode usar Vetor2Inteiro no lugar de Vetor2<int>, simplificando
 * o código e tornando-o mais legível.
 */

template <class T>
class Vetor2
{
public:
    T x, y;

    // Construtor público
    Vetor2(T x, T y) : x(x), y(y) {}

    // Método para exibir o vetor
    void exibir() const
    {
        std::cout << "Vetor2(" << x << ", " << y << ")\n";
    }
};

int main(int argc, char **argv)
{
    // Criando aliases para tipos específicos de Vetor2 usando a palavra-chave 'using'
    // A linha abaixo cria um alias chamado 'Vetor2Inteiro' para o tipo Vetor2<int>
    using Vetor2Inteiro = Vetor2<int>;

    // Aqui estamos criando um alias para Vetor2<float>
    using Vetor2Float = Vetor2<float>;

    // E aqui, estamos criando um alias para Vetor2<unsigned>
    using Vetor2Unsigned = Vetor2<unsigned>;

    // Agora, podemos usar esses aliases para criar instâncias de Vetor2 com tipos específicos
    Vetor2Inteiro vetor1(10, 20);     // Vetor de inteiros (equivalente a Vetor2<int>)
    Vetor2Float vetor2(10.5f, 20.5f); // Vetor de floats (equivalente a Vetor2<float>)
    Vetor2Unsigned vetor3(30u, 40u);  // Vetor de unsigned integers (equivalente a Vetor2<unsigned>)

    // Exibindo os valores dos vetores
    vetor1.exibir();
    vetor2.exibir();
    vetor3.exibir();
    return 0;
}
