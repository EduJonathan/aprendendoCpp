#include <iostream>

/**
 * Em C++, a expressão "return *this;" é usada dentro de um método de uma classe e faz
 * com que o próprio objeto da classe seja retornado.
 *
 * ANALISANDO: `this` é um ponteiro que aponta para o próprio objeto da classe onde
 * o método está sendo executado. O operador '*' é usado para desreferenciar esse
 * ponteiro, acessando o objeto para o qual ele aponta.
 *
 * Assim, "return *this;" retorna o próprio objeto, permitindo o encadeamento
 * de chamadas de métodos.
 *
 * Esse encadeamento permite executar várias operações em sequência sobre
 * o mesmo objeto, tornando o código mais fluido, limpo e flexível.
 *
 * LEMBRANDO: Para isso funcionar corretamente, o método deve retornar uma referência
 * (e não uma cópia) ao objeto atual — isto é, `Tipo&` — para que os métodos encadeados
 * atuem sobre o mesmo objeto original.
 */

class ExemploEncadeamento
{
private:
    int valor;

public:
    ExemploEncadeamento &setValor(int valor)
    {
        this->valor = valor;
        return *this;
    }

    ExemploEncadeamento &print(void)
    {
        std::cout << "Valor: " << valor << '\n';
        return *this;
    }
};

int main(int argc, char **argv)
{
    ExemploEncadeamento encadearValor;
    encadearValor.setValor(10).print().setValor(20).print();
    return 0;
}
