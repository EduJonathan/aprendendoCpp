#include <iostream>
#include <vector>
#include <string>

struct CandidatosEleicao
{
    std::string nomeCandidato;
    int numeroDoCandidato;
    int quantidadeDeVotos;

    CandidatosEleicao(std::string nome, int numero) : nomeCandidato(nome),
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
        candidatos.push_back(CandidatosEleicao(nome, numero));
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
        std::cout << "Candidato não encontrado!" << '\n';
    }

    void exibirResultados(void) const
    {
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
    Urna *urna; // Ponteiro para a urna

public:
    Eleitor(const std::string &nomeEleitor, Urna *urnaReferenciada)
        : nome(nomeEleitor), urna(urnaReferenciada) {}

    void votar(int numeroDoCandidato)
    {
        std::cout << nome << " está votando...\n";
        urna->registrarVoto(numeroDoCandidato);
    }

    std::string getNome(void) const { return nome; }
};

int main(int argc, char **argv)
{
    Urna urna;

    // Adiciona candidatos
    urna.adicionarCandidato("Candidato A", 1);
    urna.adicionarCandidato("Candidato B", 2);

    // Cria eleitores que usam a mesma urna
    Eleitor eleitor1("Eleitor 1", &urna);
    Eleitor eleitor2("Eleitor 2", &urna);
    Eleitor eleitor3("Eleitor 3", &urna);

    // Votação
    eleitor1.votar(1); // Vota no Candidato A
    eleitor2.votar(2); // Vota no Candidato B
    eleitor3.votar(1); // Vota no Candidato A

    // Exibe resultados
    urna.exibirResultados();

    return 0;
}
