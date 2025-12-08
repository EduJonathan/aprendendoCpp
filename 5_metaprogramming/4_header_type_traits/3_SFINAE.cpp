#include <iostream>
#include <vector>
#include <stdexcept>
#include <type_traits>

/**
 * SFINAE (Substitution Failure Is Not An Error) é uma técnica avançada em C++ que permite a
 * seleção condicional de templates durante a compilação.
 * O que é SFINAE?
 *
 * É quando o compilador tenta instanciar um template e encontra um erro durante a substituição de parâmetros,
 * em vez de gerar um erro de compilação, ele simplesmente descarta essa especialização específica e continua
 * procurando outras alternativas válidas.
 */

template <typename Container>
class SafeWrapper
{
private:
    Container &container;

public:
    SafeWrapper(Container &c) : container(c) {}

    // Só disponível se Container tiver operator[]
    template <typename C = Container>
    auto at(std::size_t index) -> decltype(std::declval<C>()[index], typename C::value_type{})
    {
        if (index >= container.size())
        {
            throw std::out_of_range("Índice fora dos limites");
        }
        return container[index];
    }

    // Só disponível se Container tiver método size()
    template <typename C = Container>
    auto get_size() -> decltype(std::declval<C>().size(), std::size_t{})
    {
        return container.size();
    }
};

int main(int argc, char **argv)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    SafeWrapper wrapper(vec);

    std::cout << "Tamanho: " << wrapper.get_size() << '\n';
    std::cout << "Elemento 2: " << wrapper.at(2) << '\n';

    return 0;
}
