#include <iostream>
#include <variant>

/**
 * Comparando std::variant com union (C tradicional)
 * -------------------------------------------------
 *
 * O std::variant é uma **união discriminada com segurança de tipo**, introduzida no C++17,
 * que substitui as uniões C tradicionais (`union`) oferecendo verificação de tipo
 * em tempo de compilação e melhor segurança em tempo de execução.
 *
 * Abaixo estão as principais diferenças entre std::variant e union:
 *
 * 1. Segurança de Tipo:
 *    - std::variant: Garante acesso seguro ao tipo armazenado.
 *      A tentativa de acessar um tipo incorreto lança uma exceção (`std::bad_variant_access`)
 *      ou retorna `nullptr` ao usar `std::get_if`.
 *
 *    - union: Não há verificação de tipo. Acessar um membro incorreto resulta
 *      em **comportamento indefinido**.
 *
 * 2. Armazenamento de Tipos Múltiplos:
 *    - std::variant: Pode armazenar qualquer um dos tipos listados na sua definição,
 *      por exemplo `std::variant<int, float, std::string>`. O tipo ativo é rastreado automaticamente.
 *
 *    - union: Também armazena múltiplos tipos, mas o programador precisa saber
 *      manualmente qual tipo está ativo no momento.
 *
 * 3. Tamanho e Overhead:
 *    - std::variant: O tamanho baseia-se no maior tipo mais um pequeno overhead
 *      de gerenciamento interno.
 *    - union: O tamanho é exatamente o do maior membro, sem overhead.
 *
 * 4. Memória e Alinhamento:
 *    - std::variant: Gerencia automaticamente o alinhamento e a destruição dos tipos
 *      armazenados, evitando erros de acesso e uso indevido.
 *
 *    - union: Todos os membros compartilham o mesmo espaço de memória, e o programador
 *      deve garantir o alinhamento e destruição corretos, sendo o tipo responsável pelo
 *      gerenciamento aquele que possuir o maior número de bytes.
 *
 *     - Acessar um tipo incorreto pode causar **erros difíceis de diagnosticar**.
 *
 * Resumo:
 *    Use `std::variant` quando quiser a flexibilidade de múltiplos tipos, mas com segurança,
 *    legibilidade e comportamento previsível — em vez das unions em C tradicional.
 */

union Uniao
{
    int type_int;     // Normalmente 4 bytes
    float type_float; // Normalmente 4 bytes
};

void exemplo_variant()
{
    std::cout << "\n=== Exemplo com std::variant ===\n";

    std::variant<int, float> v; // Pode armazenar int ou float
    v = 42;                     // Armazena um int

    // Acesso seguro
    std::cout << "Tamanho do variant: " << sizeof(v) << " bytes\n";
    std::cout << "Valor armazenado (int): " << std::get<int>(v) << '\n';

    // Mudando o tipo armazenado
    v = 3.14f;
    std::cout << "Valor armazenado (float): " << std::get<float>(v) << '\n';

    // Acesso incorreto tratado com segurança
    if (auto val = std::get_if<int>(&v))
        std::cout << "Int armazenado: " << *val << '\n';
    else
        std::cout << "Nenhum int armazenado no momento.\n";

    // Usando std::visit para acesso genérico
    std::visit([](auto &&arg)
    {
        std::cout << "Valor visitado via std::visit: " << arg << '\n';
    }, v);

    std::cout << '\n';
}

int main(int argc, char const *argv[])
{
    Uniao u;

    const std::size_t size_of_union = sizeof(u); // Tamanho definido pelo maior membro
    std::cout << "Tamanho da união: " << size_of_union << " bytes\n";

    // Demonstração: ambos os membros compartilham o mesmo espaço de memória
    u.type_int = 42;
    std::cout << "u.type_int: " << u.type_int << '\n';
    std::cout << "Interpretando como float: " << u.type_float << '\n';

    // Isso é comportamento indefinido — estamos lendo um tipo diferente do armazenado.
    // O valor de u.type_float aqui não faz sentido e depende da representação binária do int.

    std::cout << "\nEndereços de memória:\n";
    std::cout << " &u.type_int   = " << &u.type_int << '\n';
    std::cout << " &u.type_float = " << &u.type_float << '\n';
    std::cout << "(Os endereços são iguais — ambos compartilham a mesma área de memória)\n";

    exemplo_variant();
    return 0;
}
