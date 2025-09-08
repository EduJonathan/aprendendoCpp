#include <iostream>

/**
 * A aritmética de ponteiros é quando conseguimos acessar com a desreferência o endereço
 * de uma variável e trabalhar com o endereço armazenado no ponteiro, podendo realizar
 * operações aritméticas, pecorrer arrays, matrizes pelos endereços de memória com o
 * ponteiro, alterar valores.
 */

int main(int argc, char **argv)
{
    int x = 5;
    int y = 10;

    int *pointerX = &x; // Ponteiro aponta para a variável x
    int *pointerY = &y; // Ponteiro aponta para a variável y

    std::cout << "\n-----------------------------------------------\n";

    int soma = (*pointerX + *pointerY); // Aritmética de ponteiros para somar os ponteiros
    int sub = (*pointerX - *pointerY);  // Aritmética de ponteiros para subtrair os ponteiros
    int mult = (*pointerX * *pointerY); // Aritmética de ponteiros para multiplicar os ponteiros
    int div = (*pointerY / *pointerX);  // Aritmética de ponteiros para dividir os ponteiros
    int mod = (*pointerX % *pointerY);  // Aritmética de ponteiros para obter o resto da divisão

    std::cout << "soma = " << soma << '\n';
    std::cout << "sub = " << sub << '\n';
    std::cout << "mult = " << mult << '\n';
    std::cout << "div = " << div << '\n';
    std::cout << "mod = " << mod << '\n';

    std::cout << "\n-----------------------------------------------\n";

    int array[] = {1, 2, 3, 4, 5};
    int *pointerArray = array;

    // Imprime 4, que é o valor no índice 3 do array (pointerArray + 3).
    std::cout << *(pointerArray + 3) << '\n';

    // Imprime 2, que é o valor no índice 1 do array (pointerArray + 1).
    std::cout << *(pointerArray + 1) << '\n';

    // O ponteiro é incrementado para apontar para o segundo elemento do array (array[1]).
    pointerArray++;

    // Imprime 2, o valor no qual o ponteiro pointerArray agora aponta.
    std::cout << *pointerArray << '\n';

    std::cout << "\n-----------------------------------------------\n";

    // Aritmética de ponteiros com arrays
    int arr[] = {1, 2, 3, 4, 5};
    int *ptr_arr = arr;

    // Aponta para o primeiro elemento (1)
    std::cout << "*ptr_arr = " << *ptr_arr << '\n';

    // Move para o próximo elemento (2)
    ptr_arr++;

    // Aponta para o segundo elemento (2)
    std::cout << "*ptr_arr = " << *ptr_arr << '\n';

    // Move mais 1 posição (equivalente a ptr_arr++)
    ptr_arr += 1;

    // Aponta para o terceiro elemento (3)
    std::cout << "*ptr_arr = " << *ptr_arr << '\n';

    // Move 2 posições para trás (apontará para o primeiro elemento - 1)
    ptr_arr -= 2;

    // Aponta para o primeiro elemento (1)
    std::cout << "*ptr_arr = " << *ptr_arr << '\n';

    std::cout << "\n-----------------------------------------------\n";

    // Aritmética de ponteiros fora de limites
    // ATENÇÃO: Isso é apenas para fins de demonstração, acessar memória
    // fora dos limites de um array é indefinido!

    // Aponta para o primeiro elemento (1)
    ptr_arr = arr;

    // Aponta para o segundo elemento (2)
    ptr_arr++;

    // Deve imprimir 2
    std::cout << "ptr_arr (aponta para o segundo elemento) = " << *ptr_arr << '\n';

    // Tentando acessar um valor além do array pode gerar comportamento indefinido!
    ptr_arr++; // Aponta para o terceiro elemento (3)
    ptr_arr++; // Aponta para o quarto elemento (4)
    ptr_arr++; // Aponta para o quinto elemento (5)
    ptr_arr++; // Aponta para fora do array! Isso é **inválido** e pode causar erro.

    // Imprimir o valor do ponteiro após ultrapassar os limites do array não é seguro:
    // std::cout << "*ptr_arr (fora dos limites) = " << *ptr_arr << '\n';
    // Comportamento indefinido
    return 0;
}
