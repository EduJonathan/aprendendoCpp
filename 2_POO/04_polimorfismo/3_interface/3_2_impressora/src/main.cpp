#include "../class/classe_impressora.hpp"
#include "../class/classe_documento.hpp"
#include "../class/classe_foto.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    Impressora impressora(5);

    impressora.adicionarTrabalho(std::make_unique<Documento>("Relatorio anual", 3));
    impressora.adicionarTrabalho(std::make_unique<Foto>("4K"));
    impressora.adicionarTrabalho(std::make_unique<Documento>("Contrato longo", 4));

    while (!impressora.vazia())
    {
        if (!impressora.imprimirProximo())
        {
            std::cout << "Impressora parada aguardando papel...\n\n";

            // Simula usuario colocando papel
            impressora.adicionarPapel(10);
        }
    }

    std::cout << "Fila de impressao concluida.\n";

    /**
     * Compile e execute com:
     * g++ -std=c++17 documento.cpp foto.cpp impressora.cpp main.cpp -o nome_do_executavel
     * .\nome_do_executavel
     */
    return 0;
}
