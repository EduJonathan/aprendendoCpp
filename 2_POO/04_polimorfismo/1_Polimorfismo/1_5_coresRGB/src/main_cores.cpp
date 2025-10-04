#include "../class/classRgb.hpp"
#include "../class/classHexadecimal.hpp"
#include <iostream>
#include <new>
#include <memory>

/**
 * @brief Função polimórfica que exibe uma cor.
 *
 * @param cor Ponteiro para objeto do tipo Cor.
 */
void mostrarCor(const Cor *cor)
{
    cor->exibir();
}

int main(int argc, char **argv)
{
    Cor *corVerdeFlorestaRGB = new RGB(34, 139, 34);      // verde floresta
    Cor *corVerdeFlorestaHex = new Hexadecimal("228B22"); // verde floresta em hex

    mostrarCor(corVerdeFlorestaRGB);
    mostrarCor(corVerdeFlorestaHex);

    delete corVerdeFlorestaRGB;
    delete corVerdeFlorestaHex;

    std::cout << '\n';

    // Usando smart pointers (unique_ptr) para criar objetos de cor
    std::unique_ptr<Cor> corVermelhaRGB = std::make_unique<RGB>(255, 0, 0);

    // Cor vermelha em Hexadecimal (sem o '#')
    std::unique_ptr<Cor> corVermelhaHEX = std::make_unique<Hexadecimal>("FF0000");

    mostrarCor(corVermelhaRGB.get()); // Exibe a cor RGB
    mostrarCor(corVermelhaHEX.get()); // Exibe a cor Hexadecimal

    /**
     * Compilação recomendada (execute no terminal a partir da raiz do projeto)
     * esta compilação assume que você está na pasta src e que a pasta class está no mesmo nível:
     *
     * C:\Users\maquina\Documents\aprendendoCpp\POO\04_polimorfismo\1_Polimorfismo\03_coresRGB\src
     *
     * > g++ -std=c++17 -I../class main_cores.cpp rgb.cpp hexadecimal.cpp -o main.exe
     *
     * OU (recomendado, a partir da raiz do projeto com caminhos corretos):
     *
     * > g++ -std=c++17 -Iclass coresMain.cpp rgb.cpp hexadecimal.cpp -o main.exe
     */

    return 0;
}
