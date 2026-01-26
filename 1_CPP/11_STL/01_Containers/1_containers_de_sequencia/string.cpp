#include <iostream>
#include <algorithm>
#include <list>
#include <string>

/**
 * std::string é uma classe para manipulação de texto, com métodos para concatenação,
 * busca e substituição, funcionando como um container sequencial de caracteres.
 *
 * std::list<std::string> permite armazenar sequências de strings com inserções eficientes.
 */

/**
 * @brief Adiciona os elementos de um array de strings a uma lista.
 *
 * @param lista Lista que receberá os elementos.
 * @param array Array de strings (terminado por string vazia).
 */
void adicionarEmLista(std::list<std::string> &lista, const std::string array[])
{
    for (int i = 0; !array[i].empty(); ++i)
    {
        lista.push_back(array[i]);
    }
}

/**
 * @brief Exibe os elementos de uma lista de strings separados por espaço.
 *
 * @param lista Lista de strings.
 */
void exibirLista(const std::list<std::string> &lista)
{
    for (const auto &palavra : lista)
    {
        std::cout << palavra << ' ';
    }
    std::cout << '\n';
}

/**
 * @brief Insere os elementos de uma frase no início ou no fim de uma sentença.
 *
 * @param sentenca Lista principal a ser modificada.
 * @param frase Lista com os elementos a serem inseridos.
 * @param noInicio Define se a inserção será no início (true) ou no fim (false).
 */
void inserirFraseNaSentenca(std::list<std::string> &sentenca,
                            std::list<std::string> &frase, bool noInicio)
{
    if (noInicio)
    {
        sentenca.splice(sentenca.begin(), frase);
    }
    else
    {
        sentenca.splice(sentenca.end(), frase);
    }
}

/**
 * @brief Insere uma frase na sentença após encontrar uma palavra-chave.
 *
 * @param sentenca Lista principal.
 * @param frase Lista com palavras a serem inseridas.
 * @param chave Palavra após a qual a inserção deve acontecer.
 */
void inserirAposPalavra(std::list<std::string> &sentenca,
                        std::list<std::string> &frase, const std::string &chave)
{
    auto it = std::find(sentenca.begin(), sentenca.end(), chave);

    if (it != sentenca.end())
    {
        ++it; // insere depois da palavra-chave
        sentenca.splice(it, frase);
    }
}

int main(int argc, char **argv)
{
    std::list<std::string> sentenca;
    std::list<std::string> frase;

    std::string palavras1[]{"A", "B", ""};
    std::string palavras2[]{"C", "D", ""};
    std::string palavras3[]{"E", "F", "G", ""};
    std::string palavras4[]{"A", "C", "E", "G", ""};

    adicionarEmLista(sentenca, palavras1);
    adicionarEmLista(frase, palavras2);

    std::cout << "Sentença original:\n";
    exibirLista(sentenca);

    inserirFraseNaSentenca(sentenca, frase, true);

    std::cout << "Após inserir frase no início:\n";
    exibirLista(sentenca);

    adicionarEmLista(frase, palavras3);

    inserirFraseNaSentenca(sentenca, frase, false);
    std::cout << "Após inserir frase no final:\n";
    exibirLista(sentenca);

    adicionarEmLista(frase, palavras4);

    inserirAposPalavra(sentenca, frase, palavras4[0]);
    std::cout << "Após inserir frase após a palavra-chave \"" << palavras4[0] << "\":\n";

    exibirLista(sentenca);

    return 0;
}
