#include <iostream>
#include <array>
#include <cstdlib>
#include <utility>
#include <ctime>
#include <vector>

const int SIZE = 5;        /// Tamanho da matriz do jogo
const int TOTAL_ALVOS = 6; /// Total de alvos a serem encontrados

using Monitor = std::array<std::array<char, SIZE>, SIZE>; // Matriz que representa o monitor
using Posicao = std::pair<int, int>;                      // Par para representar a posição (linha, coluna)
using Alvos = std::vector<Posicao>;                       // Vetor para armazenar as posições dos alvos

/**
 * @brief Inicializa o monitor preenchendo todas as posições com '.'
 *
 * @param monitor Referência para a matriz que representa o monitor
 */
void inicializarMonitor(Monitor &monitor)
{
    for (auto &linha : monitor)
    {
        linha.fill('.');
    }
}

/**
 * @brief Gera posições aleatórias únicas para os alvos dentro do monitor
 *
 * @param alvos Vetor onde as posições dos alvos serão armazenadas
 */
void gerarAlvos(Alvos &alvos)
{
    alvos.clear();
    while (alvos.size() < TOTAL_ALVOS)
    {
        int linha = std::rand() % SIZE;
        int coluna = std::rand() % SIZE;

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
}

/**
 * @brief Imprime o estado atual do monitor na tela
 *
 * @param monitor Matriz que representa o monitor a ser exibido
 */
void imprimirMonitor(const Monitor &monitor)
{
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

/**
 * @brief Processa o chute do jogador, atualiza o monitor e conta os acertos
 *
 * @param monitor Referência para o monitor a ser atualizado
 * @param alvos Vetor contendo as posições dos alvos
 * @param linha Linha do chute
 * @param coluna Coluna do chute
 * @param acertos Referência para a contagem de acertos do jogador
 * @return true Se o chute acertou um alvo e foi válido
 * @return false Se o chute foi inválido ou errou
 */
bool processarChute(Monitor &monitor, const Alvos &alvos, int linha, int coluna, int &acertos)
{
    if (monitor[linha][coluna] == '#' || monitor[linha][coluna] == 'X')
    {
        std::cout << "Você já tentou essa posição. Escolha outra.\n\n";
        return false;
    }

    for (auto &pos : alvos)
    {
        if (pos.first == linha && pos.second == coluna)
        {
            monitor[linha][coluna] = '#';
            acertos++;
            std::cout << "\nAcertou! Faltam " << (TOTAL_ALVOS - acertos) << " alvo(s).\n";
            return true;
        }
    }

    monitor[linha][coluna] = 'X';
    std::cout << "\nErrou! Tente novamente.\n";
    return false;
}

int main(int argc, char **argv)
{
    std::srand(std::time(0));

    Monitor monitor;
    Alvos alvos;
    int acertos = 0;

    inicializarMonitor(monitor);
    gerarAlvos(alvos);

    std::cout << "Bem-vindo ao jogo Acerte o Alvo!\n";
    std::cout << "Existem " << TOTAL_ALVOS << " alvos escondidos em uma matriz " << SIZE << 'x' << SIZE << ".\n";
    std::cout << "Você deve acertar todos eles. Cada acerto será marcado com '#'.\n\n";

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

        processarChute(monitor, alvos, chuteLinha, chuteColuna, acertos);
        imprimirMonitor(monitor);
    }

    std::cout << "Parabéns! Você encontrou todos os alvos!\n";
    return 0;
}
