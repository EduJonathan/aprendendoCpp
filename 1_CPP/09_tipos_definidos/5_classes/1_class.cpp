#include <iostream>

/**
 * Classe (class): Em C++, é um tipo definido pelo o usuário (o programador). As classes
 * são a base para a programação orientada a objetos. Elas abstraem e podem conter membros
 * conhecidos como atributos(dados) e metódos(funções) a qual define o comportamento de objetos
 * dessa classe.
 */

// Definição de uma classe chamada "Bicicleta" que servirá como um molde para
// criar objeto(s) do tipo Bicicleta
class Bicicleta
{
    // Acesso público, ou seja, pode ser acessado de qualquer lugar do código
public:
    // Atributos (variáveis/dados), qquando declarados dentro de uma classe, e quando
    // instanciamos Estes valores serão os padrões iniciais dos objetos criados a partir
    // desta classe, a não ser que sejam modificados posteriormente.
    std::string cor = "vermelha";
    std::string marca = "Monark";
    bool pneu_furado = false;

    // Método (função) para exibir informações da bicicleta
    void exibirInfo()
    {
        std::cout << "Cor: " << cor
                  << ", Marca: " << marca
                  << ", Pneus furados: "
                  << (pneu_furado ? "Não! Você não pode pedalar." : "Sim! Você pode pedalar.") << '\n';
    }
};

int main(int argc, char **argv)
{
    // Instânciando objetos da classe Bicicleta.
    Bicicleta Monark;
    Monark.exibirInfo(); // Exibindo informações da bicicleta Monark

    std::cout << "------------------------\n";

    // Criação de um objeto (instância) da classe Bicicleta
    Bicicleta Caloi;

    // Acessando e modificando atributos do objeto Caloi
    Caloi.cor = "azul";
    Caloi.marca = "Caloi";
    Caloi.pneu_furado = true;

    // Exibindo informações da bicicleta usando o método exibirInfo
    Caloi.exibirInfo();

    std::cout << "------------------------\n";

    // Criação de outro objeto (instância) da classe Bicicleta
    Bicicleta Specialized;

    // Acessando e modificando atributos do objeto Specialized
    Specialized.cor = "verde";
    Specialized.marca = "Specialized";

    // Exibindo informações da segunda bicicleta usando o método exibirInfo
    Specialized.exibirInfo();

    return 0;
}