#include <iostream>
#include <string>
#include <typeinfo>
#include <any>

/**
 * std::any é um container introduzido no C++17 que permite armazenar qualquer
 * tipo de dado de forma segura e genérica. Ele fornece uma maneira de lidar com
 * tipos heterogêneos de forma similar ao que linguagens dinâmicas como Python ou
 * JavaScript oferecem, mas com a segurança de tipos do C++.
 *
 * Embora não seja tão flexível quanto os tipos dinâmicos de linguagens como Python,
 * ele fornece uma maneira segura e eficiente de lidar com heterogeneidade de tipos
 * quando necessário, mantendo as garantias de segurança do C++.
 *
 * Atenção:
 * - Se `any_cast<T>` for usado com o tipo errado, lança `std::bad_any_cast`.
 * - Pode ser usado com ponteiros (`any_cast<T*>`) para evitar exceções.
 */

int main(int argc, char **argv)
{
    // Cria um objeto std::any que pode armazenar qualquer tipo de dado
    // std::any_cast<int>(Any) lança uma exceção se o tipo não corresponder
    std::any Any = 42;                                             // Armazena um inteiro
    std::cout << "Any: " << std::any_cast<int>(Any) << '\n';       // Acessa o valor armazenado
    std::cout << "Tipo armazenado: " << Any.type().name() << '\n'; // (i) significa int

    std::cout << "--------------------------------" << '\n';

    // Troca o valor armazenado para uma string
    Any = std::string("Hello, World!");
    std::cout << "Any: " << std::any_cast<std::string>(Any) << '\n'; // Acessa o valor armazenado

    // Apesar do nome extenso impresso o tipo armazenado significa string
    std::cout << "Tipo armazenado: " << Any.type().name() << '\n';

    std::cout << "--------------------------------" << '\n';

    try
    {
        std::cout << "Any: " << std::any_cast<double>(Any) << '\n'; // Tenta acessar como double
    }
    catch (const std::bad_any_cast &e)
    {
        std::cout << "Erro: " << e.what() << '\n'; // Captura a exceção se o tipo não corresponder
    }

    std::cout << "--------------------------------" << '\n';

    Any.reset(); // Remove o conteúdo armazenado
    if (Any.has_value())
    {
        std::cout << "Any: " << std::any_cast<int>(Any) << '\n'; // Acessa o valor armazenado
    }
    else
    {
        std::cout << "Any: vazio\n"; // Verifica se o objeto está vazio
    }

    std::cout << "--------------------------------" << '\n';

    if (int *p = std::any_cast<int>(&Any))
    {
        std::cout << "Valor inteiro: " << *p << '\n';
    }
    else
    {
        std::cout << "Any não contém um int\n";
    }

    Any = 42.0; // Armazena agora um double
    if (double *p = std::any_cast<double>(&Any))
    {
        std::cout << "Valor double: " << *p << '\n';
    }
    else
    {
        std::cout << "Any não contém um double\n";
    }

    return 0;
}
