#ifndef CLASS_ARRAY_HPP
#define CLASS_ARRAY_HPP

#include <iostream>
#include <memory>

class Array
{
public:
    /**
     * @brief Verifica se o array foi alocado corretamente.
     *
     * Verifica se o ponteiro para o array é diferente de nullptr.
     * Se o array não foi alocado corretamente, exibe uma mensagem de erro.
     *
     * @param arr Ponteiro para o array a ser verificado.
     * @param size Tamanho do array.
     * @return true se o array foi alocado corretamente, false caso contrário.
     */
    bool isValid(const std::unique_ptr<int[]> &arr, std::size_t size);

    /**
     * @brief Aloca memória dinamicamente para um array de inteiros.
     *
     * Se o tamanho do array for inválido (menor ou igual a 0), retorna nullptr.
     * Caso a memória não seja alocada corretamente, retorna nullptr.
     *
     * @param size Tamanho do array a ser alocado.
     * @return Ponteiro para o array alocado ou nullptr em caso de erro.
     */
    std::unique_ptr<int[]> criarArray(std::size_t size);

    /**
     * @brief Insere um valor no array em uma dada posição.
     *
     * @param[in] arr Ponteiro para o array.
     * @param[in] size Tamanho do array.
     * @param[in] index Índice da posição no array para inserir o valor.
     * @param[in] value Valor a ser inserido no array.
     *
     * @return true se o valor for inserido com sucesso, false caso contrário.
     */
    bool insertValue(std::unique_ptr<int[]> &arr, std::size_t size, std::size_t index, double value);

    /**
     * @brief Exibe o conteúdo do array.
     *
     * Se o array for nullptr, exibe "Array não alocado!" e retorna.
     *
     * @param arr Ponteiro para o array a ser exibido.
     * @param size Tamanho do array.
     */
    void printArray(const std::unique_ptr<int[]> &arr, std::size_t size);
};

#endif
