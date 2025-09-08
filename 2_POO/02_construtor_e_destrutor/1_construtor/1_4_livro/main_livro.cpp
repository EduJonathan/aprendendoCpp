#include <iostream>
#include "class_livro.hpp"

int main(int argc, char **argv)
{
    // Alocação dinâmica do objeto Livro usando 'new'
    Livro *livro = new Livro("O Senhor dos Anéis", "J.R.R. Tolkien", "HarperCollins", "1954");

    // Exibindo informações do livro
    std::cout << "Titulo: " << livro->getTitulo() << '\n';
    std::cout << "Autor: " << livro->getAutor() << '\n';
    std::cout << "Editora: " << livro->getEditora() << '\n';
    std::cout << "Ano de Publicação: " << livro->getAnoPublicacao() << '\n';

    // Alterando informações do livro
    livro->setTitulo("O Hobbit");
    livro->setAutor("J.R.R. Tolkien");
    livro->setEditora("HarperCollins");
    livro->setAnoPublicacao("1937");

    // Exibindo as informações alteradas
    std::cout << "\nApós modificação:" << '\n';
    std::cout << "Titulo: " << livro->getTitulo() << '\n';
    std::cout << "Autor: " << livro->getAutor() << '\n';
    std::cout << "Editora: " << livro->getEditora() << '\n';
    std::cout << "Ano de Publicação: " << livro->getAnoPublicacao() << '\n';

    // Libera a memória alocada dinamicamente
    delete livro;

    /**
     * Compile e execute o programa com:
     * > g++ -std=c++17 main_livro.cpp classLivro.cpp -o nome_do_executavel
     * > ./nome_do_executavel
     */
    return 0;
}
