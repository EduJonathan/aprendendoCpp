#include <iostream>
#include <string>
#include <memory>
#include <utility>
#include <cstddef>
#include <cstdlib>
#include <typeinfo>
#include <cxxabi.h> // Para abi::__cxa_demangle, que irá ajudar a imprimir nomes legíveis dos tipos
#include <tuple>

// Função para demangle o nome do tipo
std::string demangle(const char *mangled)
{
    int status = -1;
    std::unique_ptr<char[], void (*)(void *)> result(
        abi::__cxa_demangle(mangled, nullptr, nullptr, &status),
        std::free);
    return (status == 0) ? result.get() : mangled;
}

template <typename TupleLike, std::size_t I = 0>
void printTypes()
{
    if constexpr (I == 0)
    {
        std::cout << demangle(typeid(TupleLike).name()) << '\n';
    }

    if constexpr (I < std::tuple_size_v<TupleLike>)
    {
        using SelectedType = std::tuple_element_t<I, TupleLike>;

        std::cout << "  The type at index " << I << " is: " << demangle(typeid(SelectedType).name()) << '\n';
        printTypes<TupleLike, I + 1>();
    }
}

struct MyStruct {};

using MyTuple = std::tuple<int, long &, const char &, bool &&, std::string, volatile MyStruct>;
using MyPair = std::pair<char, bool &&>;

static_assert(std::is_same_v<std::tuple_element_t<0, MyPair>, char>);
static_assert(std::is_same_v<std::tuple_element_t<1, MyPair>, bool &&>);

int main(int argc, char **argv)
{
    printTypes<MyTuple>();
    printTypes<MyPair>();
    return 0;
}
