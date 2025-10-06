#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>

/**
 * std::queue<T> Utiliza a estrutura FIFO (First In, First Out). Ideal para gerenciar
 * recursos que precisam ser utilizados em ordem.
 */

// Mapeia o código do dono para o nome do dono
std::unordered_map<int, std::string> donos;

// Mapeia o código do dono para o número da vaga
std::unordered_map<int, int> vagasOcupadas;

/**
 * @brief Inicializa o estacionamento, adicionando lugares disponíveis.
 *
 * @param lugaresDisponiveis Fila que armazena as vagas do estacionamento.
 * A função a preenche com números de 1 a 20.
 */
void inicializarEstacionamento(std::queue<int> &lugaresDisponiveis)
{
    for (int i = 1; i <= 20; ++i)
    {
        lugaresDisponiveis.push(i);
    }
}

/**
 * @brief Estaciona um carro e atribui um código ao dono.
 *
 * @param dono Nome do proprietário do carro.
 * @param lugaresDisponiveis Fila de vagas disponíveis no estacionamento.
 * @param codigo Código único para o dono, usado para associar o carro ao estacionamento.
 * @return O próximo código para o próximo dono, ou o código atual se não houver vagas.
 */
int estacionarCarro(const std::string &dono, std::queue<int> &lugaresDisponiveis, int codigo)
{
    if (lugaresDisponiveis.empty())
    {
        std::cout << "Estacionamento cheio! Não há vagas disponíveis.\n";
        return codigo;
    }

    int vaga = lugaresDisponiveis.front();
    lugaresDisponiveis.pop();

    donos[codigo] = dono;
    vagasOcupadas[codigo] = vaga;

    std::cout << "Carro de " << dono << " estacionado na vaga L" << vaga << ". Código do dono: " << codigo << '\n';

    return codigo + 1;
}

/**
 * @brief Retira um carro do estacionamento.
 *
 * @param codigoDono Código do dono do carro a ser retirado.
 * @param lugaresDisponiveis Fila de vagas disponíveis no estacionamento, que será atualizada
 * quando uma vaga for liberada.
 *
 * @note Se o código do dono não for encontrado, significa que o carro não está estacionado ou
 * o código foi fornecido incorretamente.
 */
void retirarCarro(int codigoDono, std::queue<int> &lugaresDisponiveis)
{
    if (donos.find(codigoDono) == donos.end() || vagasOcupadas.find(codigoDono) == vagasOcupadas.end())
    {
        std::cout << "Código inválido! Nenhum carro encontrado para o código " << codigoDono << ".\n";
        return;
    }

    std::string nome = donos[codigoDono];
    int vaga = vagasOcupadas[codigoDono];

    donos.erase(codigoDono);
    vagasOcupadas.erase(codigoDono);

    lugaresDisponiveis.push(vaga);

    std::cout << "Carro de " << nome << " retirado da vaga L" << vaga << ". Vaga liberada.\n";
}

int main(int argc, char **argv)
{
    std::queue<int> lugaresDisponiveis;
    int codigo = 1;

    inicializarEstacionamento(lugaresDisponiveis);

    // Estacionar carros
    codigo = estacionarCarro("João", lugaresDisponiveis, codigo);
    codigo = estacionarCarro("Maria", lugaresDisponiveis, codigo);
    codigo = estacionarCarro("Carlos", lugaresDisponiveis, codigo);

    std::cout << "\n--- Retirada de carros ---\n";
    retirarCarro(1, lugaresDisponiveis); // João
    retirarCarro(2, lugaresDisponiveis); // Maria

    std::cout << "\n--- Tentativa de retirada inválida ---\n";
    retirarCarro(99, lugaresDisponiveis); // Código inválido

    return 0;
}
