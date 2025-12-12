#include <iostream>
#include <bitset>

/**
 * Os operadores bitwise utilizados para realizar operações com os bits(0 e 1)
 * do valor de que as variáveis armazenam, sendo eles:
 *
 * +---------------------+----------------------------+
 * | OPERADORES BITWISES | SHORTS OPERADORES BITWISES |
 * +---------------------+----------------------------+
 * | & (and)             | &= (and)                   |
 * +---------------------+----------------------------+
 * | | (or)              | |= (or)                    |
 * +---------------------+----------------------------+
 * | ^ (xor)             | ^= (xor)                   |
 * +---------------------+----------------------------+
 * | ~ (not)             | NÃO POSSUE                 |
 * +---------------------+----------------------------+
 * | << (shift left)     | <<= (shift left)           |
 * +---------------------+----------------------------+
 * | >> (shift right)    | >>= (shift right)          |
 * +---------------------+----------------------------+
 *
 * -----------------
 *
 * `&`(AND bitwise): Compara os bits correspondentes de dois números.
 *                   O resultado será 1 apenas se ambos os bits forem 1.
 *
 * `|` (OR bitwise): Compara os bits correspondentes de dois números.
 *                   O resultado será 1 se pelo menos um dos bits for 1.
 *
 * `^` (XOR bitwise): Compara os bits correspondentes de dois números.
 *                    O resultado será 1 apenas se os bits forem diferentes(um é 1 e o outro é 0).
 *
 * `~` (NOT bitwise): Inverte todos os bits de um número (1 vira 0 e 0 vira 1)
 *
 * -----------------
 *
 * TABELA VERDADE PARA OPERADORES BITWISE:
 * +----+----+-------+-------+-------+-----+
 * | X  | Y  | X & Y | X | Y | X ^ Y | ~X  |
 * +----+----+-------+-------+-------+-----+
 * | 00 | 00 |  00   |  00   |   00  |  11 |
 * +----+----+-------+-------+-------+-----+
 * | 00 | 01 |  00   |  01   |   01  |  11 |
 * +----+----+-------+-------+-------+-----+
 * | 00 | 10 |  00   |  10   |   10  |  11 |
 * +----+----+-------+-------+-------+-----+
 * | 00 | 11 |  00   |  11   |   11  |  11 |
 * +----+----+-------+-------+-------+-----+
 * | 01 | 00 |  00   |  01   |   01  |  10 |
 * +----+----+-------+-------+-------+-----+
 * | 01 | 01 |  01   |  01   |   00  |  10 |
 * +----+----+-------+-------+-------+-----+
 * | 01 | 10 |  00   |  11   |   11  |  10 |
 * +----+----+-------+-------+-------+-----+
 * | 01 | 11 |  01   |  11   |   10  |  10 |
 * +----+----+-------+-------+-------+-----+
 * | 10 | 00 |  00   |  10   |   10  |  01 |
 * +----+----+-------+-------+-------+-----+
 * | 10 | 01 |  00   |  11   |   11  |  01 |
 * +----+----+-------+-------+-------+-----+
 * | 10 | 10 |  10   |  10   |   00  |  01 |
 * +----+----+-------+-------+-------+-----+
 * | 10 | 11 |  10   |  11   |   01  |  01 |
 * +----+----+-------+-------+-------+-----+
 * | 11 | 00 |  00   |  11   |   11  |  00 |
 * +----+----+-------+-------+-------+-----+
 * | 11 | 01 |  01   |  11   |   10  |  00 |
 * +----+----+-------+-------+-------+-----+
 * | 11 | 10 |  10   |  11   |   01  |  00 |
 * +----+----+-------+-------+-------+-----+
 * | 11 | 11 |  11   |  11   |   00  |  00 |
 * +----+----+-------+-------+-------+-----+
 */

int main(int argc, char **argv)
{
    std::cout << "\n=== OPERADORES BITWISE EM C++ ===\n\n";

    unsigned int a = 0b1100; // 12 em decimal
    unsigned int b = 0b1010; // 10 em decimal

    std::cout << "1. OPERADORES BÁSICOS:" << '\n';
    std::cout << "a = " << std::bitset<4>(a) << " (bin) = " << a << " (dec)\n";
    std::cout << "b = " << std::bitset<4>(b) << " (bin) = " << b << " (dec)\n\n";

    std::cout << "AND (a & b): " << std::bitset<4>(a & b) << " = " << (a & b) << '\n';
    std::cout << "OR  (a | b): " << std::bitset<4>(a | b) << " = " << (a | b) << '\n';
    std::cout << "XOR (a ^ b): " << std::bitset<4>(a ^ b) << " = " << (a ^ b) << '\n';
    std::cout << "NOT (~a): " << std::bitset<32>(~a) << " = " << ~a << '\n';

    std::cout << "=========================================================" << '\n';
    std::cout << "\n2. OPERADORES DE SHIFT:" << '\n';

    unsigned char c = 0b00101111; // 0x2F = 47, que é o caractere '/'

    // << (Shift à esquerda): Desloca os bits de um número para a esquerda, adicionando 0s à direita.
    std::cout << "\nc = " << std::bitset<8>(c)
              << " (bin) = " << static_cast<int>(c)
              << " (dec) = '" << static_cast<char>(c)
              << "' (ASCII)\n\n";

    std::cout << "Shift left (c << 1):  "
              << std::bitset<8>(c << 1) << " = " << (c << 1)
              << " = '" << static_cast<char>(c << 1) << "'\n"; // caractere '^'

    // >> (Shift à direita): Desloca os bits de um número para a direita,descartando
    // os bits mais à direita e preenchendo com 0s ou 1s dependendo da implementação.
    std::cout << "Shift right (c >> 1): "
              << std::bitset<8>(c >> 1) << " = " << (c >> 1)
              << " = '" << static_cast<char>(c >> 1) << "'\n"; // ESC (não imprimível)

    std::cout << "=========================================================" << '\n';
    std::cout << "\n3. OPERADORES COMPOSTOS:" << '\n';

    unsigned int num = 0xFF; // 255

    std::cout << "\nnum = " << std::bitset<8>(num) << " = " << num << '\n';

    num <<= 2;
    std::cout << "num <<= 2: " << std::bitset<8>(num) << " = " << num << '\n';

    num >>= 3;
    std::cout << "num >>= 3: " << std::bitset<8>(num) << " = " << num << '\n';

    num &= 0b1010;
    std::cout << "num &= 1010: " << std::bitset<8>(num) << " = " << num << '\n';

    num |= 0b0101;
    std::cout << "num |= 0101: " << std::bitset<8>(num) << " = " << num << '\n';

    num ^= 0b1111;
    std::cout << "num ^= 1111: " << std::bitset<8>(num) << " = " << num << '\n';

    std::cout << "=========================================================" << '\n';
    std::cout << "\n4. APLICAÇÕES PRÁTICAS:" << '\n';

    // Verificar se um bit está setado
    unsigned int flags = 0b1010;
    unsigned int mask = 0b0100;

    std::cout << "\nBit 2 está " << ((flags & mask) ? "ligado" : "desligado") << '\n';

    // Ligar um bit específico
    flags |= 0b0001;
    std::cout << "Ligar bit 0: " << std::bitset<4>(flags) << '\n';

    // Desligar um bit específico
    flags &= ~0b1000;
    std::cout << "Desligar bit 3: " << std::bitset<4>(flags) << '\n';

    // Alternar (toggle) um bit
    flags ^= 0b0100;
    std::cout << "Alternar bit 2: " << std::bitset<4>(flags) << '\n';
    return 0;
}
