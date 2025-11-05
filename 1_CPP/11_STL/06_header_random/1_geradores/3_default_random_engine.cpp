#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

/**
 * std::default_random_engine é um *alias* (apelido) para um motor pseudoaleatório padrão,
 * definido pela implementação do compilador. Ou seja, o tipo real que ele representa
 * pode variar entre diferentes compiladores e plataformas.
 *
 * --------------------
 *
 * Isso significa que:
 * - Em algumas implementações, ele pode ser equivalente a std::minstd_rand0.
 * - Em outras, pode usar outro gerador linear ou até um Mersenne Twister reduzido.
 * - Portanto, o comportamento e a sequência gerada **não são padronizados**.
 *
 * --------------------
 *
 * Características principais:
 * - Serve como um ponto de partida rápido para geração de números aleatórios,
 *   quando você não precisa de controle sobre o tipo de motor usado.
 * - Pode ser inicializado com uma semente (seed), como os demais geradores.
 * - Determinístico dentro da mesma implementação, mas **não entre compiladores diferentes**.
 *
 * --------------------
 *
 * ⚠️ Atenção:
 * - Como o motor real usado não é padronizado, **nunca use** std::default_random_engine
 *   quando for necessário reproduzir a mesma sequência aleatória em diferentes sistemas
 *   (por exemplo, jogos, simulações determinísticas ou testes automatizados).
 * - Prefira motores explícitos e estáveis, como:
 *     - std::mt19937     → alta qualidade e rapidez (geral)
 *     - std::ranlux24    → maior independência estatística (simulações científicas)
 *     - std::minstd_rand → leve e previsível (ideal para aprendizado e demonstrações)
 *
 * --------------------
 *
 * Em resumo:
 * std::default_random_engine é útil para exemplos rápidos, protótipos e aplicações simples,
 * mas não deve ser usado em projetos que exijam consistência entre execuções ou plataformas.
 */

struct Pos
{
    int x;
    int y;
};

int main(int argc, char **argv)
{
    const int largura = 8; // colunas
    const int altura = 5;  // linhas
    const int numPersonagens = 4;
    const int numCartas = 15;

    std::random_device rd;
    std::default_random_engine engine(rd());

    // 1. Todas as coordenadas possíveis
    std::vector<Pos> coordenadas;
    for (int y = 0; y < altura; ++y)
    {
        for (int x = 0; x < largura; ++x)
        {
            coordenadas.push_back({x, y});
        }
    }

    // 2. Embaralhar tudo
    std::shuffle(coordenadas.begin(), coordenadas.end(), engine);

    // 3. Posições para personagens e cartas
    std::vector<Pos> posPersonagens(coordenadas.begin(), coordenadas.begin() + numPersonagens);
    std::vector<Pos> posCartas(coordenadas.begin() + numPersonagens,
                               coordenadas.begin() + numPersonagens + numCartas);

    // 4. Criar matriz do mapa
    std::vector<std::vector<char>> mapa(altura, std::vector<char>(largura, '.'));

    // Inserir personagens
    for (const auto &p : posPersonagens)
        mapa[p.y][p.x] = 'P';

    // Inserir cartas
    for (const auto &c : posCartas)
        mapa[c.y][c.x] = 'C';

    // 5. Exibir mapa
    std::cout << "=== MAPA (8x5) ===\n";
    for (int y = 0; y < altura; ++y)
    {
        for (int x = 0; x < largura; ++x)
        {
            std::cout << '[' << mapa[y][x] << ']';
        }
        std::cout << '\n';
    }

    // 6. Exibir coordenadas
    std::cout << "\n=== Coordenadas dos Personagens ===\n";
    for (size_t i = 0; i < posPersonagens.size(); ++i)
    {
        std::cout << "Personagem " << i + 1 << ": ("
                  << posPersonagens[i].x << ", "
                  << posPersonagens[i].y << ")\n";
    }

    std::cout << "\n=== Coordenadas das Cartas ===\n";
    for (size_t i = 0; i < posCartas.size(); ++i)
    {
        std::cout << "Carta " << i + 1 << ": ("
                  << posCartas[i].x << ", "
                  << posCartas[i].y << ")\n";
    }

    return 0;
}
