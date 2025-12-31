#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>

/**
 * fabricante de transporte (Factory Method): É um padrão de criação que define uma
 * interface para criar objetos em uma superclasse, mas permite que as subclasses
 * decidam qual classe instanciar. Ele permite que uma classe delegue a responsabilidade
 * de instanciar objetos a subclasses,
 */
class ITransporte
{
public:
    virtual void entregar() = 0;
    virtual ~ITransporte() = default;
};

// Implementação concreta: Caminhão
class Caminhao : public ITransporte
{
public:
    /**
     * @brief Método de entrega específico para caminhão
     * Essa implementação é específica para o caminhão e pode ser alterada
     * sem afetar outras implementações.
     */
    void entregar(void) override
    {
        std::cout << "Entrega realizada por Caminhão!" << '\n';
    }
};

// Implementação concreta: Navio
class Navio : public ITransporte
{
public:
    void entregar(void) override
    {
        std::cout << "Entrega realizada por Navio!" << '\n';
    }
};

// Enum para tipos de transporte (melhor que strings)
enum class TipoTransporte
{
    CAMINHAO,
    NAVIO
};

// Classe Fábrica
class TransporteFactory
{
public:
    /**
     * @brief Método estático para criar transporte com base no tipo
     * Essa abordagem é mais eficiente e menos propensa a erros.
     *
     * @param tipo Tipo de transporte (enum)
     * @return Ponteiro inteligente para o transporte criado
     * @throws std::invalid_argument Se o tipo de transporte não for reconhecido
     */
    static std::unique_ptr<ITransporte> criarTransporte(TipoTransporte tipo)
    {
        switch (tipo)
        {
        case TipoTransporte::CAMINHAO:
            return std::make_unique<Caminhao>();

        case TipoTransporte::NAVIO:
            return std::make_unique<Navio>();

        default:
            throw std::invalid_argument("Tipo de transporte desconhecido");
        }
    }

    /**
     * @brief Alternativa: Usando string para criar transporte (menos eficiente)
     * Essa abordagem pode ser menos eficiente e mais propensa a erros, pois depende de strings
     *
     * @param tipo Tipo de transporte como string
     * @return Ponteiro inteligente para o transporte criado
     * @throws std::invalid_argument Se o tipo de transporte não for reconhecido
     */
    static std::unique_ptr<ITransporte> criarTransporte(const std::string &tipo)
    {
        if (tipo == "caminhao")
        {
            return std::make_unique<Caminhao>();
        }
        else if (tipo == "navio")
        {
            return std::make_unique<Navio>();
        }
        throw std::invalid_argument("Tipo de transporte desconhecido: " + tipo);
    }
};

int main(int argc, char **argv)
{
    try
    {
        // Usando a fábrica com enum
        auto transporte1 = TransporteFactory::criarTransporte(TipoTransporte::CAMINHAO);
        transporte1->entregar();

        // Usando a fábrica com string (alternativa)
        auto transporte2 = TransporteFactory::criarTransporte("navio");
        transporte2->entregar();

        // Teste com tipo inválido (lançará exceção)
        auto transporte3 = TransporteFactory::criarTransporte("aviao");
        transporte3->entregar(); // Não será alcançado
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro: " << e.what() << '\n';
        return 1;
    }    
    return 0;
}
