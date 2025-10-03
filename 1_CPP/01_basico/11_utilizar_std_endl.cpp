#include <iostream>
#include <string>
#include <limits>
#include <fstream> // Para escrita em arquivos
#include <chrono>  // Para medir desempenho entre std::endl e '\n'

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
    // 1. Exemplo de saída com '\n' (sem flush)
    std::cout << "Linha normal\n";
    std::cout << "Pronto, digite algo: " << std::flush; // Flush para mostrar o prompt imediatamente

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

    std::cout << "--------------------------" << std::endl;

    // Metódos para medir a eficiência entre std::endl e '\n'
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration_endl = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // Cenário de exemplo com saída para arquivo (onde std::endl é mais custoso)
    {
        std::ofstream out_file("saida_endl.txt");
        if (out_file.is_open())
        {
            // Inicia o contador do inicio da iteração
            start = std::chrono::high_resolution_clock::now();

            // Insere no arquivo uma contagem ao contrária de 0 até 9999
            for (int i = 0; i < 10000; ++i)
            {
                out_file << i << std::endl; // Força flush a cada iteração com std::endl
            }

            // Demarca até o fim da contagem
            end = std::chrono::high_resolution_clock::now();
            out_file.close(); // Fecha o arquivo

            // Verifica a quantidade de milisegundos que foi iterar a contagem no arquivo com std::endl
            auto duration_file_endl = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
            std::cout << "Tempo com std::endl dentro de um arquivo: " << duration_file_endl.count() << " ms\n";
        }
        else
        {
            std::cout << "Erro ao abrir saida_endl.txt\n";
        }
    }

    // Cenário de exemplo com saída para arquivo (onde vemos o custo com '\n')
    {
        std::ofstream out_file("saida_n.txt");
        if (out_file.is_open())
        {
            // Inicia o contador do inicio da iteração
            start = std::chrono::high_resolution_clock::now();

            // Insere no arquivo uma contagem ao contrária de 10000 até 1
            for (int i = 10000; i > 0; --i)
            {
                out_file << i << '\n'; // Apenas nova linha('\n') a cada iteração
            }

            // Demarca até o fim da contagem
            end = std::chrono::high_resolution_clock::now();
            out_file.close(); // Fecha o arquivo

            // Verifica a quantidade de milisegundos que foi iterar a contagem no arquivo com '\n'
            auto duration_file_n = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
            std::cout << "Tempo com \\n dentro de um arquivo: " << duration_file_n.count() << " ms\n";
        }
        else
        {
            std::cout << "Erro ao abrir saida_n.txt\n";
        }
    }

    /**
     * Resumo sobre std::endl vs. '\n':
     * 1. O que é std::endl?
     *    - Insere '\n' e força flush do buffer.
     *    - Útil em prompts interativos ou depuração.
     *
     * 2. Por que std::endl parece rápido no terminal?
     *    - O terminal usa line buffering, onde '\n' já desencadeia um flush automático.
     *    - A diferença é menos perceptível em saídas pequenas.
     *
     * 3. Quando a lentidão de std::endl é mais evidente?
     *    - Em saídas para arquivos (full buffering) ou loops grandes.
     *    - O flush forçado por std::endl é custoso em disco ou saídas redirecionadas.
     *
     * 4. Boas práticas:
     *    - Use '\n' por padrão para eficiência.
     *    - Use std::endl ou std::flush apenas quando o flush for necessário (ex.: prompts).
     *    - Utilize aspas simples ('') em vez de aspas duplas ("") para tratar o caractere propriamente como um char.
     */
    return 0;
}
