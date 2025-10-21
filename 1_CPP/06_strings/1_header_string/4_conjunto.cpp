#include <iostream>
#include <cstring>
#include <string>

int main(int argc, char **argv)
{
    // Array de std::string
    std::string conjuntoDeNome[]{"Eduardo", "Pedro", "Luana", "Juliana"};

    // Array de const char*
    const char *Nomes[] = {"Eduardo", "pedro", "Luana", "Juliana"};

    // Para Comparar lexicograficamente
    bool iguais = true;

    // Tamanho do array
    const std::size_t TAMANHO = sizeof(Nomes) / sizeof(Nomes[0]);

    // Verificando se as strings nos arrays são lexicograficamente iguais
    for (std::size_t i = 0; i < TAMANHO; ++i)
    {
        if (conjuntoDeNome[i] != Nomes[i])
        {
            iguais = false;
            std::cout << "Os nomes são diferentes em índice "
                      << i << ": " << conjuntoDeNome[i] << " != " << Nomes[i] << '\n';
        }
    }

    if (iguais)
    {
        std::cout << "Todos os nomes são lexicograficamente iguais!" << '\n';
    }
    else
    {
        std::cout << "Os nomes não são lexicograficamente iguais!" << '\n';
    }
    return 0;
}
