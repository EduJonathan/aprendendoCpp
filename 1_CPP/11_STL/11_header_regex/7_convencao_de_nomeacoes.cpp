#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <regex>

/**
 * @brief Enum class para representar diferentes convenções de nomenclatura.
 */
enum class Convencoes
{
    camelCase,
    snake_case,
    PascalCase,
    kebab_case,
    desconhecida // Caso não se encaixe em nenhum padrão válido
};

/**
 * @brief Converte o enum Convencoes em uma string legível.
 * 
 * @param conv A convenção a ser convertida.
 * @return std::string_view Representação em string da convenção.
 */
std::string_view to_string(Convencoes conv)
{
    switch (conv)
    {
    case Convencoes::camelCase:
        return "camelCase";

    case Convencoes::snake_case:
        return "snake_case";

    case Convencoes::PascalCase:
        return "PascalCase";

    case Convencoes::kebab_case:
        return "kebab_case";

    case Convencoes::desconhecida:
        return "desconhecida";

    default:
        return "desconhecida";
    }
}

/**
 * @brief Estrutura responsável por classificar uma nomenclatura segundo o padrão usado.
 */
struct Classificar
{
    std::string nomeclatura;

    // Construtor sem 'explicit' — permite conversão implícita de string_view
    Classificar(std::string_view n) : nomeclatura(n) {}

    /**
     * @brief Classifica o tipo de convenção de nomenclatura usada.
     * 
     * @return Convencoes Tipo de convenção detectada.
     */
    Convencoes classificar() const
    {
        if (nomeclatura.empty())
        {
            return Convencoes::desconhecida; // Trata entrada vazia
        }

        // Expressões regulares para cada convenção
        static const std::regex camelCase(R"([a-z]+([A-Z][a-z]*)*)");
        static const std::regex snake_case(R"([a-z]+(_[a-z]+)*)");
        static const std::regex PascalCase(R"([A-Z][a-z]*([A-Z][a-z]*)*)");
        static const std::regex kebab_case(R"([a-z]+(-[a-z]+)*)");

        if (std::regex_match(nomeclatura, camelCase))
        {
            return Convencoes::camelCase;
        }

        if (std::regex_match(nomeclatura, snake_case))
        {
            return Convencoes::snake_case;
        }

        if (std::regex_match(nomeclatura, PascalCase))
        {
            return Convencoes::PascalCase;
        }

        if (std::regex_match(nomeclatura, kebab_case))
        {
            return Convencoes::kebab_case;
        }

        return Convencoes::desconhecida; // Nenhum padrão corresponde
    }
};

int main(int argc, char **argv)
{
    // Casos de teste
    std::vector<Classificar> testes = {
        Classificar("olaMundo"),            // camelCase
        Classificar("toString"),            // camelCase
        Classificar("ola_mundo"),           // snake_case
        Classificar("variavel_int_numero"), // snake_case
        Classificar("OlaMundo"),            // PascalCase
        Classificar("PrintLn"),             // PascalCase
        Classificar("ola-mundo"),           // kebab_case
        Classificar("frutas-legumes"),      // kebab_case
        Classificar("invalido_Formato"),    // formato inválido
        Classificar("")                     // string vazia
    };

    for (const auto &teste : testes)
    {
        std::cout << "Nomenclatura: " << teste.nomeclatura
                  << " → " << to_string(teste.classificar()) << '\n';
    }
    return 0;
}
