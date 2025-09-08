#include <iostream>

class Contador
{
private:
    static int total; // Contador de todas as instâncias
    int id;           // Identificador único

public:
    // Construtor
    Contador()
    {
        total++;
        id = total;
        std::cout << "Objeto Contador criado. ID: " << id << " (Total: " << total << ")\n";
    }

    // Destrutor
    ~Contador()
    {
        std::cout << "Objeto Contador destruído. ID: " << id << " (Restam: " << (total - 1) << ")\n";
        total--;
    }

    // Método para mostrar o ID
    void mostrar(void) const
    {
        std::cout << "Eu sou o Contador ID: " << id << '\n';
    }
};

// Inicializa o membro estático
int Contador::total = 0;

// Função auxiliar
void testeEscopo(void)
{
    std::cout << "\n--- Início de testeEscopo() ---\n";
    Contador c3;
    c3.mostrar();
    std::cout << "\n--- Fim de testeEscopo() ---\n";
} // Destrutor chamado aqui para c3

int main(int argc, char **argv)
{
    std::cout << "=== Programa iniciado ===\n";

    // Objetos criados diretamente no main
    Contador c1;
    c1.mostrar();

    Contador c2;
    c2.mostrar();

    testeEscopo(); // c3 vive apenas dentro da função

    std::cout << "\n=== Programa finalizando ===\n";
    return 0;
}
