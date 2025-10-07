#include <iostream>
#include <new>

/**
 * Em C++, `this` é um ponteiro implícito que é passado para todos os métodos de
 * instância (não estáticos). Ele aponta para o objeto atual no qual o método foi
 * chamado. O this é automaticamente disponível dentro de qualquer função membro não
 * estática, permitindo que você acesse o endereço de memória do objeto em que o método
 * foi invocado.
 *
 * Uso Prático:
 * - Resolver ambiguidades quando nomes de parâmetros colidem com membros da classe.
 * - Retornar referências ao próprio objeto (para encadeamento de métodos).
 * - Passar o objeto atual como parâmetro para outras funções.
 */
class THIS
{
public:
    int x = 10;

public:
    /**
     * @brief Exibe informações sobre o objeto atual usando o ponteiro `this`.
     *
     * Este método mostra:
     *
     * - O valor da variável `x`
     *
     * - O endereço de memória de `x`
     *
     * - O endereço do próprio objeto (via `this`)
     *
     * - O valor de `x` acessado por `this->x`
     *
     * - O endereço de memória de `x` acessado por `&(this->x)`
     */
    void get_this(void) const
    {
        std::cout << "O valor de x: " << x << '\n'
                  << "O endereço de memória do valor de x: " << &x << '\n'
                  << "E o valor do ponteiro This: " << this << '\n'
                  << "this->x aponta para o valor: " << this->x << '\n'
                  << "Endereço de memória de 'x' via this: " << &(this->x) << '\n';
    }
};

int main(int argc, char **argv)
{
    THIS This;       // Criação de um objeto `THIS` da classe `This`
    This.get_this(); // Chama o método para exibir informação sobre os valores que this acessa

    std::cout << "\n----------------------------\n";

    // Criando o objeto dinamicamente na heap com new para o objeto THIS
    THIS *object_this = new THIS();

    // Chamando o método para exibir informações sobre o objeto
    object_this->get_this();

    // Liberando a memória alocada com delete para obj
    delete object_this;
    return 0;
}
