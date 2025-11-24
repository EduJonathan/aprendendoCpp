#include <iostream>
#include <new>

/**
 * @class Altura
 * @brief Representa a altura de um objeto.
 *
 * Esta classe tem um atributo `altura` e um construtor para inicializar o valor da altura.
 */
class Altura
{
public:
    double altura; /**< Atributo que armazena a altura do objeto */

    /**
     * @brief Construtor que inicializa a altura do objeto.
     *
     * @param a Valor da altura a ser atribuído ao objeto.
     */
    Altura(double a);
};

/**
 * @class Comprimento
 * @brief Representa o comprimento de um objeto.
 *
 * Esta classe contém o atributo `comprimento` e um construtor para inicializar o comprimento.
 */
class Comprimento
{
public:
    double comprimento; /**< Atributo que armazena o comprimento do objeto */

    /**
     * @brief Construtor que inicializa o comprimento do objeto.
     *
     * @param c Valor do comprimento a ser atribuído ao objeto.
     */
    Comprimento(double c);
};

/**
 * @class Largura
 * @brief Representa a largura de um objeto.
 *
 * Esta classe herda de `Comprimento` e tem um atributo adicional `largura`.
 */
class Largura : public Comprimento
{
public:
    double largura; /**< Atributo que armazena a largura do objeto */

    /**
     * @brief Construtor que inicializa o comprimento e a largura do objeto.
     *
     * @param c Valor do comprimento.
     * @param l Valor da largura.
     */
    Largura(double c, double l);
};

/**
 * @class Result
 * @brief Classe responsável por calcular o volume do objeto.
 *
 * Esta classe herda de `Largura` e `Altura` e usa esses atributos para calcular
 * o resultado multiplicando comprimento, largura e altura.
 */
class Result : public Largura, public Altura
{
public:
    /**< Atributo que armazena o resultado da multiplicação do comprimento, largura e altura */
    double result;

    /**
     * @brief Construtor que inicializa o comprimento, largura e altura do objeto.
     *
     * @param c Valor do comprimento.
     * @param l Valor da largura.
     * @param a Valor da altura.
     */
    Result(double c, double l, double a);

    /**
     * @brief Método para calcular e exibir o resultado.
     *
     * Este método calcula o volume multiplicando as três dimensões
     * (comprimento, largura e altura) e exibe o resultado.
     */
    void getResultado();
};

Altura::Altura(double a) : altura(a) {}
Comprimento::Comprimento(double c) : comprimento(c) {}
Largura::Largura(double c, double l) : Comprimento(c), largura(l) {}
Result::Result(double c, double l, double a) : Largura(c, l), Altura(a) {}

void Result::getResultado()
{
    // Calcula o resultado multiplicando as três dimensões
    result = comprimento * largura * altura;
    std::cout << "\nResultado (Comprimento * Largura * Altura): " << result << '\n';
}

int main(int argc, char **argv)
{
    double comprimento = 0.0, largura = 0.0, altura = 0.0;

    // Solicita as dimensões do objeto ao usuário
    std::cout << "Qual o comprimento do objeto: ";
    std::cin >> comprimento;

    std::cout << "Digite a largura do objeto: ";
    std::cin >> largura;

    std::cout << "Qual a altura do objeto: ";
    std::cin >> altura;

    // Cria uma instância da classe Result usando os valores fornecidos
    Result *resultado = new Result(comprimento, largura, altura);

    // Chama o método para calcular e exibir o resultado
    resultado->getResultado();

    // Libera a memória alocada
    delete resultado;
    return 0;
}
