#include <iostream>
#include <ratio>

constexpr int convertToCelsius(int fahrenheit)
{
    return (fahrenheit - 32) * 5 / 9;
}

using FahrenheitToCelsius = std::ratio<5, 9>;
using MetersToCentimeters = std::ratio<100, 1>; // 1 metro = 100 centímetros

int main(int argc, char **argv)
{
    constexpr int celsius = convertToCelsius(100); // Converte 100°F para Celsius
    std::cout << "100°F é " << celsius << "°C\n";  // 100°F -> 37.77°C (aproximadamente)

    std::cout << "Conversão de 2 metros para centímetros: "
              << 2 * MetersToCentimeters::num / MetersToCentimeters::den << " cm\n"; // 2 * 100 = 200
    return 0;
}
