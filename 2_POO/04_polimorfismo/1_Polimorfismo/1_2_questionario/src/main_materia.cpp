#include "../include/class_materia.hpp"
#include "../include/class_matematica.hpp"
#include "../include/class_portugues.hpp"
#include "../include/class_programacao.hpp"
#include <iostream>
#include <vector>
#include <clocale>
#include <stdexcept>
#include <new>

int main(int argc, char **argv)
{
    try
    {
        // Tenta usar pt_BR.UTF-8
        std::locale::global(std::locale("pt_BR.UTF-8"));
        std::wcin.imbue(std::locale("pt_BR.UTF-8"));
        std::wcout.imbue(std::locale("pt_BR.UTF-8"));
    }
    catch (const std::runtime_error &e)
    {
        // Caso a localidade não esteja disponível, usa o padrão "C"
        std::cout << "Localidade pt_BR.UTF-8 não encontrada, usando localidade padrão 'C'.\n";
        std::locale::global(std::locale("C"));
        std::wcin.imbue(std::locale("C"));
        std::wcout.imbue(std::locale("C"));
    }

    std::wcout << L"=== Bem-vindo ao Quiz de Conhecimentos Gerais ===\n";
    std::wcout << L"Responda as questões escolhendo a letra correspondente (A, B, C ou D).\n\n";

    // Criando vetor de ponteiros brutos
    std::vector<Materia *> materias;

    materias.push_back(new Portugues());
    materias.push_back(new Matematica());
    materias.push_back(new Programacao());

    double soma = 0.0;

    for (std::size_t i = 0ull; i < materias.size(); ++i)
    {
        materias[i]->questionario();
        double porcentagem = materias[i]->calcularPorcentagem();
        std::cout << materias[i]->getNome() << " - Porcentagem de acertos: " << porcentagem << "%\n\n";
        soma += porcentagem;
    }

    double mediaGeral = soma / materias.size();
    std::cout << "Média geral de acertos: " << mediaGeral << "%\n";

    // Liberar memória alocada
    for (std::size_t i = 0ull; i < materias.size(); ++i)
    {
        delete materias[i];
    }

    /**
     * Compilação e execute com:
     * g++ -std=c++11 .\main_materia.cpp .\materia_matematica.cpp .\materia_portugues.cpp .\materia_programacao.cpp -o quiz
     * ./quiz.exe
     */
    return 0;
}
