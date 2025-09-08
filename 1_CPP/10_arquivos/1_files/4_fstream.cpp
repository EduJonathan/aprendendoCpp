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
 */
void criarArquivoHtml(double latitude, double longitude)
{
    /**
     * std::fstream(): Permite ler e escrever em arquivos. Permite abrir um arquivo para
     * leitura e/ou escrita. É uma classe genérica, que pode ser configurada para permitir
     * qualquer tipo de operação de fluxo (entrada e saída).
     *
     * std::ios::out => O arquivo é aberto no modo predefinido, mas é uma boa prática
     * especificar que está a ser aberto para saída (escrita). Realizado passando
     * std::ios::out como um segundo argumento para fstream.
     */
    std::fstream mapa_html("mapa_coordenada_random.html", std::ios::out);

    mapa_html << "<html>\n"
              << "<head>\n"
              << "<title>Mapa de coordenada aleatória</title>\n"
              << "</head>\n"
              << "<body>\n"
              << "<p>Latitude: " << latitude << "<br>\n"
              << "Longitude: " << longitude << "</p>\n"
              << "<iframe width=\"600\" height=\"400\" src=\"https://www.google.com/maps/embed/v1/view?key=AIzaSyD...abc123&center=" << latitude << ',' << longitude << "&zoom=10\" frameborder=\"0\" style=\"border:0;\" allowfullscreen></iframe>\n"
              << "</body>\n"
              << "</html>\n";

    mapa_html.close();
}

int main(int argc, char **argv)
{
    std::srand(std::time(0));

    double latitude = gerarCoordenadaRandom(-90.0, 90.0);
    double longitude = gerarCoordenadaRandom(-180.0, 180.0);

    std::cout << "Coordenadas aleatórias geradas: Latitude = " << latitude << ", Longitude: " << longitude << '\n';

    criarArquivoHtml(latitude, longitude);
    std::cout << "Arquivo HTML com o mapa gerado: mapa_coordenada_random.html" << '\n';
    return 0;
}
