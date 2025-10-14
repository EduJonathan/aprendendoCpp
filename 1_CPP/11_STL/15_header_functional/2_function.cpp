#include <iostream>
#include <functional>
#include <vector>
#include <numeric>

/*
 * std::function<class _Fp>: Classe que armazena funções, lambdas ou objetos funcionais.
 * É útil para passar funções como argumentos e para permitir maior flexibilidade na
 * programação funcional e otimizações.
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
