#include <iostream>
#include <iomanip> // Biblioteca para controle de formato de saída de dados
#include <bitset>  // Biblioteca para conversão e exibição em binário
#include <cstdint> // Biblioteca para tipos de dados inteiros com tamanho fixo (Relacionado ao stdint.h ou inttypes.h do C)

/**
 * Este código demonstra como formatar saídas em C++ utilizando as bibliotecas
 * <iomanip>, <bitset> e <cstdint>.
 *
 * ------------------------------------------------------------------------------------
 * BIBLIOTECA <iomanip> — Manipulação de Formatação de Saída:
 *
 * - std::hex → Exibe valores inteiros no formato hexadecimal.
 * - std::oct → Exibe valores inteiros no formato octal.
 * - std::dec → Retorna à exibição no formato decimal (padrão).
 * - std::showbase → Adiciona prefixo: "0x" para hex e "0" para octal.
 * - std::setw(n) → Define a largura mínima do campo de saída como 'n' caracteres.
 * - std::setfill(c) → Define o caractere 'c' como preenchimento para campos menores.
 * - std::fixed → Exibe números de ponto flutuante com casas decimais fixas.
 * - std::setprecision(n) → Define o número de casas decimais ou dígitos significativos.
 * - std::scientific → Exibe números de ponto flutuante em notação científica.
 *
 * ------------------------------------------------------------------------------------
 * BIBLIOTECA <bitset> — Representação Binária:
 *
 * - std::bitset<N>(valor) → Converte e exibe o número em binário com N bits.
 *
 * ------------------------------------------------------------------------------------
 * BIBLIOTECA <cstdint> — Tipos Inteiros com Tamanhos Fixos:
 *
 * - reinterpret_cast<std::uintptr_t>(ptr)
 * → Converte um ponteiro para um inteiro sem sinal com o mesmo tamanho do ponteiro,
 * de forma segura e portável (ideal para exibir endereços de memória em formato numérico).
 */

int main(int argc, char **argv)
{
    // 1. FORMATAÇÃO BINÁRIA
    std::cout << "\n------------------------------------------------\n";
    std::cout << "\tFormatação de Saída Binária\n";
    std::cout << "--------------------------------------------------\n";

    int binario = 42;

    std::cout << "Decimal: " << binario << '\n';
    std::cout << "Binário (32 bits): " << std::bitset<32>(binario) << '\n';
    std::cout << "Binário com prefixo: 0b" << std::bitset<8>(binario) << '\n';
    std::cout << "Binário formatado: " << std::setw(16) << std::setfill('0')
              << "0b" << std::bitset<8>(binario) << '\n';

    // Retornando ao valor original da variável binario, exibindo em formato decimal
    std::cout << "Valor original em decimal: " << std::dec << binario << '\n';

    // 2. FORMATAÇÃO HEXADECIMAL
    std::cout << "\n------------------------------------------------\n";
    std::cout << "\tFormatação de Saída Hexadecimal\n";
    std::cout << "--------------------------------------------------\n";

    int Hexadecimal = 255;

    std::cout << "Decimal: " << Hexadecimal << '\n';
    std::cout << "Hexadecimal: " << std::hex << Hexadecimal << '\n';
    std::cout << "Hexadecimal com 0x: " << std::showbase << Hexadecimal << '\n';
    std::cout << "Hexadecimal formatado: " << std::setw(8) << std::setfill('0') << Hexadecimal << '\n';

    // Retornando ao valor original da variável binario, exibindo em formato decimal
    std::cout << "Valor original em hexadecimal: " << std::dec << Hexadecimal << '\n';

    // 3. FORMATAÇÃO OCTAL
    std::cout << "\n------------------------------------------------\n";
    std::cout << "\tFormatação de Saída Octal\n";
    std::cout << "--------------------------------------------------\n";

    int Octal = 64;

    std::cout << "Decimal: " << std::dec << Octal << '\n';
    std::cout << "Octal: " << std::oct << Octal << '\n';
    std::cout << "Octal com 0: " << std::showbase << Octal << '\n';
    std::cout << "Octal formatado: " << std::setw(6) << std::setfill('0') << Octal << '\n';

    // Retornando ao valor original da variável Octal, exibindo em formato decimal
    std::cout << "Valor original em octal: " << std::dec << Octal << '\n';

    // 4. FORMATAÇÃO DE PONTEIROS
    std::cout << "\n------------------------------------------------\n";
    std::cout << "\tFormatação de Ponteiros\n";
    std::cout << "--------------------------------------------------\n";

    int num = 42;
    int *ptr = &num;

    std::cout << "Valor: " << std::dec << num << '\n';
    std::cout << "Endereço: " << std::showbase << std::hex
              << reinterpret_cast<std::uintptr_t>(ptr) << '\n';
    std::cout << "Endereço formatado: " << std::setw(10) << std::setfill('0')
              << reinterpret_cast<std::uintptr_t>(ptr) << '\n';

    // Retornando ao valor original da variável num, exibindo em formato decimal
    std::cout << "Valor original em decimal: " << std::dec << num << '\n';

    // 5. FORMATAÇÃO COM FLAGS
    std::cout << "\n------------------------------------------------\n";
    std::cout << "\tFormatação com Flags\n";
    std::cout << "--------------------------------------------------\n";

    std::cout << "Mostrar sinal (+): " << std::showpos << 100 << " | (-): " << -100 << '\n';
    std::cout << "Sem sinal: " << std::noshowpos << 100 << " | " << -100 << '\n';
    std::cout << "Hexadecimal maiúsculo: " << std::uppercase << std::hex << 255 << '\n';

    // 6. FORMATAÇÃO DE DECIMAIS
    std::cout << "\n------------------------------------------------\n";
    std::cout << "\tFormatação de Casas Decimais\n";
    std::cout << "--------------------------------------------------\n";

    double pi = 3.14159265358979;

    std::cout << "Padrão: " << pi << '\n';
    std::cout << "Fixed (4 casas): " << std::fixed << std::setprecision(4) << pi << '\n';
    std::cout << "Científico (2 casas): " << std::scientific << std::setprecision(2) << pi << '\n';
    std::cout << "Voltando ao padrão: " << std::defaultfloat << pi << '\n';
    return 0;
}
