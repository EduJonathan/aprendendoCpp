#include <iostream>
#include <stdexcept>
#include <memory>

/**
 * A sobrecarga dos operadores abreviados (`operator*=`, `operator+=`, `operator-=`, `operator/=`, ...)
 * permite que você defina a lógica personalizada para realizar operações de atribuição modificada
 * em objetos. Esses operadores são úteis para realizar operações como multiplicação, soma, subtração
 * e divisão em um objeto e atualizar seu estado diretamente, ao mesmo tempo que retornam o
 * próprio objeto para permitir encadeamento de operações.
 *
 * Exemplo:
 *
 * // Definindo um objeto
 * Distancia d1(100); // Distância inicial de 100 metros
 * d1 *= 2;  // Multiplica a distância por 2 (agora 200 metros)
 * d1 += 50; // Adiciona 50 metros (agora 250 metros)
 *
 * Isso é equivalente a:
 * d1 = d1 * 2;  // Multiplica e atribui o resultado
 * d1 = d1 + 50; // Adiciona 50 e atribui o resultado
 *
 * A vantagem do operador abreviado é que ele facilita a leitura e torna o código mais conciso.
 *
 * Os operadores abreviados podem ser sobrecarregados para modificar diretamente
 * o estado do objeto e realizar a operação desejada. Além disso, eles retornam o
 * próprio objeto, o que possibilita encadear várias operações em uma única linha.
 *
 * Exemplo de sobrecarga de `operator*=` e `operator/=`:
 *
 * - `operator*=`: Multiplica o valor atual do objeto por um fator e retorna o objeto atualizado.
 * - `operator/=`: Divide o valor atual do objeto por um fator e retorna o objeto atualizado.
 *
 * Caso você sobrecarregue um operador abreviado, você pode controlar a lógica da operação
 * e tornar o comportamento do objeto mais intuitivo em contextos específicos.
 *
 * Quando usar:
 * - Quando você deseja modificar diretamente o estado de um objeto usando operações como
 *   soma, subtração, multiplicação ou divisão.
 * - Quando você deseja simplificar o código e permitir a operação encadeada de forma concisa.
 * - Quando a lógica de alteração do estado do objeto pode ser expressa de maneira mais
 *   natural com um operador abreviado.
 *
 * Ao sobrecarregar operadores abreviados, lembre-se de garantir que o comportamento
 * da operação seja claro e fácil de entender para quem lê o código.
 */

class Distancia
{
private:
    double metros; // Armazena a distância em metros

public:
    // Construtor para inicializar a distância em metros
    Distancia(double m = 0) : metros(m) {}

    // Sobrecarga do operador *= para multiplicar a distância por um fator
    Distancia &operator*=(double fator)
    {
        metros *= fator;
        return *this; // Retorna o objeto atualizado
    }

    // Sobrecarga do operador /= para dividir a distância por um fator
    Distancia &operator/=(double fator)
    {
        if (fator == 0)
        {
            throw std::invalid_argument("Não é possível dividir por zero.");
        }
        metros /= fator;
        return *this; // Retorna o objeto atualizado
    }

    // Função para exibir a distância em metros
    void imprimir() const
    {
        std::cout << metros << " metros" << '\n';
    }

    // Função para obter a distância em metros
    double getDistancia() const
    {
        return metros;
    }
};

int main(int argc, char **argv)
{
    try
    {
        std::unique_ptr<Distancia> distancia = std::make_unique<Distancia>(200);

        std::cout << "Distância original: ";
        distancia->imprimir();

        // Multiplicando a distância por 2 para simular uma conversão (por exemplo, metros para centímetros)
        *distancia *= 2;
        std::cout << "Após multiplicar por 2: ";
        distancia->imprimir(); // Resultado: 200 metros

        // Dividindo a distância por 2 para simular uma conversão inversa
        *distancia /= 2;
        std::cout << "Após dividir por 2: ";
        distancia->imprimir(); // Resultado: 100 metros

        // Dividindo a distância por 10 para simular uma conversão para quilômetros
        *distancia /= 1000;
        std::cout << "Após dividir por 1000 (para km): ";
        distancia->imprimir(); // Resultado: 0.1 metros (ou 10 centímetros)
    }
    catch (const std::exception &e)
    {
        std::cout << "Erro: " << e.what() << '\n';
    }

    return 0;
}
