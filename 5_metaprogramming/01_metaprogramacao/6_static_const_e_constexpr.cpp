#include <iostream>

/**
 * static const  –
 *    Define um membro de classe constante. O valor não pode mudar após a inicialização.
 *    Pode ser usado com tipos primitivos e tipos definidos pelo usuário.
 *    O valor *pode* ser conhecido em tempo de compilação, mas isso não é obrigatório.
 *    Em muitos casos, especialmente com tipos não primitivos, é necessário fornecer
 *    uma definição em um arquivo .cpp.
 *
 * static constexpr –
 *    Define um membro de classe que deve ser obrigatoriamente uma expressão constante.
 *    Isso significa que seu valor é garantido em tempo de compilação.
 *    Pode ser usado em contextos que exigem constant expressions, como:
 *       - limites de arrays
 *       - parâmetros de template
 *       - inicialização de outros valores constexpr
 *       - instruções if constexpr e metaprogramação
 *    Por ser constexpr, nunca requer definição fora da classe (desde que o tipo seja literal).
 *
 * Resumo prático:
 *    - static const      = valor imutável, mas nem sempre disponível em compile-time.
 *    - static constexpr  = valor imutável *e* garantidamente avaliado em compile-time.
 */

class Exemplo
{
public:
    // static const member
    static const int valorConst = 10;

    // static constexpr member
    static constexpr int valorConstexpr = 20;

    // static const member with user-defined type
    struct Ponto
    {
        int x;
        int y;
    };
    static const Ponto pontoConst;

    // static constexpr member with user-defined type
    static constexpr Ponto pontoConstexpr = {30, 40};
};

// Definição do membro estático const
const Exemplo::Ponto Exemplo::pontoConst = {50, 60};

int main()
{
    std::cout << "Static const int: " << Exemplo::valorConst << '\n';
    std::cout << "Static constexpr int: " << Exemplo::valorConstexpr << '\n';

    std::cout << "Static const Ponto: (" << Exemplo::pontoConst.x << ", " << Exemplo::pontoConst.y << ')' << '\n';
    std::cout << "Static constexpr Ponto: (" << Exemplo::pontoConstexpr.x << ", " << Exemplo::pontoConstexpr.y << ')' << '\n';

    return 0;
}