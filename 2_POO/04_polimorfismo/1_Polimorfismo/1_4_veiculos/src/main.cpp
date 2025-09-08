#include <iostream>
#include <vector>
#include <memory>
#include "../classes/classVeiculo.hpp"

// Veiculo *criarCarro();
// Veiculo *criarMoto();
// Veiculo *criarBarco();
// Veiculo *criarAviao();

std::unique_ptr<Veiculo> criarCarro();
std::unique_ptr<Veiculo> criarMoto();
std::unique_ptr<Veiculo> criarBarco();
std::unique_ptr<Veiculo> criarAviao();

void testarVeiculo(const Veiculo &v)
{
    v.mover();
    v.tipo();
}

void testarTodosOsVeiculos(const std::vector<std::unique_ptr<Veiculo>> &veiculos)
{
    for (const auto &v : veiculos)
    {
        testarVeiculo(*v);
        std::cout << '\n';
    }
}

int main(int argc, char **argv)
{
    std::vector<std::unique_ptr<Veiculo>> veiculos;

    // Usando unique_ptr para garantir gerenciamento automático
    veiculos.push_back(criarCarro());
    veiculos.push_back(criarMoto());
    veiculos.push_back(criarBarco());
    veiculos.push_back(criarAviao());

    std::cout << "=== Testando Todos os Veículos ===\n\n";
    testarTodosOsVeiculos(veiculos);

    /**
     * Compile e execute com:
     * C:\Users\maquina\Documents\aprendendoCpp\POO\04_polimorfismo\1_Polimorfismo\02_Veiculos\src"
     *
     * > g++ -std=c++17 main.cpp veiculo_carro.cpp veiculo_moto.cpp veiculo_barco.cpp veiculo_aviao.cpp -o veiculos
     * > .\veiculos.exe
     */
    return 0;
}
