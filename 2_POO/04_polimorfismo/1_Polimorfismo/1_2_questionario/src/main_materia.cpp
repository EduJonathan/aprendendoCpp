#include "../include/class_materia.hpp"
#include "../include/class_matematica.hpp"
#include "../include/class_portugues.hpp"
#include "../include/class_programacao.hpp"
#include <iostream>
#include <vector>
#include <clocale>
#include <stdexcept>
#include <string>

int main(int argc, char **argv)
{
    // Configura locale para português com acentos
    try
    {
        std::locale::global(std::locale("pt_BR.UTF-8"));
    }
    catch (...)
    {
        std::wcout << L"Aviso: locale pt_BR.UTF-8 não disponível, usando padrão.\n";
    }

    std::wcin.imbue(std::locale());
    std::wcout.imbue(std::locale());

    std::wcout << L"=== Bem-vindo ao Quiz de Conhecimentos Gerais ===\n";
    std::wcout << L"Responda as questões escolhendo a letra correspondente (A, B, C ou D).\n\n";

    // Criando vetor de ponteiros brutos
    std::vector<Materia *> materias;

    materias.push_back(new Portugues());
    materias.push_back(new Matematica());
    materias.push_back(new Programacao());

    double soma = 0.0;

    for (const auto &m : materias)
    {
        m->questionario();

        double pct = m->calcularPorcentagem();
        soma += pct;

        // Conversão segura de std::string → std::wstring
        std::wstring nome_wide(m->getNome().begin(), m->getNome().end());

        std::wcout << nome_wide
                   << L" - Acertos: " << m->calcularPorcentagem()
                   << L"% (" << m->getAcertos() << L"/" << m->getTotalQuestoes() << L")\n\n";
    }

    double media = soma / materias.size();

    std::wcout << L"══════════════════════════════════════════\n";
    std::wcout << L"Média Geral de Acertos: " << media << L"%\n";

    if (media >= 70.0)
    {
        std::wcout << L"Parabéns! Você mandou bem!\n";
    }
    else if (media >= 50.0)
    {
        std::wcout << L"Não foi mal! Estude um pouco mais!\n";
    }
    else
    {
        std::wcout << L"Que tal revisar os conteúdos?\n";
    }

    /**
     * Compilação e execute com:
     * g++ -std=c++11 .\main_materia.cpp .\materia_matematica.cpp .\materia_portugues.cpp .\materia_programacao.cpp -o quiz
     * ./quiz.exe
     */
    return 0;
}
