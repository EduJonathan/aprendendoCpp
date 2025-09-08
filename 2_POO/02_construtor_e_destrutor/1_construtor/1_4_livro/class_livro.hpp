#ifndef PROTOTIPO_CLASS_LIVRO_HPP
#define PROTOTIPO_CLASS_LIVRO_HPP

class Livro
{
private:
    char *titulo;
    char *autor;
    char *editora;
    char *anoPublicacao;

public:
    // Construtor
    Livro(const char *titulo, const char *autor, const char *editora, const char *anoPublicacao);

    // Destruidor para liberar memória alocada dinamicamente
    ~Livro();

    // Getters e Setters
    const char *getTitulo(void) const;
    void setTitulo(const char *titulo);

    const char *getAutor(void) const;
    void setAutor(const char *autor);
    
    const char *getEditora(void) const;
    void setEditora(const char *editora);
    
    const char *getAnoPublicacao(void) const;
    void setAnoPublicacao(const char *anoPublicacao);
};

#endif
