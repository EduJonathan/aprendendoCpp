#include <iostream>
#include <cstdint>
#include <memory>
#include <new>

/**
 * std::shared_ptr<T>: É um ponteiro inteligente que permite que vários ponteiros
 * compartilhem a propriedade de um mesmo objeto. Isso significa que, quando o último
 * shared_ptr que aponta para o objeto é destruído, o objeto também é destruído
 * automaticamente.
 *
 * É útil quando você precisa de múltiplos ponteiros para o mesmo recurso e deseja
 * garantir que a memória será desalocada quando todos os ponteiros forem destruídos.
 * Contudo, ele tem um custo de desempenho maior devido à contagem de referência.
 *
 * SINTAXE: std::shared_ptr<T> nome_ponteiro(new T);
 * ou
 * std::shared_ptr<T> nome_ponteiro = std::make_shared<T>(parametros_construtor);
 */

struct dados
{
    std::string str;
    uint16_t num;

    dados(std::string str, uint16_t n) : str(str), num(n) {};

    void imprimir()
    {
        std::cout << "String: " << str << '\n';
        std::cout << "Número: " << num << '\n';
    }
};

class MyClass
{
public:
    MyClass() { std::cout << "MyClass criada!" << '\n'; }
    ~MyClass() { std::cout << "MyClass destruída!" << '\n'; }
};

int main(int argc, char **argv)
{
    std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>();
    std::shared_ptr<MyClass> ptr2 = ptr1; // Compartilhando o recurso com ptr2

    std::cout << "O recurso será liberado automaticamente quando ambos os ponteiros forem destruídos." << '\n';

    std::cout << "-------------------------------" << '\n';

    /**
     * 01. Memória Stack: é a memória onde as variáveis locais são armazenadas.
     * Ela é gerenciada automaticamente pelo compilador.
     */
    dados d("Exemplo de dados", 10);
    d.imprimir();

    std::cout << "-------------------------------" << '\n';

    /**
     * 02. Memória Heap: é a memória onde os objetos são alocados dinamicamente.
     * Ela é gerenciada manualmente pelo programador. Para alocar memória na heap,
     * usamos o operador new.
     */
    dados *Dados = new dados("Exemplo de dados com ponteiro", 10);
    Dados->imprimir();
    delete Dados; // Liberando a memória alocada manualmente

    std::cout << "-------------------------------" << '\n';

    std::shared_ptr<dados> datas = std::make_shared<dados>("Exemplo de dados com shared_ptr!!", 10);
    datas->imprimir();

    /**
     * Caso utilizar a modificador auto, você deve de imediato usar já inicializa-lo.
     *
     * auto datas = std::make_shared<dados>("Exemplo de dados com shared_ptr");
     * datas->imprimir();
     *
     * Caso fizer:
     * auto datas; // Não inicializa o ponteiro, apenas declara.
     * datas = std::make_shared<dados>("Exemplo de dados com shared_ptr"); // Inicializa o ponteiro.
     * // Isso não é permitido, pois o ponteiro não foi inicializado.
     * // datas->imprimir(); // Erro: ponteiro não inicializado.
     */
    return 0;
}
