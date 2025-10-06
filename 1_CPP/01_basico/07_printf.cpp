/*
 * Não é necessário incluir bibliotecas externas, pois podemos utilizar funções nativas
 * da linguagem C, como a `printf`, que podem ser declaradas explicitamente em C++ com
 * a palavra-chave `extern "C"`. Isso permite que utilizemos a função de forma compatível
 * com a convenção de chamada da linguagem C.
 *
 * No exemplo abaixo, a função `printf` é declarada com a assinatura tradicional de C,
 * e posteriormente é utilizada no código principal para imprimir uma mensagem.
 *
 * Em C++, para que alguns headers que vem da linguagem C serem utilizados de maneira
 * compatível em C++, temos que usar o prefixo `c` e remover a extensão `.h`.
 *
 * Por exemplo,
 * `#include <cstdio>` em vez de `#include <stdio.h>`.
 * `#include <cstdlib>` em vez de `#include <stdlib.h>`.
 * `#include <cstring>` em vez de `#include <string.h>`.
 * `#include <cmath>` em vez de `#include <math.h>`.
 * `#include <cstddef>` em vez de `#include <stddef.h>`.
 * `#include <cstdint>` em vez de `#include <stdint.h>`.
 * `#include <cctype>` em vez de `#include <ctype.h>`.
 * e assim por diante.
 *
 * Além disso, essas versões C++ dos headers da linguagem C podemos em funções
 * utilizando o namespace `std`, o que ajuda a evitar conflitos de nomes, exemplo:
 * `std::pow`, `std::strlen`, `std::malloc`, `std::atoi`, `std::abs` e assim por diante.
 *
 * Mas no exemplo abaixo, não estamos incluindo nenhum header, apenas declarando
 * a função `printf` diretamente com `extern "C"`.
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
