#include <iostream>
#include <cstdlib>

// std::getenv(): Exibie diretórios e subdiretótios de uma determinada variável ambiente do sistema.

int main(int argc, char **argv)
{
    if (const char *diretorio = std::getenv("PATH"))
        std::cout << "diretório PATH: " << diretorio << '\n';
    return 0;
}
