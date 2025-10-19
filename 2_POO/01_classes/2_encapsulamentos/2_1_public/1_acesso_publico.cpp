#include <iostream>
#include <string>

/**
 * ENCAPSULAMENTO: O encapsulamento é um conceito que envolve agrupar os dados e os métodos
 * que operam nesses dados em uma única unidade, chamada de objeto. Isso permite que os
 * dados sejam ocultos e protegidos dentro do objeto, evitando acessos não autorizados e
 * garantindo a integridade do sistema. Há 3 tipos de encapsulamento:
 *
 * 1. Public: Os dados e métodos podem ser acessados de qualquer lugar.
 * 2. Private: Os dados e métodos só podem ser acessados dentro da classe.
 * 3. Protected: Os dados e métodos podem ser acessados dentro da classe e subclasses.
 */

class CaracteristicasPessoais
{
public:
    std::string corDoCabelo;
    std::string corDePele;
    std::string estatura;
    bool temBarba;

    void set_caracteristicas(std::string cabelo, std::string pele, std::string aparencia, bool barba)
    {
        corDoCabelo = cabelo;
        corDePele = pele;
        estatura = aparencia;
        temBarba = barba;
    }

    // Getter geral: retorna a aparência completa em formato de texto
    std::string get_aparencia()
    {
        std::string descricao = "Cabelo: " + corDoCabelo +
                                "\nPele: " + corDePele +
                                "\nEstatura: " + estatura +
                                "\nTem barba: " + (temBarba ? "Sim" : "Não");
        return descricao;
    }
};

int main(int argc, char **argv)
{
    CaracteristicasPessoais Aparencia;

    // Acesso direto aos atributos (porque são public), tanto na main quanto na própria classe
    Aparencia.corDoCabelo = "Loiro";
    Aparencia.corDePele = "Branco";
    Aparencia.estatura = "Porte físico médio";
    Aparencia.temBarba = false;

    // Exibir aparência geral via getter
    std::cout << Aparencia.get_aparencia() << '\n';

    // Alteração novamente dos atributos
    Aparencia.set_caracteristicas("Preto", "Moreno", "Forte", true);

    // Exibir aparência atualizada
    std::cout << '\n'
              << Aparencia.get_aparencia() << '\n';

    return 0;
}
