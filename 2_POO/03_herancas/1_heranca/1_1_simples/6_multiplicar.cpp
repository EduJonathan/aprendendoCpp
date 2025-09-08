#include <iostream>
#include <memory>

/**
 * @brief Classe base que contém dois atributos inteiros e métodos
 * para manipulação e exibição desses atributos.
 */
class Base
{
protected:
    int valor1; ///< Primeiro valor inteiro.
    int valor2; ///< Segundo valor inteiro.

public:
    /**
     * @brief Construtor da classe base.
     *
     * @param v1 Valor a ser atribuído ao primeiro atributo.
     * @param v2 Valor a ser atribuído ao segundo atributo.
     */
    Base(int v1 = 0, int v2 = 0);

    /**
     * @brief Exibe os valores dos atributos da classe base.
     */
    void imprimir(void) const;
};

/**
 * @brief Classe derivada que herda da classe base e adiciona um novo atributo.
 */
class Derivado : protected Base
{
private:
    int resultado; ///< Resultado do cálculo com valor1 e valor2.

public:
    /**
     * @brief Construtor da classe derivada.
     *
     * @param v1 Valor a ser atribuído ao valor1 da classe base.
     * @param v2 Valor a ser atribuído ao valor2 da classe base.
     */
    Derivado(int v1, int v2);

    /**
     * @brief Exibe o resultado e os valores herdados da classe base.
     */
    void imprimir(void) const;
};

Base::Base(int v1, int v2) : valor1(v1), valor2(v2) {}
Derivado::Derivado(int v1, int v2) : Base(v1, v2) { resultado = valor1 * valor2; }

void Base::imprimir(void) const
{
    std::cout << "valor1 = " << valor1 << '\n';
    std::cout << "valor2 = " << valor2 << '\n';
}

void Derivado::imprimir(void) const
{
    std::cout << "\nresultado = " << resultado << '\n';
    Base::imprimir();
}

int main(int argc, char **argv)
{
    // Cria um objeto da classe derivada e inicializa com valor1 = 1 e valor2 = 2.
    // Cria um ponteiro inteligente para um objeto da classe Derivado
    std::unique_ptr<Derivado> classeDerivada = std::make_unique<Derivado>(1, 2);

    // Chama o método imprimir através do ponteiro
    classeDerivada->imprimir();

    std::unique_ptr<Derivado> classeDerivada2 = std::make_unique<Derivado>(5, 5);
    classeDerivada2->imprimir();
    return 0;
}
