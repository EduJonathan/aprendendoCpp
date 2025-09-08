#include <iostream>
#include <string>
#include <new>

/**
 * A Programação Orientada a Objetos (POO) em C++, diferentemente de linguagens como
 * Java, C# e Python que abstraem o uso de ponteiros, oferece suporte direto ao uso
 * de ponteiros — tanto para variáveis quanto para objetos também.
 *
 * Isso permite a alocação dinâmica de memória, um recurso essencial quando o
 * número de objetos a serem criados não é conhecido em tempo de compilação.
 *
 * Essa capacidade é uma das principais vantagens do C++ dentro do paradigma POO,
 * pois possibilita um controle mais preciso sobre o uso da memória, otimizações,
 * evitando desperdícios e permitindo a construção de estruturas de dados mais
 * flexíveis e eficientes.
 */

class Triangulo
{
private:
    std::string classificao[3]{"Isóceles", "Equilátero", "Escaleno"};

public:
    double lado1, lado2, lado3;

    // Método para classificar o triângulo
    const std::string classificaTriangulo(void)
    {
        if (lado1 == lado2 && lado2 == lado3)
        {
            return classificao[0]; // Equilátero
        }
        else if (lado1 == lado2 || lado2 == lado3 || lado1 == lado3)
        {
            return classificao[1]; // Isóceles
        }
        return classificao[2]; // Escaleno
    }

    // Metódo para definir os lados dos triângulos
    void setLados(double l1, double l2, double l3)
    {
        lado1 = l1;
        lado2 = l2;
        lado3 = l3;
    }

    // Método para exibir a classificação
    void getClassificacao(void)
    {
        std::cout << "A classificação do triângulo é: " << classificaTriangulo() << '\n';
    }
};

int main(int argc, char **argv)
{
    Triangulo *triangulo = new Triangulo;

    // Triângulo Equilátero
    triangulo->setLados(5.0, 5.0, 5.0); // Esperado: Equilátero
    triangulo->getClassificacao();      // Esperado: Equilátero

    // Triângulo Isósceles
    triangulo->setLados(3.0, 3.0, 5.0); // Esperado: Isósceles
    triangulo->getClassificacao();      // Esperado: Isósceles

    // Triângulo Escaleno
    triangulo->setLados(5.0, 6.0, 7.0); // Esperado: Escaleno
    triangulo->getClassificacao();      // Esperado: Escaleno

    // Outros exemplos de Triângulos Equiláteros
    triangulo->setLados(7.0, 7.0, 7.0); // Esperado: Equilátero
    triangulo->getClassificacao();      // Esperado: Equilátero

    triangulo->setLados(10.0, 10.0, 10.0); // Esperado: Equilátero
    triangulo->getClassificacao();         // Esperado: Equilátero

    // Liberando a memória alocada dinamicamente
    delete triangulo; // Necessário para evitar vazamento de memória
    return 0;
}
