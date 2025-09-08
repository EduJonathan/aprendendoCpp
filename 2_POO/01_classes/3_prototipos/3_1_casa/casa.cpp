#include <iostream>

/**
 * PROTÓTIPOS: Prototipação de metódos é a declaração antecipada dentro da classe
 * e que informa ao compilador o nome da função, o tipo de retorno e os parâmetros
 * que ela recebe.
 *
 * SINTAXE: <tipo de retorno> <classe::nomeDoMetodo>(param...) {}
 *
 * Isso permite que a função seja chamada em qualquer parte do código antes
 * de sua implementação real, garantindo que o compilador conheça sua assinatura.
 *
 * Em programas maiores, o uso de protótipos — especialmente em conjunto com a separação
 * entre arquivos de cabeçalho (.hpp) e de implementação (.cpp) — melhora a organização,
 * modularidade e legibilidade do código.
 *
 * Essa prática é essencial para trabalhar com classes, structs e métodos em projetos
 * mais complexos, pois facilita a abstração, a reutilização de código e a manutenção.
 */

class Casa
{
private:
    int qntdQuartos;
    bool temSuite;
    static const int limiteQuartos = 3; // Limite máximo de quartos

public:
    // Getters
    int getQntdQuartos() const;
    bool getTemSuite() const;

    // Setters
    bool setQntdQuartos(int quartos);
    void setTemSuite(bool suite);

    // Método para exibir os dados
    void exibirInformacoes() const;
};

int main(int argc, char **argv)
{
    Casa CasaDePraia;
    CasaDePraia.setQntdQuartos(3);
    CasaDePraia.setTemSuite(true);
    CasaDePraia.exibirInformacoes();

    Casa CasaDePraia1;
    CasaDePraia1.setQntdQuartos(4); // Tentando configurar mais quartos do que o permitido
    CasaDePraia1.setTemSuite(false);
    CasaDePraia1.exibirInformacoes();

    return 0;
}

// Implementações essas que pode está implementando antes ou depois da função `main`
int Casa::getQntdQuartos() const
{
    return qntdQuartos;
}

bool Casa::getTemSuite() const
{
    return temSuite;
}

void Casa::setTemSuite(bool suite)
{
    temSuite = suite;
}

bool Casa::setQntdQuartos(int quartos)
{
    if (quartos > limiteQuartos)
    {
        std::cout << "Erro: Não há quartos suficientes! A casa tem no máximo " << limiteQuartos << " quartos.\n";
        return false;
    }

    qntdQuartos = quartos;
    return true;
}

void Casa::exibirInformacoes() const
{
    std::cout << "Quartos: " << qntdQuartos
              << ", Suite: " << (temSuite ? "Sim" : "Não") << '\n';
}
