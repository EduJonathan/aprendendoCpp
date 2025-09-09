#include <iostream>
#include <string_view>

/**
 * std::string_view é uma classe introduzida no C++17 que fornece uma visão não-destrutiva
 * e leve de uma sequência de caracteres (uma string). Ela é usada para manipular strings
 * sem possuir ou copiar os dados, apenas referenciando uma sequência de caracteres existente.
 * Isso a torna eficiente para cenários onde você quer evitar cópias desnecessárias.
 *
 * Características principais:
 * - Não possui os dados: std::string_view armazena apenas um ponteiro para os dados e o tamanho da sequência.
 * - Os dados reais pertencem a outra fonte (como uma std::string, um array de caracteres, ou uma string literal).
 * - Imutável: Você não pode modificar os caracteres através de um std::string_view (é uma visão de leitura).
 * - Leve: Como não copia os dados, é muito eficiente em termos de memória e desempenho.
 *
 * - Segura: Garante que a string referenciada seja válida enquanto o std::string_view estiver
 * em uso, mas você deve garantir que os dados originais não sejam destruídos antes do std::string_view.
 *
 * Quando usar?
 * - Quando você precisa passar strings para funções sem fazer cópias.
 * - Para manipular substrings sem alocar memória adicional.
 * - Para trabalhar com strings literais ou buffers de caracteres.
 *
 * Cuidados:
 * Tempo de vida: std::string_view não gerencia a memória dos dados. Se a string original
 * for destruída ou modificada, o std::string_view pode acessar memória inválida (dangling pointer).
 */

void print_string(std::string_view sv)
{
    std::cout << sv << '\n';
}

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

    std::cout << "--------------------------------" << '\n';

    std::string String = "Hello, World!";
    std::string_view sv = String; // Refere-se à std::string
    print_string(sv);             // Passa sem cópia

    const char *cstr = "C-style string";
    std::string_view sv2 = cstr; // Refere-se a um array de caracteres
    print_string(sv2);

    std::string_view sv3 = "Literal string"; // Refere-se a uma string literal
    print_string(sv3);

    // Substring sem cópia
    std::string_view substr = sv3.substr(0, 7); // "Literal"
    print_string(substr);
    return 0;
}
