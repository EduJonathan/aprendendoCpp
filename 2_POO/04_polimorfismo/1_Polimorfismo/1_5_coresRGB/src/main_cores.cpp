#include "../class/classRgb.hpp"
#include "../class/classHexadecimal.hpp"
#include <iostream>
#include <memory>
#include <vector>

/**
 * @brief Função polimórfica que exibe uma cor.
 *
 * @param cor Ponteiro para objeto do tipo Cor.
 */
void mostrarCor(const Cor &cor)
{
    cor.exibir();
    std::cout << "   → comoString(): " << cor.comoString() << "\n\n";
}

int main(int argc, char **argv)
{
    auto corVerdeFlorestaRGB = new RGB(34, 139, 34);      // verde floresta
    auto corVerdeFlorestaHex = new Hexadecimal("228B22"); // verde floresta em hex
    auto VerdeFlorestaHex = new Hexadecimal("#228B22");   // verde floresta em hex
    auto cor = new Hexadecimal("ff0000");                 // Aceita minúsculas também!

    mostrarCor(*corVerdeFlorestaRGB);
    mostrarCor(*corVerdeFlorestaHex);
    mostrarCor(*VerdeFlorestaHex);
    mostrarCor(*cor);

    delete corVerdeFlorestaRGB;
    delete corVerdeFlorestaHex;
    delete VerdeFlorestaHex;
    delete cor;

    std::cout << '\n';

    std::vector<std::unique_ptr<Cor>> paleta;
    paleta.emplace_back(std::make_unique<RGB>(255, 215, 0));       // Ouro
    paleta.emplace_back(std::make_unique<Hexadecimal>("#4B0082")); // Índigo
    paleta.emplace_back(std::make_unique<RGB>(0, 255, 255));       // Ciano
    paleta.emplace_back(std::make_unique<Hexadecimal>("magenta"));

    std::cout << "Paleta de cores variada (container polimórfico):\n";
    for (const auto &cor : paleta)
    {
        mostrarCor(*cor);
    }
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
