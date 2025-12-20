#include <iostream>
#include <memory>

/**
 * INTERFACE: Em C++, interfaces são implementadas por classes abstratas puras, que
 * contêm pelo menos um método virtual puro. Diferente de linguagens como Java ou C#,
 * C++ não possui uma palavra-chave (keyword) específica para interfaces.
 *
 * Uma interface define um contrato com um conjunto de métodos que a classe deve implementar,
 * permitindo que objetos de diferentes classes compartilhem a mesma interface,
 * mesmo com implementações distintas.
 *
 * Use interfaces para promover flexibilidade, extensibilidade, polimorfismo e
 * baixo acoplamento entre os componentes do sistema.
 */

class IInterface
{
public:
    // Método puramente virtual (equivale a um método de interface)
    virtual void metodo1() = 0;

    // Outro método da interface
    virtual int metodo2(int parametro) = 0;

    // Destrutor virtual (importante para herança)
    virtual ~IInterface() {}
};

class MinhaClasse : public IInterface
{
public:
    void metodo1() override;
    int metodo2(int parametro) override;
};

void MinhaClasse::metodo1()
{
    // Implementação do método1
    std::cout << "Implementação de metodo1" << '\n';
}

int MinhaClasse::metodo2(int parametro)
{
    // Implementação do metodo2
    return parametro * 2;
}

void usarInterface(IInterface *obj)
{
    obj->metodo1();
    int resultado = obj->metodo2(5);
    std::cout << "Resultado: " << resultado << '\n';
}

int main(int argc, char **argv)
{
    // Criação de um objeto da classe que implementa a interface
    // Usando ponteiro inteligente para gerenciar a memória automaticamente
    std::unique_ptr<IInterface> obj = std::make_unique<MinhaClasse>();
    usarInterface(obj.get());
    return 0;
}
