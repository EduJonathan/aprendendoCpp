#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

// Área de transferência
std::string clipboard;

// Tipos de operações usando typedef e using (C++11)
typedef void (*OperacaoTextoOld)(std::string &, int, int);          // Estilo C
using OperacaoTexto = std::function<void(std::string &, int, int)>; // Moderno C++

// Funções de operação de texto
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

// Função que aplica operação (agora mais genérica)
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
