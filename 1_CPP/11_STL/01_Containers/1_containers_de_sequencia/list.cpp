#include <iostream>
#include <list>

/**
 * std::list<T> é um container que implementa uma lista duplamente encadeada,
 * permitindo inserções e remoções rápidas em qualquer posição.
 */

/**
 * @brief Soma dois números representados por listas em ordem reversa.
 *
 * Cada lista contém os dígitos de um número em ordem reversa, ou seja, o dígito
 * menos significativo vem primeiro. A função retorna a soma dos dois números
 * também em formato de lista reversa.
 *
 * @param l1 Primeira lista.
 * @param l2 Segunda lista.
 * @return Lista contendo o resultado da soma.
 */
std::list<int> somarListasReversas(const std::list<int> &l1, const std::list<int> &l2)
{
    std::list<int> resultado;
    auto it1 = l1.begin();
    auto it2 = l2.begin();
    int carry = 0;

    while (it1 != l1.end() || it2 != l2.end() || carry != 0)
    {
        int soma = carry;

        if (it1 != l1.end())
        {
            soma += *it1;
            ++it1;
        }

        if (it2 != l2.end())
        {
            soma += *it2;
            ++it2;
        }

        resultado.push_back(soma % 10);
        carry = soma / 10;
    }
    
    // A lista resultado já está em ordem reversa, então não é necessário inverter.
    return resultado;
}

int main(int argc, char **argv)
{
    // Representa os números 342 e 465 como listas: 2->4->3 e 5->6->4
    std::list<int> numero1 = {2, 4, 3};
    std::list<int> numero2 = {5, 6, 4};

    // Soma as listas
    std::list<int> resultado = somarListasReversas(numero1, numero2);

    // Exibe o resultado: esperado 7->0->8 (807)
    std::cout << "Resultado da soma: ";
    for (int digito : resultado)
    {
        std::cout << digito << "->";
    }
    std::cout << "nullptr\n";

    return 0;
}
