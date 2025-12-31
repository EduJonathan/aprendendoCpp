#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Função para imprimir qualquer contêiner de strings
template <typename T>
void print(const T &container);

template <typename T>
void print(const T &container)
{
    for (const auto &elem : container)
    {
        std::cout << elem << '\n';
    }
    std::cout << "-----\n"; // Separador visual
}

int main(int argc, char **argv)
{
    // Inicialização direta dos vetores
    std::vector<char> grupoCaracteres1{'A', 'B', 'C'};
    std::vector<char> grupoCaracteres2{'D', 'E', 'F', 'G'};

    std::cout << "Grupo 1 inicial:\n";
    print(grupoCaracteres1);

    // Ordena o grupo 1
    std::sort(grupoCaracteres1.begin(), grupoCaracteres1.end());
    std::cout << "Grupo 1 ordenado:\n";
    print(grupoCaracteres1);

    std::cout << "Grupo 2:\n";
    print(grupoCaracteres2);

    // Concatenar grupo 2 no início do grupo 1
    grupoCaracteres1.insert(grupoCaracteres1.begin(), grupoCaracteres2.begin(), grupoCaracteres2.end());
    std::cout << "Após inserção do Grupo 2 no início:\n";
    print(grupoCaracteres1);

    // Ordena novamente
    std::sort(grupoCaracteres1.begin(), grupoCaracteres1.end());
    std::cout << "Grupo 1 final ordenado:\n";
    print(grupoCaracteres1);

    return 0;
}
