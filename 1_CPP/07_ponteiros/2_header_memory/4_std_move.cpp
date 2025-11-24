#include <iostream>
#include <utility> // // Para std::move
#include <memory>

/**
 * `std::move` em smart pointers é usado para transferir a propriedade de
 * um recurso de um smart pointer para outro. Ele não move os dados em si, mas sim a posse do recurso.
 *
 * Resumo:
 *
 * - std::move não move dados, mas transfere propriedade.
 * - Necessário para unique_ptr (já que cópia é proibida).
 * - Opcional para shared_ptr (cópia é preferível para compartilhamento).
 * - O ponteiro origem torna-se nullptr após o move.
 * - Garante que sempre há apenas um dono (para unique_ptr).
 */

class Recurso
{
public:
    Recurso() { std::cout << "Recurso criado\n"; }
    ~Recurso() { std::cout << "Recurso destruído\n"; }
    void usar() { std::cout << "Usando recurso\n"; }
};

int main(int argc, char **argv)
{
    std::cout << "=== Início do exemplo ===\n";

    {
        auto ptr1 = std::make_unique<Recurso>();
        std::cout << "ptr1 possui recurso: " << (ptr1 != nullptr) << '\n';

        auto ptr2 = std::move(ptr1); // Transferência de posse
        std::cout << "ptr1 possui recurso: " << (ptr1 != nullptr) << '\n';
        std::cout << "ptr2 possui recurso: " << (ptr2 != nullptr) << '\n';

        ptr2->usar();
    } // Recurso destruído aqui

    std::cout << "=== Fim do exemplo ===\n";
    return 0;
}
