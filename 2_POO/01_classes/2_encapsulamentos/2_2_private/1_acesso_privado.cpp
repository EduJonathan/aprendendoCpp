#include <iostream>
#include <string>

/**
 * ENCAPSULAMENTO (private):
 * Aqui os dados estão protegidos dentro da classe.
 * Eles só podem ser alterados e acessados por meio dos métodos públicos.
 *
 * PRIVATE: Membros de classe marcados com private só podem ser acessados ou modificados
 * dentro da própria classe. Ou seja, você não pode acessar ou modificar diretamente esses
 * membros fora da classe. O private ajuda a proteger as variáveis internas da classe,
 * impedindo que elas sejam alteradas de forma não controlada por código externo.
 *
 * Isso melhora a segurança e a manutenção do código, pois você pode garantir que os dados
 * de um objeto só sejam alterados através de métodos definidos, como getters e setters.
 * Garantindo maior controle e segurança sobre o estado do objeto.
 */

class Veiculo
{
private: // ← Agora os atributos são privados, uma pequena ressalva, caso private não esteja declarado antes dos atributos,
         // por padrão eles já seriam privates
    std::string marca;
    std::string modelo;
    std::string cor;
    int ano;

public:
    // Método para definir os detalhes do veículo
    void set_detalhes(std::string marcaVeiculo, std::string modeloVeiculo, std::string corVeiculo, int anoFabricacao)
    {
        marca = marcaVeiculo;
        modelo = modeloVeiculo;
        cor = corVeiculo;
        ano = anoFabricacao;
    }

    // Método para obter todas as informações do veículo
    std::string get_informacoes()
    {
        std::string info = "Marca: " + marca +
                           "\nModelo: " + modelo +
                           "\nCor: " + cor +
                           "\nAno: " + std::to_string(ano);
        return info;
    }
};

int main(int argc, char **argv)
{
    Veiculo carro;

    // Agora NÃO é possível acessar diretamente:
    // carro.marca = "Toyota";   // Erro de compilação
    // carro.cor = "Prata";      // Erro de compilação

    // Só é possível alterar através do método público set_detalhes()
    carro.set_detalhes("Toyota", "Corolla", "Prata", 2022);

    // E só é possível exibir através do método público get_informacoes()
    std::cout << carro.get_informacoes() << '\n';

    // Atualização dos valores, lembrando que só é possível acessar set_detalhes e get_informacoes por conta que eles são publicos.
    carro.set_detalhes("Honda", "Civic", "Preto", 2024);

    std::cout << "\nApós atualização:\n"
              << carro.get_informacoes() << '\n';

    return 0;
}
