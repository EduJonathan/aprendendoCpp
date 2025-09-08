#include <iostream>
#include <cstring>

// Função que usa memmove para copiar regiões de memória sobrepondo-se
void test_memmove(void)
{
    char str[] = "Hello, World!";

    // Usando memmove para copiar regiões de memória sobrepondo-se
    std::memmove(str + 7, str, 5);
    str[12] = '\0'; // Null-terminar a string

    std::cout << str << '\n'; // Saída: "Hello, Hello!"
    std::cout << "----------------------------------------" << '\n';
}

// Função que usa memcpy para copiar dados entre arrays
void test_memcpy(void)
{
    char src[] = "Hello, World!";
    char dest[20] = "";

    // Usando memcpy para copiar a string
    std::memcpy(dest, src, strlen(src) + 1);

    std::cout << "Destino " << dest << '\n';
    std::cout << "----------------------------------------" << '\n';
}

// Função que compara dois buffers com memcmp
void test_memcmp(void)
{
    char buffer1[] = "DWgaOtP12df0";
    char buffer2[] = "DWGAOTP12DF0";

    int result = std::memcmp(buffer1, buffer2, sizeof(buffer1));

    if (result > 0)
    {
        std::cout << '\'' << buffer1 << "' é maior que '" << buffer2 << '\n';
    }
    else if (result < 0)
    {
        std::cout << '\'' << buffer1 << "' é menor que '" << buffer2 << '\n';
    }
    else
    {
        std::cout << '\'' << buffer1 << "' é o mesmo que '" << buffer2 << '\n';
    }
    std::cout << "----------------------------------------" << '\n';
}

// Função que usa memchr para encontrar um caractere na memória
void test_memchr(void)
{
    const char data[] = "Hello, world!";
    char target = 'o';

    // Usando memchr para encontrar o caractere 'o'
    char *resultado = (char *)std::memchr(data, target, sizeof(data));
    if (resultado != NULL)
    {
        std::cout << "Encontrado '" << target << "' na posição: " << (resultado - data) << '\n';
    }
    else
    {
        std::cout << "Caractere não encontrado!" << '\n';
    }
}

int main(int argc, char **argv)
{
    /**
     * memmove(): Semelhante ao memcpy, mas seguro para cópias em regiões de memória sobrepostas.
     *
     * SINTAXE: void *memmove(void* dest, const void* src, size_t n);
     * Os parâmetros e uso é semelhante ao memcpy, mas ideal para quando dest e src se sobrepõem.
     */
    test_memmove();

    /**
     * memcpy(): Copia um bloco de memória de uma posição para outra.
     *
     * SINTAXE: void* memcpy(void* dest, const void* src, size_t n);
     *
     * PARAMETROS:
     *
     * @param dest Ponteiro para o destino.
     * @param src Ponteiro para a origem.
     * @param n Número de bytes a copiar.
     */
    test_memcpy();

    /**
     * memcmp(): Compara dois blocos de memória byte a byte.
     *
     * SINTAXE: int memcmp(const void* ptr1, const void* ptr2, size_t n);
     *
     * PARAMETROS:
     *
     * @param ptr1 e ptr2 Ponteiros para os blocos de memória.
     * @param n Número de bytes a comparar.
     * @return 0 se os blocos forem iguais.
     * Valor negativo se ptr1 for menor que ptr2.
     * Valor positivo se ptr1 for maior que ptr2.
     */
    test_memcmp();

    /**
     * memchr(): É usada para localizar a primeira ocorrência de um valor específico em um
     * bloco de memória. Ela é útil para buscar um byte (caractere ou outro valor) em uma
     * sequência de bytes.
     *
     * SINTAXE: void *memchr(const void* ptr, int value, size_t n);
     *
     * PARAMETROS:
     *
     * @param ptr Ponteiro para o bloco de memória onde será feita a busca.
     * @param value O valor a ser procurado, do tipo int. Este valor será convertido para um
     * unsigned char antes da busca.
     * @param n O número de bytes a serem analisados a partir do endereço indicado por ptr.
     * @return Retorna um ponteiro para a primeira ocorrência do valor value dentro do
     * bloco de memória, ou NULL caso o valor não seja encontrado.
     */
    test_memchr();

    return 0;
}
