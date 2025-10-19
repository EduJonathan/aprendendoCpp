#include <iostream>
#include <cmath>
#include <float.h>
#include <string>
#include <utility>
#include <vector>

class Public
{
public:
    unsigned age;
    float peso;
    float altura;
    std::string nome;

    // private:
    // void IMC() {}

public:
    /**
     * @brief Calcula o IMC (Índice de Massa Corporal) da pessoa.
     *
     * @return O valor do IMC.
     */
    float imc(void)
    {
        if (altura > 0.0f)
        {
            return peso / powf(altura, 2); // IMC = peso / altura^2
        }
        return 0.0f; // Return 0 se a altura for inválida
    }

    /**
     * @brief Retorna a classificação do IMC.
     *
     * @return Uma string com o status do IMC.
     */
    const std::string statusIMC(void)
    {
        static const std::vector<std::pair<float, std::string>> classificacoes = {
            {18.5f, "Abaixo do peso"},
            {24.9f, "Peso normal"},
            {29.9f, "Sobrepeso"},
            {34.9f, "Obesidade grau 1"},
            {39.9f, "Obesidade grau 2 (severa)"},
            {FLT_MAX, "Obesidade grau 3 (mórbida)"}};

        float valor_imc = imc();

        for (const auto &classificacao : classificacoes)
        {
            if (valor_imc <= classificacao.first)
            {
                return classificacao.second;
            }
        }

        return "IMC inválido"; // Caso não corresponda a nenhum intervalo (imc < 0 ou sem altura)
    }
};

int main(int argc, char **argv)
{
    Public pessoa;

    pessoa.nome = "Eduardo";
    pessoa.age = 25;
    pessoa.altura = 1.73f;
    pessoa.peso = 73.40f;

    /* function "Public::IMC" (declared at line 12) is inaccessibleC/C++(265) */
    // pessoa.IMC();
    /**
     * Não é possível acessar com o objeto da classe, metódos e variáveis(atribudos)
     * `privados` na main somente dentro da classe.
     */

    std::cout << "Nome: " << pessoa.nome << '\n';
    std::cout << "IMC: " << pessoa.imc() << '\n';
    std::cout << "Status IMC: " << pessoa.statusIMC() << '\n';
    return 0;
}
