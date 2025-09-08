#include <iostream>
#include <string>

/**
 * Neste exemplo, temos uma herança multinível em que:
 *
 * - A classe `Dispositivo` herda da classe `EnvioEmail`, adquirindo a capacidade de enviar mensagens.
 * - As classes `Celular` e `PC` herdam de `Dispositivo`, especializando o comportamento de envio.
 *
 * Isso permite que os dispositivos compartilhem funcionalidades comuns, como ligar o
 * dispositivo e acessar a mensagem, enquanto ainda permitem comportamentos específicos
 * para cada tipo.
 */

// Nível 1: comportamento de envio
class EnvioEmail
{
protected:
    std::string mensagem;

public:
    EnvioEmail()
    {
        mensagem = "Olá, você foi aprovado na entrevista de C/C++. Compareça no dia 31/12/2025.";
    }

    void mostrarMensagem(void) const
    {
        std::cout << "Mensagem: " << mensagem << '\n';
    }
};

// Nível 2: Dispositivo genérico
class Dispositivo : public EnvioEmail
{
protected:
    bool ligado;

public:
    Dispositivo() : ligado(false) {}

    void ligar(void)
    {
        ligado = true;
        std::cout << "Dispositivo ligado." << '\n';
    }

    bool estaLigado(void) const
    {
        return ligado;
    }
};

// Nível 3: Especializações de dispositivo
class Celular : public Dispositivo
{
private:
    std::string numeroChip;

public:
    Celular(std::string chip) : numeroChip(chip) {}

    void enviarEmail(std::string email)
    {
        if (estaLigado())
        {
            std::cout << "[Celular] Enviando email para: " << email << '\n';
            mostrarMensagem();
        }
        else
        {
            std::cout << "[Celular] Erro: celular desligado." << '\n';
        }
    }
};

class Pc : public Dispositivo
{
private:
    std::string usuarioLogado;

public:
    Pc(std::string usuario) : usuarioLogado(usuario) {}

    void enviarEmail(std::string email)
    {
        if (estaLigado())
        {
            std::cout << "[PC] Usuário: " << usuarioLogado << " enviando email para: " << email << '\n';
            mostrarMensagem();
        }
        else
        {
            std::cout << "[PC] Erro: PC desligado." << '\n';
        }
    }
};

int main(int argc, char **argv)
{
    Celular meuCelular("21999999999");
    Pc meuPC("eduardo");

    // Testa com celular
    meuCelular.ligar();
    meuCelular.enviarEmail("eduardoJ@gmail.com");

    std::cout << '\n';

    // Testa com PC sem ligar
    meuPC.enviarEmail("rh@empresa.com");

    std::cout << '\n';

    // Liga PC e tenta novamente
    meuPC.ligar();
    meuPC.enviarEmail("rh@empresa.com");

    return 0;
}
