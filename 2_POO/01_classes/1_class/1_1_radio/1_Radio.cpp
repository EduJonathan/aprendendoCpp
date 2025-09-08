#include <iostream>
#include <string>

/**
 * CLASSES: Uma classe é uma estrutura que define um tipo de objeto. Ela especifica
 * os dados que cada objeto desse tipo contém (através de atributos) e os comportamentos
 * que cada objeto pode realizar (através de métodos). Classes é a forma do C++ traduzir
 * uma abstração em um tipo definido pelo desenvolvedor.
 */

class Radio
{
public:
    bool ligar = false;   // Valores de atributos já definidos dentro da classe
    bool desligar = true; // Valores de atributos já definidos dentro da classe
    int volume = 0;
    std::string estacao = "Radio FM";
};

/**
 * OBJETO: Um objeto é a instância de uma classe. Ou seja, é uma entidade concreta que
 * possui seus próprios valores para os atributos definidos pela classe e pode realizar
 * operações de acordo com os métodos disponíveis na classe. Cada objeto é único e
 * independente de outros objetos da mesma classe.
 */

int main(int argc, char **argv)
{
    Radio radio; // Instanciação de um objeto `radio` com base na classe `Radio`.

    std::cout << "Endereço do objeto radio: " << &radio << '\n';

    // O tamanho pode variar dependendo dos atributos e do alinhamento de memória
    // Aqui, o tamanho é calculado com base nos atributos definidos na classe Radio
    // Em C++, o tamanho de um objeto é determinado pelo tamanho dos seus atributos
    // e pelo alinhamento de memória.
    std::cout << "Tamanho do objeto radio: " << sizeof(radio) << " bytes\n";

    // Irá apresentar com os valores já definidos na classe
    std::cout << "O radio está desligado? " << radio.desligar << '\n';
    std::cout << "O radio está ligado? " << radio.ligar << '\n';

    // Redefinindo os atributos para Desligar o radio
    radio.desligar = false;

    // Redefinindo os atributos para Ligar radio
    radio.ligar = true;

    std::cout << "O radio está desligado? " << radio.desligar << '\n';
    std::cout << "O radio está ligado? " << radio.ligar << '\n';

    // Definido a estação e volume do radio
    radio.estacao = "Radio AM";
    radio.volume = 50;

    std::cout << "Você está na " << radio.estacao << '\n';
    std::cout << "Volume: " << radio.volume << '\n';
    return 0;
}
