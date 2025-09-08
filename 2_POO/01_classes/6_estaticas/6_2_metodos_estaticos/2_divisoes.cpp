#include <iostream>
#include <cmath>
#include <cstdlib>

class Division
{
public:
    // Método normal com casting
    static long long division(int a, int b)
    {
        return static_cast<long long>(a) / static_cast<long long>(b);
    }

    // Divisão usando laço (subtração sucessiva)
    static long long divisionUsingLoop(int a, int b)
    {
        int absA = std::abs(a);
        int absB = std::abs(b);

        long long temp = absA;
        long long result = 0;

        while (temp >= 0)
        {
            temp -= absB;
            if (temp >= 0)
            {
                result++;
            }
        }
        return (a > 0 && b > 0 || a < 0 && b < 0) ? result : -result;
    }

    // Divisão usando recursão
    static long long divisionUsingRecursion(int a, int b)
    {
        int absA = std::abs(a);
        int absB = std::abs(b);

        long long result = 1;
        int diff = absA - absB;

        if (diff > 0 && diff <= 1)
        {
            return result;
        }
        else if (diff < 0)
        {
            return 0;
        }

        result += divisionUsingRecursion(diff, absB);
        return (a > 0 && b > 0 || a < 0 && b < 0) ? result : -result;
    }

    // Divisão usando multiplicação por potências de dois
    static long long divisionUsingMultiplication(int a, int b)
    {
        int absA = std::abs(a);
        int absB = std::abs(b);

        int temp = absB;
        int counter = 0;
        while (temp <= absA)
        {
            temp <<= 1;
            counter++;
        }

        absA -= absB << (counter - 1);
        long long result = static_cast<long long>(std::pow(2, counter - 1));

        if (absB <= absA)
        {
            result += divisionUsingMultiplication(absA, absB);
        }
        return (a > 0 && b > 0 || a < 0 && b < 0) ? result : -result;
    }

    // Divisão usando deslocamento de bits
    static long long divisionUsingShift(int a, int b)
    {
        int absA = std::abs(a);
        int absB = std::abs(b);
        int tempA, tempB, counter;
        long long result = 0;

        while (absA >= absB)
        {
            tempA = absA >> 1;
            tempB = absB;
            counter = 1;

            while (tempA >= tempB)
            {
                tempB <<= 1;
                counter <<= 1;
            }

            absA -= tempB;
            result += counter;
        }
        return (a > 0 && b > 0 || a < 0 && b < 0) ? result : -result;
    }

    // Divisão usando logaritmos
    static long long divisionUsingLogs(int a, int b)
    {
        long long absA = std::abs(a);
        long long absB = std::abs(b);
        double logBase10A = std::log10(absA);
        double logBase10B = std::log10(absB);
        double powOf10 = std::pow(10, logBase10A - logBase10B);
        long long result = static_cast<long long>(std::floor(powOf10));
        return (a > 0 && b > 0 || a < 0 && b < 0) ? result : -result;
    }
};

int main(int argc, char **argv)
{
    Division divisao; // Não é necessário instanciar a classe para usar métodos estáticos
    int a = -20;      // Numerador
    int b = 4;        // Denominador

    std::cout << "Divisão normal : " << Division::division(a, b) << '\n';
    std::cout << "Divisão com loop : " << Division::divisionUsingLoop(a, b) << '\n';
    std::cout << "Divisão recursiva : " << Division::divisionUsingRecursion(a, b) << '\n';
    std::cout << "Divisão com multiplicação : " << divisao.divisionUsingMultiplication(a, b) << '\n';
    std::cout << "Divisão com shift : " << divisao.divisionUsingShift(a, b) << '\n';
    std::cout << "Divisão com log : " << divisao.divisionUsingLogs(a, b) << '\n';
    return 0;
}
