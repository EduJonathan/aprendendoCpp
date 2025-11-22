#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

/**
 * std::function<_Signature>:
 * --------------------------
 * Classe template que pode **armazenar, copiar e invocar** qualquer entidade
 * chamável compatível com uma determinada assinatura:
 * funções normais, lambdas, ponteiros para funções ou objetos funcionais
 * (functors).
 *
 * É especialmente útil para:
 *  - Passar funções como argumentos para outras funções ou algoritmos.
 *  - Guardar callbacks ou manipuladores de eventos.
 *  - Criar interfaces genéricas que aceitam diferentes tipos de funções.
 *
 * Exemplo:
 *   std::function<int(int, int)> soma = [](int a, int b){ return a + b; };
 *   std::cout << soma(2, 3); // saída: 5
 *
 * Em resumo: `std::function` fornece **flexibilidade e generalidade** no uso
 * de funções, lambdas e objetos funcionais, permitindo programação funcional
 * em C++ moderno.
 */

void sayHello()
{
    std::cout << "Olá, mundo!" << '\n';
}

inline float mult(float a, float b)
{
    return a * b;
}

// Função com retorno auto (dedução de tipo)
// Armazena 10 números, calcula a média, e retorna apenas os acima da média
std::function<std::vector<int>()> numerosAcimaDaMedia = []()
{
    std::vector<int> numeros = {10, 20, 30, 25, 15, 40, 35, 5, 50, 45};

    float soma = std::accumulate(numeros.begin(), numeros.end(), 0);
    float media = soma / numeros.size();

    std::vector<int> acimaDaMedia;
    for (int n : numeros)
    {
        if (n > media)
            acimaDaMedia.push_back(n);
    }

    std::cout << "Média: " << media << '\n';
    return acimaDaMedia;
};

int main(int argc, char **argv)
{
    // Armazena a função sayHello
    std::function<void()> func = sayHello;
    func(); // Chama a função armazenada

    // Use lambda para passar os argumentos para mult
    std::function<float()> adicao = []()
    {
        return mult(4.0f, 5.0f);
    };
    std::cout << "Resultado da adição: " << adicao() << '\n';

    auto resultado_media_notas = numerosAcimaDaMedia();

    return 0;
}
