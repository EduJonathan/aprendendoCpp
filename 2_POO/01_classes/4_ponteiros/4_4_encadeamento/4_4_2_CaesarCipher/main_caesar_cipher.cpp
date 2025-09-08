#include "class_cipher.hpp"

/**
 * @brief Função principal que executa a criptografia usando a cifra de César.
 *
 * A função cria uma instância de CaesarCipher, solicita a senha do usuário,
 * randomiza o deslocamento, criptografa a senha e exibe os resultados.
 *
 * @param argc Número de argumentos na linha de comando.
 * @param argv Argumentos passados na linha de comando.
 * @return Retorna 0 ao final da execução.
 */
int main(int argc, char **argv)
{
    CaesarCipher().requestPassword(argc, argv).randomizeShift().encrypt().prompt();

    /**
     * Compile e execute o programa com:
     * > g++ -std=c++17 .\main_caesar_cipher.cpp .\implementar_caesar_cipher.cpp -o executavel
     * > .\executavel.exe "minhaSenhaSecreta"
     */
    return 0;
}
