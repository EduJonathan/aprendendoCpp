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
 * Organização da memória entre `struct` e `class`:
 * - Ambos `struct` e `class` armazenam seus membros de forma contígua na memória,
 * na ordem em que são declarados, respeitando as regras de alinhamento da arquitetura.
 *
 * - O alinhamento (alignment) é o requisito de que certos tipos primitivos (como `int`, `double`)
 * sejam armazenados em endereços de memória específicos (ex: múltiplos de 4 ou 8 bytes).
 * Isso garante acesso eficiente pelo processador.
 *
 * - Em classes com herança e funções virtuais, pode haver um ponteiro oculto para
 * a vtable (vptr), o que afeta o layout e o tamanho final do objeto.
 *
 * - O padding (preenchimento) pode ser inserido automaticamente pelo compilador entre membros,
 * ou no final da estrutura, para satisfazer os requisitos de alinhamento.
 *
 * USE:
 * - `struct` Para tipos de dados simples e agrupamentos sem lógica complexa.
 * - `class` Para objetos mais complexos que necessitam de encapsulamento e controle sobre os membros.
 *
 * Então o uso de `struct` e `class` é mais uma questão de entender como seu código irá
 * operar de acordo com a complexidade dos dados e comportamentos que você está modelando.
 *
 * Veja mais em: https://en.cppreference.com/w/cpp/language/class
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

// Função auxiliar para imprimir valores e endereços
void printValues(const StructType &s, const ClassType &c)
{
    std::cout << "\n=== [Função printValues()] ===\n";
    std::cout << "Struct x: " << s.x << " | Endereço: " << &s.x << '\n';
    std::cout << "Class  y: " << c.y << " | Endereço: " << &c.y << '\n';
}

// Função para exibir endereços e tamanhos
void showMemoryInfo(const StructType &s, const ClassType &c)
{
    std::cout << "\n-------------------------------\n";
    std::cout << "[Endereços de Memória]\n";
    std::cout << "  Struct (objeto): " << &s << '\n';
    std::cout << "  Struct.x       : " << &s.x << '\n';
    std::cout << "  Class  (objeto): " << &c << '\n';
    std::cout << "  Class.y        : " << &c.y << '\n';

    std::cout << "\n[Tamanho dos Objetos]\n";
    std::cout << "  sizeof(StructType): " << sizeof(StructType) << " bytes\n";
    std::cout << "  sizeof(ClassType) : " << sizeof(ClassType) << " bytes\n";
}

int main(int argc, char **argv)
{
    // Instanciando e inicializando uma struct
    StructType s;
    s.x = 10;

    // Instanciando e inicializando uma class
    ClassType c;
    c.y = 10; // Acessando diretamente porque é público

    showMemoryInfo(s, c);
    printValues(s, c);

    std::cout << "-------------------------------\n";

    // Declarando novos objetos explicitamente
    StructType s2 = {20};
    ClassType c2;
    c2.setY(30); // Usando o método para definir o valor de y

    showMemoryInfo(s2, c2);
    printValues(s2, c2);

    return 0;
}
