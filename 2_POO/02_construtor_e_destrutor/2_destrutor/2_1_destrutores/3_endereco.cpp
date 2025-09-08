#include <iostream>
#include <string>

/**
 * @class Propriedade
 * @brief Representa uma propriedade imobiliária com informações básicas
 */
class Propriedade
{
private:
    std::string endereco;
    std::string tipo;
    double area;
    int *codigo; // Ponteiro para demonstrar gerenciamento no destrutor

public:
    // Construtor padrão
    Propriedade() : endereco(""), tipo("Desconhecido"), area(0.0), codigo(new int(0))
    {
        std::cout << "Propriedade padrão criada (construtor padrão)\n";
    }

    // Construtor parametrizado
    Propriedade(const std::string &end, const std::string &tp, double ar, int cod)
        : endereco(end), tipo(tp), area(ar), codigo(new int(cod))
    {
        std::cout << "Propriedade específica criada (construtor parametrizado)\n";
    }

    // Construtor de cópia
    Propriedade(const Propriedade &other) : endereco(other.endereco), tipo(other.tipo),
                                            area(other.area), codigo(new int(*other.codigo))
    {
        std::cout << "Propriedade copiada (construtor de cópia)\n";
    }

    // Destrutor
    ~Propriedade()
    {
        std::cout << "Destruindo propriedade: " << endereco << '\n';
        delete codigo;
    }

    // Método para exibir informações
    void exibir(void) const
    {
        std::cout << "\n=== Informações da Propriedade ===\n";
        std::cout << "Endereço: " << endereco << '\n';
        std::cout << "Tipo: " << tipo << '\n';
        std::cout << "Área: " << area << " m²\n";
        std::cout << "Código: " << *codigo << '\n';
    }

    // Atualizar endereço
    void atualizarEndereco(const std::string &novoEnd)
    {
        endereco = novoEnd;
    }
};

int main(int argc, char **argv)
{
    std::cout << "=== Programa iniciado ===\n";

    // 1. Construtor padrão (alocação automática)
    Propriedade padrao;
    padrao.exibir();

    // 2. Construtor parametrizado (alocação dinâmica)
    Propriedade *casa = new Propriedade("Rua das Flores, 123", "Casa Residencial", 250.5, 1001);
    casa->exibir();

    // 3. Construtor de cópia (a partir do ponteiro `casa`, mas ainda é automático)
    Propriedade copiaCasa(*casa); // Cópia do objeto apontado
    copiaCasa.atualizarEndereco("Rua das Flores, 123-A");
    copiaCasa.exibir();

    // 4. Propriedade adicional (também alocação dinâmica)
    std::cout << "\nCriando propriedade adicional...\n";
    Propriedade *apartamento = new Propriedade("Av. Central, 456", "Apartamento", 85.0, 2002);
    apartamento->exibir();
    std::cout << "Propriedade adicional criada.\n";

    // Liberação da memória alocada dinamicamente
    delete casa;
    delete apartamento;

    return 0;
}
