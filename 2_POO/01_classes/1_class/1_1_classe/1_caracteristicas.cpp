#include <iostream>
#include <cstdint>

/**
 * a CLASSE se comporta semelhantemente a uma ESTRUTURA (struct), o porém é, que enquanto uma classe
 * foi designada para se trabalhar com POO (Programação Orientada a Objetos), representando um OBJETO
 * com características e comportamentos a estrutura foi projetada para agrupar dados e trabalhar de maneira mais complexa.
 *
 * Porém suas características em questão de alocação de memória, organização dos dados, alinhamento, entre outros,
 * são as praticamente as mesmas de uma struct.
 */

class Classe
{
public:
    // Características (atributos, propriedades, campos), ao todo são 9 bytes, mas por conta do
    // alinhamento de memória(padding) o sizeof da classe será 12 bytes.
    int atributo1;   // 4 bytes
    float atributo2; // 4 bytes
    char atributo3;  // 1 byte

    // Comportamentos (métodos, funções)
    void metodo1()
    {
        std::cout << "\nMétodo 1 executado!" << '\n';
    }

    int metodo2(int parametro)
    {
        return parametro * 2;
    }
};

int main(int argc, char **argv)
{
    Classe objeto; // Criação de um objeto da classe

    // Endereços de memória do objeto
    std::cout << "Endereço do objeto: " << &objeto << '\n';

    // Mostrar o padding explicitamente
    std::cout << "\nPadding após atributo3: "
              << (uintptr_t)&objeto.atributo3 - (uintptr_t)&objeto.atributo2 - 1
              << " bytes" << '\n';

    // sizeof do objeto
    std::cout << "\nTamanho do objeto: " << sizeof(objeto) << " bytes" << '\n';

    // Endereços de memória dos atributos
    std::cout << "\nEndereço de atributo1: " << &objeto.atributo1 << '\n';
    std::cout << "Endereço de atributo2: " << &objeto.atributo2 << '\n';
    std::cout << "Endereço de atributo3: " << &objeto.atributo3 << '\n';

    // Valores dos atributos
    objeto.atributo1 = 10;
    objeto.atributo2 = 20.5f;
    objeto.atributo3 = 'A';

    std::cout << "\nValor de atributo1: " << objeto.atributo1 << '\n';
    std::cout << "Valor de atributo2: " << objeto.atributo2 << '\n';
    std::cout << "Valor de atributo3: " << objeto.atributo3 << '\n';

    // Chamando os métodos
    objeto.metodo1();
    int resultado = objeto.metodo2(5);
    std::cout << "Resultado de metodo2: " << resultado << '\n';
    return 0;
}
