#include <iostream>
#include <cstring>

/**
 * std::strerror(): Função em C++ é usada para converter códigos de erro em mensagens
 * de erro legíveis. Basicamente retorna uma string descritiva correspondente ao código
 * de erro passado como argumento.
 *
 * SINTAXE: char *strerror(int errnum);
 *
 * PARAMETROS:
 * @param errnum Um inteiro que representa o código do erro. Geralmente, este valor é
 * obtido a partir da variável global errno, que é definida por funções padrão da biblioteca
 * C sempre que ocorre um erro. Cada código de erro corresponde a uma mensagem específica.
 *
 * @return Retorna um ponteiro para uma string (char*) contendo a mensagem de erro
 * correspondente ao código passado no parâmetro errnum. Caso o código de erro fornecido
 * não seja válido, a mensagem retornada geralmente será algo genérico, como "Unknown error".
 */

int main(int argc, char **argv)
{
    int erro = 2;
    const char *mensagemErro = std::strerror(erro);

    std::cout << "Código de erro: " << erro << " - " << mensagemErro << '\n';
    return 0;
}
