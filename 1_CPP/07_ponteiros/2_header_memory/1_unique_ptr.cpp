#include <iostream>
#include <algorithm>
#include <string>
#include <memory>

/**
 * std::unique_ptr<T>: É um ponteiro inteligente que possui a propriedade de ser exclusivo,
 * ou seja, não pode haver mais de um ponteiro apontando para o mesmo objeto.
 * Isso significa que, quando um unique_ptr é destruído, o objeto que ele aponta
 * também é destruído automaticamente.
 *
 * é adequado quando você precisa garantir que a memória será desalocada assim que
 * o ponteiro sair de escopo. Ele é mais eficiente porque não envolve contagem de referência.
 *
 * SINTAXE: std::unique_ptr<T> nome_ponteiro(new T);
 * ou
 * std::unique_ptr<T> nome_ponteiro = std::make_unique<T>(parametros_construtor);
 *
 * O uso do std::make_unique é recomendado, pois evita vazamentos de memória e
 * garante que o ponteiro seja inicializado corretamente.
 */

class Carro
{
private:
    std::string modelo;
    int ano;

public:
    // Adicionando construtor padrão
    Carro() : modelo("Indefinido"), ano(0)
    {
        std::cout << "Carro padrão construído\n";
    }

    Carro(const std::string &m, int a) : modelo(m), ano(a)
    {
        std::cout << "Carro " << modelo << " construído\n";
    }

    ~Carro()
    {
        std::cout << "Carro " << modelo << " destruído\n";
    }

    void mostrarDetalhes() const
    {
        std::cout << "Modelo: " << modelo << ", Ano: " << ano << '\n';
    }

    // Métodos para modificar após construção
    void setModelo(const std::string &m)
    {
        modelo = m;
    }

    void setAno(int a)
    {
        ano = a;
    }
};

// Função que demonstra transferência de ownership
void usarCarro(std::unique_ptr<Carro> carro)
{
    std::cout << "Dentro da função usarCarro:\n";
    carro->mostrarDetalhes();
}

void usarCarro(std::unique_ptr<Carro> &carro)
{
    std::cout << "Dentro da função usarCarro:\n";
    carro->mostrarDetalhes();
    // O carro será destruído automaticamente quando a função terminar
}

class MyClass
{
public:
    MyClass() { std::cout << "MyClass criada!" << '\n'; }
    ~MyClass() { std::cout << "MyClass destruída!" << '\n'; }
};

int main(int argc, char **argv)
{
    // 1. Uso básico com string
    std::unique_ptr<std::string> nome = std::make_unique<std::string>("Linguagem C++");
    std::cout << "Nome: " << *nome << "\nTamanho: " << nome->size() << "\nEndereço: " << nome.get() << "\n\n";

    std::cout << "--------------------------------\n";

    std::unique_ptr<MyClass> ptr1 = std::make_unique<MyClass>();

    // Transferindo a posse para ptr2
    std::unique_ptr<MyClass> ptr2 = std::move(ptr1);

    // ptr1 agora é nulo, a posse foi transferida para ptr2
    if (!ptr1)
    {
        std::cout << "ptr1 não possui mais a posse do recurso." << '\n';
    }

    std::cout << "--------------------------------\n";

    // 2. Criação e transferência de unique_ptr
    std::unique_ptr<Carro> meuCarro = std::make_unique<Carro>("Fusca", 1970);
    meuCarro->mostrarDetalhes();

    // Transferindo posse
    std::unique_ptr<Carro> outroCarro = std::move(meuCarro);
    if (!meuCarro)
    {
        std::cout << "Posse transferida - meuCarro agora é nullptr\n";
    }
    outroCarro->mostrarDetalhes();

    std::cout << "--------------------------------\n";

    // 3. Passando para função
    usarCarro(std::move(outroCarro));
    if (!outroCarro)
    {
        std::cout << "Posse transferida para função - outroCarro agora é nullptr\n";
    }

    std::cout << "--------------------------------\n";

    // 4. Array de Carros
    std::unique_ptr<Carro[]> frota(new Carro[3]{
        Carro("Gol", 2020),
        Carro("Palio", 2018),
        Carro("Civic", 2021)});

    // Alternativa com make_unique (requer construtor padrão)
    /*
    std::unique_ptr<Carro[]> frota = std::make_unique<Carro[]>(3);
    frota[0].setModelo("Gol"); frota[0].setAno(2020);
    frota[1].setModelo("Palio"); frota[1].setAno(2018);
    frota[2].setModelo("Civic"); frota[2].setAno(2021);
    */

    std::cout << "--------------------------------\n";
    std::cout << "Fim do main - destruição automática dos objetos\n";

    return 0;
}
