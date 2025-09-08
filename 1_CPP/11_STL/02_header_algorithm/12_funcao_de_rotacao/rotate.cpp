#include <iostream>
#include <vector>
#include <algorithm>

/**
 * - std::rotate(): Rotaciona os elementos "in-place".
 * - std::rotate_copy(): Faz uma cópia rotacionada
 */

/**
 * @brief Rotaciona os elementos de um vetor para a esquerda.
 *
 * @param vec Vetor a ser rotacionado.
 * @param desloc Quantidade de posições a rotacionar.
 */
void rotacionarEsquerda(std::vector<int> &vec, int desloc)
{
    if (vec.empty())
        return;

    desloc %= vec.size(); // Garante que o deslocamento não ultrapasse o tamanho
    std::rotate(vec.begin(), vec.begin() + desloc, vec.end());
}

/**
 * @brief Rotaciona os elementos de um vetor para a direita.
 *
 * @param vec Vetor a ser rotacionado.
 * @param desloc Quantidade de posições a rotacionar.
 */
void rotacionarDireita(std::vector<int> &vec, int desloc)
{
    if (vec.empty())
        return;

    desloc %= vec.size(); // Garante que o deslocamento não ultrapasse o tamanho
    std::rotate(vec.rbegin(), vec.rbegin() + desloc, vec.rend());
}

/**
 * @brief Imprime os elementos de um vetor.
 *
 * @param vec Vetor a ser impresso.
 */
void imprimirVetor(const std::vector<int> &vec)
{
    for (int num : vec)
    {
        std::cout << num << ' ';
    }
    std::cout << '\n';
}

int main(int argc, char **argv)
{
    std::vector<int> v = {1, 2, 3, 4, 5};

    // Exemplo fixo de rotação para a esquerda
    std::rotate(v.begin(), v.begin() + 2, v.end());
    std::cout << "Vetor após std::rotate para a esquerda (2 posições): ";
    imprimirVetor(v);

    std::cout << "=====================================\n";

    int deslocamento = 0;
    std::cout << "Digite quantas posições deseja rotacionar: ";
    std::cin >> deslocamento;

    if (deslocamento < 0)
    {
        std::cout << "Deslocamento inválido. Deve ser >= 0.\n";
        return 1;
    }

    char direcao = '\0';
    std::cout << "Rotacionar para a (E)squerda ou (D)ireita? ";
    std::cin >> direcao;

    if (direcao == 'E' || direcao == 'e')
    {
        rotacionarEsquerda(v, deslocamento);
    }
    else if (direcao == 'D' || direcao == 'd')
    {
        rotacionarDireita(v, deslocamento);
    }
    else
    {
        std::cout << "Direção inválida!\n";
        return 1;
    }

    std::cout << "Vetor após rotação interativa: ";
    imprimirVetor(v);
    return 0;
}
