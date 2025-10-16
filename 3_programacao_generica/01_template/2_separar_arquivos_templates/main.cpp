#include "declaracoes.hpp"
#include <iostream>

/**
 * Separar Arquivos .hpp e .tpp
 *
 * Arquivo .hpp (Declarações):
 *
 * - Contém as declarações das classes, structs, funções e métodos de templates.
 * - Inclui membros de dados, assinaturas de métodos, classes internas e quaisquer outros elementos que definem a interface da classe ou função.
 * - Não contém as implementações (corpos) dos métodos ou funções de templates, exceto para funções inline muito curtas, se desejar.
 * - Inclui o arquivo .tpp correspondente no final do arquivo, após as declarações, usando #include "nome_do_arquivo.tpp".
 * - Usa guardas de inclusão (#ifndef, #define, #endif) para evitar múltiplas inclusões.
 *
 * -------------------------------------------
 *
 * Arquivo .tpp (Implementações de Templates):
 * - Contém as definições (implementações) dos métodos e funções declarados no .hpp para classes ou funções template.
 * - É incluído no final do arquivo .hpp para garantir que as definições de template estejam disponíveis quando o compilador precisar instanciar o template.
 * - Também deve ter guardas de inclusão para evitar múltiplas definições.
 * - Geralmente, não é compilado diretamente; ele é incluído pelo .hpp durante a compilação.
 *
 * -------------------------------------------
 *
 *  Arquivo .cpp (Opcional, para Código Não-Template ou Testes):
 *
 * - Usado para implementações não-template, instanciações explícitas de templates (template class MinhaClasse<int>;) ou para conter o programa principal (main).
 * - Inclui o arquivo .hpp para acessar as declarações e, indiretamente, as implementações do .tpp.
 */

int main(int argc, char **argv)
{
    MinhaClasse<int> Classe;
    Classe.adicionar(42);
    std::cout << "Valor: " << Classe.obterValor() << '\n';

    /**
     * g++ -std=c++11 main.cpp -o programa
     * ./programa
     */
    return 0;
}
