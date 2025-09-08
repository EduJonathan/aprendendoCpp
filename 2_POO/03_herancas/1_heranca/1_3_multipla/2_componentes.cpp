#include <iostream>
#include <string>
#include <vector>

class ComponentesComputador
{
public:
    std::string componentes[5]{
        "Placa-mãe",
        "Processador (CPU)",
        "SSD",
        "Memória RAM",
        "Fonte de alimentação"};

    // Simula se o componente está presente ou com defeito
    bool componentesPresentes[5]{true, true, true, true, true};

    // Verifica a presença e se está funcionando corretamente
    void verificarComponentes(void)
    {
        for (int i = 0; i < 5; ++i)
        {
            if (!componentesPresentes[i])
            {
                std::cout << componentes[i] << " está com defeito ou ausente!" << '\n';
            }
        }
    }

    // Lista os componentes presentes e funcionais
    void listarComponentes(void)
    {
        std::cout << "Componentes do computador:" << '\n';
        for (int i = 0; i < 5; ++i)
        {
            if (componentesPresentes[i])
            {
                std::cout << "- " << componentes[i] << ": Funcionando corretamente." << '\n';
            }
            else
            {
                std::cout << "- " << componentes[i] << ": Com defeito ou ausente." << '\n';
            }
        }
    }

    // Simula o defeito de um componente (aleatório ou específico)
    void simularDefeitoComponente(int indice)
    {
        if (indice >= 0 && indice < 5)
        {
            componentesPresentes[indice] = false;
        }
    }
};

class Monitor
{
public:
    bool monitorFuncionando = true;

    void verificarMonitor(void)
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

    void ligarMonitor(void)
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

class Notebook : public ComponentesComputador
{
public:
    void inicializar(void)
    {
        std::cout << "[Notebook] Iniciando o sistema..." << '\n';
        listarComponentes(); // Verifica todos os componentes
        std::cout << "Monitor embutido ligado." << '\n';
    }
};

class Pc : public ComponentesComputador, public Monitor
{
public:
    void inicializar(void)
    {
        std::cout << "[PC] Iniciando o sistema..." << '\n';
        listarComponentes(); // Verifica todos os componentes
        verificarMonitor();  // Verifica o monitor
        ligarMonitor();      // Tenta ligar o monitor
    }
};

int main(int argc, char **argv)
{
    // Alocação dinâmica
    Pc *meuPcComDefeito = new Pc();
    Pc *meuPcSemDefeito = new Pc();
    Notebook *meuNotebook = new Notebook();

    // Exemplo 1: Simulando defeitos no PC
    std::cout << "\n=== Exemplo com defeitos (PC) ===" << '\n';
    meuPcComDefeito->simularDefeitoComponente(2); // Simula defeito no SSD
    meuPcComDefeito->simularDefeitoComponente(4); // Simula defeito na fonte de alimentação
    meuPcComDefeito->simularDefeitoMonitor();     // Simula defeito no monitor do PC
    meuPcComDefeito->inicializar();               // Inicializa o PC com defeitos

    // Exemplo 2: Sem defeitos (Notebook)
    std::cout << "\n=== Exemplo sem defeitos (Notebook) ===" << '\n';
    meuNotebook->inicializar(); // Inicializa o Notebook sem defeitos

    // Exemplo 3: Sem defeitos no PC
    std::cout << "\n=== Exemplo sem defeitos (PC) ===" << '\n';
    meuPcSemDefeito->inicializar(); // Inicializa o PC sem defeitos

    // Liberação de memória alocada dinamicamente
    delete meuPcComDefeito;
    delete meuPcSemDefeito;
    delete meuNotebook;

    return 0;
}
