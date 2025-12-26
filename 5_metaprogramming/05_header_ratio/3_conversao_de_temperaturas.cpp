#include <iostream>
#include <iomanip>
#include <type_traits>
#include <ratio>

struct FahrenheitToCelsius
{
    static constexpr std::ratio<5, 9> scale{};
    static constexpr int offset = 32;

    template <typename T>
    static constexpr T convert(T f) noexcept
    {
        return (f - offset) * scale.num / scale.den;
    }
};

struct CelsiusToFahrenheit
{
    static constexpr std::ratio<9, 5> scale{};
    static constexpr int offset = 32;

    template <typename T>
    static constexpr T convert(T c) noexcept
    {
        return c * scale.num / scale.den + offset;
    }
};

int main(int argc, char **argv)
{
    std::cout << std::fixed;

    // 1. Temperatura
    constexpr double f100 = 100.0;
    constexpr auto c_from_f = FahrenheitToCelsius::convert(f100);
    std::cout << "100°F  = " << c_from_f << "°C\n"; // → 37.777...

    constexpr double c37 = 37.0;
    std::cout << "37°C   = " << CelsiusToFahrenheit::convert(c37) << "°F\n\n";
    return 0;
}
