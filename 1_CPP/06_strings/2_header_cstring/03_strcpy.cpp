#include <iostream>
#include <string>
#include <cstring>

/**
 * std::strcpy(): Função de cópia, que cópia uma o parâmetro _Source para _Dest
 *
 * SINTAXE: char *strcpy(char *__restrict__ _Dest, const char *__restrict__ _Source);
 *
 * @param _Source Parâmetro de string recebida para cópia.
 * @param _Dest Parâmetro de string que recebe a cópia.
 * @return Retorna um ponteiro para _Dest após a cópia.
 *
 * -------------------------------------------------------
 *
 * std::strncpy(): Função de cópia, que copia até `n` caracteres de _Source para _Dest.
 * A cópia é limitada ao número de caracteres especificado, o que pode evitar
 * transbordamento de memória.
 *
 * SINTAXE: char *strncpy(char *__restrict__ _Dest, const char *__restrict__ _Source, size_t _Count);
 *
 * @param _Source Ponteiro para a string de origem a ser copiada.
 * @param _Dest Ponteiro para a string de destino que receberá a cópia.
 * @param _MaxCount Número máximo de caracteres a serem copiados de _Source para _Dest.
 * @return Retorna um ponteiro para _Dest após a cópia.
 */

int main(int argc, char **argv)
{
    // Parte 1: Copiando com std::strcpy
    char texto[] = "C++";
    char copiarTexto[10] = ""; // Garantir que o tamanho seja suficiente

    std::strcpy(copiarTexto, texto);

    std::cout << "Conteúdo de `copiarTexto`: " << copiarTexto << '\n';

    std::cout << "-----------------------------------" << '\n';

    // Parte 2: Copiando com std::strncpy
    char text[20] = "";                     // Garantir que o array tenha espaço suficiente
    const char *destino = "String Copiada"; // String para copiar

    std::strncpy(text, destino, sizeof(text) - 1); // Copiar até 19 caracteres
    text[sizeof(text) - 1] = '\0';                 // Garantir a terminação nula

    std::cout << "Conteúdo de `text`: " << text << '\n';

    std::cout << "-----------------------------------" << '\n';

    /**
     * O std::strncpy não funciona diretamente com objetos do tipo std::string porque
     * ele foi projetado para trabalhar com arrays de caracteres (char[]), não com
     * objetos std::string.
     *
     * Exemplo de uso incorreto:
     *
     * std::string strCopiar;
     * std::string strCopia = "String Copiada Com Sucesso";
     * std::strncpy(strCopia, strCopiar, 15);
     */

    // Parte 3: Trabalhando com std::string
    std::string strCopiar = "";
    std::string strCopia = "String Copiada Com Sucesso";

    // Usando substr() para copiar os primeiros 15 caracteres
    strCopiar = strCopia.substr(0, 15); // Copia os primeiros 15 caracteres

    std::cout << "Conteúdo de `strCopiar`: " << strCopiar << '\n';
    return 0;
}
