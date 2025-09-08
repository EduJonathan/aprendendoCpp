#include <iostream>
#include <memory>
#include <string>

/**
 * @brief Classe base para todos os veículos.
 */
class Veiculo
{
protected:
    std::string marca;
    int ano;

public:
    /**
     * @brief Construtor da classe Veiculo.
     *
     * @param m Marca do veículo.
     * @param year Ano do veículo.
     */
    Veiculo(const std::string &m, int year) : marca(m), ano(year) {}

    /**
     * @brief Exibe informações básicas do veículo.
     */
    void getInfoVeiculo(void) const
    {
        std::cout << "Veículo: " << marca << ", Ano: " << ano << '\n';
    }
};

/**
 * @brief Classe que representa um motor a combustão.
 */
class MotorCombustao : virtual public Veiculo
{
protected:
    double capacidadeTanque; // Em Litros

public:
    /**
     * @brief Construtor do motor a combustão.
     *
     * @param m Marca do veículo.
     * @param year Ano do veículo.
     * @param capacity Capacidade do tanque em litros.
     */
    MotorCombustao(const std::string m, int year, double capacity)
        : Veiculo(m, year), capacidadeTanque(capacity) {}

    /**
     * @brief Simula o abastecimento do tanque.
     *
     * @param litros Quantidade de litros a abastecer.
     */
    void abastecer(double litros)
    {
        std::cout << "Abastecendo " << litros << "L no tanque de capacidade " << capacidadeTanque << 'L' << '\n';
    }
};

/**
 * @brief Classe que representa um motor elétrico.
 */
class MotorEletrico : virtual public Veiculo
{
protected:
    double capacidadeBateria; // Em KWh

public:
    /**
     * @brief Construtor do motor elétrico.
     *
     * @param m Marca do veículo.
     * @param year Ano do veículo.
     * @param capacity Capacidade da bateria em KWh.
     */
    MotorEletrico(const std::string m, int year, double capacity)
        : Veiculo(m, year), capacidadeBateria(capacity) {}

    /**
     * @brief Simula o carregamento da bateria.
     *
     * @param Kwh Quantidade de energia a carregar.
     */
    void carregar(int Kwh)
    {
        std::cout << "Carregando " << Kwh << "KWh na bateria de " << capacidadeBateria << "KWh" << '\n';
    }
};

/**
 * @brief Classe que representa um veículo híbrido.
 */
class VeiculoHibrido : public MotorCombustao, public MotorEletrico
{
private:
    std::string modelo;

public:
    /**
     * @brief Construtor do veículo híbrido.
     *
     * @param m Marca.
     * @param year Ano.
     * @param capTanque Capacidade do tanque.
     * @param capBateria Capacidade da bateria.
     * @param mod Modelo do veículo.
     */
    VeiculoHibrido(const std::string &m, int year, double capTanque, int capBateria,
                   const std::string &mod) : Veiculo(m, year), MotorCombustao(m, year, capTanque),
                                             MotorEletrico(m, year, static_cast<double>(capBateria)),
                                             modelo(mod) {}

    /**
     * @brief Exibe as informações completas do veículo híbrido.
     */
    void get_veiculo_hibrido() const
    {
        getInfoVeiculo();
        std::cout << "Modelo: " << modelo << '\n';
        std::cout << "Capacidade Tanque: " << capacidadeTanque << "L\n";
        std::cout << "Capacidade da Bateria: " << capacidadeBateria << "KWh\n";
    }

    /**
     * @brief Simula operações do veículo híbrido.
     */
    void set_veiculo_hibrido()
    {
        std::cout << "\n=== Operando Veículo Híbrido ===" << '\n';
        abastecer(20.0);
        carregar(10);
    }
};

/**
 * @brief Função que testa o funcionamento de um veículo híbrido.
 *
 * @param v Referência para o objeto VeiculoHibrido.
 */
void testarVeiculo(VeiculoHibrido &vh)
{
    std::cout << "\n=== Teste do Veículo Híbrido ===" << '\n';
    vh.get_veiculo_hibrido();
    vh.set_veiculo_hibrido();
}

int main(int argc, char **argv)
{
    // Uso de smart pointer para gerenciar a memória do objeto
    std::unique_ptr<VeiculoHibrido> toyota =
        std::make_unique<VeiculoHibrido>("Toyota", 2023, 50.0, 80, "Prius");

    testarVeiculo(*toyota);

    // Informações adicionais
    toyota->getInfoVeiculo();
    toyota->abastecer(30.0);
    toyota->carregar(5);
    return 0;
}
