#include <iostream>
#include <new>

class Distancia
{
private:
    int metro;
    float polegada;

public:
    // Construtores
    Distancia() : metro(0), polegada(0.0f) {}

    Distancia(int m, float p) : metro(m), polegada(p) {}

    Distancia(float p)
    {
        metro = static_cast<int>(p / 12);
        polegada = p - (metro * 12);
    }

    // Método para exibir a distância
    void exibir(void) const
    {
        std::cout << metro << "\'-" << polegada << "\"" << '\n';
    }

    // Declaração da função amiga
    friend Distancia square(Distancia);
};

/**
 * @brief Função amiga que calcula o quadrado da distância
 * A função recebe um objeto Distancia como parâmetro e retorna um novo objeto Distancia
 *
 * @note Perceba que, embora a função não seja membro da classe Distancia, ela pode
 * acessar os membros privados da classe porque foi explicitamente declarada como amiga
 * da classe Distancia.
 */
Distancia square(Distancia d)
{
    // Converte tudo para metros
    float totalMetros = d.metro + d.polegada / 12.0f;

    // Calcula o quadrado da distância em metros
    totalMetros = totalMetros * totalMetros;

    // Converte de volta para metros e polegadas
    int metros = static_cast<int>(totalMetros);
    float polegadas = (totalMetros - metros) * 12.0f;

    return Distancia(metros, polegadas);
}

int main(int argc, char **argv)
{
    Distancia *distancia1 = new Distancia(3.0f, 4.0f);

    std::cout << "Distancia 1: ";
    distancia1->exibir(); // Exibe a distância distancia1

    std::cout << "Distancia 2 (quadrado da distancia1): ";

    Distancia distancia2;

    // Chama a função amiga square para calcular o quadrado da distância
    distancia2 = square(*distancia1);

    // Exibe o quadrado da distância
    distancia2.exibir();

    delete distancia1;
    return 0;
}
