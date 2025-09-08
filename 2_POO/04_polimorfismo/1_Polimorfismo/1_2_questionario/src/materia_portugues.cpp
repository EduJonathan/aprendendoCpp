#include "../include/class_portugues.hpp"
#include <iostream>
#include <locale>
#include <cwctype>

Portugues::Portugues() : acertos(0), totalQuestoes(3) {}

void Portugues::questionario()
{
    acertos = 0;
    wchar_t resposta;

    std::wcout << L"\n[Português]\n";

    std::wcout << L"1. Qual é a capital do Brasil?\n";
    std::wcout << L"A) Brasília\nB) Rio de Janeiro\nC) São Paulo\nD) Salvador\n";
    std::wcout << L"Sua resposta: ";
    std::wcin >> resposta;

    if (std::towupper(resposta) == L'A')
        acertos++;

    std::wcout << L"2. Qual está correto?\n";
    std::wcout << L"A) Exceção\nB) Excessão\nC) Excessao\nD) Exce\n";
    std::wcout << L"Sua resposta: ";
    std::wcin >> resposta;

    if (std::towupper(resposta) == L'A')
        acertos++;

    std::wcout << L"3. Qual frase está corretamente escrita?\n";
    std::wcout << L"A) Fazem dez anos que não o vejo.\n";
    std::wcout << L"B) Há dez anos que não o vejo.\n";
    std::wcout << L"C) Tem dez anos que não o vejo.\n";
    std::wcout << L"D) Vai fazer dez anos que não o vejo.\n";
    std::wcin >> resposta;
    
    if (std::towupper(resposta) == L'B')
        acertos++;
}

double Portugues::calcularPorcentagem() const
{
    return (totalQuestoes == 0) ? 0 : (static_cast<double>(acertos) / totalQuestoes) * 100;
}

std::string Portugues::getNome() const
{
    return "Português";
}
