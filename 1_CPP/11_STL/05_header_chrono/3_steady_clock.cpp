#include <iostream>
#include <thread>
#include <chrono>

/**
 * std::chrono::steady_clock(): É um relógio monotônico, ou seja, ele nunca retrocede.
 * Isso o torna ideal para medir duração de intervalos de tempo, como por exemplo:
 * (tempo de execução de uma função, delays em loops, tempo entre eventos).
 *
 * Diferente do std::chrono::system_clock, que pode ser ajustado pelo sistema operacional
 * e pode sofrer alterações devido à sincronização do relógio do sistema, o steady_clock
 * é um relógio que não pode retroceder. Isso significa que ele é ideal para medir
 * intervalos de tempo com precisão, sem o risco de mudanças inesperadas.
 */

/**
 * @brief Imprime caracteres '*' até o tempo limite ser atingido.
 *
 * Esta função imprime até 1500 caracteres '*' no console, mas interrompe o processo
 * caso o tempo limite especificado seja atingido antes que todos os caracteres
 * sejam impressos.
 *
 * @param tempoLimiteEmSegundos O tempo máximo (em segundos) que a função pode rodar
 * antes de ser interrompida. Se o tempo limite for atingido, o número de caracteres
 * impressos será mostrado na tela.
 */
void imprimeCaracteresAntesDoTempoAcabar(int tempoLimiteEmSegundos)
{
    // Inicia o tempo
    auto tempoIniciado = std::chrono::steady_clock::now();

    // Define o tempo limite
    auto tempoLimite = std::chrono::seconds(tempoLimiteEmSegundos);

    std::cout << "Imprimindo a quantidade de caracteres...\n";

    // Variável para contar quantos caracteres foram impressos
    int caracteresImpressos = 0;

    // Loop de impressão
    for (int i = 0; i < 1500; ++i)
    {
        // Verifica se o tempo acabou
        auto tempoDecorrido = std::chrono::steady_clock::now() - tempoIniciado;

        if (tempoDecorrido >= tempoLimite)
        {
            std::cout << "\nTempo esgotado antes de imprimir todos os caracteres.\n";
            std::cout << "Foram impressos " << caracteresImpressos << " caracteres antes do tempo acabar.\n";
            return; // Sai da função se o tempo esgotar
        }

        // Imprime o caractere
        std::cout << '*';
        caracteresImpressos++;
    }

    // Calcula o tempo total de impressão
    auto tempoDeExito = std::chrono::steady_clock::now();
    std::chrono::duration<double> tempoDeImpressao = tempoDeExito - tempoIniciado;

    // Exibe o tempo total de impressão
    std::cout << "\nImpressão completa dentro do tempo!\n";
    std::cout << "Tempo total de impressão: " << tempoDeImpressao.count() << " segundos.\n";
}

int main(int argc, char **argv)
{
    // Usando steady_clock para medir tempo
    auto inicio = std::chrono::steady_clock::now();

    // Simulando algum trabalho
    std::this_thread::sleep_for(std::chrono::seconds(2));

    auto fim = std::chrono::steady_clock::now();

    // Calculando duração
    auto duracao = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);
    std::cout << "Trabalho levou: " << duracao.count() << "ms\n";

    std::cout << "==============================================" << '\n';

    // Define o tempo limite em segundos
    int tempoLimiteEmSegundos = 5; // 5 segundos como exemplo

    // Verifica se o tempo limite é negativo
    if (tempoLimiteEmSegundos < 0)
    {
        std::cout << "Erro: O tempo limite não pode ser negativo." << '\n';
        return 1; // Encerra o programa com um código de erro
    }

    // Chama a função para imprimir caracteres dentro do tempo limite
    imprimeCaracteresAntesDoTempoAcabar(tempoLimiteEmSegundos);
    return 0;
}
