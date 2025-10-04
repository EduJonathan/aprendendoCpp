#include <iostream>
#include <cmath>
#include <new>

constexpr double PI = 3.14159265358979323846; // Definindo o valor de PI

// Classe base para formas geométricas
class FormaGeometrica
{
public:
    virtual double calcular_volume() const = 0;                                 // Método virtual puro
    virtual FormaGeometrica *operator+(const FormaGeometrica &outra) const = 0; // Sobrecarga do operador +
    virtual ~FormaGeometrica() {}                                               // Destruidor virtual
};

// Classe Cubo derivada de FormaGeometrica
class Cubo : public FormaGeometrica
{
public:
    Cubo(double comprimento, double altura, double largura) : comprimento(comprimento), altura(altura), largura(largura) {}

    double calcular_volume() const override
    {
        return comprimento * altura * largura;
    }

    FormaGeometrica *operator+(const FormaGeometrica &outra) const override
    {
        // Soma somente se for outro Cubo
        const Cubo *outro_cubo = dynamic_cast<const Cubo *>(&outra);
        if (outro_cubo)
        {
            return new Cubo(this->comprimento + outro_cubo->comprimento,
                            this->altura + outro_cubo->altura,
                            this->largura + outro_cubo->largura);
        }

        // Se não for Cubo, retorna nullptr
        std::cout << "Não é possível somar Cubo com outra forma geométrica!" << '\n';
        return nullptr;
    }

private:
    double comprimento, altura, largura;
};

// Classe Cilindro derivada de FormaGeometrica
class Cilindro : public FormaGeometrica
{
public:
    Cilindro(double raio, double altura) : raio(raio), altura(altura) {}

    double calcular_volume() const override
    {
        return PI * raio * raio * altura;
    }

    FormaGeometrica *operator+(const FormaGeometrica &outra) const override
    {
        // Soma somente se for outro Cilindro
        const Cilindro *outro_cilindro = dynamic_cast<const Cilindro *>(&outra);
        if (outro_cilindro)
        {
            return new Cilindro(this->raio + outro_cilindro->raio,
                                this->altura + outro_cilindro->altura);
        }

        // Se não for Cilindro, retorna nullptr
        std::cout << "Não é possível somar Cilindro com outra forma geométrica!" << '\n';
        return nullptr;
    }

private:
    double raio, altura;
};

// Classe Esfera derivada de FormaGeometrica
class Esfera : public FormaGeometrica
{
public:
    Esfera(double raio) : raio(raio) {}

    double calcular_volume() const override
    {
        return (4.0 / 3.0) * PI * std::pow(raio, 3);
    }

    FormaGeometrica *operator+(const FormaGeometrica &outra) const override
    {
        // Soma somente se for outra Esfera
        const Esfera *outra_esfera = dynamic_cast<const Esfera *>(&outra);
        if (outra_esfera)
        {
            return new Esfera(this->raio + outra_esfera->raio);
        }
        
        // Se não for Esfera, retorna nullptr
        std::cout << "Não é possível somar Esfera com outra forma geométrica!" << '\n';
        return nullptr;
    }

private:
    double raio;
};

int main(int argc, char **argv)
{
    // Criando formas geométricas
    FormaGeometrica *cubo1 = new Cubo(3.0, 4.0, 5.0);
    FormaGeometrica *cubo2 = new Cubo(1.0, 2.0, 3.0);
    FormaGeometrica *cilindro = new Cilindro(3.0, 5.0);
    FormaGeometrica *esfera = new Esfera(3.0);

    // Somando volumes (somente cubo + cubo)
    FormaGeometrica *cubo_soma = *dynamic_cast<Cubo *>(cubo1) + *dynamic_cast<Cubo *>(cubo2);
    if (cubo_soma)
    {
        std::cout << "Volume do cubo somado: " << cubo_soma->calcular_volume() << '\n';
    }

    // Tentando somar cubo com cilindro
    FormaGeometrica *resultado = *dynamic_cast<Cubo *>(cubo1) + *dynamic_cast<Cilindro *>(cilindro);
    if (resultado)
    {
        std::cout << "Volume do cubo + cilindro: " << resultado->calcular_volume() << '\n';
    }
    else
    {
        std::cout << "Operação de soma inválida entre cubo e cilindro." << '\n';
    }

    // Liberando a memória
    delete cubo1;
    delete cubo2;
    delete cilindro;
    delete esfera;
    delete cubo_soma;
    delete resultado;

    return 0;
}
