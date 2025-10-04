#include <iostream>
#include <string>
#include <algorithm>
#include <memory>

/**
 * Design Pattern - Service
 * É um padrão que define uma interface para enviar mensagens, permitindo que diferentes
 * implementações sejam utilizadas. Este padrão é útil para desacoplar o código que
 * envia mensagens do código que as recebe.
 */

/**
 * @brief Interface para serviços de envio de mensagens.
 *
 * Define o contrato para qualquer serviço que envie mensagens.
 */
class IMessageService
{
public:
    /**
     * @brief Envia uma mensagem.
     *
     * @param message Conteúdo da mensagem.
     */
    virtual void sendMessage(const std::string &message) = 0;

    /**
     * @brief Destrutor virtual para permitir destruição correta via ponteiro para base.
     */
    virtual ~IMessageService() = default;
};

/**
 * @brief Serviço de envio de mensagens por e-mail.
 */
class EmailService : public IMessageService
{
public:
    void sendMessage(const std::string &message) override
    {
        std::cout << "Enviando email: " << message << '\n';
    }
};

/**
 * @brief Serviço de notificação que encapsula outro serviço de mensagem.
 *
 * Age como um decorador, permitindo adicionar comportamento (como log, ou notificações)
 * antes de delegar o envio real ao serviço encapsulado.
 */
class NotificationService : public IMessageService
{
private:
    std::unique_ptr<IMessageService> service; ///< Serviço de mensagem a ser decorado.

public:
    /**
     * @brief Construtor que recebe um serviço de mensagem a ser utilizado.
     *
     * @param svc Serviço de mensagem encapsulado (por smart pointer).
     */
    NotificationService(std::unique_ptr<IMessageService> svc) : service(std::move(svc)) {}

    void sendMessage(const std::string &message) override
    {
        std::cout << "Enviando notificação: " << message << '\n';
        service->sendMessage(message); // delega para o serviço real
    }
};

int main(int argc, char **argv)
{
    // Cria um serviço de email
    std::unique_ptr<IMessageService> emailService = std::make_unique<EmailService>();

    // Cria um serviço de notificação que usa o email como backend
    NotificationService notificationService(std::move(emailService));

    // Envia uma mensagem através da notificação
    notificationService.sendMessage("Olá, você tem uma nova mensagem!");

    return 0;
}
