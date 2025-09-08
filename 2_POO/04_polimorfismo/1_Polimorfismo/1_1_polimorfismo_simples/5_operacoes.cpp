#include <iostream>
#include <memory>

/**
 * @brief Classe base abstrata para operações matemáticas.
 */
class Operacao
{
public:
    /**
     * @brief Método puro virtual para calcular a operação.
     *
     * @param num1 Primeiro número.
     * @param num2 Segundo número.
     * @return Resultado da operação.
     */
    virtual double calcular_operacao(double num1, double num2) = 0;

    /// @brief Destrutor virtual.
    virtual ~Operacao() = default;
};

/**
 * @brief Classe que representa a operação de soma.
 */
class Soma : public Operacao
{
public:
    double calcular_operacao(double num1, double num2) override
    {
        return num1 + num2;
    }
};

/**
 * @brief Classe que representa a operação de subtração.
 */
class Subtracao : public Operacao
{
public:
    double calcular_operacao(double num1, double num2) override
    {
        return num1 - num2;
    }
};

/**
 * @brief Classe que representa a operação de multiplicação.
 */
class Multiplicar : public Operacao
{
public:
    double calcular_operacao(double num1, double num2) override
    {
        return num1 * num2;
    }
};

/**
 * @brief Classe que representa a operação de divisão.
 *
 * Retorna 0 se a divisão for por zero.
 */
class Dividir : public Operacao
{
public:
    double calcular_operacao(double num1, double num2) override
    {
        return num2 != 0 ? num1 / num2 : 0;
    }
};

/**
 * @brief Classe que representa a operação de módulo.
 *
 * Retorna 0 se o divisor for zero.
 * Realiza cast para int.
 */
class Modulo : public Operacao
{
public:
    double calcular_operacao(double num1, double num2) override
    {
        return num2 != 0 ? static_cast<int>(num1) % static_cast<int>(num2) : 0;
    }
};

int main(int argc, char **argv)
{
    const char *nomesOperacoes[] = {"Soma", "Subtração", "Multiplicação", "Divisão", "Módulo"};
    std::unique_ptr<Operacao> operacaoSmart[5];

    operacaoSmart[0] = std::make_unique<Soma>();
    operacaoSmart[1] = std::make_unique<Subtracao>();
    operacaoSmart[2] = std::make_unique<Multiplicar>();
    operacaoSmart[3] = std::make_unique<Dividir>();
    operacaoSmart[4] = std::make_unique<Modulo>();

    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Resultado da " << nomesOperacoes[i] << ": "
                  << operacaoSmart[i]->calcular_operacao(10.0, 5.0) << '\n';
    }

    return 0;
}
