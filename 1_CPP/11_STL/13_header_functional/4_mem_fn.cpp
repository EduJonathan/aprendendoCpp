#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <functional>

/**
 * std::mem_fn:
 * ------------
 * Função utilitária que cria um **functor** (objeto funcional) a partir de um
 * ponteiro para um método de classe, permitindo invocá-lo de forma genérica.
 *
 * Principais características:
 *  - Pode ser usado com métodos de instância ou métodos constantes.
 *  - Permite chamar o método em diferentes objetos sem precisar saber qual será
 *    usado no momento da criação do functor.
 *  - Facilita a integração com algoritmos STL e com `std::function`.
 *
 * Exemplo:
 *   #include <functional>
 *   #include <iostream>
 *
 *   struct Pessoa {
 *       void falar(const std::string& msg) const {
 *           std::cout << "Dizendo: " << msg << "\n";
 *       }
 *   };
 *
 *   int main() {
 *       auto func = std::mem_fn(&Pessoa::falar);
 *       Pessoa p;
 *       func(p, "Olá!");  // saída: Dizendo: Olá!
 *   }
 *
 * Explicação do exemplo:
 *  - `std::mem_fn` cria um functor que encapsula o método `falar`.
 *  - O functor pode ser chamado passando o objeto como primeiro argumento,
 *    seguido dos argumentos do método.
 *
 * Em resumo: `std::mem_fn` permite transformar **métodos de classe em funções
 * genéricas**, úteis para programação funcional e integração com algoritmos STL.
 */

// Definição de uma estrutura que contém um número e um método
// que calcula o valor elevado ao quadrado (valorElevado).
struct Struct
{
    double numero; // A variável membro 'numero' armazena um número

    // Método que retorna o número elevado ao quadrado
    inline double valorElevado() { return std::pow(numero, 2); }

    // Lambda para calcular a raiz quadrada usando std::function
    std::function<double(double)> raizQuadrada = [](double n)
    {
        return std::sqrt(n);
    };
};

// Função que recebe um vetor de strings e retorna um vetor com os comprimentos das strings
std::vector<int> calcularComprimentos(const std::vector<std::string> &strings)
{
    std::vector<int> lengths(strings.size()); // Vetor para armazenar os comprimentos

    // Utilizando std::transform para calcular os comprimentos das strings
    std::transform(strings.begin(), strings.end(), lengths.begin(), std::mem_fn(&std::string::length));

    return lengths;
}

int main(int argc, char **argv)
{
    // Criação de dois objetos do tipo Struct com valores diferentes para 'numero'
    Struct value{10}; // O valor de 'numero' é 10
    Struct value1{5}; // O valor de 'numero' é 5

    auto valorDobrado = std::mem_fn(&Struct::valorElevado);  // Função para 'valorElevado'
    auto valorDobrado1 = std::mem_fn(&Struct::valorElevado); // Outra instância para 'valorElevado'

    // Usamos as funções criadas com std::mem_fn para invocar 'valorElevado' em 'value' e 'value1'
    std::cout << valorDobrado(value) << '\n';   // Calcula 10^2 = 100
    std::cout << valorDobrado1(value1) << '\n'; // Calcula 5^2 = 25

    // Usando a lambda 'raizQuadrada' definida dentro de 'Struct'
    std::cout << "Raiz quadrada de 16 é " << value.raizQuadrada(16) << '\n'; // Calcula sqrt(16) = 4

    std::cout << "====================================================" << '\n';

    std::vector<std::string> numbers = {"one", "two", "three", "four", "five"};

    // Chamando a função para calcular os comprimentos
    std::vector<int> lengths = calcularComprimentos(numbers);

    // Imprimindo os resultados
    for (std::size_t i = 0ull; i < numbers.size(); ++i)
    {
        std::cout << numbers[i] << " tem " << lengths[i] << " letras.\n";
    }

    return 0;
}
