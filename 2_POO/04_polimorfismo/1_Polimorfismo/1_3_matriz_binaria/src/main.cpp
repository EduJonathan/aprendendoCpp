#include "../class/class_decimal.hpp"
#include "../class/class_hexadecimal.hpp"
#include "../class/class_octal.hpp"
#include "../class/class_matriz.hpp"
#include <iostream>
#include <ctime>

int main(int argc, char **argv)
{
    Matriz matriz;  // Criando a matriz 8x8
    srand(time(0)); // Inicializa o gerador de números aleatórios

    // Criando objetos para os três tipos de valores
    Valor *valorDecimal = new Decimal(10);           // Valor decimal 255
    Valor *valorHexadecimal = new Hexadecimal(0xA5); // Valor hexadecimal 0xA5
    Valor *valorOctal = new Octal(0233);             // Valor octal 0233

    // Exibindo a matriz inicial (toda com zeros)
    std::cout << "Matriz inicial (inicializadas com zeros):" << '\n';
    matriz.exibirMatriz();

    // Atualizando a matriz com valores binários dos objetos polimórficos
    matriz.atualizarLinhaComBinario(valorDecimal);     // Atualiza com o valor decimal
    matriz.atualizarLinhaComBinario(valorHexadecimal); // Atualiza com o valor hexadecimal
    matriz.atualizarLinhaComBinario(valorOctal);       // Atualiza com o valor octal

    // Exibindo a matriz após as atualizações
    std::cout << "\nMatriz atualizada:" << '\n';
    matriz.exibirMatriz();

    // Limpeza da memória
    delete valorDecimal;
    delete valorHexadecimal;
    delete valorOctal;

    /**
     * Compile e Execute com
     *
     * g++ -std=c++23 .\decimal.cpp .\hexadecimal.cpp .\main.cpp .\matriz.cpp .\octal.cpp -o matriz
     * .\matriz.exe
     */

    return 0;
}
