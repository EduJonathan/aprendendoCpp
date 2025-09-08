#include <iostream>
#include <string>

/**
 * COMPOSIÇÃO: Em POO, composição é um conceito onde uma classe contém outra
 * como parte de sua definição. Ao contrário da herança, que define uma especialização,
 * na composição a classe composta não é uma especialização, mas uma agregação.
 *
 * A composição é uma relação "tem um", onde a classe que contém é responsável
 * pela criação e destruição de seus componentes. Se a classe composta for destruída,
 * todos os componentes também são destruídos.
 *
 * VANTAGENS:
 * - Maior flexibilidade: Facilita a substituição ou adição de comportamentos.
 * - Redução de dependências: Evita acoplamento forte, diferente da herança.
 *
 * DESVANTAGENS:
 * - Complexidade: Pode aumentar a complexidade do design, pois as classes precisam
 *   gerenciar a criação e destruição de objetos componentes.
 * 
 * - Menor reutilização: Ao contrário da herança, não há compartilhamento de comportamentos
 *   entre classes, o que pode exigir mais código duplicado em algumas situações.
 */

class VideoGame
{
public:
    std::string marca;
    std::string modelo;
    int ano;
    bool ligado;

    // Construtor
    VideoGame(std::string marca, std::string modelo, int ano)
        : marca(marca), modelo(modelo), ano(ano), ligado(false) {}

    // Método para ligar o videogame
    void ligar(void)
    {
        ligado = true;
    }

    // Método para desligar o videogame
    void desligar(void)
    {
        ligado = false;
    }

    // Método para pegar o status do videogame
    std::string status(void)
    {
        return "Marca: " + marca + ", Modelo: " + modelo +
               ", Ano: " + std::to_string(ano) +
               ", Status: " + (ligado ? "Ligado" : "Desligado");
    }
};

// Classe derivada (herança) VideoGamePortatil
class VideoGamePortatil
{
private:
    VideoGame videogame; // Composição: VideoGame como parte de VideoGamePortatil
    bool turbo;

public:
    // Construtor
    VideoGamePortatil(std::string marca, std::string modelo, int ano)
        : videogame(marca, modelo, ano), turbo(false) {}

    // Método para ligar
    void ligar(void)
    {
        videogame.ligar();
    }

    // Método para desligar
    void desligar(void)
    {
        videogame.desligar();
    }

    // Método para ativar o turbo
    void ativarTurbo(void)
    {
        if (!turbo)
        {
            turbo = true;
            std::cout << "Modo Turbo Ativado!" << '\n';
        }
        else
        {
            std::cout << "Modo Turbo já está ativado!" << '\n';
        }
    }

    // Método para desativar o turbo
    void desativarTurbo(void)
    {
        if (turbo)
        {
            turbo = false;
            std::cout << "Modo Turbo Desativado!" << '\n';
        }
        else
        {
            std::cout << "Modo Turbo já está desativado!" << '\n';
        }
    }

    // Método para pegar o status
    std::string status(void)
    {
        std::string statusTurbo = turbo ? ", Modo Turbo Ativado" : ", Modo Turbo Desativado";
        return videogame.status() + statusTurbo;
    }
};

int main(int argc, char **argv)
{
    // Criando instâncias dos videogames
    VideoGame xbox("Microsoft", "Xbox Series X", 2020);
    VideoGame xbox360("Microsoft", "Xbox 360", 2003);
    VideoGame ps4("Sony", "PlayStation 4", 2013);

    VideoGamePortatil ps5("Sony", "PlayStation 5", 2020);
    VideoGamePortatil ps2("Sony", "PlayStation 2", 2000);

    // Alterando os status
    xbox.ligar();
    xbox360.ligar();
    ps4.ligar();

    ps5.ligar();
    ps2.ligar();
    ps2.ativarTurbo();

    // Imprimindo status
    std::cout << xbox.status() << '\n';
    std::cout << xbox360.status() << '\n';
    std::cout << ps4.status() << '\n';

    std::cout << ps5.status() << '\n';
    std::cout << ps2.status() << '\n';
    return 0;
}
