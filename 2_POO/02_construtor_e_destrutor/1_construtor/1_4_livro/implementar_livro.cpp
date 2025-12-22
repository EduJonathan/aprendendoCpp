#include <cstring>
#include <new>
#include "class_livro.hpp"

/**
 * @brief Construtor da classe Livro.
 *
 * Aloca dinamicamente memória para armazenar as informações do livro:
 * título, autor, editora e ano de publicação.
 *
 * @param titulo O título do livro.
 * @param autor O autor do livro.
 * @param editora A editora do livro.
 * @param anoPublicacao O ano de publicação do livro.
 */
Livro::Livro(const char *titulo, const char *autor, const char *editora, const char *anoPublicacao)
{
    this->titulo        = new char[std::strlen(titulo) + 1];        // +1 para o caractere nulo '\0'
    this->autor         = new char[std::strlen(autor) + 1];         // +1 para o caractere nulo '\0'
    this->editora       = new char[std::strlen(editora) + 1];       // +1 para o caractere nulo '\0'
    this->anoPublicacao = new char[std::strlen(anoPublicacao) + 1]; // +1 para o caractere nulo '\0'

    std::strcpy(this->titulo, titulo);               // Copia o conteúdo para a variável alocada dinamicamente
    std::strcpy(this->autor, autor);                 // Copia o conteúdo para a variável alocada dinamicamente
    std::strcpy(this->editora, editora);             // Copia o conteúdo para a variável alocada dinamicamente
    std::strcpy(this->anoPublicacao, anoPublicacao); // Copia o conteúdo para a variável alocada dinamicamente
}

/**
 * @brief Destruidor da classe Livro.
 *
 * Libera a memória alocada dinamicamente para os atributos
 * título, autor, editora e ano de publicação.
 */
Livro::~Livro()
{
    delete[] titulo;
    delete[] autor;
    delete[] editora;
    delete[] anoPublicacao;
}

/**
 * @brief Obtém o título do livro.
 *
 * @return O título do livro.
 */
const char *Livro::getTitulo(void) const
{
    return titulo;
}

/**
 * @brief Define o título do livro.
 *
 * @param titulo O novo título do livro.
 */
void Livro::setTitulo(const char *titulo)
{
    delete[] this->titulo; // Libera a memória antes de alocar nova
    this->titulo = new char[std::strlen(titulo) + 1];
    std::strcpy(this->titulo, titulo);
}

/**
 * @brief Obtém o autor do livro.
 *
 * @return O autor do livro.
 */
const char *Livro::getAutor(void) const
{
    return autor;
}

/**
 * @brief Define o autor do livro.
 *
 * @param autor O novo autor do livro.
 */
void Livro::setAutor(const char *autor)
{
    delete[] this->autor;
    this->autor = new char[std::strlen(autor) + 1];
    std::strcpy(this->autor, autor);
}

/**
 * @brief Obtém a editora do livro.
 *
 * @return A editora do livro.
 */
const char *Livro::getEditora(void) const
{
    return editora;
}

/**
 * @brief Define a editora do livro.
 *
 * @param editora A nova editora do livro.
 */
void Livro::setEditora(const char *editora)
{
    delete[] this->editora;
    this->editora = new char[std::strlen(editora) + 1];
    std::strcpy(this->editora, editora);
}

/**
 * @brief Obtém o ano de publicação do livro.
 *
 * @return O ano de publicação do livro.
 */
const char *Livro::getAnoPublicacao(void) const
{
    return anoPublicacao;
}

/**
 * @brief Define o ano de publicação do livro.
 *
 * @param anoPublicacao O novo ano de publicação do livro.
 */
void Livro::setAnoPublicacao(const char *anoPublicacao)
{
    delete[] this->anoPublicacao;
    this->anoPublicacao = new char[std::strlen(anoPublicacao) + 1];
    std::strcpy(this->anoPublicacao, anoPublicacao);
}
