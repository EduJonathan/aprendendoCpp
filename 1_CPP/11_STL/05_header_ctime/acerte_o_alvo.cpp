#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
#include <vector>

int main(int argc, char **argv)
{
    const int SIZE = 5;
    const int TOTAL_ALVOS = 6;

    std::array<std::array<char, SIZE>, SIZE> monitor;
    std::vector<std::pair<int, int>> alvos; // Armazena posições dos alvos

    std::srand(std::time(0));

    // Inicializa o monitor com '.'
    for (auto &linha : monitor)
    {
        linha.fill('.');
    }

    // Gera 6 alvos aleatórios em posições distintas
    while (alvos.size() < TOTAL_ALVOS)
    {
        int linha = std::rand() % SIZE;
        int coluna = std::rand() % SIZE;

        // Verifica se já existe um alvo nesta posição
        bool jaExiste = false;
        for (auto &pos : alvos)
        {
            if (pos.first == linha && pos.second == coluna)
            {
                jaExiste = true;
                break;
            }
        }

        if (!jaExiste)
        {
            alvos.push_back({linha, coluna});
        }
    }

    std::cout << "Bem-vindo ao jogo Acerte o Alvo!\n";
    std::cout << "Existem " << TOTAL_ALVOS << " alvos escondidos em uma matriz " << SIZE << 'x' << SIZE << ".\n";
    std::cout << "Você deve acertar todos eles. Cada acerto será marcado com '#'.\n\n";

    int acertos = 0;

    while (acertos < TOTAL_ALVOS)
    {
        int chuteLinha, chuteColuna;

        std::cout << "Digite a linha (0-" << SIZE - 1 << "): ";
        std::cin >> chuteLinha;
        std::cout << "Digite a coluna (0-" << SIZE - 1 << "): ";
        std::cin >> chuteColuna;

        if (chuteLinha < 0 || chuteLinha >= SIZE || chuteColuna < 0 || chuteColuna >= SIZE)
        {
            std::cout << "Posição inválida! Tente novamente.\n\n";
            continue;
        }

        // Verifica se já foi revelado
        if (monitor[chuteLinha][chuteColuna] == '#' || monitor[chuteLinha][chuteColuna] == 'X')
        {
            std::cout << "Você já tentou essa posição. Escolha outra.\n\n";
            continue;
        }

        // Verifica se o chute acertou algum dos alvos
        bool acertou = false;
        for (auto &pos : alvos)
        {
            if (pos.first == chuteLinha && pos.second == chuteColuna)
            {
                monitor[chuteLinha][chuteColuna] = '#';
                acertos++;
                std::cout << "\nAcertou! Faltam " << (TOTAL_ALVOS - acertos) << " alvo(s).\n";
                acertou = true;
                break;
            }
        }

        if (!acertou)
        {
            monitor[chuteLinha][chuteColuna] = 'X';
            std::cout << "\nErrou! Tente novamente.\n";
        }

        // Mostra o monitor atualizado
        std::cout << "\nMonitor:\n";
        for (const auto &linha : monitor)
        {
            for (char c : linha)
            {
                std::cout << c << ' ';
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }

    std::cout << "Parabéns! Você encontrou todos os alvos!\n";

    return 0;
}
