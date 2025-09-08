#include <iostream>
#include <string>

// Classe Base
class AtributosAnimais
{
public:
    std::string nome;
    std::string especie;
    std::string corDoPelo;
    int idade;

    void caminhar(void)
    {
        std::cout << nome << " está caminhando." << '\n';
    }
};

// Classe Derivada Cachorro
class Cachorro : public AtributosAnimais
{
public:
    std::string raca;

    void latir(void)
    {
        std::cout << nome << " Cachorro Late!" << '\n';
    }

    static void getCachorro(Cachorro *dog)
    {
        std::cout << "=== Dados do Cachorro ===\n";
        std::cout << "Nome: " << dog->nome << '\n';
        std::cout << "Espécie: " << dog->especie << '\n';
        std::cout << "Idade: " << dog->idade << " anos\n";
        std::cout << "Cor do Pelo: " << dog->corDoPelo << '\n';
        std::cout << "Raça: " << dog->raca << "\n\n";
    }
};

// Classe Derivada Gato
class Gato : public AtributosAnimais
{
public:
    std::string raca;

    void miar(void)
    {
        std::cout << nome << " Gato Mia!" << '\n';
    }

    static void getGato(Gato *cat)
    {
        std::cout << "=== Dados do Gato ===\n";
        std::cout << "Nome: " << cat->nome << '\n';
        std::cout << "Espécie: " << cat->especie << '\n';
        std::cout << "Idade: " << cat->idade << " anos\n";
        std::cout << "Cor do Pelo: " << cat->corDoPelo << '\n';
        std::cout << "Raça: " << cat->raca << "\n\n";
    }
};

int main(int argc, char **argv)
{
    Cachorro *dog = new Cachorro;
    dog->nome = "Rex";
    dog->especie = "Canino";
    dog->idade = 3;
    dog->corDoPelo = "Marrom";
    dog->raca = "Pit Bull";

    Gato *cat = new Gato;
    cat->nome = "Prince";
    cat->especie = "Felino";
    cat->idade = 2;
    cat->corDoPelo = "Branco";
    cat->raca = "Persa";

    // Exibir informações
    Cachorro::getCachorro(dog);
    Gato::getGato(cat);

    // Usando métodos herdados e específicos
    dog->caminhar();
    dog->latir();

    cat->caminhar();
    cat->miar();

    delete dog; // Liberar memória do cachorro
    delete cat; // Liberar memória do gato
    return 0;
}
