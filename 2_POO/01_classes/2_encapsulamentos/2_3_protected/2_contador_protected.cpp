#include <iostream>
#include <string>

class Counter
{
protected:
    int count = 0;
    std::string name = "Counter";

    // Método protected para validação interna
    void validate_count(int value)
    {
        if (value < 0)
        {
            count = 0; // Garante que count não seja negativo
        }
        else
        {
            count = value;
        }
    }

    // Método protected para obter o nome.
    std::string get_name() const
    {
        return name;
    }

public:
    // Método público para incrementar o contador
    void increment(int step = 1)
    {
        validate_count(count + step); // Usa método protected
    }

    // Método público para acessar o estado.
    int get_count() const
    {
        return count;
    }

    // Método público para exibir informações
    void display() const
    {
        std::cout << "Name: " << get_name() << ", Count: " << count << '\n';
    }
};

int main(int argc, char **argv)
{
    Counter counter;
    counter.display(); // Saída: Name: Counter, Count: 0

    counter.increment(5);
    counter.display(); // Saída: Name: Counter, Count: 5

    counter.increment(-10); // Não permite negativo devido a validate_count
    counter.display();      // Saída: Name: Counter, Count: 0

    // Erro de compilação: acesso direto a membros protected não é permitido
    // counter.count = 10; // Ilegal: count é protected
    // counter.validate_count(10); // Ilegal: validate_count é protected

    return 0;
}
