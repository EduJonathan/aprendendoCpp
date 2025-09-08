#include <iostream>
#include <chrono>
#include "class_cipher.hpp"

CaesarCipher::CaesarCipher() {}

CaesarCipher &CaesarCipher::prompt()
{
    std::cout << '\n'
              << "password: " << password << '\n'
              << "encryptedPassword: " << encryptedPassword << '\n'
              << "shift: " << shift << '\n'
              << '\n';

    return *this;
}

CaesarCipher &CaesarCipher::requestPassword(int argc, char **argv)
{
    if (argc > 1)
    {
        password = argv[1];
        return *this;
    }

    std::cout << "Digite a senha: ";
    std::cin >> password;
    return *this;
}

CaesarCipher &CaesarCipher::randomizeShift()
{
    std::chrono::time_point<std::chrono::steady_clock> now = std::chrono::steady_clock::now();
    shift = now.time_since_epoch().count() % 255;
    return *this;
}

CaesarCipher &CaesarCipher::encrypt()
{
    /**
     * Função lambda que implementa a logica de criptografia para deslocar um
     * caractere de acordo com o valor do deslocamento.
     *
     * @param act Caractere a ser deslocado.
     * @param shift Valor do deslocamento.
     * @return Caractere deslocado.
     */
    auto shiftChar = [](char &act, int &shift)
    {
        int i{97};

        if (!((act >= 65 && act <= 90) && !(act >= 97 && act <= 122)))
        {
            // Não é alfa-numérico, retorne o caractere original
            return act;
        }

        if (act <= 90)
        {
            i = 65;
        }

        return static_cast<char>((act - i + shift) % 26 + i);
    };

    for (std::size_t i{0}; i < password.length(); ++i)
    {
        encryptedPassword += shiftChar(password[i], shift);
    }
    return *this;
}
