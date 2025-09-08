#include <iostream>
#include <iomanip>
#include <new>

/**
 * Tipos de casting em C++: casting (ou cast) é o processo de conversão de tipos
 * para outros. Em C++ além do tradicional, temos opções específicas e mais seguras:
 *
 * 1. static_cast: Conversões bem definidas e seguras em tempo de compilação:
 *  - Entre tipos numéricos (int para float, etc.).
 *  - Entre classes relacionadas na hierarquia.
 *
 * 2. const_cast: Remove ou adiciona const ou volatile:
 *  - Permite modificar dados onde const foi aplicado.
 *  - Deve ser usado com MUITO cuidado (comportamento indefinido se o objeto for realmente const).
 *
 * 3. dynamic_cast: Conversão segura na hierarquia de classes polimórficas (Utilizado em POO):
 *  - Requer pelo menos uma função virtual na classe base.
 *  - Retorna nullptr (ponteiros) ou lança std::bad_cast (referências) se a conversão falhar.
 *
 * 4. reinterpret_cast: Reinterpreta os bits de um tipo para outro:
 *  - Perigoso e dependente da implementação.
 *  - Usado com ponteiros e tipos binários.
 */

class Base
{
public:
    virtual void fala() { std::cout << "class Base\n"; }
};

class Derivada : public Base
{
public:
    void fala() override { std::cout << "class Derivada\n"; }
};

int main(int argc, char **argv)
{
    std::cout << "1. CASTING TRADICIONAL (C-Style Cast)" << '\n';

    int inteiro = 65;
    char caractere = (char)inteiro;

    std::cout << "Casting tradicional: " << inteiro << " -> " << caractere << '\n';

    std::cout << "\n-----------------------------------" << '\n';

    std::cout << "2. STATIC_CAST - conversão numérica segura" << '\n';

    int numero = 10;
    double decimal = static_cast<double>(numero);

    std::cout << "static_cast: " << numero << " -> " << std::fixed << std::setprecision(2) << decimal << '\n';

    std::cout << "\n-----------------------------------" << '\n';

    std::cout << "3. CONST_CAST - remover const (use com cuidado!)" << '\n';

    int valor = 5;
    const int *ptrConst = &valor;
    int *ptrModificavel = const_cast<int *>(ptrConst);
    *ptrModificavel = 8;

    std::cout << "const_cast (valor original): " << valor << '\n';
    std::cout << "const_cast (modificado): " << *ptrModificavel << '\n';

    std::cout << "\n-----------------------------------" << '\n';

    std::cout << "4. DYNAMIC_CAST - conversão segura entre classes polimórficas" << '\n';

    Base *base = new Derivada(); // Alocando a classe
    Derivada *derivada = dynamic_cast<Derivada *>(base);

    if (derivada)
    {
        derivada->fala(); // Deve imprimir "Derivada"
    }
    else
    {
        std::cout << "dynamic_cast falhou\n";
    }
    
    delete base; // liberar memória alocada por new

    std::cout << "\n-----------------------------------" << '\n';

    std::cout << "5. REINTERPRET_CAST - uso de baixo nível (perigoso!)" << '\n';

    int numeroReinterpret = 65; // ASCII 'A'
    char *ptrBytes = reinterpret_cast<char *>(&numeroReinterpret);
    std::cout << "reinterpret_cast (char*): " << *ptrBytes << '\n'; // Deve imprimir 'A'

    std::cout << "Bytes do inteiro (hex): ";
    for (std::size_t i = 0ull; i < sizeof(int); ++i)
    {
        std::cout << std::hex << static_cast<int>(ptrBytes[i] & 0xFF) << ' ';
    }
    std::cout << std::dec << '\n';

    return 0;
}
