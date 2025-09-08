#include <iostream>
#include <string>
#include <memory>

/**
 * Um namespace é um mecanismo para organizar código em escopos nomeados, agrupando
 * identificadores (como funções, variáveis, classes, etc.) sob um nome comum.
 * Ele é usado principalmente para:
 *
 * - Evitar conflitos de nomes entre diferentes partes do código ou bibliotecas.
 * - Agrupar funcionalidades relacionadas para melhorar a modularidade e legibilidade.
 *
 * Uma classe é um tipo definido pelo usuário que encapsula dados (atributos)
 * e comportamentos (métodos) relacionados. Ela é usada para modelar objetos no
 * paradigma de programação orientada a objetos (POO).
 *
 * Seu propósito é o encapsulamento, abstração, herança e polimorfismo em POO.
 */

namespace utilitarios
{
    void log(std::string msg)
    {
        std::cout << "Log: " << msg << '\n';
    }

    class Contador
    {
        int valor;

    public:
        Contador(int v) : valor(v) {}

        void incrementar()
        {
            valor++;
        }

        int getValor()
        {
            return valor;
        }
    };
}

int main(int argc, char **argv)
{
    utilitarios::log("Iniciando programa"); // Usa função do namespace

    using Contador = utilitarios::Contador;
    std::unique_ptr<Contador> contador = std::make_unique<Contador>(5); // Instancia classe do namespace
    contador->incrementar();

    std::cout << "Valor: " << contador->getValor() << '\n';

    utilitarios::log("Finalizando programa");
    return 0;
}
