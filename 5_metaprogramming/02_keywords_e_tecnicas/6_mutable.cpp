#include <iostream>

/**
 * mutable é uma keyword do C++ que permite modificar membros de um objeto
 * mesmo quando o objeto é declarado como const. Isso é útil em situações
 * onde você deseja manter a constância lógica do objeto, mas ainda assim
 * precisa alterar certos membros internos.
 */

struct Contador
{
private:
    mutable int contagem; // Pode ser modificado mesmo em objetos const

public:
    Contador() : contagem(0) {}

    void incrementar() const
    {
        contagem++; // Permitido devido ao uso de mutable
    }

    int obterContagem() const
    {
        return contagem;
    }
};

int main(int argc, char **argv)
{
    const Contador c; // Objeto const
    c.incrementar();
    c.incrementar();
    std::cout << "Contagem: " << c.obterContagem() << '\n'; // Saída: Contagem: 2
    return 0;
}