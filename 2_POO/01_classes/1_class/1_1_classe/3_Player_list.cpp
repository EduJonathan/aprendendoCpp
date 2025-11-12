#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

// Playlist global (disponível para todos)
std::vector<std::string> musicas = {
    "Bohemian Rhapsody - Queen",
    "Imagine - John Lennon",
    "Hotel California - Eagles",
    "Billie Jean - Michael Jackson",
    "Smells Like Teen Spirit - Nirvana",
    "I Still Stand - Elton John",
    "Don't Cry - Guns N' Roses",
    "Vamos Fugir - Skank",
    "Proibida Pra Mim - Charlie Brown Jr.",
    "Ana Julia - Los Hermanos"};

class Reprodutor_Musical
{
public:
    bool ligado = false;
    int volume = 0;
    int musica_atual = 0;
    std::vector<std::string> playlist; // vai ser preenchida no main

    void ligar()
    {
        ligado = true;
        std::cout << "Reprodutor ligado!\n";
    }

    void desligar()
    {
        ligado = false;
        std::cout << "Reprodutor desligado.\n";
    }

    void aumentarVolume()
    {
        if (volume < 100)
            volume++;
        std::cout << "Volume: " << volume << "%\n";
    }

    void diminuirVolume()
    {
        if (volume > 0)
            volume--;
        std::cout << "Volume: " << volume << "%\n";
    }

    void tocar()
    {
        if (!ligado)
        {
            std::cout << "ERRO: Reprodutor está desligado!\n";
            return;
        }
        if (playlist.empty())
        {
            std::cout << "Playlist vazia!\n";
            return;
        }
        std::cout << "Tocando: " << playlist[musica_atual] << '\n';
    }

    void proxima()
    {
        if (playlist.empty())
            return;
        musica_atual = (musica_atual + 1) % playlist.size();
        tocar();
    }

    void anterior()
    {
        if (playlist.empty())
            return;
        musica_atual = (musica_atual - 1 + playlist.size()) % playlist.size();
        tocar();
    }

    void mostrarPlaylist()
    {
        std::cout << "\n=== PLAYLIST (" << playlist.size() << " músicas) ===\n";
        for (std::size_t i = 0; i < playlist.size(); ++i)
        {
            std::cout << std::setw(2) << (i + 1) << ". ";
            if (i == musica_atual && ligado)
                std::cout << ">> ";
            else
                std::cout << "   ";
            std::cout << playlist[i] << '\n';
        }
        std::cout << "========================================\n";
    }

    void mostrarStatus()
    {
        std::cout << "\n--- STATUS ---\n";
        std::cout << "Ligado: " << (ligado ? "Sim" : "Não") << '\n';
        std::cout << "Volume: " << volume << "%\n";
        if (ligado && !playlist.empty())
            std::cout << "Música atual: " << playlist[musica_atual] << '\n';
        std::cout << "---------------\n";
    }
};

int main(int argc, char **argv)
{
    Reprodutor_Musical mp3;

    mp3.playlist = musicas; // Copia a playlist global

    // Testando tudo
    mp3.ligar();
    mp3.aumentarVolume();
    mp3.aumentarVolume();
    mp3.aumentarVolume();

    mp3.mostrarPlaylist();
    mp3.tocar();

    std::cout << "\nPulando músicas...\n";
    mp3.proxima();
    mp3.proxima();

    std::cout << "\nVoltando uma...\n";
    mp3.anterior();

    mp3.mostrarStatus();

    std::cout << "\nDesligando...\n";
    mp3.desligar();

    return 0;
}
