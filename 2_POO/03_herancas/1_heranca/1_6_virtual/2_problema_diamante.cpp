#include <iostream>
#include <new>

class Dispositivo
{
public:
    void ligar()
    {
        std::cout << "Dispositivo ligado" << '\n';
    }
};

class Impressora : public Dispositivo
{
public:
    void imprimir()
    {
        std::cout << "A classe Impressora está Imprimindo" << '\n';
    }
};

class Scanner : public Dispositivo
{
public:
    void escanear()
    {
        std::cout << "A classe Scanner está Escaneando" << '\n';
    }
};

class Multifuncional : public Impressora, public Scanner
{
public:
    void copiar()
    {
        std::cout << "A classe Multifuncional está Copiando" << '\n';
    }
};

/**
 * EXEMPLO COM O PROBLEMA DO DIAMANTE (PROPOSITAL):
 *
 * A classe Multifuncional herda de Impressora e Scanner, ambas herdando separadamente de Dispositivo.
 *
 * Isso causa o "problema do diamante": a classe Multifuncional herda
 * duas instâncias da classe Dispositivo, criando ambiguidade na chamada de métodos.
 *
 * Por isso, ao chamar mult->ligar(), o compilador gera erro:
 * "ligar() is ambiguous".
 *
 * SOLUÇÃO TEMPORÁRIA: especificar explicitamente o caminho desejado:
 * mult->Impressora::ligar(); ou mult->Scanner::ligar();
 *
 * SOLUÇÃO DEFINITIVA: usar herança virtual em Impressora e Scanner.
 */

int main(int argc, char **argv)
{
    Multifuncional *mult = new Multifuncional();

    /* mult->ligar(); */ // "Multifuncional::ligar" is ambiguous
    /// ERROR: Ambiguidade de qual ligar()?
    /// USAR: Impressora::Dispositivo::ligar ou Scanner::Dispositvo::ligar?

    // Para resolver temporariamente, é necessário especificar o caminho:
    mult->Impressora::ligar(); // Usa ligar() herdado por Impressora
    mult->Scanner::ligar();    // Usa ligar() herdado por Scanner

    mult->imprimir();
    mult->escanear();
    mult->copiar();

    delete mult;
    return 0;
}
