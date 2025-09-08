#include <iostream>
#include <cstring>

/**
 * std::strstr(): Procura uma substring dentro de outra string.
 *
 * SINTAXE: inline char *strstr(char *__s1, const char *__s2);
 *
 * @param __s1 A string onde a busca será realizada.
 * @param __s2 A substring que está sendo procurada.
 * @return Retorna um ponteiro para a primeira ocorrência da substring, ou NULL se não for encontrada.
 */

int main(int argc, char **argv)
{
    char string[] = "Brilha Brilha Estrelinha";
    char *isSubstring = std::strstr(string, "ilha");
    std::size_t position = 0ull;

    while (isSubstring != NULL)
    {
        // Calculando a posição inicial da substring encontrada
        position = isSubstring - string;
        std::cout << "Substring encontrada na posição: " << position << '\n';

        // Avança o ponteiro para procurar a próxima ocorrência
        isSubstring = std::strstr(isSubstring + 1, "ilha");
    }

    std::cout << "---------------------------" << '\n';

    char listaDeCompras[] = {"Arroz, Feijão, Sabão, Óleo"};
    const char elementoExistente[] = "Carne";

    // Checa elemento na lista
    char *existe = std::strstr(listaDeCompras, elementoExistente);

    std::cout << "Sua lista de compras: " << listaDeCompras << '\n';

    // Checa se o item  está ou não na lista
    if (existe != NULL)
    {
        std::cout << "O item '" << elementoExistente << "' já está na lista!" << '\n';
    }
    else
    {
        std::cout << "O item '" << elementoExistente << "' não está na lista." << '\n';
    }
    return 0;
}
