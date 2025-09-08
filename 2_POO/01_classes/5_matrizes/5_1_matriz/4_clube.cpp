#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <memory>

// Classe que representa um Atleta
class Atleta
{
public:
    std::string nome;
    std::string esporte; // Esporte do atleta
    std::chrono::system_clock::time_point horario;
    std::string treino;

    // Método para setar os valores
    void setarAtleta(const std::string &n, const std::string &e, const std::chrono::system_clock::time_point &h, const std::string &t)
    {
        nome = n;
        esporte = e;
        horario = h;
        treino = t;
    }

    // Método para exibir as informações
    void getInformacao(void)
    {
        std::cout << "Nome: " << nome << '\n';
        std::cout << "Esporte: " << esporte << '\n';
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
    int numeroDeAtletas = 3; // Número fixo de atletas

    // Usando smart pointer (unique_ptr) para alocar a matriz de atletas
    std::unique_ptr<Atleta[]> clube = std::make_unique<Atleta[]>(numeroDeAtletas);

    // Inicializando os dados dos atletas diretamente no código
    std::chrono::hours h1(14);   // 14 horas
    std::chrono::minutes m1(22); // 22 minutos
    std::chrono::seconds s1(56); // 56 segundos
    std::chrono::system_clock::time_point horario1 = std::chrono::system_clock::now();
    horario1 -= std::chrono::duration_cast<std::chrono::seconds>(horario1.time_since_epoch());

    // Remove a data
    horario1 += h1 + m1 + s1;

    // Adiciona o horário desejado
    clube[0].setarAtleta("Juliano", "Futebol", horario1, "Treinamento Técnico");

    std::chrono::hours h2(14);   // 14 horas
    std::chrono::minutes m2(30); // 30 minutos
    std::chrono::seconds s2(55); // 55 segundos
    std::chrono::system_clock::time_point horario2 = std::chrono::system_clock::now();
    horario2 -= std::chrono::duration_cast<std::chrono::seconds>(horario2.time_since_epoch());

    // Remove a data
    horario2 += h2 + m2 + s2;

    // Adiciona o horário desejado
    clube[1].setarAtleta("Eduardo", "Vôlei", horario2, "Treinamento de Defesa");

    std::chrono::hours h3(15);   // 15 horas
    std::chrono::minutes m3(10); // 10 minutos
    std::chrono::seconds s3(20); // 20 segundos
    std::chrono::system_clock::time_point horario3 = std::chrono::system_clock::now();

    // Remove a data
    horario3 -= std::chrono::duration_cast<std::chrono::seconds>(horario3.time_since_epoch());
    horario3 += h3 + m3 + s3; // Adiciona o horário desejado

    clube[2].setarAtleta("Ana", "Basquete", horario3, "Treinamento de Arremesso");

    // Exibindo os dados dos atletas
    std::cout << "\nInformações dos atletas cadastrados no clube:\n";
    for (int i = 0; i < numeroDeAtletas; ++i)
    {
        clube[i].getInformacao();
        std::cout << "--------------------------\n";
    }

    // Não precisamos liberar a memória manualmente,
    // pois o unique_ptr automaticamente a libera quando sai de escopo.
    return 0;
}
