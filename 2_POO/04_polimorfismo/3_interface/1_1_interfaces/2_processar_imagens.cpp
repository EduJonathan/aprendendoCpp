#include <iostream>
#include <memory>
#include <string>

// Interface (classe abstrata com funções virtuais puras)
class IProcessadorImagem
{
public:
    // Função virtual pura para processar uma imagem
    virtual void processar(const std::string &imagem) = 0;

    // Destrutor virtual
    virtual ~IProcessadorImagem() = default;
};

// Classe derivada Redimensionar implementando a interface
class Redimensionar : public IProcessadorImagem
{
public:
    void processar(const std::string &imagem) override;
};

// Classe derivada AplicarFiltro implementando a interface
class AplicarFiltro : public IProcessadorImagem
{
public:
    void processar(const std::string &imagem) override;
};

// Classe derivada Rotacionar implementando a interface
class Rotacionar : public IProcessadorImagem
{
public:
    void processar(const std::string &imagem) override;
};

void Redimensionar::processar(const std::string &imagem)
{
    std::cout << "Redimensionando a imagem: " << imagem << " para 50% do tamanho original.\n";
}

void AplicarFiltro::processar(const std::string &imagem)
{
    std::cout << "Aplicando filtro sépia na imagem: " << imagem << ".\n";
}

void Rotacionar::processar(const std::string &imagem)
{
    std::cout << "Rotacionando a imagem: " << imagem << " 90 graus no sentido horário.\n";
}

int main(int argc, char **argv)
{
    // Nomes de imagens para processamento
    std::string imagens[] = {"foto1.jpg", "paisagem.png", "retrato.bmp"};

    // Criando um array de smart pointers para os processadores
    std::unique_ptr<IProcessadorImagem> processadores[] = {
        std::make_unique<Redimensionar>(),
        std::make_unique<AplicarFiltro>(),
        std::make_unique<Rotacionar>()};

    // Iterando sobre as imagens e processadores
    for (const auto &imagem : imagens)
    {
        for (const auto &processador : processadores)
        {
            processador->processar(imagem);
        }
        std::cout << "----------------\n";
    }

    // Não é necessário liberar memória manualmente com smart pointers
    return 0;
}
