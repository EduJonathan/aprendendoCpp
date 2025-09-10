#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

/**
 * Ponteiro para função?
 * Um ponteiro para função é uma variável que armazena o endereço de uma função,
 * permitindo que a função seja chamada através desse endereço, em vez de diretamente
 * pelo nome. Isso é útil quando queremos passar funções como argumentos para outras
 * funções, ou quando queremos escolher dinamicamente qual função chamar.
 *
 * Como funciona o ponteiro para função no C/C++?
 * No C/C++, um ponteiro para função é declarado especificando o
 * tipo de retorno e os tipos de parâmetros da função que ele pode apontar.
 *
 * Por exemplo:
 * // Declaração de um ponteiro para função que recebe uma string, dois inteiros, e retorna void
 * typedef void (*OperacaoTextoOld)(std::string &, int, int);
 */

// Área de transferência
std::string clipboard;

/**
 * @typedef OperacaoTextoOld
 *
 * @brief Tipo de ponteiro para função no estilo C, que aceita uma string,
 * um índice de início e um tamanho como parâmetros.
 */
typedef void (*OperacaoTextoOld)(std::string &, int, int); // Estilo C

/**
 * @typedef OperacaoTexto
 *
 * @brief Tipo de ponteiro para função moderno usando std::function do C++11,
 * que também recebe uma string, um índice de início e um tamanho como parâmetros.
 */
using OperacaoTexto = std::function<void(std::string &, int, int)>; // Estilo moderno C++

/**
 * @brief Função que simula a operação de copiar um trecho de texto para a área de transferência.
 *
 * @param texto String de onde o trecho será copiado.
 * @param inicio Posição inicial do trecho a ser copiado.
 * @param tamanho Quantidade de caracteres a serem copiados.
 */
void copiar(std::string &texto, int inicio, int tamanho)
{
    if (inicio >= 0 && inicio + tamanho <= texto.size())
    {
        clipboard = texto.substr(inicio, tamanho);
        std::cout << "Copiado: \"" << clipboard << "\"\n";
    }
    else
    {
        std::cout << "Intervalo inválido para copiar.\n";
    }
}

/**
 * @brief Função que simula a operação de recortar um trecho de texto (copiar + apagar).
 *
 * @param texto String de onde o trecho será recortado.
 * @param inicio Posição inicial do trecho a ser recortado.
 * @param tamanho Quantidade de caracteres a serem recortados.
 */
void recortar(std::string &texto, int inicio, int tamanho)
{
    if (inicio >= 0 && inicio + tamanho <= texto.size())
    {
        clipboard = texto.substr(inicio, tamanho);
        texto.erase(inicio, tamanho);
        std::cout << "Recortado: \"" << clipboard << "\"\n";
        std::cout << "Após recorte: " << texto << '\n';
    }
    else
    {
        std::cout << "Intervalo inválido para recortar.\n";
    }
}

/**
 * @brief Função que simula a operação de colar um trecho de texto da área de transferência
 * em uma posição específica de uma string.
 *
 * @param texto String onde o conteúdo será colado.
 * @param posicao Posição onde o conteúdo será inserido.
 * @param ignorado Parâmetro adicional que não é utilizado.
 */
void colar(std::string &texto, int posicao, int = 0)
{
    // Parâmetro adicional ignorado
    if (posicao >= 0 && posicao <= texto.size())
    {
        texto.insert(posicao, clipboard);
        std::cout << "Após colar: " << texto << '\n';
    }
    else
    {
        std::cout << "Posição inválida para colar.\n";
    }
}

/**
 * @brief Função que aplica uma operação sobre uma string usando um ponteiro para função.
 *
 * @param texto String sobre a qual a operação será realizada.
 * @param operacao Função que executa a operação sobre a string.
 * @param arg1 Primeiro argumento da operação.
 * @param arg2 Segundo argumento da operação (opcional, padrão é 0).
 */
void operarString(std::string &texto, OperacaoTexto operacao, int arg1, int arg2 = 0)
{
    operacao(texto, arg1, arg2);
}

int main(int argc, char **argv)
{
    // Demonstração dos diferentes tipos de ponteiros para funções
    std::string texto = "Programando em C++ é poderoso!";

    // 1. Usando o typedef tradicional (estilo C)
    OperacaoTextoOld op_old = copiar;

    // 2. Usando std::function (moderno C++)
    OperacaoTexto op1 = copiar;
    OperacaoTexto op2 = recortar;
    OperacaoTexto op3 = colar; // Agora funciona mesmo com assinatura diferente

    // 3. Usando lambda (C++11)
    OperacaoTexto op4 = [](std::string &txt, int inicio, int tam)
    {
        std::cout << "Lambda: invertendo trecho...\n";
        if (inicio >= 0 && inicio + tam <= txt.size())
        {
            std::string trecho = txt.substr(inicio, tam);
            std::reverse(trecho.begin(), trecho.end());
            txt.replace(inicio, tam, trecho);
        }
    };

    std::cout << "Texto original: \"" << texto << "\"\n\n";

    // Testando as operações
    operarString(texto, op1, 12, 5); // Copiar "C++ é"
    operarString(texto, op3, 0);     // Colar no início
    operarString(texto, op2, 7, 6);  // Recortar "ndo em"
    operarString(texto, op4, 0, 8);  // Inverter os primeiros 8 caracteres

    std::cout << "\nTexto final: \"" << texto << "\"\n";
    std::cout << "Clipboard: \"" << clipboard << "\"\n";

    return 0;
}
