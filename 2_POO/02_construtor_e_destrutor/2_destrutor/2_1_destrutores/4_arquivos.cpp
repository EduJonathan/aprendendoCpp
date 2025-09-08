#include <iostream>
#include <fstream>
#include <string>

class GerenciadorArquivo
{
private:
    std::fstream arquivo;
    std::string nomeArquivo;
    bool aberto;

public:
    // Construtor padrão
    GerenciadorArquivo() : nomeArquivo(""), aberto(false)
    {
        std::cout << "Gerenciador criado (sem arquivo associado)\n";
    }

    // Construtor com nome de arquivo
    GerenciadorArquivo(const std::string &nome) : nomeArquivo(nome), aberto(false)
    {
        abrirArquivo();
        std::cout << "Gerenciador criado com arquivo: " << nome << '\n';
    }

    // Destrutor
    ~GerenciadorArquivo()
    {
        if (aberto)
        {
            arquivo.close();
            std::cout << "Arquivo " << nomeArquivo << " fechado no destrutor\n";
        }
        std::cout << "Gerenciador destruído\n";
    }

    // Método para abrir arquivo
    bool abrirArquivo(void)
    {
        if (nomeArquivo.empty())
        {
            std::cerr << "Erro: Nome do arquivo não especificado\n";
            return false;
        }

        // Abrir arquivo em modo leitura e escrita, criando se não existir
        arquivo.open(nomeArquivo, std::ios::in | std::ios::out | std::ios::app);

        if (!arquivo.is_open())
        {
            std::cerr << "Erro ao abrir arquivo: " << nomeArquivo << '\n';
            aberto = false;
            return false;
        }
        aberto = true;
        std::cout << "Arquivo " << nomeArquivo << " aberto com sucesso\n";
        return true;
    }

    // Método para escrever no arquivo
    void escrever(const std::string &conteudo)
    {
        if (!aberto)
        {
            std::cerr << "Erro: Arquivo não está aberto\n";
            return;
        }
        arquivo << conteudo << '\n';
        std::cout << "Conteúdo escrito no arquivo\n";
    }

    // Método para ler do arquivo
    void ler(void)
    {
        if (!aberto)
        {
            std::cerr << "Erro: Arquivo não está aberto\n";
            return;
        }

        arquivo.seekg(0); // Volta para o início do arquivo
        std::string linha;
        std::cout << "\nConteúdo do arquivo " << nomeArquivo << ":\n";

        while (std::getline(arquivo, linha))
        {
            std::cout << linha << '\n';
        }
    }
};

void testeEscopo(void)
{
    std::cout << "\n=== INÍCIO DO BLOCO ===\n";
    GerenciadorArquivo log("registro.log");

    log.escrever("Mensagem de teste 1");
    log.escrever("Mensagem de teste 2");
    log.ler();
    std::cout << "=== FIM DO BLOCO ===\n";
    // Destrutor chamado aqui
}

int main(int argc, char **argv)
{
    // Demonstração do ciclo de vida completo
    std::cout << "=== INÍCIO DO PROGRAMA ===\n";

    // 1. Criando gerenciador sem arquivo
    GerenciadorArquivo g1;

    // 2. Criando gerenciador com arquivo
    GerenciadorArquivo g2("dados.txt");
    g2.escrever("Linha inicial");

    // 3. Testando em bloco de escopo
    testeEscopo();

    // 4. Tentando usar após fechamento
    std::cout << "\nTentando escrever após fechamento...\n";
    // g2 ainda existe, mas o arquivo foi fechado no destrutor

    std::cout << "=== FIM DO PROGRAMA ===\n";
    // Destrutores chamados aqui para g1 e g2
    return 0;
}
