#include <iostream>
#include <string>
#include <map>
#include <new>

// Definição do enum class para os componentes do computador
enum class Componente
{
    PlacaMae,
    Processador,
    SSD,
    MemoriaRAM,
    FonteAlimentacao,
    NumeroDeComponentes
};

// Mapeia o enum class Componente para sua representação em string.
const std::string &componenteToString(Componente &comp)
{
    // Mapa estático para armazenar as strings correspondentes aos enums
    static const std::map<Componente, std::string> map = {
        {Componente::PlacaMae, "Placa-mãe"},
        {Componente::Processador, "Processador (CPU)"},
        {Componente::SSD, "SSD"},
        {Componente::MemoriaRAM, "Memória RAM"},
        {Componente::FonteAlimentacao, "Fonte de alimentação"}};

    // Retorna a string do mapa; se não encontrar, retorna uma string de erro.
    auto it = map.find(comp);
    if (it != map.end())
    {
        return it->second;
    }

    // Caso de uso improvável: Se o enum for inválido, retorna um valor padrão.
    static const std::string erro = "Componente Desconhecido";
    return erro;
}

// Classe Monitor (inalterada na funcionalidade)
class Monitor
{
private:
    bool monitorFuncionando = true;

public:
    void verificarMonitor(void) const
    {
        if (monitorFuncionando)
        {
            std::cout << "Monitor funcionando corretamente." << '\n';
        }
        else
        {
            std::cout << "Monitor com defeito!" << '\n';
        }
    }

    void ligarMonitor(void) const
    {
        if (monitorFuncionando)
        {
            std::cout << "Monitor ligado com sucesso." << '\n';
        }
        else
        {
            std::cout << "Não é possível ligar o monitor (defeito)." << '\n';
        }
    }

    // Simula defeito no monitor
    void simularDefeitoMonitor(void)
    {
        monitorFuncionando = false;
    }
};

// Classe ComponentesComputador (usando enum class)
class ComponentesComputador
{
private:
    bool componentesPresentes[static_cast<int>(Componente::NumeroDeComponentes)];

public:
    // Construtor: Inicializa todos os componentes como presentes e funcionais
    ComponentesComputador()
    {
        for (int i = 0; i < static_cast<int>(Componente::NumeroDeComponentes); ++i)
        {
            componentesPresentes[i] = true;
        }
    }

    // Verifica a presença e se está funcionando corretamente
    void verificarComponentes(void) const
    {
        for (int i = 0; i < static_cast<int>(Componente::NumeroDeComponentes); ++i)
        {
            Componente comp = static_cast<Componente>(i);
            if (!componentesPresentes[i])
            {
                std::cout << componenteToString(comp) << " está com defeito ou ausente!" << '\n';
            }
        }
    }

    // Lista os componentes presentes e funcionais
    void listarComponentes(void) const
    {
        std::cout << "Componentes do computador:" << '\n';
        for (int i = 0; i < static_cast<int>(Componente::NumeroDeComponentes); ++i)
        {
            Componente comp = static_cast<Componente>(i);
            if (componentesPresentes[i])
            {
                std::cout << "- " << componenteToString(comp) << ": Funcionando corretamente." << '\n';
            }
            else
            {
                std::cout << "- " << componenteToString(comp) << ": Com defeito ou ausente." << '\n';
            }
        }
    }

    // Simula o defeito de um componente
    void simularDefeitoComponente(Componente comp)
    {
        int indice = static_cast<int>(comp);
        if (indice >= 0 && indice < static_cast<int>(Componente::NumeroDeComponentes))
        {
            componentesPresentes[indice] = false;
        }
    }
};

// Notebook herda apenas de ComponentesComputador (pois o monitor é embutido)
class Notebook : public ComponentesComputador
{
public:
    void inicializar(void) const
    {
        std::cout << "[Notebook] Iniciando o sistema..." << '\n';
        listarComponentes(); // Método herdado de ComponentesComputador
        std::cout << "Monitor embutido ligado." << '\n';
    }
    // Não é necessário implementar simularDefeitoMonitor() aqui, pois não há Monitor na herança
};

// PC usa Composição (tem um Monitor) em vez de Herança Múltipla.
class Pc
{
private:
    ComponentesComputador componentes; // Composição: O PC tem ComponentesComputador
    Monitor monitor;                   // Composição: O PC tem um Monitor

public:
    void inicializar(void) const
    {
        std::cout << "[PC] Iniciando o sistema..." << '\n';
        componentes.listarComponentes(); // Acessa o objeto componentes
        monitor.verificarMonitor();      // Acessa o objeto monitor
        monitor.ligarMonitor();
    }

    // Encapsula os métodos de simulação de defeito
    void simularDefeitoComponente(Componente comp)
    {
        componentes.simularDefeitoComponente(comp);
    }

    void simularDefeitoMonitor(void)
    {
        monitor.simularDefeitoMonitor();
    }
};

int main(int argc, char **argv)
{
    Pc *meuPcComDefeito = new Pc();
    Pc *meuPcSemDefeito = new Pc();
    Notebook *meuNotebook = new Notebook();

    // Exemplo 1: Simulando defeitos no PC
    std::cout << "\n=== Exemplo com defeitos (PC) ===" << '\n';

    meuPcComDefeito->simularDefeitoComponente(Componente::SSD);
    meuPcComDefeito->simularDefeitoComponente(Componente::FonteAlimentacao);
    meuPcComDefeito->simularDefeitoMonitor();
    meuPcComDefeito->inicializar();

    std::cout << "\n=== Exemplo sem defeitos (Notebook) ===" << '\n';
    meuNotebook->inicializar();

    std::cout << "\n=== Exemplo sem defeitos (PC) ===" << '\n';
    meuPcSemDefeito->inicializar();

    // Liberação de memória alocada dinamicamente
    delete meuPcComDefeito;
    delete meuPcSemDefeito;
    delete meuNotebook;
    return 0;
}
