#include <iostream>
#include <string>
#include <memory>

class Veiculo
{
protected:
    std::string nome;

public:
    Veiculo(const std::string &name) : nome(name) {}

    void mover(void) const
    {
        std::cout << "Veículo: " << nome << " está se movendo." << '\n';
    }
};

class VeiculoTerrestre : virtual public Veiculo
{
public:
    VeiculoTerrestre(const std::string &name) : Veiculo(name) {}

    void dirigir(void) const
    {
        std::cout << "Veículo Terrestre: " << nome << " está dirigindo em terra." << '\n';
    }
};

class VeiculoAquatico : virtual public Veiculo
{
public:
    VeiculoAquatico(const std::string &name) : Veiculo(name) {}

    void navegar(void) const
    {
        std::cout << "Veículo Aquático: " << nome << " está navegando." << '\n';
    }
};

class VeiculoAnfibio : public VeiculoTerrestre, public VeiculoAquatico
{
public:
    VeiculoAnfibio(const std::string &name) : Veiculo(name), VeiculoTerrestre(name), VeiculoAquatico(name) {}

    void operar(void) const
    {
        std::cout << nome << " (anfibio) está operando." << '\n';
        mover();
        dirigir();
        navegar();
    }
};

// O virtual nas heranças permite que a classe base seja compartilhada entre as
// classes derivadas, evitando a duplicação de dados e garantindo que haja apenas
// uma instância da classe base.

int main(int argc, char **argv)
{
    auto meuVeiculo = std::make_unique<VeiculoAnfibio>("Meu Veículo Anfíbio");
    meuVeiculo->operar();

    return 0;
}
