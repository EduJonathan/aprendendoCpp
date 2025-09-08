#include <iostream>
#include <string>
#include <cstring>

int main(int argc, char **argv)
{
    // Array de std::string
    std::string conjuntoDeNome[]{"Eduardo", "Pedro", "Luana", "Juliana"};

    // Array de const char*
    const char *Nomes[] = {"Eduardo", "pedro", "Luana", "Juliana"};

    // Para Comparar lexicograficamente
    bool iguais = true;

    // Verificando se as strings nos arrays são lexicograficamente iguais
    // c_str: Retorna um ponteiro para um array de caracteres terminada em nulo com dados
    // equivalentes aos armazenados na cadeia de caracteres.
    for (int i = 0; i < 4; ++i)
    {
        if (std::strcmp(conjuntoDeNome[i].c_str(), Nomes[i]) != 0)
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
