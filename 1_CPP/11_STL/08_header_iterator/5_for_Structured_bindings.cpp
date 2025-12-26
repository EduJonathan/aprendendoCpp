#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <unordered_map>
#include <iterator>

/**
 * Structured bindings (C++17+)
 * Structured bindings permitem "desestruturar" tipos compostos diretamente
 * na declaração de variáveis, tornando o código mais legível e expressivo.
 *
 * Elas funcionam com:
 *  - std::pair
 *  - std::tuple
 *  - std::array
 *  - structs/classes agregadas (com membros públicos)
 *  - tipos que seguem o modelo "tuple-like"
 *
 * ATENÇÃO: a forma usada influencia se há cópia ou referência!
 *
 * 1) auto [a, b]
 *    - Cria CÓPIAS dos elementos.
 *    - Use quando você precisa de valores independentes do objeto original.
 *
 * 2) auto& [a, b]
 *    - Cria REFERÊNCIAS mutáveis aos elementos.
 *    - Use quando pretende modificar o objeto original.
 *
 * 3) const auto& [a, b]  ← forma MAIS comum e recomendada
 *    - Cria REFERÊNCIAS constantes (sem cópia).
 *    - Ideal para leitura, especialmente em loops.
 *
 * Exemplo recomendado em containers:
 *   for (const auto& [key, value] : mapa) {
 *       // leitura segura e eficiente
 *   }
 *
 * Em resumo:
 *   - Use const auto& por padrão
 *   - Use auto& quando precisar modificar
 *   - Use auto (por valor) apenas quando fizer sentido copiar
 */

// 1. Range-based for loop (C++11) – o "for each" moderno
void for_Range_based_loop()
{
    std::cout << "=== 1. Range-based for loop (for moderno simples) ===\n";

    std::vector<std::string> frutas{"maçã", "banana", "laranja", "uva"};

    // Forma mais comum e recomendada para percorrer contêineres
    for (const auto &fruta : frutas)
    {
        std::cout << "Fruta: " << fruta << '\n';
    }

    std::cout << "---------------------------------" << '\n';
    
    // Se precisar modificar os elementos:
    std::cout << "\nDobrando o tamanho das strings:\n";
    for (auto &fruta : frutas)
    {
        fruta += fruta; // duplica a std::string
        std::cout << fruta << '\n';
    }
}

// 2. Structured bindings (C++17) – desestruturação de pares, tuplas, structs
void for_structured_bindings()
{
    std::cout << "\n=== 2. Structured bindings (desestruturação) ===\n";

    // Com std::pair
    std::pair<std::string, int> pessoa{"Maria", 28};
    auto [nome, idade] = pessoa; // desestrutura diretamente
    std::cout << nome << " tem " << idade << " anos\n";

    std::cout << "---------------------------------" << '\n';

    // Com std::tuple
    std::tuple<int, std::string, double> dados = {42, "resposta", 3.14};
    auto [numero, texto, pi] = dados;
    std::cout << "Número: " << numero << ", Texto: " << texto << ", Pi ≈ " << pi << '\n';

    std::cout << "---------------------------------" << '\n';

    // Com struct (se tiver membros públicos ou suporte via tuple-like)
    struct Point
    {
        int x, y;
    };

    Point p = {10, 20};
    auto [x, y] = p; // funciona porque Point é "tuple-like"
    std::cout << "Ponto: (" << x << ", " << y << ")\n";
}

// 3. Range-based for + Structured bindings (C++17) – a combinação mais poderosa
void for_range_based_for_with_structured_bindings()
{
    std::cout << "\n=== 3. Range-based for com Structured bindings (o mais moderno) ===\n";

    std::unordered_map<std::string, int> pontuacoes{
        {"Ana", 95},
        {"Beto", 87},
        {"Bill", 78},
        {"Davi", 92}};

    // Forma antiga (pré-C++17): verbosa
    std::cout << "Forma antiga (com .first e .second):\n";
    for (const auto &par : pontuacoes)
    {
        std::cout << par.first << " -> " << par.second << '\n';
    }

    std::cout << "---------------------------------" << '\n';

    // Conceitualmente é válido com iterators como:
    // for (auto it = pontuacoes.begin(); it != pontuacoes.end(); ++it)
    // {
    //      const auto& nome   = it->first;
    //      const auto& pontos = it->second;
    // }

    std::cout << "---------------------------------" << '\n';

    // Forma moderna (C++17+): limpa e legível
    std::cout << "\nForma moderna (com desestruturação):\n";

    // for (auto &[nome, pontos] : pontuacoes), EM caso de modificação nos valores
    for (const auto &[nome, pontos] : pontuacoes)
    {
        std::cout << nome << " -> " << pontos << " pontos\n";

        // Pode até modificar o valor diretamente: (descomente se quiser testar)
        // if (pontos < 80)
        // pontos = 80;
    }

    std::cout << "---------------------------------" << '\n';

    // Outro exemplo: ignorando a chave com '_', O '_' não é especial em C++ É só um nome de variável
    std::cout << "\nSomente os valores (ignorando chave com '_'):\n";
    int soma = 0;
    for (const auto &[_, pontos] : pontuacoes)
    {
        soma += pontos;
    }
    std::cout << "Soma total de pontos: " << soma << '\n';
}

int main(int argc, char **argv)
{
    for_Range_based_loop();
    for_structured_bindings();
    for_range_based_for_with_structured_bindings();
    return 0;
}
