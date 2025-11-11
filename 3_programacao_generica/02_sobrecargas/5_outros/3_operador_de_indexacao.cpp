#include <iostream>
#include <array>
#include <memory>
#include <stdexcept>
#include <string>
#include <cmath>

class Medida
{
private:
    // km³, hm³, dam³, m³, dm³, cm³, mm³
    std::array<double, 7> capacidade{};

public:
    enum Unidade
    {
        KM3 = 0,
        HM3,
        DAM3,
        M3,
        DM3,
        CM3,
        MM3
    };

    // Sobrecarga do operador [] para acessar/modificar
    double &operator[](int indice)
    {
        if (indice < 0 || indice >= 7)
            throw std::out_of_range("Índice fora do limite!");
        return capacidade[indice];
    }

    // Define um valor em uma unidade e atualiza as demais
    void definirValor(Unidade unidade, double valor)
    {
        capacidade.fill(0.0);
        capacidade[unidade] = valor;
        atualizarUnidades(unidade);
    }

    // Mostra todas as unidades com formatação
    void mostrar() const
    {
        static const char *nomes[] = {"km³", "hm³", "dam³", "m³", "dm³", "cm³", "mm³"};
        std::cout << std::fixed;
        std::cout.precision(0);
        for (int i = 0; i < 7; ++i)
        {
            std::cout << nomes[i] << ": " << capacidade[i] << '\n';
        }
    }

    // Função de conversão entre unidades
    static double converter(double valor, Unidade origem, Unidade destino)
    {
        // diferença de ordens na escala
        int diferenca = destino - origem;

        // cada passo é x1000, então multiplicamos ou dividimos por potências de 1000
        return valor * std::pow(1000.0, diferenca);
    }

private:
    // Atualiza todas as unidades com base na unidade fornecida
    void atualizarUnidades(Unidade unidadeBase)
    {
        double base = capacidade[unidadeBase];

        // Unidades maiores (dividir por 1000 a cada passo)
        for (int i = unidadeBase - 1; i >= 0; --i)
        {
            base /= 1000.0;
            capacidade[i] = base;
        }

        // Unidades menores (multiplicar por 1000 a cada passo)
        base = capacidade[unidadeBase];
        for (int i = unidadeBase + 1; i < 7; ++i)
        {
            base *= 1000.0;
            capacidade[i] = base;
        }
    }
};

int main(int argc, char **argv)
{
    std::unique_ptr<Medida> volume = std::make_unique<Medida>();

    try
    {
        // Definindo 2 hm³ e mostrando tabela
        volume->definirValor(Medida::KM3, 2);
        std::cout << "Tabela de conversão de 2 hm³:\n";
        volume->mostrar();

        std::cout << "\nConversões diretas:\n";

        std::cout << "5000 m³ em km³ = "
                  << Medida::converter(5000, Medida::M3, Medida::KM3)
                  << " km³\n";

        std::cout << "3 km³ em m³ = "
                  << Medida::converter(3, Medida::KM3, Medida::M3)
                  << " m³\n";

        std::cout << "2500000 cm³ em m³ = "
                  << Medida::converter(2500000, Medida::CM3, Medida::M3)
                  << " m³\n";
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
