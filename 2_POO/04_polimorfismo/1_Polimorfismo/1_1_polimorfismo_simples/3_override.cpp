#include <iostream>
#include <string>
#include <vector>
#include <memory>

/**
 * OVERRIDE: Sobrescrita de métodos virtuais
 *
 * O modificador "override" é usado para indicar que um método está sobrescrevendo
 * um método virtual da classe base. Ajudando a evitar erros de digitação ou assinatura
 * incorreta, garantindo que a sobrescrita seja intencional sem o compilador gerar erro
 * caso se não for.
 *
 * Use `override` quando estiver sobrescrevendo um método virtual da classe base que não é const.
 * EXE: `virtual void foo()`; ou `virtual void foo() = 0`, use `void foo() override`;
 *
 * Use `const override` quando estiver sobrescrevendo um método virtual que foi declarado
 * como const na classe base. Se a função na base for `virtual void foo() const`;
 * use `void foo() const override`;
 */

class Mensagem
{
public:
    // Método virtual puro (obrigatório implementar)
    virtual void dizer() const = 0;

    // Sobrecarga: com nome
    virtual void dizer(const std::string &nome) const
    {
        std::cout << "Olá, tudo bem, " << nome << "?\n";
    }

    // Sobrecarga: com repetição
    virtual void dizer(int vezes) const
    {
        for (int i = 0; i < vezes; ++i)
        {
            dizer();
        }
    }

    // Destrutor virtual
    virtual ~Mensagem() = default;
};

// Português
class Portugues : public Mensagem
{
public:
    void dizer() const override
    {
        std::cout << "Olá, tudo bem?\n";
    }
};

// Inglês
class Ingles : public Mensagem
{
public:
    void dizer() const override
    {
        std::cout << "Hello, how are you?\n";
    }
};

// Espanhol
class Espanhol : public Mensagem
{
public:
    void dizer() const override
    {
        std::cout << "Hola, ¿cómo estás?\n";
    }
};

// Francês
class Frances : public Mensagem
{
public:
    void dizer() const override
    {
        std::cout << "Bonjour, ça va?\n";
    }
};

// Alemão
class Alemao : public Mensagem
{
public:
    void dizer() const override
    {
        std::cout << "Hallo, wie geht's?\n";
    }
};

// Italiano
class Italiano : public Mensagem
{
public:
    void dizer() const override
    {
        std::cout << "Ciao, come stai?\n";
    }
};

int main(int argc, char **argv)
{
    // Usando unique_ptr para gerenciar dinamicamente as mensagens
    std::vector<std::unique_ptr<Mensagem>> idiomas;

    idiomas.push_back(std::make_unique<Portugues>());
    idiomas.push_back(std::make_unique<Ingles>());
    idiomas.push_back(std::make_unique<Espanhol>());
    idiomas.push_back(std::make_unique<Frances>());
    idiomas.push_back(std::make_unique<Alemao>());
    idiomas.push_back(std::make_unique<Italiano>());

    // Chamada polimórfica
    for (const auto &msg : idiomas)
    {
        msg->dizer();
    }

    std::cout << "\n== Sobrecarga com nome ==\n";
    idiomas[0]->dizer("Maria");

    std::cout << "\n== Sobrecarga com repetição ==\n";
    idiomas[1]->dizer(3);
    return 0;
}
