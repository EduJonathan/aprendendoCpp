#include <iostream>
#include <memory>

/**
 * Em C++, no contexto de smart pointers, semântica refere-se ao comportamento
 * e às regras de propriedade que determinam como o ponteiro inteligente gerencia
 * o ciclo de vida do recurso (memória, arquivo, etc.).
 *
 * Em resumo: A "semântica" define as regras do jogo de como cada smart pointer se comporta
 * em relação à propriedade, cópia e gerenciamento do ciclo de vida dos recursos.
 */

class Recurso
{
public:
    Recurso() { std::cout << "Recurso criado\n"; }
    ~Recurso() { std::cout << "Recurso destruído\n"; }
    void usar() { std::cout << "Usando recurso\n"; }
};

void demonstraSemantica(void)
{
    // SEMÂNTICA DE UNIQUE_PTR
    {
        std::unique_ptr<Recurso> único = std::make_unique<Recurso>();
        único->usar();
        // Posse exclusiva - só este ponteiro gerencia o recurso
    } // Recurso destruído aqui

    // SEMÂNTICA DE SHARED_PTR
    {
        std::shared_ptr<Recurso> dono1 = std::make_shared<Recurso>();
        {
            std::shared_ptr<Recurso> dono2 = dono1; // Posse compartilhada
            std::cout << "Contagem de referências: " << dono1.use_count() << '\n';
        } // dono2 destruído, mas recurso permanece
        // Recurso só destruído quando dono1 sair do escopo
    }

    // SEMÂNTICA DE WEAK_PTR
    {
        std::shared_ptr<Recurso> shared = std::make_shared<Recurso>();
        std::weak_ptr<Recurso> observador = shared;

        std::cout << "Contagem shared: " << shared.use_count() << '\n'; // 1

        if (auto acesso = observador.lock())
        {
            acesso->usar(); // Acesso temporário
        }
    } // Recurso destruído aqui
}

int main(int argc, char **argv)
{
    demonstraSemantica();
    return 0;
}
