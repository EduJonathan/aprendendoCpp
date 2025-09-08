#include <iostream>
#include <string_view>

/**
 * std::string_view: É uma visão leve de uma string, que não realiza cópias desnecessárias.
 * Ele é útil para manipulação eficiente de strings, especialmente em contextos onde
 * a performance é crítica.
 *
 * Seus benefícios incluem:
 * *Eficiência*: std::string_view evita a cópia de dados, reduzindo a sobrecarga de memória.
 * *Flexibilidade*: Pode se referir a qualquer sequência contígua de caracteres,
 * inclusive cadeias de caracteres C e objetos std::string.
 */

int main(int argc, char **argv)
{
    std::string_view stringView1 = "Hello, World!";
    std::string_view stringView2 = "Hello, World.";

    std::cout << "As strings são: " << (stringView1 == stringView2 ? "Iguais" : "Diferentes") << '\n';

    std::cout << "--------------------------------" << '\n';
    std::cout << "\tREMOVE PREFIX" << '\n';

    std::string_view stringView = "Linguagem C++ é incrível!";

    std::cout << "Original: " << stringView << '\n';
    stringView.remove_prefix(7); // Remove "Linguagem "
    std::cout << "Modificado: " << stringView << '\n';

    std::cout << "--------------------------------" << '\n';
    std::cout << "\tREMOVE SUFFIX" << '\n';

    std::string_view string_View = "Você está gostando de C++?";

    std::cout << "Original: " << string_View << '\n';
    string_View.remove_suffix(12); // Remove "ando de C++?"
    std::cout << "Modificado: " << string_View << '\n';

    std::cout << "--------------------------------" << '\n';
    std::cout << "\tFIND" << '\n';

    std::string_view str = "Mundo!";
    std::cout << "String: " << str << '\n';
    std::cout << "Tamanho: " << str.size() << '\n';

    // Encontrar a posição da substring "Mundo"
    std::size_t pos = str.find("Mundo");
    if (pos != std::string_view::npos)
    {
        // Se encontrado, exibe a posição
        std::cout << "Encontrado na posição: " << pos << '\n';
    }
    return 0;
}
