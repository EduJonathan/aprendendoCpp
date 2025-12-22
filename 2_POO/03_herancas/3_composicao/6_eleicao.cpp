#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <memory>

struct CandidatosEleicao
{
    std::string nomeCandidato;
    int numeroDoCandidato;
    int quantidadeDeVotos;

    CandidatosEleicao(std::string nome, int numero)
        : nomeCandidato(std::move(nome)), // Usa move para maior eficiência
          numeroDoCandidato(numero),
          quantidadeDeVotos(0) {}
};

class Urna
{
private:
    std::vector<CandidatosEleicao> candidatos;

public:
    void adicionarCandidato(const std::string &nome, int numero)
    {
        candidatos.emplace_back(nome, numero); // Usa emplace_back para construção direta
    }

    void registrarVoto(int numeroDoCandidato)
    {
        for (auto &candidato : candidatos)
        {
            if (candidato.numeroDoCandidato == numeroDoCandidato)
            {
                candidato.quantidadeDeVotos++;
                std::cout << "Voto registrado para " << candidato.nomeCandidato << "!\n";
                return;
            }
        }
        std::cout << "Candidato não encontrado!\n";
    }

    void exibirResultados() const
    {
        // Removido "void" desnecessário nos parênteses
        std::cout << "\n=== Resultados da eleição ===\n";
        for (const auto &candidato : candidatos)
        {
            std::cout << "Candidato: " << candidato.nomeCandidato
                      << " - Votos: " << candidato.quantidadeDeVotos << '\n';
        }
    }
};

class Eleitor
{
private:
    std::string nome;
    std::shared_ptr<Urna> urna; // Substituído Urna* por std::shared_ptr<Urna>

public:
    Eleitor(const std::string &nomeEleitor, std::shared_ptr<Urna> urnaReferenciada)
        : nome(nomeEleitor), urna(urnaReferenciada) {}

    void votar(int numeroDoCandidato)
    {
        std::cout << nome << " está votando...\n";

        // Verifica se o ponteiro é válido
        if (urna)
        {
            urna->registrarVoto(numeroDoCandidato);
        }
        else
        {
            std::cout << "Erro: Urna não inicializada!\n";
        }
    }

    std::string getNome() const { return nome; }
};

int main(int argc, char **argv)
{
    // Cria a urna como um shared_ptr
    auto urna = std::make_shared<Urna>();

    // Adiciona candidatos
    urna->adicionarCandidato("Candidato A", 1);
    urna->adicionarCandidato("Candidato B", 2);

    // Cria eleitores passando o shared_ptr da urna
    Eleitor eleitor1("Eleitor 1", urna);
    Eleitor eleitor2("Eleitor 2", urna);
    Eleitor eleitor3("Eleitor 3", urna);

    // Votação
    eleitor1.votar(1); // Vota no Candidato A
    eleitor2.votar(2); // Vota no Candidato B
    eleitor3.votar(1); // Vota no Candidato A

    // Exibe resultados
    urna->exibirResultados();

    return 0;
}
