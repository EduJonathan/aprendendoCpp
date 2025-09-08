#include <iostream>
#include <cstring>

/**
 * std::strxfrm(): Função em C++ usada para transformar uma string em uma forma que
 * pode ser comparada diretamente usando funções de comparação de strings padrão,
 * como o std::strcmp.
 *
 * SINTAXE: size_t strxfrm(char *__restrict__ _Dst, const char *__restrict__ _Src, size_t _MaxCount);
 *
 * PARAMETROS:
 * @param dest Um ponteiro para a string de destino onde a transformação será armazenada.
 * @param src A string de entrada que será transformada.
 * @param count O número máximo de caracteres a serem copiados para dest, incluindo o caractere
 * nulo de terminação.
 * @return Retorna o comprimento da string transformada (sem contar o caractere nulo).
 * Se o valor retornado for maior ou igual a count, a string no destino não é válida.
 */

int main(int argc, char **argv)
{
    // Define o locale para Português do Brasil
    std::setlocale(LC_COLLATE, "pt_BR.UTF-8");

    // String de entrada
    const char *src = "maçã";

    // Buffer de destino
    char dest[100] = "";

    // Transforma a string para uso em comparação
    std::size_t len = std::strxfrm(dest, src, sizeof(dest));

    // Exibe a string transformada (apenas para demonstração)
    std::cout << "Tamanho da string transformada: " << len << '\n';
    std::cout << "String transformada: " << dest << '\n';
    return 0;
}
