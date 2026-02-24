#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

class Calculator
{
private:
    int valor;

public:
    // Construtor com valor inicial padrão
    Calculator(int valorInicial = 0);

    // Método que duplica o valor atual e retorna a referência do objeto
    Calculator &valorDuplicado();

    // Método que adiciona um número ao valor atual e retorna a referência do objeto
    Calculator &add(int numero);

    // Método para obter o valor atual
    int getValor() const;
};

#endif // CALCULATOR_HPP
