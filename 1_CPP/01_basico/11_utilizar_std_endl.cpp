#include <iostream>
#include <string>
#include <limits>

/**
 * O uso de std::endl em C++ não é necessariamente uma má prática, mas deve ser feito com
 * consciência, pois ele pode impactar o desempenho do programa em determinados contextos.
 *
 * O que é std::endl?
 * std::endl é um manipulador de fluxo da biblioteca <iostream> que executa duas ações:
 *
 * 1. Insere um caractere de nova linha ('\n') no fluxo de saída.
 * 2. Força o descarregamento (flush) do buffer de saída, escrevendo imediatamente os dados
 * no destino (como a tela, um arquivo ou outro dispositivo).
 *
 * Quando usar std::endl:
 * - Quando for necessário garantir que a saída apareça imediatamente, como ao solicitar
 *   uma entrada do usuário (ex: "Digite um valor: ").
 * - Durante a depuração (debug), para assegurar que mensagens sejam exibidas na ordem
 *   correta, mesmo que o programa falhe em seguida.
 *
 * Quando evitar std::endl:
 * - Em loops ou em saídas frequentes, pois o flush forçado pode causar queda significativa
 *   de desempenho.
 * - Quando apenas uma quebra de linha é necessária, prefira '\n', que é mais leve e evita
 *   o custo do flush automático.
 *
 * Resumo:
 * - Use std::endl apenas quando o flush for realmente necessário.
 * - Caso contrário, '\n' é mais eficiente e geralmente suficiente.
 */

int main(int argc, char **argv)
{
    std::cout << "Linha normal\n";
    std::cout << "Pronto, digite algo: " << std::flush;

    std::string texto;

    // Ignora o '\n' pendente no buffer de entrada
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Digite um texto: " << std::endl;
    std::getline(std::cin, texto);
    std::cout << "Texto digitado: " << texto << std::endl;

    // Se quiser capturar apenas uma palavra, `std::cin` está ótimo.
    // Se for capturar uma linha inteira com espaços, use std::getline com cuidado para limpar o buffer antes.

    std::cout << "--------------------------" << std::endl;

    // Na maioria dos casos, usar apenas \n é suficiente para inserir uma nova linha sem forçar
    // o flush do buffer. Isso é mais eficiente, especialmente em loops ou quando a saída é
    // direcionada para um arquivo.
    for (int i = 0; i < 100; ++i)
    {
        std::cout << i << std::endl; // Força flush a cada iteração (lento)
    }

    std::cout << "--------------------------" << std::endl;

    // Substituir por \n melhora o desempenho:
    for (int i = 100; i > 0; --i)
    {
        std::cout << i << '\n'; // Apenas insere nova linha, sem flush
    }
    return 0;
}
