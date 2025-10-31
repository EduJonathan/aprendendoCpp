#include <iostream>

class Animal
{
public:
    virtual void fazerSom(void) = 0;
    virtual ~Animal() = default;
};

class Cachorro : public Animal
{
public:
    void fazerSom(void) override
    {
        std::cout << "Au au!\n";
    }
};

/**
 * POLIMORFISMO: `Poli` significa (muitos) e `morfo` significa (formas), então temos
 * a possibilidade de um objeto assumir diversas formas diferentes na orientação a
 * objetos.
 *
 * - EXEMPLOS:
 * - Como podemos escrever? temos várias formas, como (`caneta`, `lápis`).
 * - Como podemos pagar um produto? temos várias formas de pagamento, como (`cartão`, `dinheiro`, `pix`, etc.).
 * - Como podemos nos locomover? temos várias formas, como (`carro`, `moto`, `bicicleta`, `a pé`, etc.).
 * - Como podemos nos comunicar? temos várias formas, como (`falar`, ligação`, `email`, `mensagem de texto`, etc.).
 *
 * Todas estas possibilidade de ações são abstratos ou seja suas formas de agir envolve diversas ações.
 * Então, polimorfismo permite que um objeto assuma várias formas, possibilitando tratar objetos
 * de diferentes classes de forma uniforme.
 *
 * ----------------------------------
 *
 * Em C++, O polimorfismo é habilitado com a keyword `virtual`.
 *
 * Funções virtuais: Permitem que métodos sejam sobrescritos em classes derivadas
 * e invocados corretamente com base no tipo real do objeto (mesmo via ponteiros
 * ou referências da classe base).
 *
 * POLIMORFISMO: Garante comportamento adequado conforme a classe real.
 * SOBRESCRITA: Permite redefinir métodos da classe base, fornecendo implementações específicas.
 * DESTRUTORES VIRTUAIS: Garante que o destrutor correto seja chamado ao deletar objetos via ponteiros da base.
 *
 * Prefira `virtual ~Classe() = default;` Se: está usando C++11 ou superior, Não precisa
 * de lógica no destrutor e deseja beneficiar-se de possíveis otimizações.
 *
 * Use `virtual ~Classe() {}` se: Você pretende adicionar lógica de destruição futuramente.
 * Está usando uma versão de C++ mais antiga, Por preferência de estilo.
 */

int main(int argc, char **argv)
{
    /// ERROR: Animal animal; Animal é uma classe abstrata e não pode ser instanciada
    Cachorro cachorro;
    cachorro.fazerSom(); // Saída: Au au!

    return 0;
}
