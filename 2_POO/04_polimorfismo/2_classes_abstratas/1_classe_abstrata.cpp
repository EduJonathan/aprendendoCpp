#include <iostream>
#include <new>
#include <memory>

/**
 * CLASSE ABSTRATA:
 * - Define uma interface comum para um grupo de classes relacionadas.
 * - Contém pelo menos uma função `virtual pura (= 0)`(sua assinatura), que deve ser implementada pelas subclasses.
 * - Não pode ser instanciada diretamente.
 *
 * APLICAÇÃO:
 * - Usada para aplicar o princípio da abstração, ocultando detalhes internos e expondo apenas o necessário.
 * - Em C++, são criadas usando funções virtuais puras.
 * - C++ não possui a keyword `abstract` como Java, mas qualquer classe com pelo menos uma função virtual pura é abstrata.
 *
 * QUANDO USAR:
 * - Quando quiser forçar que subclasses implementem certos métodos.
 * - Quando deseja trabalhar com polimorfismo e reutilização de código base.
 * - Quando a classe base é genérica e não faz sentido instanciá-la diretamente (ex: Forma, Animal, Veículo).
 *
 * VANTAGENS:
 * - Promove reutilização e organização do código.
 * - Permite polimorfismo (uso de ponteiros/referências para a classe base).
 * - Separa interface da implementação.
 *
 * DESVANTAGENS:
 * - Pode aumentar a complexidade do projeto.
 * - Exige maior planejamento de hierarquia de classes.
 */

class FormaGeometrica
{
public:
    // Método virtual puro - torna a classe abstrata
    virtual double calcularArea() const = 0;

    // Método virtual com implementação padrão
    virtual void descrever() const
    {
        std::cout << "Esta é uma forma geométrica." << '\n';
    }

    // Método não-virtual
    void imprimirTipo() const
    {
        std::cout << "Tipo: Forma Geométrica" << '\n';
    }

    // Destrutor virtual (importante para classes base)
    virtual ~FormaGeometrica()
    {
        std::cout << "Descontruindo a forma geometrica" << '\n';
    }
};

class Retangulo : public FormaGeometrica
{
private:
    double largura;
    double altura;

public:
    Retangulo(double l, double a) : largura(l), altura(a) {}

    // Implementação do método virtual puro
    double calcularArea() const override
    {
        return largura * altura;
    }

    // Sobrescrevendo o método virtual (opcional)
    void descrever() const override
    {
        std::cout << "Este é um retângulo com área " << calcularArea() << '\n';
    }
};

class Circulo : public FormaGeometrica
{
private:
    double raio;

public:
    Circulo(double r) : raio(r) {}

    double calcularArea() const override
    {
        return 3.14159 * raio * raio;
    }
};

void imprimirArea(const FormaGeometrica &forma)
{
    std::cout << "Área: " << forma.calcularArea() << '\n';
}

int main(int argc, char **argv)
{
    // FormaGeometrica forma; // Erro! Não pode instanciar classe abstrata

    Retangulo ret(5.0, 3.0);
    Circulo circ(2.5);

    imprimirArea(ret);  // Área: 15
    imprimirArea(circ); // Área: 19.6349

    // Usando ponteiros para a classe base

    FormaGeometrica *forms[2];
    forms[0] = new Retangulo(4.0, 6.0);
    forms[1] = new Circulo(3.0);

    // Usando smart pointers para evitar vazamentos de memória
    std::unique_ptr<FormaGeometrica> formas[2];

    formas[0] = std::make_unique<Retangulo>(4.0, 6.0);
    formas[1] = std::make_unique<Circulo>(3.0);

    for (int i = 0; i < 2; ++i)
    {
        formas[i]->descrever();
        formas[i]->imprimirTipo(); // Chama o método não-virtual da classe base
        std::cout << "\nÁrea: " << formas[i]->calcularArea() << '\n';
    }
    return 0;
}
