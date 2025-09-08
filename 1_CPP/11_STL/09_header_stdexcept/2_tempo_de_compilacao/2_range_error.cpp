#include <iostream>
#include <stdexcept>

/**
 * std::range_error(): é uma exceção padrão da biblioteca C++ que indica que um valor está
 * fora do intervalo esperado. Ela é uma subclasse de std::logic_error e é usada para indicar
 * erros lógicos relacionados a intervalos de valores.
 */

void verificaValor(int valor)
{
    if (valor < 0 || valor > 100)
    {
        throw std::range_error("Valor fora do intervalo permitido!");
    }
    else
    {
        std::cout << "Valor dentro do intervalo." << '\n';
    }
}

int main(int argc, char **argv)
{
    try
    {
        verificaValor(150); // Este valor causará uma exceção
    }
    catch (const std::range_error &e)
    {
        std::cerr << "Erro capturado: " << e.what() << '\n';
    }
    
    return 0;
}
