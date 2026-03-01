#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdint>

/**
 * @brief Determina o número de bytes que compõem um caractere UTF-8 com base no primeiro byte
 *
 * @param byte O primeiro byte do caractere UTF-8
 * @return O número de bytes que compõem o caractere (1 a 4) ou 0 se o byte for inválido
 */
std::uint8_t comprimento_utf8(unsigned char byte)
{
    if ((byte & 0b10000000) == 0b00000000)
        return 1;

    if ((byte & 0b11100000) == 0b11000000)
        return 2;

    if ((byte & 0b11110000) == 0b11100000)
        return 3;

    if ((byte & 0b11111000) == 0b11110000)
        return 4;
    return 0; // byte inválido
}

/**
 * @brief Verifica se um caractere UTF-8 completo é válido
 *
 * @param dados Ponteiro para os bytes do caractere
 * @param tamanho Número de bytes que compõem o caractere
 * @return true Se o caractere é válido
 * @return false Se o caractere é inválido
 */
bool caractere_utf8_valido(const unsigned char *dados, std::size_t tamanho)
{
    if (tamanho == 0)
        return false;

    std::size_t esperado = comprimento_utf8(dados[0]);
    if (esperado == 0 || tamanho < esperado)
        return false;

    // Verifica bytes de continuação: 10xxxxxx
    for (std::size_t i = 1; i < esperado; ++i)
    {
        if ((dados[i] & 0b11000000) != 0b10000000)
            return false;
    }

    // Decodifica o ponto de código (code point)
    uint32_t codigo = 0;
    if (esperado == 1)
    {
        codigo = dados[0];
    }
    else if (esperado == 2)
    {
        codigo = ((dados[0] & 0b00011111) << 6) | (dados[1] & 0b00111111);
    }
    else if (esperado == 3)
    {
        codigo = ((dados[0] & 0b00001111) << 12) |
                 ((dados[1] & 0b00111111) << 6) |
                 (dados[2] & 0b00111111);
    }
    else if (esperado == 4)
    {
        codigo = ((dados[0] & 0b00000111) << 18) |
                 ((dados[1] & 0b00111111) << 12) |
                 ((dados[2] & 0b00111111) << 6) |
                 (dados[3] & 0b00111111);
    }

    // Regras de validade UTF-8
    if (codigo > 0x10FFFF) // fora do intervalo Unicode
        return false;

    if (codigo >= 0xD800 && codigo <= 0xDFFF) // área de surrogates inválida
        return false;

    if ((esperado == 2 && codigo < 0x80) ||
        (esperado == 3 && codigo < 0x800) ||
        (esperado == 4 && codigo < 0x10000))
        return false; // codificação superdimensionada (overlong)

    return true;
}

int main(int argc, char **argv)
{
    std::vector<unsigned char> dados = {
        'A', 'B',
        0xF0, 0x9F, 0x98, 0x80, // 😀
        'Z',
        0xF0, // incompleto
        'X',
        0xF0, 0x98,             // inválido
        0xF0, 0x9F, 0x98, 0x80, // 😀 novamente
        0xFF,                   // inválido
        0xC3, 0xA5              // å
    };

    const unsigned char *ponteiro = dados.data();
    std::size_t restante = dados.size();

    while (restante > 0)
    {
        unsigned char primeiro = *ponteiro;
        std::size_t tamanho = comprimento_utf8(primeiro);

        if (tamanho == 0 || tamanho > restante || !caractere_utf8_valido(ponteiro, tamanho))
        {
            std::cout << "Byte inválido: 0x"
                      << std::hex << std::setw(2) << std::setfill('0')
                      << static_cast<int>(primeiro) << std::dec << '\n';
            ++ponteiro;
            --restante;
        }
        else
        {
            std::cout << "Caractere válido: ";
            for (std::size_t i = 0; i < tamanho; ++i)
            {
                std::cout << "0x" << std::hex << std::setw(2)
                          << std::setfill('0')
                          << static_cast<int>(ponteiro[i]) << ' ';
            }
            std::cout << std::dec << "→ \"";
            std::cout.write(reinterpret_cast<const char *>(ponteiro), tamanho);
            std::cout << "\"\n";

            ponteiro += tamanho;
            restante -= tamanho;
        }
    }
    return 0;
}
