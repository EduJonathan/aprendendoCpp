#include <iostream>
#include <cstdlib>
#include <ctime>

/**
 * A biblioteca <ctime> em C++, fornece funções relacionadas a data, hora e manipulação de tempo
 * ela vem herdada do C (<time.h>)
 *
 * - ctime
 * - difftime
 * - gmtime
 * - localtime
 * - mktime
 * - time
 * - timespec_get
 * 
 * @note Porém para este tipo de situação temos a biblioteca moderna em C++, conhecida como chrono
 * A partir do C++11, a biblioteca <chrono> que substitui muitas funções antigas de <ctime>,
 * com mais precisão e segurança. Mas <ctime> ainda é muito usado para coisas simples e
 * compatibilidade com C.
 */

int main(int argc, char **argv)
{
    std::time_t agora = std::time(nullptr);                   // Pega o tempo atual
    std::cout << "Data e hora atual: " << std::ctime(&agora); // Converte para string legível

    std::cout << "--------------------------" << '\n';

    std::srand(std::time(0));                   // Inicializa a semente aleatória com base no tempo atual criado por time(0);
    int numero_secreto = std::rand() % 100 + 1; // Gera número entre 1 e 100

    int chute = 0;      // Armazena o chute do usuário
    int tentativas = 0; // Contador de tentativas

    std::cout << "Jogo da Adivinhação\n";
    std::cout << "Tente adivinhar o número secreto entre 1 e 100.\n\n";

    do
    {
        std::cout << "Digite seu chute: ";
        std::cin >> chute;

        tentativas++;

        if (chute > numero_secreto)
        {
            std::cout << "Valor muito alto! Tente novamente.\n\n";
        }
        else if (chute < numero_secreto)
        {
            std::cout << "Valor muito baixo! Tente novamente.\n\n";
        }
        else
        {
            std::cout << "Parabéns! Você acertou o número em " << tentativas << " tentativa(s)!\n";
        }

    } while (chute != numero_secreto);

    return 0;
}
