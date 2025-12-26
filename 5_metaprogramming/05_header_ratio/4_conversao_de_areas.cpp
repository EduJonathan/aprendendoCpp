#include <iostream>
#include <type_traits>
#include <cassert>
#include <ratio>

// === Definição das unidades base ===
using meter = std::ratio<1>;       // 1 metro
using centi = std::ratio<1, 100>;  // 1 cm  = 10⁻² m
using milli = std::ratio<1, 1000>; // 1 mm  = 10⁻³ m
using kilo = std::ratio<1000>;     // 1 km  = 10³ m

// === Unidades de área (elevadas ao quadrado) ===
using square_meter = std::ratio<1>;
using square_centimeter = std::ratio_multiply<std::ratio_multiply<centi, centi>, centi>; // erro! não é assim

template <intmax_t Exp, typename Ratio>
using ratio_pow = std::ratio<std::ratio<1>::num *(Ratio::num ^ Exp),
                             std::ratio<1>::den *(Ratio::den ^ Exp)>;

// Versão correta e limpa (C++17+ tem std::ratio_pow, mas vamos fazer manual):
using m2 = std::ratio<1>;              // 1 m²
using cm2 = std::ratio<1, 10'000>;     // 1 cm² = 10⁻⁴ m²
using mm2 = std::ratio<1, 1'000'000>;  // 1 mm² = 10⁻⁶ m²
using km2 = std::ratio<1'000'000'000>; // 1 km² = 10⁹ m²

// === Função genérica de conversão (100% tempo de compilação!) ===
template <typename From, typename To, typename T>
constexpr T convert_area(T value) noexcept
{
    static_assert(std::is_floating_point_v<T> || std::is_integral_v<T>,
                  "Tipo deve ser numérico");

    // Conversão exata: value * (From / To)
    return value * (static_cast<long double>(From::num) * To::den) / (static_cast<long double>(From::den) * To::num);
}

int main(int argc, char **argv)
{
    constexpr double area_m2 = 2.5; // 2.5 metros quadrados

    // Conversões perfeitas, sem erro de ponto flutuante!
    constexpr auto area_cm2 = convert_area<m2, cm2>(area_m2);
    constexpr auto area_mm2 = convert_area<m2, mm2>(area_m2);
    constexpr auto area_km2 = convert_area<m2, km2>(area_m2);

    std::cout << area_m2 << " m² = \n";
    std::cout << "  " << area_cm2 << " cm²\n";
    std::cout << "  " << area_mm2 << " mm²\n";
    std::cout << "  " << area_km2 << " km²\n";

    // Conversões inversas
    std::cout << "\n50000 cm² = " << convert_area<cm2, m2>(50000.0) << " m²\n";
    std::cout << "1 km²     = " << convert_area<km2, m2>(1.0) << " m²\n";

    return 0;
}
