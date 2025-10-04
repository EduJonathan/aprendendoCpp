#include <iostream>
#include <string>
#include <memory>

// Classe base (raiz da hierarquia)
class Empregado
{
protected:
    std::string nome;
    int id;
    double salarioBase;

public:
    Empregado(const std::string &n, int i, double s) : nome(n), id(i), salarioBase(s) {}

    virtual void exibirInfo() const
    {
        std::cout << "Empregado: " << nome << ", ID: " << id << ", Salário Base: R$" << salarioBase << '\n';
    }

    virtual double calcularSalario() const
    {
        return salarioBase;
    }
};

// Classes derivadas intermediárias com herança virtual
class Engenheiro : virtual public Empregado
{
protected:
    std::string especialidade;

public:
    Engenheiro(const std::string &n, int i, double s, const std::string &esp)
        : Empregado(n, i, s), especialidade(esp) {}

    void exibirInfo() const override
    {
        Empregado::exibirInfo();
        std::cout << "Especialidade: " << especialidade << '\n';
    }

    void projetarSistema()
    {
        std::cout << nome << " está projetando um sistema na área de " << especialidade << '\n';
    }
};

class Gerente : virtual public Empregado
{
protected:
    int tamanhoEquipe;

public:
    Gerente(const std::string &n, int i, double s, int equipe)
        : Empregado(n, i, s), tamanhoEquipe(equipe) {}

    void exibirInfo() const override
    {
        Empregado::exibirInfo();
        std::cout << "Tamanho da equipe: " << tamanhoEquipe << '\n';
    }

    double calcularSalario() const override
    {
        return salarioBase + (tamanhoEquipe * 1000.0); // Bônus por tamanho da equipe
    }

    void gerenciarProjeto()
    {
        std::cout << nome << " está gerenciando um projeto com " << tamanhoEquipe << " membros" << '\n';
    }
};

// Classe derivada com herança múltipla (Engenheiro de Software)
class EngenheiroSoftware : public Engenheiro
{
private:
    std::string linguagemFavorita;

public:
    EngenheiroSoftware(const std::string &n, int i, double s, const std::string &esp, const std::string &lang) : Empregado(n, i, s), Engenheiro(n, i, s, esp), linguagemFavorita(lang) {}

    void exibirInfo() const override
    {
        Engenheiro::exibirInfo();
        std::cout << "Linguagem Favorita: " << linguagemFavorita << '\n';
    }

    void codificar()
    {
        std::cout << nome << " está codificando em " << linguagemFavorita << '\n';
    }
};

// Classe derivada com herança múltipla e virtual (Engenheiro-Gerente)
class EngenheiroGerente : public Engenheiro, public Gerente
{
private:
    std::string projetoAtual;

public:
    EngenheiroGerente(const std::string &n, int i, double s, const std::string &esp, int equipe, const std::string &proj) : Empregado(n, i, s), Engenheiro(n, i, s, esp), Gerente(n, i, s, equipe), projetoAtual(proj) {}

    void exibirInfo() const override
    {
        Engenheiro::exibirInfo();
        std::cout << "Tamanho da equipe: " << tamanhoEquipe << ", Projeto Atual: " << projetoAtual << '\n';
    }

    double calcularSalario() const override
    {
        return salarioBase + (tamanhoEquipe * 1500.0); // Bônus maior para engenheiro-gerente
    }

    void liderarDesenvolvimento()
    {
        std::cout << nome << " está liderando o desenvolvimento do projeto " << projetoAtual << '\n';
        projetarSistema();
        gerenciarProjeto();
    }
};

// Função para testar a hierarquia
void testarEmpregado(Empregado &emp)
{
    std::cout << "\n=== Informações do Empregado ===" << '\n';
    emp.exibirInfo();
    std::cout << "Salário Total: R$" << emp.calcularSalario() << '\n';

    // Verifica se é Engenheiro
    if (Engenheiro *eng = dynamic_cast<Engenheiro *>(&emp))
    {
        eng->projetarSistema();
    }

    // Verifica se é Gerente
    if (Gerente *ger = dynamic_cast<Gerente *>(&emp))
    {
        ger->gerenciarProjeto();
    }

    // Verifica se é EngenheiroSoftware
    if (EngenheiroSoftware *engSoft = dynamic_cast<EngenheiroSoftware *>(&emp))
    {
        engSoft->codificar();
    }

    // Verifica se é EngenheiroGerente
    if (EngenheiroGerente *engGer = dynamic_cast<EngenheiroGerente *>(&emp))
    {
        engGer->liderarDesenvolvimento();
    }
}

int main(int argc, char **argv)
{
    // Criando instâncias
    auto engSoft = std::make_unique<EngenheiroSoftware>("Alice", 101, 8000.0, "Desenvolvimento Web", "Python");
    auto engGer = std::make_unique<EngenheiroGerente>("Bob", 102, 12000.0, "Sistemas Embarcados", 10, "Projeto IoT");

    // Testando empregados
    testarEmpregado(*engSoft);
    testarEmpregado(*engGer);
    return 0;
}
