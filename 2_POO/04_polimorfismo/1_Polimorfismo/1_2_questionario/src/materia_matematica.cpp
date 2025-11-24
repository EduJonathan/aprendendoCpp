#include "../include/class_matematica.hpp"
#include <iostream>
#include <cctype>
#include <clocale>
#include <cwctype>

Matematica::Matematica() : acertos(0), totalQuestoes(3) {}

void Matematica::questionario()
{
    acertos = 0;
    wchar_t resposta;
    std::wcout << L"\n[Matemática]\n";

    std::wcout << L"1. Quanto é 7 x 8?\n";
    std::wcout << L"A) 56\nB) 54\nC) 64\nD) 58\n";
    std::wcout << L"Sua resposta: ";
    std::wcin >> resposta;

    if (std::towupper(resposta) == L'A')
        acertos++;

    std::wcout << L"2. Qual é o valor de pi (π) aproximado?\n";
    std::wcout << L"A) 2.14\nB) 3.14\nC) 4.13\nD) 3.41\n";
    std::wcout << L"Sua resposta: ";
    std::wcin >> resposta;

    if (std::towupper(resposta) == L'B')
        acertos++;

    std::wcout << L"3. Quanto é a raiz quadrada de 81?\n";
    std::wcout << L"A) 9\nB) 8\nC) 7\nD) 6\n";
    std::wcout << L"Sua resposta: ";
    std::wcin >> resposta;

    if (std::towupper(resposta) == L'A')
        acertos++;
}

double Matematica::calcularPorcentagem() const
{
    return (totalQuestoes == 0) ? 0 : (static_cast<double>(acertos) / totalQuestoes) * 100;
}

std::string Matematica::getNome() const
{
    return "Matemática";
}

int Matematica::getAcertos() const { return acertos; }
int Matematica::getTotalQuestoes() const { return totalQuestoes; }
