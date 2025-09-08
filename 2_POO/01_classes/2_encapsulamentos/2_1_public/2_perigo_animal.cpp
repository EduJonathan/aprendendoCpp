#include <iostream>
#include <string>
#include <algorithm>

class Perigo
{
public:
    int nivelDePerigo;

    // Método para definir o nível de perigo
    void setNivelDePerigo(int nivel)
    {
        // Limita o nivel do perigo do animal entre [0 até 50]
        nivelDePerigo = std::clamp(nivel, 0, 50);
    }

    // Método para obter o nível de perigo
    int getNivelDePerigo() const
    {
        return nivelDePerigo;
    }

    // Método para interpretar o nível de perigo
    const std::string interpretarPerigo() const
    {
        if (nivelDePerigo <= 10)
        {
            return "Dócil";
        }
        if (nivelDePerigo <= 30)
        {
            return "Pode atacar se sentir ameaçado";
        }
        return "Pode atacar";
    }
};

class Animal
{
public:
    std::string tipoDeAnimal;
    std::string classificacao;
    std::string especie;
    Perigo perigo; // Definindo um objeto da class `Perigo` dentro da classe Animal

    // Métodos setters
    void setTipoDeAnimal(const std::string &tipoDeAnimal)
    {
        this->tipoDeAnimal = tipoDeAnimal;
    }

    void setEspecie(const std::string &especie)
    {
        this->especie = especie;
    }

    void setClassificacao(const std::string &classificacao)
    {
        this->classificacao = classificacao;
    }

    // Métodos getters
    const std::string getTipoDeAnimal(void) const
    {
        return tipoDeAnimal;
    }

    const std::string getEspecie(void) const
    {
        return especie;
    }

    const std::string getClassificacao(void) const
    {
        return classificacao;
    }

    // Métodos para acessar e manipular o nível de perigo associado ao animal
    void setNivelDePerigo(int nivel)
    {
        perigo.setNivelDePerigo(nivel); // Chamando o método da classe
    }

    int getNivelDePerigo(void) const
    {
        return perigo.getNivelDePerigo(); // Chamando o método da classe Perigo
    }

    const std::string interpretarPerigo(void) const
    {
        return perigo.interpretarPerigo(); // Interpretando o nível de perigo
    }
};

int main(int argc, char **argv)
{
    // Criação do objeto 'cachorro' do tipo Animal
    Animal cachorro;

    // Atribuição dos valores aos atributos do objeto 'cachorro'
    cachorro.setTipoDeAnimal("Cachorro");
    cachorro.setEspecie("Pit Bull"); // Definindo a espécie do cachorro
    cachorro.setClassificacao("Mamífero");
    cachorro.setNivelDePerigo(25); // Definindo um nível de perigo para o cachorro

    // Exibição dos valores dos atributos do objeto 'cachorro'
    std::cout << "Tipo de animal: " << cachorro.getTipoDeAnimal() << '\n';
    std::cout << "Espécie: " << cachorro.getEspecie() << '\n';
    std::cout << "Classificação: " << cachorro.getClassificacao() << '\n';
    std::cout << "Nível de Perigo: " << cachorro.getNivelDePerigo() << '\n';
    std::cout << "Comportamento: " << cachorro.interpretarPerigo() << '\n';

    std::cout << "\n----------------------------\n";

    // Criação do objeto 'urso' do tipo Animal
    Animal urso;

    // Atribuição dos valores aos atributos do objeto 'urso'
    urso.setTipoDeAnimal("Urso");
    urso.setEspecie("Urso Pardo"); // Definindo a espécie do urso
    urso.setClassificacao("Mamífero");
    urso.setNivelDePerigo(35); // Definindo um nível de perigo para o urso

    // Exibição dos valores dos atributos do objeto 'urso'
    std::cout << "Tipo de animal: " << urso.getTipoDeAnimal() << '\n';
    std::cout << "Espécie: " << urso.getEspecie() << '\n';
    std::cout << "Classificação: " << urso.getClassificacao() << '\n';
    std::cout << "Nível de Perigo: " << urso.getNivelDePerigo() << '\n';
    std::cout << "Comportamento: " << urso.interpretarPerigo() << '\n';

    return 0;
}
