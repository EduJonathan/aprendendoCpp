#include <iostream>
#include <string>

class Radio
{
public:
    bool ligar = false;   // Valores de atributos já definidos dentro da classe
    bool desligar = true; // Valores de atributos já definidos dentro da classe
    int volume = 0;
    std::string estacao = "Radio FM";
};

int main(int argc, char **argv)
{
    Radio radio; // Instanciação de um objeto `radio` com base na classe `Radio`.

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
