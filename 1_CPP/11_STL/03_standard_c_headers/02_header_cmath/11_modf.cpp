#include <iostream>
#include <cmath>

/**
 * As funções `std::modf`, `std::modff` e `std::modfl` dividem um valor de ponto flutuante
 * em sua parte inteira e fracionária. A parte fracionária (com o mesmo sinal de `x`)
 * é retornada, enquanto a parte inteira é armazenada na variável passada por ponteiro.
 * que x. A parte fracionária com sinal de x é retornada. A parte inteira é armazenada como um valor de ponto flutuante em intptr.
 */

int main(int argc, char **argv)
{
    double inteiro_d = 0.0;
    float inteiro_f = 0.0f;
    long double inteiro_ld = 0.0l;

    double fracionario_d = std::modf(40.75, &inteiro_d);
    float fracionario_f = std::modf(40.75f, &inteiro_f);
    long double fracionario_ld = std::modf(40.75L, &inteiro_ld);

    std::cout << "std::modf (double): parte inteira = " << inteiro_d
              << ", parte fracionária = " << fracionario_d << '\n';

    std::cout << "std::modff (float): parte inteira = " << inteiro_f
              << ", parte fracionária = " << fracionario_f << '\n';

    std::cout << "std::modfl (long double): parte inteira = " << inteiro_ld
              << ", parte fracionária = " << fracionario_ld << '\n';
    return 0;
}
