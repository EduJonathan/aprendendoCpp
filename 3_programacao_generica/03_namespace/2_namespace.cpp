#include <iostream>
#include <vector>
#include <memory>
#include <new>
#include <stdexcept>

namespace diff
{
    // Classe que demonstra cálculo de diferença com uso manual de arrays
    class ArrayOutOfIndex
    {
    public:
        void calculateDifference()
        {
            int difference = 0; // Variável acumuladora da diferença

            // Aloca dinamicamente um array de 5 inteiros
            int *numbers = new int[5];

            // Preenche os índices de 0 a 4 com valores de i+1 (ou seja, 1 a 5)
            for (int i = 0; i < 5; ++i)
            {
                numbers[i] = i + 1;
            }

            // Laço para calcular a diferença acumulada subtraindo os valores do array
            // Só acessa de 1 a 4 (evita índice inválido como 5)
            for (int init = 1; init < 5; ++init)
            {
                difference -= numbers[init]; // Subtrai valor atual do array
                std::cout << "A diferença dos números do array é: " << difference << '\n';
            }

            // Libera a memória alocada para o array
            delete[] numbers;
        }
    };
}

namespace difference
{
    class ArrayOutOfIndex
    {
    public:
        void calculateDifference()
        {
            int difference = 0;
            std::vector<int> numbers(5);

            for (int i = 1; i < numbers.size(); ++i)
            {
                numbers[i] = i + 5;
            }

            try
            {
                for (int init = 1; init <= numbers.size(); ++init)
                {
                    difference -= numbers.at(init);
                    std::cout << "A diferença dos números do array é: " << difference << '\n';
                }
            }
            catch (const std::out_of_range &e)
            {
                std::cerr << "Erro: Acesso fora do índice do vetor - " << e.what() << '\n';
            }
        }
    };
}

int main(int argc, char **argv)
{
    diff::ArrayOutOfIndex *arrayOutOfIndex = new diff::ArrayOutOfIndex();
    arrayOutOfIndex->calculateDifference();
    delete arrayOutOfIndex;
    std::cout << "Programa finalizado com sucesso!" << "\n\n";

    // Usando smart pointer
    std::unique_ptr<difference::ArrayOutOfIndex> ArrayforaDoIndex =
        std::make_unique<difference::ArrayOutOfIndex>();

    ArrayforaDoIndex->calculateDifference();
    std::cout << "Programa finalizado com sucesso!" << '\n';
    return 0;
}
