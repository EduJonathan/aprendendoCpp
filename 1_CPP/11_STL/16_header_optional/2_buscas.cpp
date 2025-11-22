#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <optional>

struct Produto
{
    int id;
    std::string nome;
    double preco;
};

/**
 * @brief Busca um nome com base em uma condição booleana.
 *
 * @param encontrado Se verdadeiro, retorna o nome "Eduardo"; caso contrário, retorna std::nullopt.
 * @return std::optional<std::string> Nome encontrado ou std::nullopt se ausente.
 */
std::optional<std::string> buscar_nome(bool encontrado)
{
    // std::nullopt é uma constante especial do C++17 usada para representar
    // a ausência de valor em um std::optional.
    if (encontrado)
        return "Eduardo";
    else
        return std::nullopt; // <-- sem valor
}

/**
 * @brief Busca um nome de usuário a partir de um ID.
 *
 * @param id O identificador do usuário.
 * @return std::optional<std::string> O nome do usuário, se encontrado; std::nullopt caso contrário.
 */
std::optional<std::string> buscarUsuarioPorId(int id)
{
    static const std::map<int, std::string> usuarios = {
        {1, "Alice"},
        {2, "Bob"},
        {3, "Carlos"},
    };

    auto it = usuarios.find(id);
    if (it != usuarios.end())
    {
        return it->second;
    }
    return std::nullopt; // valor ausente
}

/**
 * @brief Busca um produto pelo ID.
 *
 * @param id O identificador do produto.
 * @return std::optional<Produto> Estrutura Produto se encontrado; std::nullopt se não encontrado.
 */
std::optional<Produto> buscarProdutoPorId(int id)
{
    static const std::unordered_map<int, Produto> produtos = {
        {101, {101, "Notebook", 3500.00}},
        {102, {102, "Mouse", 80.00}},
        {103, {103, "Teclado", 150.00}},
    };

    auto it = produtos.find(id);
    if (it != produtos.end())
    {
        return it->second;
    }
    return std::nullopt; // nullopt
}

int main(int argc, char **argv)
{
    std::cout << "---- BUSCAR NOME ----" << '\n';

    auto nome = buscar_nome(true);

    if (nome.has_value())
    {
        std::cout << "Nome encontrado: " << nome.value() << '\n';
    }
    else
    {
        std::cout << "Nenhum nome encontrado\n";
    }

    std::cout << "---- BUSCAR ID ----" << '\n';

    auto outro = buscar_nome(false);
    std::cout << "Outro: " << (outro ? *outro : "não existe") << '\n';

    int id = 3;
    std::optional<std::string> usuario = buscarUsuarioPorId(id);

    if (usuario)
    {
        std::cout << "Usuário encontrado: " << *usuario << '\n';
    }
    else
    {
        std::cout << "Nenhum usuário com ID " << id << '\n';
    }

    // Ou com valor padrão
    std::cout << "Usuário (ou padrão): " << usuario.value_or("Desconhecido") << '\n';

    std::cout << "---- Produto ----" << '\n';

    auto resultado = buscarProdutoPorId(101);

    if (resultado.has_value())
    {
        Produto p = resultado.value();
        std::cout << "Produto: " << p.nome << " - R$" << p.preco << '\n';
    }
    else
    {
        std::cout << "Produto não encontrado\n";
    }

    /**
     * Compile com: g++ -std=c++20 buscas.cpp -o buscas
     * ./buscas
     */
    return 0;
}
