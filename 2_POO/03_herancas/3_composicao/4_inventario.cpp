#include <iostream>
#include <vector>
#include <memory>
#include <new>
#include <algorithm>
#include <unordered_map>

class Item
{
private:
    std::string nome;

public:
    Item(std::string n) : nome(n) {}

    void mostrar(void) const
    {
        std::cout << "Item: " << nome << '\n';
    }

    std::string getNome(void) const { return nome; }
};

class Inventario
{
private:
    std::vector<std::shared_ptr<Item>> itens; // Agora, os itens são shared_ptr
    std::size_t limite;                       // Limite do inventário

public:
    Inventario(std::size_t limiteMax) : limite(limiteMax) {}

    bool adicionarItem(const std::string &nomeItem)
    {
        if (itens.size() < limite)
        {
            itens.emplace_back(std::make_shared<Item>(nomeItem)); // Usando smart pointer
            return true;
        }
        else
        {
            // Quando o inventário está cheio, excluímos o primeiro item
            std::cout << "Inventário cheio! Excluindo o item: " << itens.front()->getNome() << '\n';

            // Remove o primeiro item do inventário
            itens.erase(itens.begin());

            itens.emplace_back(std::make_shared<Item>(nomeItem)); // Adiciona o novo item
            return true;
        }
    }

    void removerItem(const std::string &nomeItem)
    {
        auto it = std::find_if(itens.begin(), itens.end(),
        [&nomeItem](const std::shared_ptr<Item> &item)
        {
            return item->getNome() == nomeItem;
        });

        if (it != itens.end())
        {
            std::cout << "Item removido: " << nomeItem << '\n';
            itens.erase(it); // Remove o item encontrado
        }
        else
        {
            std::cout << "Item \"" << nomeItem << "\" não encontrado no inventário.\n";
        }
    }

    void mostrarItens(void) const
    {
        std::cout << "\nInventário do jogador:" << '\n';
        for (const auto &item : itens)
        {
            item->mostrar(); // Acessando o método usando o shared_ptr
        }
    }

    std::size_t getLimite(void) const { return limite; }
};

class Jogador
{
private:
    std::string nome;
    std::shared_ptr<Inventario> inventario;
    std::string classe; // Classe do jogador

public:
    // Jogador agora é criado com sua classe e um inventário com limite baseado na classe
    Jogador(std::string n, std::string c) : nome(n)
    {
        this->classe = c;

        std::unordered_map<std::string, std::size_t> limites = {
            {"Arqueiro", 20},
            {"Mago", 10},
            {"Berserk", 5},
            {"Guerreiro", 15}};

        // Limita o inventário baseado na classe
        inventario = std::make_shared<Inventario>(limites[c]);
    }

    void coletarItem(const std::string &item)
    {
        if (inventario->adicionarItem(item))
        {
            std::cout << nome << " coletou o item: " << item << '\n';
        }
    }

    void removerItem(const std::string &item)
    {
        inventario->removerItem(item);
    }

    void exibirInventario(void) const
    {
        std::cout << "\nJogador: " << nome << " (" << classe << ")\n";
        inventario->mostrarItens();
    }
};

int main(int argc, char **argv)
{
    Jogador *jogador = new Jogador("Eduardo", "Arqueiro");

    // Coletando itens
    jogador->coletarItem("Espada de Fogo");
    jogador->coletarItem("Poção de Cura");
    jogador->coletarItem("Arco Longo");
    jogador->coletarItem("Bumerangue");
    jogador->coletarItem("Escudo");
    jogador->coletarItem("Poção de Mana");

    // Exibindo o inventário
    jogador->exibirInventario();

    // Tentando coletar mais itens do que o limite do Arqueiro
    jogador->coletarItem("Elixir"); // Isso vai remover o "Espada de Fogo" (primeiro item)

    // Exibindo o inventário após coleta do item extra
    jogador->exibirInventario();

    // Removendo um item específico ("Espada de Fogo")
    jogador->removerItem("Espada de Fogo");

    // Tentando remover um item que não existe ("Poção de Vida")
    jogador->removerItem("Poção de Vida");

    // Exibindo o inventário após remoções
    jogador->exibirInventario();

    delete jogador; // Liberando a memória alocada para o jogador
    return 0;
}
