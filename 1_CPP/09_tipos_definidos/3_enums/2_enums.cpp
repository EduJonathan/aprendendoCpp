#include <iostream>

#define JACK 11  /**< Define o valor da carta Jack como 11 */
#define QUEEN 12 /**< Define o valor da carta Queen como 12 */
#define KING 13  /**< Define o valor da carta King como 13 */
#define AS 1     /**< Define o valor da carta AS como 1 */

#ifndef CARD_SUIT
#define CARD_SUIT

/**
 * @enum CardSuit
 * @brief Enumeração para os naipes de cartas.
 *
 * Esta enumeração define os quatro naipes possíveis de um baralho:
 * Clubs, Diamonds, Hearts e Spades.
 */
enum CardSuit
{
    CLUBS,    /**< Naipe de paus */
    DIAMONDS, /**< Naipe de ouros */
    HEARTS,   /**< Naipe de copas */
    SPADES    /**< Naipe de espadas */
};

/**
 * @brief Função que converte o valor do enum CardSuit em uma string representando o nome do naipe.
 *
 * @param suit O naipe da carta a ser convertido.
 * @return Retorna o nome do naipe correspondente como string.
 */
const char *suitToString(CardSuit suit)
{
    switch (suit)
    {
    case CLUBS:
        return "Paus"; /**< Naipe de paus */

    case DIAMONDS:
        return "Ouros"; /**< Naipe de ouros */

    case HEARTS:
        return "Copas"; /**< Naipe de copas */

    case SPADES:
        return "Espadas"; /**< Naipe de espadas */

    default:
        return "Desconhecida"; /**< Caso o naipe seja desconhecido */
    }
}

#endif

#ifndef CARD_H
#define CARD_H

/**
 * @struct Card
 * @brief Estrutura que representa uma carta do baralho.
 *
 * Cada carta tem um valor e um naipe.
 */
struct Card
{
    int value;     /**< Valor da carta */
    CardSuit suit; /**< Naipe da carta */
};

#endif

/**
 * @brief Função que troca o conteúdo de duas cartas.
 *
 * Essa função recebe duas cartas por referência e troca os valores e os naipes entre elas.
 *
 * @param card1 A primeira carta a ser trocada.
 * @param card2 A segunda carta a ser trocada.
 */
void swapCards(Card &card1, Card &card2)
{
    Card temp = card1; /**< Armazena temporariamente a primeira carta */
    card1 = card2;     /**< Atribui a segunda carta para a primeira */
    card2 = temp;      /**< Atribui a carta temporária (a primeira) para a segunda */
}

int main(int argc, char **argv)
{
    Card temp;            /**< Carta temporária usada nas trocas */
    Card escolher;        /**< Carta escolhida pelo jogador */
    Card cartaEncontrada; /**< Carta que o jogador deve encontrar */

    // Inicializando as cartas com valores e naipes
    Card carta1 = {7, CLUBS};
    std::cout << "A carta 1 vale: " << carta1.value << " de " << suitToString(carta1.suit) << '\n';

    Card carta2 = {JACK, HEARTS};
    std::cout << "A carta 2 vale: " << carta2.value << " de " << suitToString(carta2.suit) << '\n';

    Card carta3 = {AS, SPADES};
    std::cout << "A carta 3 vale: " << carta3.value << " de " << suitToString(carta3.suit) << '\n';

    // Realizando trocas usando a função swapCards
    std::cout << "Trocando as cartas 1 e 3" << '\n';
    swapCards(carta1, carta3);

    std::cout << "Trocando as cartas 2 e 3" << '\n';
    swapCards(carta2, carta3);

    std::cout << "Trocando as cartas 1 e 3" << '\n';
    swapCards(carta1, carta3);

    int position = 0;
    std::cout << "Agora, Onde está a carta AS DE ESPADES? (1, 2, ou 3): ";
    std::cin >> position;

    // Validando a posição
    if (position < 1 || position > 3)
    {
        std::cout << "Posição inválida! Você deve escolher 1, 2, ou 3." << '\n';
        return 1; // Retorna com erro se a posição for inválida
    }

    // Atribuindo a carta escolhida
    switch (position)
    {
    case 1:
        escolher = carta1;
        break;

    case 2:
        escolher = carta2;
        break;

    case 3:
        escolher = carta3;
        break;
    }

    // A carta que o jogador deve encontrar
    cartaEncontrada = carta3;

    // Verificando se o jogador escolheu a carta certa
    if (escolher.value == cartaEncontrada.value && escolher.suit == cartaEncontrada.suit)
    {
        std::cout << "Parabéns, você ganhou!" << '\n';
    }
    else
    {
        std::cout << "Que pena, você perdeu!" << '\n';
    }

    /**
     * DESAFIO: Dê mais vida ao jogo! O 3 sempre será a carta certa!
     * então, refaça o jogo para que a resposta da carta seja aleatória(1, 2 ou 3).
     */
    return 0;
}
