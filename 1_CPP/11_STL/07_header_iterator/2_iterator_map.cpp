#include <iostream>
#include <map>
#include <utility>
#include <iterator>

int main(int argc, char **argv)
{
    // Criando um mapa (dicionário) associativo onde a chave e o valor são do tipo string
    std::map<std::string, std::string> mapa;

    // Inserindo pares de chave-valor no mapa, com palavras que têm opostos
    mapa.insert(std::pair<std::string, std::string>("yes", "no"));
    mapa.insert(std::pair<std::string, std::string>("cima", "baixo"));
    mapa.insert(std::pair<std::string, std::string>("direita", "esquerda"));
    mapa.insert(std::pair<std::string, std::string>("esquerda", "direita"));
    mapa.insert(std::pair<std::string, std::string>("bom", "ruim"));
    mapa.insert(std::pair<std::string, std::string>("ruim", "bom"));

    // Definindo a string que você quer procurar no mapa
    std::string str("baixo");
    std::string string("cima");

    // Declarando iterators para `mapa`
    std::map<std::string, std::string>::iterator it;

    // Procurando o par chave-valor que contém a chave igual a "baixo"
    it = mapa.find(str);

    // Verificando se a chave foi encontrada no mapa
    if (it != mapa.end()) // Se it não é igual a mapa.end(), significa que a chave foi encontrada
    {
        // Se encontrado, imprime a chave e o valor (que é o oposto da palavra)
        std::cout << "Oposto de: " << it->first << " é " << it->second << '\n';
    }
    else
    {
        // Se a chave não foi encontrada, mensagem de erro
        std::cout << "Palavra não encontrada no mapa!" << '\n';
    }

    std::cout << "=================================" << '\n';

    std::map<std::string, std::string>::iterator i;

    // Procurando o par chave-valor que contém a chave igual a "baixo"
    i = mapa.find(string);

    // Verificando se a chave foi encontrada no mapa
    if (i != mapa.end()) // Se i não é igual a mapa.end(), significa que a chave foi encontrada
    {
        // Se encontrado, imprime a chave e o valor (que é o oposto da palavra)
        std::cout << "Oposto de: " << i->first << " é " << i->second << '\n';
    }
    else
    {
        // Se a chave não foi encontrada, mensagem de erro
        std::cout << "Palavra não encontrada no mapa!" << '\n';
    }
    return 0;
}
