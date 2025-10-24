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

    mapa_html << "<html>\n"
              << "<head>\n"
              << "<title>Mapa de coordenada aleatória</title>\n"
              << "</head>\n"
              << "<body>\n"
              << "<p>Latitude: " << latitude << "<br>\n"
              << "Longitude: " << longitude << "<br>\n"
              << "Zoom: " << zoom << "</p>\n"
              << "<iframe width=\"600\" height=\"400\" src=\"https://www.google.com/maps/embed/v1/view?key=INSIRA_SUA_API_KEY_AQUI&center="
              << latitude << ',' << longitude << "&zoom=" << zoom << "\" frameborder=\"0\" style=\"border:0;\" allowfullscreen></iframe>\n"
              << "</body>\n"
              << "</html>\n";

    mapa_html.close();
    return true;
}

int main(int argc, char **argv)
{
    // Configurações padrão
    std::string filename = "mapa_coordenada_random.html";
    int zoom = 10;

    // Verifica argumentos da linha de comando
    if (argc > 1)
    {
        filename = argv[1]; // Nome do arquivo de saída
    }

    if (argc > 2)
    {
        try
        {
            zoom = std::stoi(argv[2]); // Nível de zoom
            if (zoom < 0 || zoom > 20)
            {
                std::cerr << "Nível de zoom inválido. Usando padrão (10)." << '\n';
                zoom = 10;
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "Erro ao converter nível de zoom. Usando padrão (10)." << '\n';
        }
    }

    // Gera coordenadas aleatórias
    double latitude = gerarCoordenadaRandom(-90.0, 90.0);
    double longitude = gerarCoordenadaRandom(-180.0, 180.0);

    // Exibe as coordenadas geradas
    std::cout << "Coordenadas aleatórias geradas: Latitude = " << latitude
              << ", Longitude = " << longitude << ", Zoom = " << zoom << '\n';

    // Cria o arquivo HTML
    if (criarArquivoHtml(filename, latitude, longitude, zoom))
    {
        std::cout << "Arquivo HTML com o mapa gerado: " << filename << '\n';
    }
    else
    {
        std::cout << "Falha ao gerar o arquivo HTML." << '\n';
        return 1;
    }

    return 0;
}
