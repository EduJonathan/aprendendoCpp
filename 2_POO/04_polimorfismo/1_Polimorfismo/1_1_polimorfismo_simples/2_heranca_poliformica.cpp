#include <iostream>
#include <memory>
#include <string>

// Classe base abstrata
class Escrever
{
public:
    // Função virtual pura para escrever
    virtual void escrever(const std::string &superficie) = 0;

    // Destrutor virtual
    virtual ~Escrever() = default;
};

// Classe derivada Caneta
class Caneta : public Escrever
{
public:
    void escrever(const std::string &superficie) override
    {
        std::cout << "Caneta escrevendo em: " << superficie << '\n';
    }
};

// Classe derivada Lápis
class Lápis : public Escrever
{
public:
    void escrever(const std::string &superficie) override
    {
        std::cout << "Lápis escrevendo em: " << superficie << '\n';
    }
};

// Classe derivada Grafite
class Grafite : public Escrever
{
public:
    void escrever(const std::string &superficie) override
    {
        std::cout << "Grafite escrevendo em: " << superficie << '\n';
    }
};

int main(int argc, char **argv)
{
    // Superfícies de escrita
    std::string superficies[] = {"Caderno", "Folha A4", "Caderno de Desenho"};

    // Usando ponteiros brutos
    Escrever *ferramenta1 = new Caneta();
    Escrever *ferramenta2 = new Lápis();
    Escrever *ferramenta3 = new Grafite();

    // Chama a função escrever para cada ferramenta e superfície
    for (const auto &superficie : superficies)
    {
        ferramenta1->escrever(superficie);
        ferramenta2->escrever(superficie);
        ferramenta3->escrever(superficie);
        std::cout << "------------------------\n";
    }

    // Liberar memória
    delete ferramenta1;
    delete ferramenta2;
    delete ferramenta3;

    // Usando smart pointers
    std::unique_ptr<Escrever> ferramenta4 = std::make_unique<Caneta>();
    std::unique_ptr<Escrever> ferramenta5 = std::make_unique<Lápis>();
    std::unique_ptr<Escrever> ferramenta6 = std::make_unique<Grafite>();

    // Chama a função escrever para cada ferramenta e superfície
    for (const auto &superficie : superficies)
    {
        ferramenta4->escrever(superficie);
        ferramenta5->escrever(superficie);
        ferramenta6->escrever(superficie);
        std::cout << "------------------------\n";
    }

    // Não é necessário liberar memória manualmente com smart pointers
    return 0;
}
