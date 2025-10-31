#include <iostream>
#include <vector>
#include <cstdint>

/**
 * @brief Biblioteca <cstdint> — tipos inteiros com tamanhos definidos.
 *
 * A biblioteca `<cstdint>` (herdada de `<stdint.h>` ou `<inttypes.h>`)
 * fornece tipos inteiros padronizados com tamanhos explícitos e portáveis.
 *
 * Esses tipos garantem previsibilidade entre plataformas, definindo larguras fixas,
 * como:
 * - `int8_t`, `int16_t`, `int32_t`, `int64_t` — inteiros com sinal de 8, 16, 32 e 64 bits.
 * - `uint8_t`, `uint16_t`, `uint32_t`, `uint64_t` — inteiros sem sinal.
 *
 * @note Ideal para aplicações que exigem controle preciso de memória e tamanho
 *       de variáveis, como manipulação de arquivos binários, redes e jogos.
 */

// Função que soma todos os elementos de um vetor
std::int16_t somarVetor(const std::vector<std::int16_t> &dados)
{
    std::int16_t soma = 0;
    for (std::int16_t valor : dados)
    {
        soma += valor;
    }
    return soma;
}

// Função que multiplica cada elemento por um fator
std::vector<std::int16_t> multiplicarVetor(const std::vector<std::int16_t> &dados, std::int16_t fator)
{
    std::vector<std::int16_t> resultado;
    for (std::int16_t valor : dados)
    {
        resultado.push_back(valor * fator);
    }
    return resultado;
}

int main(int argc, char **argv)
{
    std::int32_t idade = 25;
    std::uint64_t populacao = 7800000000;
    std::cout << "Idade: " << idade << "\nPopulação: " << populacao << '\n';

    std::cout << "-------------------------------------------" << '\n';
    
    std::vector<std::int16_t> dados = {10, 20, 30, 40, 50};

    std::int16_t soma = somarVetor(dados);
    std::vector<std::int16_t> multiplicados = multiplicarVetor(dados, 3);

    std::cout << "Soma dos elementos: " << soma << '\n';
    std::cout << "Elementos multiplicados por 3: ";
    for (std::int16_t valor : multiplicados)
    {
        std::cout << valor << ' ';
    }
    std::cout << '\n';
    return 0;
}
