#include <iostream>
#include <string>
#include <stdexcept>

/**
 * noexcept é uma especificação que indica que uma função não deve lançar exceções.
 * A expressão const noexcept é uma especificação que indica que uma função não deve lançar exceções.
 *
 * DIFERENÇA ENTRE `noexcept` E `const noexcept`
 *
 * `noexcept` se aplica a *funções* e indica que elas não devem lançar exceções.
 *
 * `const noexcept` se aplica a métodos de *classe* e indica que eles não devem lançar exceções
 * e não alteram o estado do objeto.
 */

// Função não-membro com noexcept
void safe_function() noexcept
{
    std::cout << "Esta função não lança exceções.\n";
}

// Função condicionalmente noexcept
template <typename T>
void process(T value) noexcept(std::is_nothrow_copy_constructible_v<T>)
{
    std::cout << "Processando: " << value << '\n';
}

class MyClass
{
    int data = 0;

public:
    // Método const noexcept: não modifica o objeto e não lança exceções
    int get_data() const noexcept
    {
        return data;
    }

    // Método apenas const: pode lançar exceções
    std::string get_description() const
    {
        // Pode lançar std::bad_alloc se a string for grande
        return "Objeto com data: " + std::to_string(data);
    }

    // Método apenas noexcept: pode modificar o objeto
    void set_data(int value) noexcept
    {
        data = value;
    }

    // Método sem modificadores: pode modificar e lançar exceções
    void risky_operation()
    {
        throw std::runtime_error("Erro!");
    }
};

int main(int argc, char **argv)
{
    safe_function(); // Chama função que nunca lança exceções
    process(42);     // Chama função que é noexcept se T for seguro

    MyClass obj;
    std::cout << "Data: " << obj.get_data() << '\n'; // Chama const noexcept
    obj.set_data(42);                                // Chama noexcept
    std::cout << obj.get_description() << '\n';      // Chama const

    try
    {
        obj.risky_operation(); // Pode lançar exceção
    }
    catch (const std::exception &e)
    {
        std::cout << "Exceção capturada: " << e.what() << '\n';
    }
    return 0;
}
