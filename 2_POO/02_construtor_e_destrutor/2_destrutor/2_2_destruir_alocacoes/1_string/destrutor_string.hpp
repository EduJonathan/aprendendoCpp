#ifndef CLASS_STRING_HPP
#define CLASS_STRING_HPP

#include <string>

constexpr int SIZE = 255; ///< Tamanho máximo da string.

/**
 * @brief Classe que encapsula uma string C-style.
 *
 * Esta classe gerencia uma string alocada dinamicamente e proporciona métodos
 * para manipular e exibir a string.
 */
class String
{
private:
    char *string; ///< Ponteiro para a string armazenada.

public:
    /**
     * @brief Construtor que inicializa a classe com uma string C-style.
     *
     * Aloca memória dinamicamente para armazenar a string e copia o conteúdo
     * passado para a nova string.
     *
     * @param str A string C-style a ser copiada.
     */
    String(const char *str);

    /**
     * @brief Atualiza a string interna com uma nova string fornecida.
     *
     * Este método altera a string armazenada na classe para o conteúdo
     * da string passada como parâmetro.
     *
     * @param str A nova string a ser copiada.
     */
    void getString(const std::string &str);

    /**
     * @brief Imprime a string armazenada.
     *
     * Este método exibe o conteúdo da string interna.
     */
    void printString(void) const;

    /**
     * @brief Destruidor que libera a memória alocada dinamicamente.
     *
     * O destruidor é chamado automaticamente quando o objeto sai de escopo
     * para liberar a memória associada à string.
     */
    ~String();
};

#endif // CLASS_STRING_HPP
