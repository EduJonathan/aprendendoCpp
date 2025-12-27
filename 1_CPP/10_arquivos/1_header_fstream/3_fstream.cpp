#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

/**
 * @brief Gera uma coordenada aleatória entre min e max.
 *
 * @param min Valor mínimo da coordenada.
 * @param max Valor máximo da coordenada.
 */
double gerarCoordenadaRandom(double min, double max)
{
    return min + (std::rand() / (RAND_MAX + 1.0) * (max - min));
}

/**
 * @brief Cria um arquivo HTML com um mapa incorporado do Google Maps
 *        centrado nas coordenadas fornecidas.
 *
 * @param latitude Latitude para o centro do mapa.
 * @param longitude Longitude para o centro do mapa.
 * @param zoom Nível de zoom do mapa (padrão: 10).
 * @param filename Nome do arquivo HTML a ser gerado.
 * @return Verdadeiro se o arquivo foi criado com sucesso, falso caso contrário.
 */
bool criarArquivoHtml(const std::string &filename, double latitude, double longitude, int zoom)
{
    /**
     * std::fstream(): Permite ler e escrever em arquivos. Permite abrir um arquivo para
     * leitura e/ou escrita. É uma classe genérica, que pode ser configurada para permitir
     * qualquer tipo de operação de fluxo (entrada e saída).
     *
     * std::ios::out => O arquivo é aberto no modo predefinido,
     * mas é uma boa prática especificar que está a ser aberto para saída (escrita).
     */
    std::ofstream mapa_html(filename, std::ios::out);
    if (!mapa_html.is_open())
    {
        std::cerr << "Erro ao criar o arquivo HTML: " << filename << '\n';
        return false;
    }

    mapa_html << "<!DOCTYPE html>\n"
              << "<html>\n"
              << "<head>\n"
              << "<meta charset=\"UTF-8\">\n"
              << "<title>Mapa de coordenada aleatória</title>\n"
              << "<style>body { font-family: sans-serif; text-align: center; padding: 20px; }</style>\n"
              << "</head>\n"
              << "<body>\n"
              << "<h2>Mapa de Coordenada Aleatória</h2>\n"
              << "<p><strong>Latitude:</strong> " << latitude << "<br>\n"
              << "<strong>Longitude:</strong> " << longitude << "<br>\n"
              << "<strong>Zoom:</strong> " << zoom << "</p>\n"

              // URL QUE NÃO REQUER API KEY:
              << "<iframe width=\"800\" height=\"500\" "
              << "src=\"https://maps.google.com/maps?q=" << latitude << "," << longitude
              << "&z=" << zoom << "&output=embed\" "
              << "frameborder=\"0\" style=\"border:0; border-radius: 8px; box-shadow: 0 4px 8px rgba(0,0,0,0.2);\" allowfullscreen></iframe>\n"

              << "<p><small>Gerado automaticamente via C++</small></p>\n"
              << "</body>\n"
              << "</html>\n";

    mapa_html.close();
    return true;
}

int main(int argc, char **argv)
{
    // Inicializa a semente do número aleatório com o tempo atual
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Configurações de limites aproximados do Brasil
    double latMin = -33.75; // Extremo Sul (RS)
    double latMax = 5.27;   // Extremo Norte (AP)
    double lonMin = -73.98; // Extremo Oeste (AC)
    double lonMax = -34.79; // Extremo Leste (PB)

    std::string filename = "mapa_coordenada_random.html";
    int zoom = 10;

    if (argc > 1)
        filename = argv[1];
    if (argc > 2)
    {
        try
        {
            zoom = std::stoi(argv[2]);
            if (zoom < 1 || zoom > 20)
                zoom = 10;
        }
        catch (...)
        {
            zoom = 10;
        }
    }

    // Gera coordenadas dentro desse retângulo
    double latitude = gerarCoordenadaRandom(latMin, latMax);
    double longitude = gerarCoordenadaRandom(lonMin, lonMax);

    std::cout << "Gerando mapa para: " << latitude << ", " << longitude << " (Zoom: " << zoom << ")\n";

    if (criarArquivoHtml(filename, latitude, longitude, zoom))
    {
        std::cout << "Sucesso! Abra o arquivo '" << filename << "' no seu navegador.\n";
    }
    else
    {
        return 1;
    }

    /**
     *
     * INSTRUÇÕES:
     * 1. Substitua "INSIRA_SUA_API_KEY_AQUI" pela sua chave de API do Google Maps(REMOVIDA).
     * 2. Compile e execute o programa.
     * 3. Abra o arquivo HTML gerado em um navegador(firefox, Google Chrome) para visualizar o mapa.
     *
     * Para compilar:
     * g++ -o fstream 3_fstream.cpp
     * ./fstream mapa.html 12
     */
    return 0;
}
