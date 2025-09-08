#include <iostream>

/**
 * Em C++, tanto `struct` quanto `class` são tipos compostos, ou seja,
 * usados para agrupar dados de diferentes tipos. A principal diferença
 * entre eles é a visibilidade padrão e a semântica de uso.
 *
 * Em termos práticos, a escolha entre `struct` e `class` depende do nível de
 * controle e encapsulamento que você deseja. Ambas as estruturas podem ser usadas
 * para agrupar dados, mas o `class` oferece mais controle sobre como esses dados
 * são acessados e manipulados, enquanto o `struct` é mais simples e direto, com
 * seus membros públicos por padrão.
 *
 * Então, use:
 * - `struct` Para tipos de dados simples e agrupamentos sem lógica complexa.
 * - `class` Para objetos mais complexos que necessitam de encapsulamento e controle
 *   sobre os membros.
 */

struct StructType
{
    int x; // Público por padrão
};

class ClassType
{
public:
    int y; // Público, pois é explicitamente declarado como tal.

    void setY(int val)
    {
        y = val; // Método para manipular y, garantindo controle sobre o valor.
    }
};

void printValues(const StructType &s, const ClassType &c)
{
    // Acessando membros diretamente na struct (já são públicos)
    std::cout << "Struct x: " << s.x << '\n';

    // Acessando o membro y da class através de acesso público.
    std::cout << "Class y: " << c.y << '\n';
}

int main(int argc, char **argv)
{
    // Instanciando e inicializando uma struct
    StructType s;
    s.x = 10;

    // Instanciando e inicializando uma class
    ClassType c;
    c.y = 10; // Acessando diretamente porque é público

    // Exibindo os valores
    std::cout << "Struct: " << s.x << '\n';
    std::cout << "Class: " << c.y << '\n';

    /**
     * Neste exemplo, o código vai funcionar sem problema algum. A instância de struct (s)
     * tem o membro público x, e a instância de class (c) tem o membro público y porque ele
     * foi explicitamente declarado como public (mesmo que em uma class os membros sejam
     * privados por padrão).
     */

    std::cout << "-------------------------------" << '\n';

    // Inicializando uma struct diretamente
    StructType typeStruct = {10}; // Inicialização direta no momento da criação

    // Inicializando e manipulando uma class
    ClassType typeClass;
    typeClass.setY(20); // Modificando o valor de y usando o método

    printValues(typeStruct, typeClass);

    /**
     * Aqui, você está passando uma instância de `struct` e uma de `class` para a função
     * printValues() e manipulando seus membros. A única coisa a se preocupar é a
     * visibilidade dos membros, já que em `struct` eles são públicos por padrão, mas
     * em `class` podem precisar de métodos públicos para acesso.
     */

    return 0;
}
