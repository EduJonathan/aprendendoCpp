#include <iostream>
#include <cctype>

/**
 * `enum class`: As enum class são uma forma de definir tipos enumerados fortemente tipados.
 * Eles evitam conflitos de nomes e permitem que os valores sejam usados com segurança.
 */

enum class TipoCaractere
{
    Vogal,
    Consoante,
    Numeral,
    Especial
};

struct Classificador
{
    static TipoCaractere classificar(char ch)
    {
        if (std::isalpha(static_cast<unsigned char>(ch)))
        {
            char lower = std::tolower(static_cast<unsigned char>(ch));

            // Verifica manualmente se é vogal
            switch (lower)
            {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return TipoCaractere::Vogal;

            default:
                return TipoCaractere::Consoante;
            }
        }
        else if (std::isdigit(static_cast<unsigned char>(ch)))
        {
            return TipoCaractere::Numeral;
        }

        return TipoCaractere::Especial;
    }
};

int main(int argc, char **argv)
{
    char ch = '6'; // Altere este caractere para testar diferentes classificações

    switch (Classificador::classificar(ch))
    {
    case TipoCaractere::Vogal:
        std::cout << '\'' << ch << "' é uma VOGAL.\n";
        break;

    case TipoCaractere::Consoante:
        std::cout << '\'' << ch << "' é uma CONSOANTE.\n";
        break;

    case TipoCaractere::Numeral:
        std::cout << '\'' << ch << "' é um NUMERAL.\n";
        break;

    case TipoCaractere::Especial:
        std::cout << '\'' << ch << "\' é um CARACTERE ESPECIAL.\n";
        break;
    }

    return 0;
}
