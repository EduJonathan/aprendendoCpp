#include <iostream>
#include <optional>
#include <string>

std::optional<std::string> buscar_nome(bool encontrado)
{
    if (encontrado)
    {
        return "Eduardo";
    }
    else
    {
        return std::nullopt; // valor ausente
    }
}

int main(int argc, char **argv)
{
    auto nome = buscar_nome(true);

    if (nome.has_value())
    {
        std::cout << "Nome encontrado: " << nome.value() << '\n';
    }
    else
    {
        std::cout << "Nenhum nome encontrado\n";
    }

    auto outro = buscar_nome(false);
    std::cout << "Outro: " << (outro ? *outro : "não existe") << '\n';

    return 0;
}
