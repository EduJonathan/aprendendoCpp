#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <new>

class Academia
{
public:
    std::string nome;
    std::chrono::system_clock::time_point horario;
    std::string treino;

    // Método para setar os valores
    void setarTreino(const std::string &n, const std::chrono::system_clock::time_point &h, const std::string &t)
    {
        nome = n;
        horario = h;
        treino = t;
    }

    // Método para exibir as informações
    void getInformacao(void)
    {
        std::cout << "Nome: " << nome << '\n';
        std::cout << "Horario: " << formatarHorario(horario) << '\n';
        std::cout << "Treino: " << treino << '\n';
    }

private:
    // Função para formatar o horário como string
    std::string formatarHorario(const std::chrono::system_clock::time_point &h)
    {
        std::time_t Time = std::chrono::system_clock::to_time_t(h);
        std::tm *tm = std::gmtime(&Time); // Usando gmtime para não aplicar fuso horário local

        std::stringstream ss;
        ss << std::put_time(tm, "%H:%M:%S");
        return ss.str();
    }
};

int main(int argc, char **argv)
{
    int numeroDePessoas = 0;

    std::cout << "Insira a quantidade de pessoas para armazenar: ";
    std::cin >> numeroDePessoas;

    // Limpar o buffer de entrada residual
    std::cin.ignore(); // Ignorar o '\n' que fica após a leitura do inteiro

    // Alocação dinâmica de memória para a matriz de objetos Academia
    Academia *academia = new Academia[numeroDePessoas];

    // Preenchendo os dados para cada pessoa
    for (int i = 0; i < numeroDePessoas; ++i)
    {
        std::string nome, treino;
        std::string horarioStr;

        // Solicita os dados da pessoa
        std::cout << "\nPessoa " << i + 1 << ":\n";

        std::cout << "Digite o nome da pessoa: ";
        std::getline(std::cin, nome);

        std::cout << "Digite o horario da academia (formato HH:MM:SS): ";
        std::getline(std::cin, horarioStr);

        // Converter o horário inserido para time_point
        std::istringstream iss(horarioStr);
        int horas = 0, minutos = 0, segundos = 0;
        char separador = '\0';

        // Lê o horário no formato HH:MM:SS
        if (iss >> horas >> separador >> minutos >> separador >> segundos)
        {
            std::chrono::hours h(horas);
            std::chrono::minutes m(minutos);
            std::chrono::seconds s(segundos);

            // Cria o time_point (horário do dia) com base nas horas, minutos e segundos
            std::chrono::system_clock::time_point tp = std::chrono::system_clock::now();
            tp -= std::chrono::duration_cast<std::chrono::seconds>(tp.time_since_epoch());

            // Remove a data
            tp += h + m + s;

            // Agora o treino é lido antes de chamar setarTreino
            std::cout << "Digite o treino: ";
            std::getline(std::cin, treino);

            academia[i].setarTreino(nome, tp, treino);
        }
        else
        {
            std::cout << "Formato de horário inválido!\n";
        }
    }

    // Exibindo os dados das pessoas
    std::cout << "\nInformações das pessoas cadastradas:\n";
    for (int i = 0; i < numeroDePessoas; ++i)
    {
        academia[i].getInformacao();
        std::cout << "--------------------------\n";
    }

    // Liberação da memória alocada dinamicamente
    delete[] academia;
    return 0;
}
