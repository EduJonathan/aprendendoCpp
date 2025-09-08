#include <iostream>
#include <string>
#include <cctype>

// typedef: Permite criar um novo nome para um tipo existente, tornando o código mais legível.

// Declarando um novo sinômino para o tipo de dado std::string
typedef std::string str;

// Struct para armazenar as contagens
struct Contagem
{
    int vogais = 0;
    int consoantes = 0;
    int digitos = 0;
    int especiais = 0;

    str toString() const
    {
        return "Vogais: " + std::to_string(vogais) + '\n' +
               "Consoantes: " + std::to_string(consoantes) + '\n' +
               "Dígitos: " + std::to_string(digitos) + '\n' +
               "Caracteres Especiais: " + std::to_string(especiais) + '\n';
    }
};

// Função auxiliar que classifica um caractere
enum class TipoCaractere
{
    VOGAL,
    CONSOANTE,
    DIGITO,
    ESPECIAL
};

TipoCaractere classificarChar(char c)
{
    static const str vogaisStr = "aeiouAEIOU";

    if (std::isdigit(c))
        return TipoCaractere::DIGITO;

    if (std::isalpha(c))
    {
        return (vogaisStr.find(c) != str::npos) ? TipoCaractere::VOGAL : TipoCaractere::CONSOANTE;
    }

    return TipoCaractere::ESPECIAL;
}

/**
 * @brief Função que irá obter e analisar a string para informar quais são
 * as(vogais, caracteres especiais, consoante e digitos).
 *
 * @param s string a ser como parâmetro
 * @return Retorna todas as contagens de cada atributos da stirng
 */
str checaString(const str &s)
{
    Contagem cont;

    for (char c : s)
    {
        switch (classificarChar(c))
        {
        case TipoCaractere::VOGAL:
            cont.vogais++;
            break;

        case TipoCaractere::CONSOANTE:
            cont.consoantes++;
            break;

        case TipoCaractere::DIGITO:
            cont.digitos++;
            break;

        case TipoCaractere::ESPECIAL:
            cont.especiais++;
            break;
        }
    }
    
    return cont.toString();
}

int main(int argc, char **argv)
{
    str input = "Exemplo123!@#";
    std::cout << checaString(input);
    return 0;
}
