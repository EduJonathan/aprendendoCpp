#include <iostream>
#include <string_view>

/**
 * std::literals::string_view_literals é o namespace onde o operador de sufixo `sv` está definido.
 * Para usar o sufixo `sv`, você precisa importar esse namespace explicitamente com using namespace
 *
 * std::literals::string_view_literals; ou using namespace std::literals;. Ele faz parte da
 * biblioteca padrão do C++17 e é usado exclusivamente para criar std::string_view a partir
 * de strings literais.
 *
 * Como funciona?
 *
 * - O namespace std::literals::string_view_literals define o operador de sufixo `sv`,
 * que é aplicado a strings literais (como "texto") para criar um objeto std::string_view.
 *
 * - Esse operador é implementado como uma função literal personalizada, conforme permitido pelo C++.
 *
 * CUIDADOS:
 *
 * - Namespace explícito: Você deve incluir o namespace std::literals::string_view_literals para
 * usar o sufixo `sv`.
 *
 * - Usar using namespace std; não é suficiente, pois o namespace std::literals é mais específico.
 * - Uso restrito: O sufixo `sv` só pode ser aplicado a strings literais, não a variáveis ou expressões.
 */

using namespace std::literals::string_view_literals;

void print_sv(std::string_view sv)
{
    std::cout << sv << '\n';
}

int main(int argc, char **argv)
{
    print_sv("Direct string_view"sv); // Usa o sufixo sv
    print_sv("Outro exemplo"sv);

    // Comparando string_view
    auto sv1 = "Teste"sv;
    auto sv2 = "Teste"sv;
    std::cout << std::boolalpha << (sv1 == sv2) << '\n'; // true

    return 0;
}
