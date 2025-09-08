#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>
#include <string>

/**
 * Observer (Observador): É um padrão de design comportamental que define uma
 * dependênciaum-para-muitos entre objetos, de modo que quando um objeto muda
 * de estado, todos os seus dependentes são notificados e atualizados automaticamente.
 * É útil para implementar sistemas de eventos, onde um objeto (o sujeito) notifica
 * outros objetos (os observadores) sobre mudanças de estado.
 *
 * Exemplo: Sistema de notificações, onde um usuário (observador) se inscreve para
 * receber atualizações de um sistema (sujeito). Quando o sistema tem uma nova
 * atualização, ele notifica todos os usuários inscritos.
 */
class IObservador
{
public:
    virtual void atualizar(const std::string &mensagem) = 0;
    virtual ~IObservador() = default;
};

// Classe concreta do observador
class Usuario : public IObservador
{
    std::string nome;

public:
    explicit Usuario(const std::string &nome) : nome(nome) {}

    /**
     * @brief Método que é chamado quando o sujeito notifica o observador.
     * Neste caso, imprime a mensagem recebida.
     *
     * @param mensagem A mensagem a ser processada pelo observador.
     */
    void atualizar(const std::string &mensagem) override
    {
        std::cout << nome << " recebeu notificação: " << mensagem << '\n';
    }
};

// Classe observável (Subject)
class Sistema
{
private:
    std::vector<std::weak_ptr<IObservador>> observadores;

    /**
     * @brief Remove observadores inválidos (expirados) da lista de observadores.
     * Isso é necessário para evitar chamadas a observadores que já foram destruídos.
     *
     * @note Utiliza-se weak_ptr para evitar ciclos de referência e vazamentos de memória.
     *       O método remove_if é usado para remover os weak_ptr expirados da lista.
     */
    void removerObservadoresInvalidos(void)
    {
        observadores.erase(std::remove_if(observadores.begin(), observadores.end(),
        [](const auto &weakObs)
        {
            return weakObs.expired();
        }), observadores.end());
    }

public:
    /**
     * @brief Adiciona um observador à lista de observadores.
     *
     * @param obs Um ponteiro compartilhado para o observador a ser adicionado.
     */
    void adicionarObservador(std::shared_ptr<IObservador> obs)
    {
        removerObservadoresInvalidos();
        observadores.emplace_back(obs);
    }

    /**
     * @brief Notifica todos os observadores registrados com uma mensagem.
     * Esta função percorre a lista de observadores e chama o método atualizar de cada um deles.
     * Antes de notificar, remove os observadores inválidos (expirados) da lista.     *
     *
     * @param mensagem A mensagem a ser enviada aos observadores.
     */
    void notificar(const std::string &mensagem)
    {
        removerObservadoresInvalidos();

        for (auto &weakObs : observadores)
        {
            if (auto obs = weakObs.lock())
            {
                obs->atualizar(mensagem);
            }
        }
    }
};

int main(int argc, char **argv)
{
    Sistema sistema;

    auto usuario1 = std::make_shared<Usuario>("João");
    auto usuario2 = std::make_shared<Usuario>("Maria");

    sistema.adicionarObservador(usuario1);
    sistema.adicionarObservador(usuario2);

    sistema.notificar("Nova atualização disponível!");

    // Teste com observador que saiu do escopo
    {
        auto usuarioTemp = std::make_shared<Usuario>("Temporário");
        sistema.adicionarObservador(usuarioTemp);
        sistema.notificar("Mensagem durante vida do temp");
    }

    sistema.notificar("Mensagem após temp sair do escopo");
    return 0;
}
