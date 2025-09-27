/*
 * Não é necessário incluir bibliotecas externas, pois podemos utilizar funções nativas
 * da linguagem C, como a `printf`, que podem ser declaradas explicitamente em C++ com
 * a palavra-chave `extern "C"`. Isso permite que utilizemos a função de forma compatível
 * com a convenção de chamada da linguagem C.
 *
 * No exemplo abaixo, a função `printf` é declarada com a assinatura tradicional de C,
 * e posteriormente é utilizada no código principal para imprimir uma mensagem.
 */

extern "C"
{
    // Declara a função printf conforme a convenção de chamada da linguagem C
    int printf(const char *format, ...);

    // Da mesma forma, outras funções como scanf podem ser declaradas, se necessário:
    // int scanf(const char *format, ...);
}

int main(int argc, char **argv)
{
    // Chama a função printf (declarada externamente) para imprimir uma mensagem
    printf("Utilizando a função printf em C++\n");

    return 0;
}
