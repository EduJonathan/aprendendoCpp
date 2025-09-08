#include <iostream>
#include <vector>
#include <memory>

class TipoNavio
{
public:
    virtual void descreverTipo() = 0;
    virtual ~TipoNavio() {}
};

class Propulsao
{
public:
    virtual void modoPropulsao() = 0;
    virtual ~Propulsao() {}
};

class NavioGraneleiro : public TipoNavio, public Propulsao
{
public:
    void descreverTipo() override
    {
        std::cout << "Navio Graneleiro: transporta cargas sólidas a granel, como grãos e minérios.\n";
    }

    void modoPropulsao() override
    {
        std::cout << "Propulsão: motor diesel com hélice simples.\n";
    }
};

class NavioTanque : public TipoNavio, public Propulsao
{
public:
    void descreverTipo() override
    {
        std::cout << "Navio Tanque: transporta líquidos como petróleo, químicos e gás liquefeito.\n";
    }

    void modoPropulsao() override
    {
        std::cout << "Propulsão: motor diesel de dois tempos com eixo direto.\n";
    }
};

class NavioLuxo : public TipoNavio, public Propulsao
{
public:
    void descreverTipo() override
    {
        std::cout << "Navio de Luxo: usado para cruzeiros e transporte de passageiros em alto padrão.\n";
    }

    void modoPropulsao() override
    {
        std::cout << "Propulsão: turbinas a gás com propulsão elétrica.\n";
    }
};

class NavioPortaContainer : public TipoNavio, public Propulsao
{
public:
    void descreverTipo() override
    {
        std::cout << "Navio Porta-Contêiner: transporta grandes volumes de cargas em contêineres.\n";
    }

    void modoPropulsao() override
    {
        std::cout << "Propulsão: motor diesel com hélice de passo fixo.\n";
    }
};

// Função genérica usando ponteiro polimórfico
void imprimirInformacoesNavio(TipoNavio *navio)
{
    navio->descreverTipo();

    // Tentativa de fazer downcast para acessar a propulsão
    Propulsao *propulsao = dynamic_cast<Propulsao *>(navio);
    if (propulsao)
    {
        propulsao->modoPropulsao();
    }
    else
    {
        std::cout << "Este navio não tem sistema de propulsão definido.\n";
    }
    std::cout << "--------------------------------------------\n";
}

int main(int argc, char **argv)
{
    // Vetor de ponteiros para a interface base
    std::vector<TipoNavio *> frota;

    frota.push_back(new NavioGraneleiro());
    frota.push_back(new NavioTanque());
    frota.push_back(new NavioLuxo());
    frota.push_back(new NavioPortaContainer());

    std::cout << "=== Informações da Frota ===\n\n";
    for (TipoNavio *navio : frota)
    {
        imprimirInformacoesNavio(navio);
    }

    // Liberar memória (uso de raw pointers exige delete)
    for (TipoNavio *navio : frota)
    {
        delete navio;
    }
    return 0;
}
