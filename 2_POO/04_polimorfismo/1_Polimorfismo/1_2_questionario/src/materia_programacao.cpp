#include "../include/class_programacao.hpp"
#include <iostream>
#include <locale>
#include <cwctype>

Programacao::Programacao() : acertos(0), totalQuestoes(3) {}

void Programacao::questionario()
{
    acertos = 0;
    wchar_t resposta;

    std::wcout << L"\n[Programação]\n";

    std::wcout << L"1. Qual linguagem é orientada a objetos?\n";
    std::wcout << L"A) C\nB) SQL\nC) C++\nD) CSS\n";
    std::wcout << L"Sua resposta: ";
    std::wcin >> resposta;

    if (std::towupper(resposta) == L'C')
        acertos++;

    std::wcout << L"2. Qual estrutura é usada para repetição?\n";
    std::wcout << L"A) if\nB) else\nC) for\nD) switch\n";
    std::wcout << L"Sua resposta: ";
    std::wcin >> resposta;

    if (std::towupper(resposta) == L'C')
        acertos++;

    std::wcout << L"3. Qual destes operadores é usado para comparar igualdade em C++?\n";
    std::wcout << L"A) =\nB) ==\nC) !=\nD) <=\n";
    std::wcout << L"Sua resposta: ";
    std::wcin >> resposta;

    if (std::towupper(resposta) == L'B')
        acertos++;
}

double Programacao::calcularPorcentagem() const
{
    return (totalQuestoes == 0) ? 0 : (static_cast<double>(acertos) / totalQuestoes) * 100;
}

std::string Programacao::getNome() const
{
    return "Programação";
}
