#include <iostream>
#include <new>
#include <memory>

/**
 * A sobrecarga do operador `operator()` permite que um objeto seja tratado como se fosse
 * uma função. Isso é útil quando você quer que um objeto execute uma tarefa ou operação quando
 * chamado com parênteses. Em vez de invocar um método diretamente, você pode "chamar" o objeto
 * como se fosse uma função.
 *
 * Exemplo:
 *
 * // Definindo um functor
 * Functor f;
 * f();  // Chama o operador `operator()`, como se fosse uma função
 *
 * Isso é equivalente a chamar uma função, mas usando a instância de um objeto.
 *
 * O operador `operator()` pode ser sobrecarregado para fornecer funcionalidades específicas.
 *
 * Por exemplo:
 *
 * - Quando você quer que um objeto se comporte como uma função.
 * - Quando você deseja criar um objeto que pode ser chamado repetidamente com diferentes argumentos,
 * como se fosse uma função com estado.
 *
 * Caso você sobrecarregue o `operator()`, você poderá definir a lógica que será executada
 * quando o objeto for chamado com `()` e, se necessário, pode também passar parâmetros.
 *
 * Quando usar:
 * - Quando você quer que um objeto se comporte como uma função.
 * - Quando precisa de um objeto que tenha estado, mas que ainda assim possa ser chamado como uma função.
 * - Para definir comportamento customizado em algoritmos ou callbacks.
 */

class Funcao
{
public:
    int operator()(int x)
    {
        return x * x;
    }
};

// Functor com parâmetros
class Adder
{
private:
    int valor;

public:
    Adder(int v) : valor(v) {}

    // Sobrecarga do operator() para somar um valor ao valor interno
    int operator()(int x) const
    {
        return valor + x;
    }
};

template <typename T>
class Multiplicador
{
private:
    static int fator;

public:
    Multiplicador(int f) : fator(f) {}

    // Sobrecarga do operator() para multiplicar o parâmetro pelo fator
    int operator()(int x) const
    {
        return x * fator;
    }
};

int main(int argc, char **argv)
{
    Funcao *function = new Funcao();
    std::cout << "Resultado: " << (*function)(5) << '\n';

    Adder soma(10);               // Cria o functor com valor inicial 10
    std::cout << soma(5) << '\n'; // Chama o operador, soma 10 + 5, imprime 15

    using MultiplicadorInt = Multiplicador<int>;
    std::unique_ptr<MultiplicadorInt> mult = std::make_unique<MultiplicadorInt>(3); // Cria o functor com fator 3

    std::cout << (*mult)(5) << '\n'; // Chama o operador, imprime 15

    return 0;
}
