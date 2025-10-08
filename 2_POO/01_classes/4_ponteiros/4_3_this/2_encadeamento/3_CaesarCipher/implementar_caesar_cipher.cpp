#include <iostream>
#include <random>
#include <algorithm>
#include <cctype>
#include "class_cipher.hpp"

CaesarCipher::CaesarCipher() : shift(0), password(""), encryptedPassword("") {}

CaesarCipher &CaesarCipher::prompt()
{
    std::cout << '\n'
              << "Password: " << password << '\n'
              << "Encrypted Password: " << encryptedPassword << '\n'
              << "Shift: " << shift << "\n\n";
    return *this;
}

CaesarCipher &CaesarCipher::requestPassword(int argc, char **argv)
{
    if (argc > 1)
    {
        password = argv[1];
    }
    else
    {
        std::cout << "Enter password: ";
        std::getline(std::cin, password); // Use getline to handle spaces
    }
    if (password.empty())
    {
        std::cerr << "Error: Password cannot be empty.\n";
        password = "default"; // Fallback to avoid empty password
    }
    return *this;
}

CaesarCipher &CaesarCipher::randomizeShift()
{
    std::random_device rd;                      // Dispositivo de geração de números aleatórios
    std::mt19937 gen(rd());                     // Motor de geração de números aleatórios (Mersenne Twister)
    std::uniform_int_distribution<> dis(0, 25); // Distribuição uniforme entre 0 e 25
    shift = dis(gen);                           // Gera o valor de deslocamento
    return *this;
}

CaesarCipher &CaesarCipher::encrypt()
{
    encryptedPassword.clear();

    /**
     * Função lambda que implementa a logica de criptografia para deslocar um
     * caractere de acordo com o valor do deslocamento.
     *
     * @param act Caractere a ser deslocado.
     * @param shift Valor do deslocamento.
     * @return Caractere deslocado.
     */
    auto shiftChar = [](char c, int shift)
    {
        if (!std::isalpha(c))
        {
            return c; // Retorna o caractere inalterado se não for alfabético
        }
        char base = std::isupper(c) ? 'A' : 'a';
        return static_cast<char>((c - base + shift) % 26 + base);
    };

    for (char c : password)
    {
        encryptedPassword += shiftChar(c, shift);
    }
    return *this;
}
