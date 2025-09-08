#ifndef CLASS_CAESAR_CIPHER_HPP
#define CLASS_CAESAR_CIPHER_HPP

#include <string>

/**
 * @class CaesarCipher
 * @brief Classe para realizar a cifra de César, um algoritmo de criptografia simples.
 *
 * Esta classe permite criptografar uma senha utilizando a cifra de César, que desloca
 * cada letra do texto por um número fixo de posições no alfabeto.
 */
class CaesarCipher
{
private:
    int shift;                     // Deslocamento de caracteres.
    std::string password;          // Senha a ser criptografada.
    std::string encryptedPassword; // Senha criptografada.

public:
    /**
     * @brief Construtor padrão da classe CaesarCipher.
     */
    CaesarCipher();

    /**
     * @brief Solicita a senha ao usuário ou a recebe via argumentos de linha de comando.
     *
     * @param argc Número de argumentos na linha de comando.
     * @param argv Argumentos passados na linha de comando.
     * @return Referência para o objeto atual (permite chamadas encadeadas).
     */
    CaesarCipher &requestPassword(int argc, char **argv);

    /**
     * @brief Randomiza o valor de deslocamento da cifra (shift).
     *
     * Utiliza um dispositivo aleatório para gerar um valor de deslocamento entre 0 e 25.
     *
     * @return Referência para o objeto atual (permite chamadas encadeadas).
     */
    CaesarCipher &randomizeShift();

    /**
     * @brief Criptografa a senha usando a cifra de César.
     *
     * Desloca cada caractere da senha de acordo com o valor do deslocamento (shift).
     *
     * @return Referência para o objeto atual (permite chamadas encadeadas).
     */
    CaesarCipher &encrypt();

    /**
     * @brief Exibe a senha original, a senha criptografada e o valor do deslocamento.
     *
     * Exibe as informações no console para o usuário.
     *
     * @return Referência para o objeto atual (permite chamadas encadeadas).
     */
    CaesarCipher &prompt();
};

#endif
