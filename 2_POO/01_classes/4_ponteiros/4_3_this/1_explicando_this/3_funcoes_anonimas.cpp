#include <iostream>
#include <functional>

/**
 * Como funções anônimas (lambdas) são funções que são especialmente úteis para criar
 * funções simples e temporárias sem a necessidade de declarar uma função tradicional,
 * em POO, elas podem capturar o ponteiro `this` de uma classe.
 *
 * Conceitos
 * Lambdas com captura de this: para acessar membros da instância da classe.
 * Passagem por referência em funções lambda: útil para modificar variáveis externas.
 * Uso de std::function para armazenar lambdas que podem ser chamadas mais tarde.
 * POO e lambdas funcionando juntos para lógica mais modular e reutilizável.
 */

class Contador
{
private:
    int incrementarValor;

public:
    Contador(int valor) : incrementarValor(valor) {}

    void incrementar(int &valor)
    {
        /**
         * A expressão lambda captura o ponteiro `this` para acessar o membro `incrementarValor`
         * da classe `Contador`. Isso permite que a lambda utilize o valor do incremento
         * definido na instância da classe.
         */
        auto funcaoIncrementar = [this](int &v)
        {
            v += this->incrementarValor;
            std::cout << "Valor Atual: " << v << '\n';
        };

        /** Chama a função lambda para incrementar o valor */
        funcaoIncrementar(valor);

        // Cria uma função que captura `this` e a armazena em uma variável
        std::function<void()> set_incrementar_valor = [this]()
        {
            incrementarValor++; // Acessa e modifica o membro da classe
            std::cout << "Valor Atual: " << incrementarValor << '\n';
        };

        set_incrementar_valor();
        set_incrementar_valor();
        set_incrementar_valor();
    }

    int get_value() const
    {
        return incrementarValor;
    }
};

int main(int argc, char **argv)
{
    Contador contador(5); // Cria um objeto Contador com valor de incremento 5
    int valor = 10;

    std::cout << "Valor Inicial: " << valor << '\n';
    contador.incrementar(valor); // Incrementa o valor usando a função lambda

    std::cout << "Valor Final do IncrementarValor: " << contador.get_value() << '\n';

    /**
     * Porque de [this]? entenda que esta expressão captura o ponteiro `this` da instância
     * da classe, permitindo que a função lambda acesse os membros e métodos da classe.
     * Sem o [this], a lambda não poderia modificar ou acessar `incrementarValor`,
     * resultado error. É uma maneira de encapsular a lógica que depende do estado do
     * objeto dentro da própria classe.
     */
    return 0;
}
