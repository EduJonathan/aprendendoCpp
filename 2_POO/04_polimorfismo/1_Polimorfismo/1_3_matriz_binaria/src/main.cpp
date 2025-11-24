#include "../class/class_decimal.hpp"
#include "../class/class_hexadecimal.hpp"
#include "../class/class_octal.hpp"
#include "../class/class_matriz.hpp"
#include <memory>
#include <vector>
#include <iostream>

int main(int argc, char **argv)
{
    Matriz matriz;

    // Vetor de smart pointers → memória automática e segura!
    std::vector<std::unique_ptr<Valor>> valores;

    // Usando make_unique
    valores.push_back(std::make_unique<Decimal>(170));      // 10101010
    valores.push_back(std::make_unique<Hexadecimal>(0xA5)); // 10100101
    valores.push_back(std::make_unique<Octal>(0377));       // 11111111

    std::cout << "=== DEMONSTRAÇÃO DE POLIMORFISMO COM SMART POINTERS ===\n\n";
    std::cout << "Matriz inicial (zeros):\n";
    matriz.exibirMatriz();

    std::cout << "=== ATUALIZANDO LINHAS (sem repetição) ===\n";
    for (const auto &valor : valores)
    {
        matriz.atualizarLinhaAleatoria(valor);
    }
    std::cout << '\n';

    std::cout << "=== MATRIZ FINAL ===\n";
    matriz.exibirMatriz();

    // NENHUM delete necessário → unique_ptr libera tudo automaticamente!

    /**
     * Compile e Execute com
     *
     * g++ -std=c++20 .\decimal.cpp .\hexadecimal.cpp .\main.cpp .\matriz.cpp .\octal.cpp -o matriz
     * .\matriz.exe
     */

    return 0;
}
