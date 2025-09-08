#ifndef LABIRINTO_HPP
#define LABIRINTO_HPP

#include <vector>

/**
 * @brief Classe que representa um jogo de labirinto com dois jogadores.
 *
 * O objetivo do jogo é que o jogador 1 (X) chegue ao objetivo (~) antes do jogador 2 (Y).
 */
class Labirinto
{
private:
    const int tamanho = 6;                 // Tamanho fixo da matriz do labirinto.
    std::vector<std::vector<char>> matriz; // Matriz que representa o labirinto.

    int jogador1X, jogador1Y; // Posição do jogador 1 (X).
    int jogador2X, jogador2Y; // Posição do jogador 2 (Y).

    int saidaX, saidaY; // Coordenadas da saída (~) do labirinto.

    bool jogoFinalizado; // Indica se o jogo foi finalizado.
    bool jogador1Ativo;  // Indica se o jogador 1 ainda está ativo.
    bool jogador2Ativo;  // Indica se o jogador 2 ainda está ativo.

public:
    /**
     * @brief Construtor da classe Labirinto.
     *
     * Inicializa o labirinto, posiciona os jogadores e gera uma saída aleatória.
     */
    Labirinto();

    /**
     * @brief Exibe a matriz do labirinto no console.
     */
    void mostrarMatriz();

    /**
     * @brief Move o jogador indicado em uma direção.
     *
     * @param jogador Caractere 'X' ou 'Y' representando o jogador.
     * @param direcao Direção do movimento: 'w', 'a', 's', 'd'.
     */
    void moverJogador(char jogador, char direcao);

    /**
     * @brief Move automaticamente o jogador Y em direção à saída.
     *
     * A estratégia usada é simples: o movimento se dá na direção da menor distância.
     */
    void moverJogadorY();

    /**
     * @brief Verifica se o jogo terminou.
     *
     * @return true se o jogo terminou; false caso contrário.
     */
    bool jogoTerminou() const;
};

#endif
