#ifndef CLASS_PROTOTIPO_HPP
#define CLASS_PROTOTIPO_HPP

#include <array>
#include <vector>
#include <string>

/**
 * @class Prototipo
 *
 * @brief Classe que contém funções para manipulação de palavras e verificação de
 * subconjuntos de palavras.
 */
class Prototipo
{
public:
    /**
     * @brief Verifica se todas as ocorrências dos caracteres de uma palavra estão presentes
     * em outra palavra.
     *
     * @param s1 Vetor de inteiros representando as ocorrências de caracteres de uma palavra.
     * @param s2 Vetor de inteiros representando as ocorrências de caracteres de outra palavra.
     * @return Retorna true se todos os caracteres de s2 estão presentes em s1, false caso contrário.
     */
    bool isUniverse(std::array<int, 26> &s1, std::array<int, 26> &s2);

    /**
     * @brief Encontra todas as palavras de words1 que são subconjuntos de palavras em words2.
     *
     * @param words1 Vetor de palavras para verificar.
     * @param words2 Vetor de palavras que definem os subconjuntos.
     * @return Um vetor de strings contendo as palavras de words1 que são subconjuntos de words2.
     */
    std::vector<std::string> wordSubsets(const std::vector<std::string> &words1,
                                         const std::vector<std::string> &words2);
};

#endif
