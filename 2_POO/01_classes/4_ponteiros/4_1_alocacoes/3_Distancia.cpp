#include <iostream>
#include <memory>
#include <limits>

/**
 * @class Distancia
 * @brief Classe que representa uma distância em centímetros e polegadas.
 */
class Distancia
{
private:
    double centimetro; // Distância em centímetros
    double polegada;   // Distância em polegadas

public:
    /**
     * @brief Solicita ao usuário as distâncias em centímetros e polegadas.
     */
    void getDistancia(void)
    {
        std::cout << "Digite a distancia em centimetros: ";
        while (!(std::cin >> centimetro))
        {
            std::cin.clear(); // Limpa o erro
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada invalida. Digite um numero para centimetros: ";
        }

        std::cout << "Digite a distancia em polegadas: ";
        while (!(std::cin >> polegada))
        {
            std::cin.clear(); // Limpa o erro
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada invalida. Digite um numero para polegadas: ";
        }
    }

    /**
     * @brief Exibe as distâncias em centímetros e polegadas.
     */
    void exibirDistancia(void) const
    {
        std::cout << "A distancia em centimetros é: " << centimetro << '\n';
        std::cout << "A distancia em polegadas é: " << polegada << '\n';
    }
};

int main(int argc, char **argv)
{
    const int LIMITE = 10;
    int qntd = 0;
    char continuar = '\0';

    // Array de ponteiros inteligentes para objetos Distancia
    std::unique_ptr<Distancia> distance[LIMITE];

    do
    {
        if (qntd >= LIMITE)
        {
            std::cout << "Limite de " << LIMITE << " distancias atingido.\n";
            break;
        }

        distance[qntd] = std::make_unique<Distancia>();
        distance[qntd]->getDistancia();
        qntd++;

        std::cout << "Deseja adicionar outra distancia? (S/N): ";
        std::cin >> continuar;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (continuar == 'S' || continuar == 's');

    std::cout << "\n--- Distancias Registradas ---\n";
    for (int i = 0; i < qntd; ++i)
    {
        std::cout << "\nDistancia #" << (i + 1) << ":\n";
        distance[i]->exibirDistancia();
    }

    return 0;
}
