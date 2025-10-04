#include <iostream>
#include <memory>
#include <new>
#include <cmath>

// Constante de PI
constexpr double PI = 3.141592653589793;

/**
 * @brief Converte graus para radianos.
 *
 * @param grau Valor em graus a ser convertido.
 * @return Valor em radianos.
 */
double grauParaRadiano(double grau)
{
    return grau * (PI / 180.0);
}

// Classe GPS
class GPS
{
private:
    double latAtual; // Latitude do motorista
    double lonAtual; // Longitude do motorista

public:
    // Construtor com latitude e longitude fornecidas pelo usuário
    GPS(double lat = -22.9068, double lon = -43.1729) : latAtual(lat), lonAtual(lon)
    {
        std::cout << "GPS ativado!\n";
    }

    // Método para obter a localização atual do motorista
    void obterLocalizacao(void)
    {
        std::cout << "Localização atual: "
                  << std::abs(latAtual) << (latAtual < 0 ? "° S" : "° N") << ", "
                  << std::abs(lonAtual) << (lonAtual < 0 ? "° W" : "° E") << '\n';
    }

    /**
     * @brief Calcula a distância entre a localização atual do motorista e um destino.
     *
     * @param latDestino Latitude do destino.
     * @param lonDestino Longitude do destino.
     * @return Distância em quilômetros.
     *
     * @note Utiliza-se a fórmula de Haversine para calcular a distância entre dois pontos
     * na superfície da Terra. A fórmula leva em consideração a curvatura da Terra e
     * é precisa para distâncias relativamente curtas.
     */
    double calcularDistancia(double latDestino, double lonDestino)
    {
        const double R = 6371.0; // Raio da Terra em km

        double lat1 = grauParaRadiano(latAtual);   // Converter latitude atual para radianos
        double lon1 = grauParaRadiano(lonAtual);   // Converter longitude atual para radianos
        double lat2 = grauParaRadiano(latDestino); // Converter latitude do destino para radianos
        double lon2 = grauParaRadiano(lonDestino); // Converter longitude do destino para radianos

        double difflat = lat2 - lat1; // Diferença de latitude
        double difflon = lon2 - lon1; // Diferença de longitude

        // Fórmula de Haversine
        double a = std::sin(difflat / 2) * std::sin(difflat / 2) +
                   std::cos(lat1) * std::cos(lat2) * std::sin(difflon / 2) * std::sin(difflon / 2);

        double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a)); // Cálculo do ângulo central
        return R * c;                                              // Retorna a distância em quilômetros
    }
};

// Classe Carro
class Carro
{
private:
    std::unique_ptr<GPS> gps; // GPS exclusivo do carro
    // Alternativa: std::shared_ptr<GPS> gps; // Se o GPS fosse compartilhado entre carros

public:
    // Construtor que cria um GPS com latitude e longitude passadas pelo usuário
    Carro(double latMotorista, double lonMotorista) : gps(std::make_unique<GPS>(latMotorista, lonMotorista))
    {
        std::cout << "Carro pronto para uso!\n";
    }

    // Método para verificar a localização do GPS
    void verificarGPS() const
    {
        // Verifica se o GPS é válido
        if (gps)
        {
            gps->obterLocalizacao();
        }
        else
        {
            std::cout << "Erro: GPS não inicializado!\n";
        }
    }

    // Método para calcular a distância até o destino
    void calcularDistanciaDestino(double latDestino, double lonDestino) const
    {
        if (gps)
        {
            double distancia = gps->calcularDistancia(latDestino, lonDestino);
            std::cout << "A distância até o destino é: " << distancia << " km\n";
        }
        else
        {
            std::cout << "Erro: GPS não inicializado!\n";
        }
    }
};

int main(int argc, char **argv)
{
    // Cria o objeto Carro com a localização do motorista
    Carro *meuCarro = new Carro(-22.9068, -43.1729);

    // Verifica a localização atual do motorista
    meuCarro->verificarGPS();

    // Calcula e exibe a distância até o destino
    meuCarro->calcularDistanciaDestino(-23.5505, -46.6333);

    auto gpsCompartilhado = std::make_shared<GPS>(-22.9068, -43.1729);
    Carro carro1(-22.9068, -43.1729); // Usa unique_ptr internamente
    Carro carro2(-22.9068, -43.1729);
    carro1.verificarGPS();
    carro2.verificarGPS();

    delete meuCarro; // Libera a memória alocada para o carro
    return 0;
}
