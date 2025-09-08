#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

class Animal
{
private:
    std::string nome;
    std::vector<std::string> ambientes;

public:
    // Construtor que recebe o nome do animal de forma diferente, conhecido como
    // construtor declarativo e permite adicionar ambientes posteriormente.
    Animal(const std::string &n) : nome(n) {}

    void adicionarAmbiente(const std::string &ambiente)
    {
        if (std::find(ambientes.begin(), ambientes.end(), ambiente) == ambientes.end())
        {
            ambientes.push_back(ambiente);
        }
    }

    void adicionarAmbientes(const std::vector<std::string> &lista)
    {
        for (const auto &amb : lista)
        {
            adicionarAmbiente(amb);
        }
    }

    void exibir(void) const
    {
        std::cout << "Animal: " << nome << "\nAmbientes: ";
        for (const auto &amb : ambientes)
        {
            std::cout << amb << ' ';
        }
        std::cout << '\n';
    }

    const std::string getNome(void) const
    {
        return nome;
    }
};

int main(int argc, char **argv)
{
    // Lista de animais
    std::list<Animal> *animais = new std::list<Animal>{
        Animal("Cobra"),
        Animal("Minhoca"),
        Animal("Cachorro"),
        Animal("Peixe-Palhaço"),
        Animal("Toupeira"),
        Animal("Águia")};

    // Mapa declarativo: animal → ambientes, funciona só se o animal já existir na lista.
    std::map<std::string, std::vector<std::string>> ambientesPorAnimal = {
        {"Cobra", {"terrestre"}},
        {"Minhoca", {"terrestre", "subsolo"}},
        {"Cachorro", {"terrestre"}},
        {"Peixe-Palhaço", {"aquatico"}},
        {"Toupeira", {"subsolo"}},
        {"Águia", {"voador", "terrestre"}}};

    // Atribui os ambientes de forma genérica
    for (auto &animal : *animais)
    {
        auto it = ambientesPorAnimal.find(animal.getNome());
        if (it != ambientesPorAnimal.end())
        {
            animal.adicionarAmbientes(it->second);
        }
    }

    // Exibir todos
    for (const auto &animal : *animais)
    {
        animal.exibir();
        std::cout << "-------------------\n";
    }

    return 0;
}
