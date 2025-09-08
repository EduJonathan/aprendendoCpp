#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cctype>
#include "class_labirinto.hpp"

Labirinto::Labirinto() : jogador1X(0), jogador1Y(0), jogador2X(tamanho - 1),
                         jogador2Y(tamanho - 1), jogoFinalizado(false),
                         jogador1Ativo(true), jogador2Ativo(true)
{
    std::srand(std::time(nullptr));
    matriz.resize(tamanho, std::vector<char>(tamanho, ' '));

    matriz[jogador1X][jogador1Y] = 'X';
    matriz[jogador2X][jogador2Y] = 'Y';

    do
    {
        saidaX = std::rand() % tamanho;
        saidaY = std::rand() % tamanho;
    } while ((saidaX == jogador1X && saidaY == jogador1Y) ||
             (saidaX == jogador2X && saidaY == jogador2Y));

    matriz[saidaX][saidaY] = '~';
}

void Labirinto::mostrarMatriz(void)
{
    for (int i = 0; i < tamanho; ++i)
    {
        for (int j = 0; j < tamanho; ++j)
        {
            std::cout << '[' << matriz[i][j] << ']';
        }
        std::cout << '\n';
    }

    std::cout << "Jogador 1 (X) em: (" << jogador1X << ", " << jogador1Y << ")\n";
    std::cout << "Jogador 2 (Y) em: (" << jogador2X << ", " << jogador2Y << ")\n";
    std::cout << "Saída (~) em: (" << saidaX << ", " << saidaY << ")\n";
}

void Labirinto::moverJogador(char jogador, char direcao)
{
    if (jogoFinalizado)
    {
        std::cout << "O jogo já terminou!\n";
        return;
    }

    int *x = nullptr, *y = nullptr;
    char simbolo = '\0';

    if (jogador == 'X')
    {
        if (!jogador1Ativo)
            return;
        x = &jogador1X;
        y = &jogador1Y;
        simbolo = 'X';
    }
    else if (jogador == 'Y')
    {
        if (!jogador2Ativo)
            return;
        x = &jogador2X;
        y = &jogador2Y;
        simbolo = 'Y';
    }
    else
        return;

    int novoX = *x;
    int novoY = *y;

    switch (direcao)
    {
    case 'w':
        novoX--;
        break;

    case 's':
        novoX++;
        break;

    case 'a':
        novoY--;
        break;

    case 'd':
        novoY++;
        break;

    default:
        return;
    }

    if (novoX < 0 || novoX >= tamanho || novoY < 0 || novoY >= tamanho)
        return;

    matriz[*x][*y] = ' ';
    *x = novoX;
    *y = novoY;
    matriz[*x][*y] = simbolo;

    if (*x == saidaX && *y == saidaY)
    {
        mostrarMatriz();
        std::cout << "Parabéns! Jogador " << jogador << " chegou ao objetivo e venceu!\n";
        jogoFinalizado = true;
    }
}

void Labirinto::moverJogadorY(void)
{
    if (!jogador2Ativo || jogoFinalizado)
        return;

    int dx = saidaX - jogador2X;
    int dy = saidaY - jogador2Y;

    char direcao = '\0';

    if (std::abs(dx) >= std::abs(dy))
        direcao = (dx > 0) ? 's' : 'w';
    else
        direcao = (dy > 0) ? 'd' : 'a';

    moverJogador('Y', direcao);
}

bool Labirinto::jogoTerminou(void) const
{
    return jogoFinalizado;
}

int main(int argc, char **argv)
{
    Labirinto jogo;

    std::cout << "\tBEM VINDO ao Labirinto\n\n";
    std::cout << "Você é o jogador (X) e deve chegar até o objetivo (~) antes do (Y).\n";
    std::cout << "Movimente seu personagem com:\n";
    std::cout << "w - Cima\n";
    std::cout << "a - Esquerda\n";
    std::cout << "s - Baixo\n";
    std::cout << "d - Direita\n\n";

    jogo.mostrarMatriz();

    char comando = '\0';

    while (!jogo.jogoTerminou())
    {
        std::cout << "\nMover (w/a/s/d): ";
        std::cin >> comando;
        comando = std::tolower(comando);

        jogo.moverJogador('X', comando);
        if (!jogo.jogoTerminou())
        {
            jogo.moverJogadorY();
            jogo.mostrarMatriz();
        }
    }
    return 0;
}
