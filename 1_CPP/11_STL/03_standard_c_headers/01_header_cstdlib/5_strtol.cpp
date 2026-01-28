#include <iostream>
#include <cstdlib>
#include <cerrno>

enum class Formato
{
    Decimal = 10,
    Hexadecimal = 16,
    Octal = 8,
    Auto = 0
};

struct Conversor
{
private:
    static bool conversaoValida(const char *inicio, const char *fim)
    {
        return inicio != fim && errno != ERANGE;
    }

public:
    // --- Inteiros Sinalizados ---
    static bool paraInt(const char *str, int &out)
    {
        errno = 0;
        char *end;
        long valor = std::strtol(str, &end, 10);

        if (!conversaoValida(str, end))
            return false;

        out = static_cast<int>(valor);
        return true;
    }

    static bool paraLong(const char *str, long &out, Formato base = Formato::Decimal)
    {
        errno = 0;
        char *end;
        out = std::strtol(str, &end, static_cast<int>(base));
        return conversaoValida(str, end);
    }

    static bool paraLongLong(const char *str, long long &out, Formato base = Formato::Decimal)
    {
        errno = 0;
        char *end;
        out = std::strtoll(str, &end, static_cast<int>(base));
        return conversaoValida(str, end);
    }

    // --- Inteiros Não Sinalizados ---
    static bool paraULong(const char *str, unsigned long &out, Formato base = Formato::Decimal)
    {
        errno = 0;
        char *end;
        out = std::strtoul(str, &end, static_cast<int>(base));
        return conversaoValida(str, end);
    }

    static bool paraULongLong(const char *str, unsigned long long &out, Formato base = Formato::Decimal)
    {
        errno = 0;
        char *end;
        out = std::strtoull(str, &end, static_cast<int>(base));
        return conversaoValida(str, end);
    }

    // --- Ponto Flutuante ---
    static bool paraDouble(const char *str, double &out)
    {
        errno = 0;
        char *end;
        out = std::strtod(str, &end);
        return conversaoValida(str, end);
    }

    static bool paraLongDouble(const char *str, long double &out)
    {
        errno = 0;
        char *end;
        out = std::strtold(str, &end);
        return conversaoValida(str, end);
    }
};

int main()
{
    int i;
    long h;
    double d;

    // Exemplo de uso prático:
    if (Conversor::paraInt("42", i))
        std::cout << "Int: " << i << '\n';

    if (Conversor::paraLong("0x2A", h, Formato::Auto))
        std::cout << "Hex: " << h << '\n';

    if (!Conversor::paraDouble("abc", d))
        std::cout << "Erro ao converter double\n";

    return 0;
}
