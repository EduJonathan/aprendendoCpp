/*
 * Sem necessitar incluir nenhuma biblioteca, podemos utilizar a função printf da
 * biblioteca stdio.h, e criar uma função que recebe uma string formatada e os
 * argumentos que ela recebe.
 */

extern "C"
{
    // Declara a função printf como se fosse uma função C
    int printf(const char *format, ...);

    // A mesma abordagem pode ser usada para outras funções como scanf:
    // int scanf(const char *format, ...);
}

int main(int argc, char **argv)
{
    // Chama a função printf declarada externamente para imprimir uma mensagem
    printf("Utilizando a função printf em C++\n");

    return 0;
}
