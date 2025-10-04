#include <iostream>
#include <new>

class Retangulo
{
public:             // Declaração da seção pública da classe
    double largura; // Atributo que armazena a largura do retângulo
    double altura;  // Atributo que armazena a altura do retângulo

    /**
     * @brief Define os valores de largura e altura do retângulo.
     *
     * Este método define os valores dos atributos largura e altura
     * do objeto retângulo, utilizando os parâmetros fornecidos.
     *
     * @param l O valor a ser atribuído à largura do retângulo.
     * @param a O valor a ser atribuído à altura do retângulo.
     */
    void setValores(double l, double a)
    {
        largura = l; // Atribui o valor de 'l' à largura
        altura = a;  // Atribui o valor de 'a' à altura
    }

    /**
     * @brief Retorna o valor da área do retângulo.
     *
     * Este método acessa os valores dos atributos largura e altura do objeto
     * retângulo e retorna o produto desses valores, que é a área do retângulo.
     *
     * @return O valor da área do retângulo.
     */
    double getArea() const { return largura * altura; }
};

int main(int argc, char **argv)
{
    // Declara um objeto 'rectangle1' e um ponteiro para 'Retangulo'
    Retangulo rectangle1;

    // Declara um objeto 'rectangle1' e um ponteiro para 'Retangulo'
    Retangulo *rectangle2 = nullptr;

    // Declara um objeto 'rectangle1' e um ponteiro para 'Retangulo'
    Retangulo *rectangle3 = nullptr;

    // Aloca dinamicamente um array de 2 objetos do tipo 'Retangulo' e o 
    // armazena em 'rectangle4' A alocação é feita usando 'new[]' para criar 
    // um array de 2 retângulos
    Retangulo *rectangle4 = new Retangulo[2];

    // Aloca dinamicamente um único objeto 'Retangulo' e armazena o ponteiro em 'rectangle2'
    rectangle2 = new Retangulo;

    // Aponta 'rectangle3' para 'rectangle1' (não aloca memória)
    rectangle3 = &rectangle1;

    // Define os valores de largura e altura para 'rectangle1'
    rectangle1.setValores(3.0, 4.0);

    // Usa o operador '->' para acessar o método de um objeto alocado dinamicamente em 'rectangle2'
    rectangle2->setValores(5.0, 6.0);

    // Define os valores de largura e altura para o primeiro retângulo do array 'rectangle4'
    rectangle4->setValores(7.0, 8.0);

    // Define os valores de largura e altura para o segundo retângulo do array 'rectangle4'
    rectangle4[1].setValores(9.0, 10.0);

    // Exibe a área de 'rectangle1'
    std::cout << "Área do Retangulo 1: " << rectangle1.getArea() << '\n';

    // Exibe a área de 'rectangle2' (acessado via ponteiro)
    std::cout << "Área do *Retangulo 2: " << rectangle2->getArea() << '\n';

    // Exibe a área de 'rectangle3' (apontando para 'rectangle1')
    std::cout << "Área do *Retangulo 3: " << rectangle3->getArea() << '\n';

    // Exibe a área do primeiro retângulo de 'rectangle4'
    std::cout << "Área do *Retangulo[0] 4: " << rectangle4[0].getArea() << '\n';

    // Exibe a área do segundo retângulo de 'rectangle4'
    std::cout << "Área do *Retangulo[1] 4: " << rectangle4[1].getArea() << '\n';

    // Libera a memória alocada dinamicamente por new
    delete[] rectangle4; // Libera o array de objetos 'rectangle4' que foi alocado com 'new[]'
    delete rectangle2;   // Libera o único objeto 'rectangle2' alocado com 'new'
    
    return 0;
}
