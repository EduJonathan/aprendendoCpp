#include <iostream>
#include <string>
#include <vector>
#include <ranges>

/**
 * std::views::transform(): é um *range adaptor* que aplica uma função a cada elemento de um range,
 * transformando os valores originais e gerando um novo range com os resultados da função.
 */

struct Transacao
{
    double quantia;
    std::string data;
    char tipoDeTransacao;
};

int main(int argc, char **argv)
{
    // Vetor de transações (crédito 'C' e débito 'D')
    std::vector<Transacao> transacoes = {
        {100.0, "2023-01-01", 'C'},
        {50.0, "2023-01-02", 'D'},
        {200.0, "2023-01-03", 'C'},
        {150.0, "2023-01-04", 'D'}};

    // Lambda para filtrar transações do tipo débito
    auto debito = [](const Transacao &t)
    {
        return t.tipoDeTransacao == 'D';
    };

    // Lambda para transformar a quantia de transações (exemplo: dobrar o valor)
    auto quantia_no_debito = [](const Transacao &t)
    {
        return t.quantia * 2;
    };

    // Aplica os filtros e transformações sobre a lista de transações
    auto processo = transacoes | std::views::filter(debito) | std::views::transform(quantia_no_debito);

    // Exibe os valores resultantes após o processamento
    std::cout << "Valores transformados das transações de débito (dobrados):\n";
    for (auto quantia : processo)
    {
        std::cout << quantia << '\n'; // Imprime a quantia transformada (dobrada)
    }

    /**
     * As views filter e transform => são utilizadas para processar apenas transações
     * de débito e depois duplicar os seus montantes, respetivamente. Toda a operação é
     * realizada sem modificar os dados originais ou criar coleções adicionais,
     * mostrando como os intervalos suportam um processamento de dados eficiente.
     */
    return 0;
}
