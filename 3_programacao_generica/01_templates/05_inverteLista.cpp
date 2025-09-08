#include <iostream>
#include <list>
#include <string>
#include <iterator>
#include <algorithm>

/**
 * @class InverterLista
 *
 * Classe para inverter uma lista
 *
 * @param T tipo da lista
 */
template <class T>
class InverterLista
{
public:
    /**
     * @brief inverter a lista
     *
     * Metodo para inverter uma lista
     *
     * @param list lista para receber como parâmetro e a ser invertida
     */
    std::list<T> inverter(std::list<T> list)
    {
        // Método de inversão STL, usando iteradores para inverter a lista
        list.reverse();
        return list;
    }

    /**
     * @brief representar a lista como string
     *
     * Metodo para representar a lista como string
     *
     * @param list lista para receber como parâmetro e a ser representada
     */
    std::string toString(const std::list<T> &list)
    {
        std::string str = "Lista";

        // Iterando sobre os elementos da lista, pecorrendo com o for-each
        for (const T &element : list)
        {
            // Concatena os elementos da lista, o to_string converte os elementos para string
            str += ' ' + std::to_string(element);
        }

        // Retorna a string invertida
        return str;
    }
};

int main(int argc, char **argv)
{
    // Declarando a lista
    std::list<int> list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    InverterLista<int> inverter; // Criando uma instância da classe InverterLista

    std::cout << "Original: " << inverter.toString(list) << '\n'; // Exibindo a lista original
    std::list<int> inverted = inverter.inverter(list);            // Invertendo a lista

    // Exibindo a lista invertida, toString retorna uma string com os elementos da lista
    std::cout << "Invertida: " << inverter.toString(inverted) << '\n';
    return 0;
}
