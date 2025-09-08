#include <iostream>

/**
 * ENUMS: São usados para representar um conjunto de constantes relacionadas, geralmente
 * utilizados para representar estados, tipos de dados, operações, etc.
 */

enum DIAS_SEMANAIS
{
    SEGUNDA_FEIRA,
    TERCA_FEIRA,
    QUARTA_FEIRA,
    QUINTA_FEIRA,
    SEXTA_FEIRA,
    SABADO,
    DOMINGO
};

int main(int argc, char **argv)
{
    /* Entregando um valor de enum DIAS_SEMANAIS para o tipo enum DIA */
    DIAS_SEMANAIS DIA = SABADO;

    if (DIA == DOMINGO)
    {
        std::cout << "APROVEITE SEU DOMINGO" << '\n';
    }
    else
    {
        std::cout << "HORA DE TRABALHAR/ESTUDAR" << '\n';
    }
    return 0;
}
