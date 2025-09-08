#include <iostream>
#include <string>

/**
 * A herança **protected** em C++ faz com que os membros públicos e protegidos da classe base
 * se tornem protegidos na classe derivada. Isso significa que esses membros são acessíveis
 * dentro da classe derivada e suas subclasses, mas não são acessíveis externamente, nem por
 * objetos da classe base ou fora da hierarquia de classes.
 *
 * É usada quando se deseja permitir o acesso aos membros da classe base apenas dentro da classe
 * derivada e suas subclasses, sem expô-los externamente.
 *
 * Diferença entre herança protected e private:
 * - **protected**: membros acessíveis na classe derivada e suas subclasses.
 * - **private**: membros inacessíveis mesmo nas subclasses.
 */

class Exemplo1
{
public:
    int atributoPublico;

protected:
    int atributoProtegido;

private:
    int atributoPrivado;
};

// Classe derivada, onde a classe Exemplo2 herda privadamente de Exemplo1
class Exemplo2 : protected Exemplo1
{
public:
    void acessarAtributos(void)
    {
        atributoPublico = 1;   // Acesso permitido, porém se torna protegido em Exemplo2
        atributoProtegido = 2; // Acesso permitido, porém se torna protegido em Exemplo2
        // atributoPrivado = 3; // Erro: não é possível acessar atributoPrivado
    }
};

// Classe base
class Dispositivo
{
public:
    void ligar(void)
    {
        std::cout << "Dispositivo ligado.\n";
    }

    void desligar(void)
    {
        std::cout << "Dispositivo desligado.\n";
    }

protected:
    std::string nome = "Dispositivo Genérico";
};

// Classe derivada com herança protected
class Celular : protected Dispositivo
{
public:
    void iniciar(void)
    {
        std::cout << "Iniciando celular...\n";
        ligar(); // Pode acessar ligar() porque virou protected
        std::cout << "Celular iniciado com nome: " << nome << "\n";
    }

    void desligarCelular(void)
    {
        desligar(); // Pode acessar desligar() também
        std::cout << "Celular desligado.\n";
    }
};

int main(int argc, char **argv)
{
    Exemplo2 exemplo2;
    /* exemplo2.atributoPublico = 1; */ // Acesso permitido, porém não é possível acessar fora de Exemplo2

    std::cout << "-------------------\n";

    Celular meuCelular;

    // meuCelular.ligar(); ERRO: ligar() virou protected
    // meuCelular.desligar(); ERRO: desligar() virou protected

    meuCelular.iniciar();         // Funciona
    meuCelular.desligarCelular(); // Funciona

    return 0;
}
