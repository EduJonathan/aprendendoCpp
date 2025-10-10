#include <iostream>

/**
 * Use namespace para organizar e proteger nomes.
 * Use using para facilitar o uso de nomes já definidos em um namespace.
 * Evite using namespace em arquivos .h ou em projetos grandes, para não gerar conflitos.
 */

namespace util
{
    void saudacao()
    {
        std::cout << "Oi do namespace util!\n";
    }
}

using namespace std;  // evita escrever std::
using util::saudacao; // evita escrever util::

int main(int argc, char **argv)
{
    saudacao(); // usa diretamente, sem util:: ou std::
    cout << "Fim do exemplo!\n";
    return 0;
}
