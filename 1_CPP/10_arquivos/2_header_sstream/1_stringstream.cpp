#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cctype>
#include <sstream>

/**
 * classe std::stringstream: É a combinação das funcionalidades std::istringstream
 * e std::ostringstream permitindo tanto a leitura e escrita
 */

/**
 * @brief Função para verificar se uma string representa um número inteiro.
 *
 * Esta função percorre cada caractere da string e verifica se todos os caracteres
 * são dígitos. Se algum caractere não for dígito, a função retorna false.
 * Caso contrário, retorna true, indicando que a string é um número inteiro válido.
 *
 * @param string A string a ser verificada.
 * @return true se a string representa um número inteiro, false caso contrário.
 */
bool isInt(const std::string &string)
{
    for (const char &caracteres : string)
    {
        if (!isdigit(caracteres))
        {
            return false;
        }
    }
    return true;
}

/**
 * @brief Função para converter um valor inteiro para hexadecimal.
 *
 * Esta função recebe um valor inteiro e o converte para uma string no formato hexadecimal.
 * O valor hexadecimal é formatado com dois dígitos, preenchido com zero à esquerda,
 * se necessário.
 *
 * @param valor O valor inteiro a ser convertido.
 * @return A string representando o valor hexadecimal.
 */
std::string toHexadecimal(int valor)
{
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << std::hex << valor;
    return ss.str();
}

/**
 * @brief Função que exibe a cor no formato hexadecimal RGB.
 *
 * Esta função recebe três strings representando os valores de vermelho (R), verde (G)
 * e azul (B) e as converte para inteiros. Após a validação, os valores são limitados
 * ao intervalo [0, 255] e então convertidos para hexadecimal.
 * A cor no formato hexadecimal RGB é exibida na tela.
 *
 * @param r String representando o valor de vermelho (R) de 0 a 255.
 * @param g String representando o valor de verde (G) de 0 a 255.
 * @param b String representando o valor de azul (B) de 0 a 255.
 */
void displayHexColor(const std::string &r, const std::string &g, const std::string &b)
{
    int red = 0, green = 0, blue = 0;

    // Converter strings para inteiros, se necessário
    red = isInt(r) ? std::stoi(r) : 0;
    green = isInt(g) ? std::stoi(g) : 0;
    blue = isInt(b) ? std::stoi(b) : 0;

    // Validar os valores
    red = (red < 0) ? 0 : (red > 255) ? 255 : red;
    green = (green < 0) ? 0 : (green > 255) ? 255 : green;
    blue = (blue < 0) ? 0 : (blue > 255) ? 255 : blue;

    // Converter para hexadecimal
    std::string hexColor = '#' + toHexadecimal(red) + toHexadecimal(green) + toHexadecimal(blue);

    // Exibir a cor no formato hexadecimal RGB
    std::cout << "A cor em hexadecimal RGB é: " << hexColor << '\n';
}

int main(int argc, char **argv)
{
    std::string nome = "Cesár";
    int idade = 16;

    /* std::stringstream para criar uma string formatada */
    std::stringstream ss;

    ss << "Nome: " << nome << ' ' << "\tIdade: " << idade;
    std::string outputString = ss.str();
    std::cout << outputString << '\n';

    std::cout << "----------------------------------------\n";

    std::string r = "0",
                g = "0",
                b = "0";

    // Solicitar ao usuário os valores de R, G e B
    std::cout << "Digite o valor de R (0-255): ";
    std::cin >> r;

    std::cout << "Digite o valor de G (0-255): ";
    std::cin >> g;

    std::cout << "Digite o valor de B (0-255): ";
    std::cin >> b;

    displayHexColor(r, g, b); // Exibir a cor no formato hexadecimal RGB

    return 0;
}
