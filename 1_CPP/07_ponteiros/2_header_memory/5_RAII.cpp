#include <iostream>
#include <string>
#include <memory>

/**
 * RAII (Resource Acquisition Is Initialization)
 *
 * RAII significa literalmente “Aquisição de Recurso é Inicialização”.
 * É um paradigma fundamental do C++, no qual um recurso (memória, arquivo, conexão, etc.)
 * é adquirido no construtor de um objeto e automaticamente liberado no destrutor.
 *
 * ------------------------------
 * Como funciona:
 * 1. O recurso é adquirido no construtor.
 * 2. O recurso é liberado automaticamente no destrutor.
 * 3. Quando o objeto sai de escopo, o destrutor é chamado automaticamente.
 *
 * ------------------------------
 * Vantagens:
 * - Evita vazamentos de memória (memory leaks)
 * - Garante liberação de recursos mesmo em caso de exceção
 * - Código mais limpo e seguro
 * - Liberação determinística: você sabe *quando* o recurso é liberado
 */

struct Arquivo
{
    std::string nome;

    Arquivo(const std::string &n) : nome(n)
    {
        std::cout << "Abrindo arquivo: " << nome << '\n';
    }

    ~Arquivo()
    {
        std::cout << "Fechando arquivo: " << nome << '\n';
    }

    void escrever(const std::string &texto)
    {
        std::cout << "Escrevendo no arquivo '" << nome << "': " << texto << '\n';
    }
};

int main(int argc, char **argv)
{
    std::cout << "Início do programa\n";

    {
        // Smart pointer gerenciando o recurso RAII
        std::unique_ptr<Arquivo> log = std::make_unique<Arquivo>("registro.txt");

        log->escrever("Iniciando sessão de jogo...");
        log->escrever("Jogador entrou na masmorra.");
        std::cout << "Dentro do escopo de 'log'\n";

        // Não precisamos chamar delete — RAII + smart pointer cuidam de tudo!
    } // <- std::unique_ptr libera o objeto automaticamente aqui

    std::cout << "Fim do programa\n";
    return 0;
}
