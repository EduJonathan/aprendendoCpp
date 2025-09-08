#include <iostream>
#include <memory>

/**
 * Em composição, usamos ponteiros para que a classe composta tenha controle total
 * sobre a alocação e desalocação dinâmica de seus componentes. Isso significa que,
 * ao invés de armazenar diretamente os objetos, a classe composta mantém ponteiros
 * para objetos de outras classes.
 *
 * Esse controle permite que a classe composta gerencie a criação e destruição dos
 * objetos dinamicamente, o que é útil quando precisamos de flexibilidade na alocação
 * de recursos ou quando os objetos são grandes e precisam de gerenciamento específico de memória.
 *
 * Contudo, esse tipo de controle exige cuidado redobrado, pois a alocação dinâmica
 * pode resultar em **vazamentos de memória** se os ponteiros não forem devidamente
 * desalocados antes de perderem o escopo. Além disso, é necessário garantir que a memória
 * seja gerenciada corretamente, especialmente quando se trabalha com ponteiros brutos,
 * o que pode tornar o código mais propenso a erros se não for bem estruturado.
 */

class Motor
{
public:
    Motor()
    {
        std::cout << "Motor criado" << '\n';
    }

    ~Motor()
    {
        std::cout << "Motor destruído" << '\n';
    }
};

class Carro
{
private:
    Motor *motor; // Ponteiro para o motor

public:
    Carro()
    {
        motor = new Motor(); // Aloca memória para o motor
        std::cout << "Carro criado" << '\n';
    }

    ~Carro()
    {
        delete motor; // Libera a memória do motor
        std::cout << "Carro destruído" << '\n';
    }
};

int main(int argc, char **argv)
{
    Carro *carro = new Carro(); // Cria um carro
    delete carro;               // Destrói o carro e o motor

    // Usando ponteiro inteligente (unique_ptr) para gerenciar a memória automaticamente
    // Cria um carro (motor é alocado automaticamente)
    std::unique_ptr<Carro> carro = std::make_unique<Carro>();
    return 0;
}
