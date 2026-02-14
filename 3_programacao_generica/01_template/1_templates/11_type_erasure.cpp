#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <functional>

/**
 * type erasure?
 *
 * Type erasure é uma técnica que permite esconder os detalhes concretos de um tipo atrás de uma interface comum,
 * sem perder desempenho e mantendo polimorfismo em tempo de execução, mas sem usar herança/virtual necessariamente.
 * Em outras palavras:
 *
 * - Você tem vários tipos diferentes (ex: int, string, Vetor, MinhaClasseCustom).
 * - Todos eles satisfazem uma mesma "ideia" (ex: podem ser impressos, ou somados, ou iterados).
 * - Você quer tratar todos eles de forma uniforme (ex: colocar numa lista heterogênea).
 * - Mas não quer pagar o custo de herança/virtual nem perder performance.
 *
 * → A solução é "apagar" o tipo concreto e guardar só uma interface genérica.
 *
 * ---------
 *
 * Exemplos:
 *
 * std::function<int(int)>
 *
 * - Pode guardar: função normal, lambda, functor, função membro + bind
 * - Todos têm tipos diferentes, mas std::function "apaga" o tipo real e oferece uma interface comum: operator()
 * - Internamente usa um pequeno heap allocation + vtable (parecido com virtual, mas manual)
 *
 * std::any
 * - Guarda qualquer tipo copiável
 * - "Apaga" completamente o tipo → você recupera com any_cast
 */

// Função que aceita qualquer callable que receba um int e retorne um int
void aplicarEImprimir(const std::function<int(int)> &func, int valor)
{
    int resultado = func(valor);
    std::cout << "Resultado: " << resultado << '\n';
}

template <typename Callable>
void aplicarEImprimirTemplate(const Callable &func, int valor)
{
    int resultado = func(valor);
    std::cout << "Resultado (template): " << resultado << '\n';
}

int main(int argc, char **argv)
{
    // Lambda
    auto lambda = [](int x)
    {
        return x * x;
    };
    aplicarEImprimir(lambda, 5); // Resultado: 25

    // Função normal
    auto funcaoNormal = [](int x)
    {
        return x + 10;
    };
    aplicarEImprimir(funcaoNormal, 5); // Resultado: 15

    // Functor (objeto com operator())
    struct Multiplicador
    {
        int fator;
        Multiplicador(int f) : fator(f) {}
        int operator()(int x) const { return x * fator; }
    };
    Multiplicador mult3(3);
    aplicarEImprimir(mult3, 5); // Resultado: 15

    // Usando template (sem type erasure)
    aplicarEImprimirTemplate(lambda, 6);       // Resultado (template): 36
    aplicarEImprimirTemplate(funcaoNormal, 6); // Resultado (template): 16
    aplicarEImprimirTemplate(mult3, 6);        // Resultado (template): 18

    return 0;
}
