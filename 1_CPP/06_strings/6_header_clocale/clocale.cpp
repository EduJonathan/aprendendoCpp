#include <iostream>
#include <string>
#include <cwchar>
#include <clocale>

/**
 * Como era de se imaginar, <clocale> é o cabeçalho C++ que traz,
 * para dentro do namespace std, os recursos da antiga <locale.h> da linguagem C.
 *
 * Ele fornece funções que permitem consultar ou alterar a *localidade* (locale)
 * do programa em tempo de execução. A localidade define regras regionais,
 * como:
 *   - Formato de números (separador decimal, agrupamento de milhares);
 *   - Símbolos de moeda e convenções monetárias;
 *   - Ordem de colação (comparação de strings segundo a língua);
 *   - Formatação de datas, horas e mensagens dependentes de idioma.
 *
 * Funções principais:
 *   - setlocale(category, name) : muda a localidade atual ou consulta a vigente.
 *   - localeconv() : retorna uma struct lconv* com informações numéricas e monetárias.
 *
 * Em C++ moderno, <clocale> é usado quando se deseja compatibilidade com
 * essas funções de estilo C. Para recursos mais avançados e orientados a
 * objetos, existe também o cabeçalho <locale> da biblioteca padrão C++,
 * que oferece a classe std::locale e facetas para personalização de I/O.
 */

// Função para exibir informações do locale atual
void exibirInformacoesLocale()
{
    // localeconv() lê as configurações numéricas/monetárias do locale atual e devolve um ponteiro
    // para uma struct lconv com campos como separador decimal, separador de milhar e
    // símbolo de moeda, que você usa para formatar saídas de acordo com a região.
    struct lconv *locale_info = localeconv();

    std::wcout << L"Separador de milhares: "
               << (locale_info->thousands_sep ? locale_info->thousands_sep : "Nenhum") << L"\n";
    std::wcout << L"Separador decimal: "
               << (locale_info->decimal_point ? locale_info->decimal_point : "Nenhum") << L"\n";
    std::wcout << L"Símbolo de moeda: "
               << (locale_info->currency_symbol ? locale_info->currency_symbol : "Nenhum") << L"\n";
}

// Função para configurar o locale e exibir informações
bool configurarLocale(const std::string &localeName, double number, const std::wstring &mensagem)
{
    if (std::setlocale(LC_ALL, localeName.c_str()) == nullptr)
    {
        std::wcerr << L"Erro: Locale '" << localeName.c_str() << L"' não suportado.\n";
        return false;
    }

    // Configurar std::wcout para o locale
    std::wcout.imbue(std::locale(localeName.c_str()));
    std::wcout << L"\nLocale configurado para " << localeName.c_str() << L".\n";

    exibirInformacoesLocale();
    std::wcout << L"Número no locale atual: " << number << L"\n";
    if (!mensagem.empty())
    {
        std::wcout << mensagem << L"\n";
    }
    return true;
}

int main(int argc, char **argv)
{
    // chamada que desativa a sincronização entre as streams de C++ (std::cin, std::cout, std::wcout, etc.) e as streams da biblioteca C (stdin, stdout).
    std::ios_base::sync_with_stdio(false);
    std::wcout.imbue(std::locale("")); // Locale padrão do sistema

    // Tentar configurar para o locale padrão do sistema
    if (std::setlocale(LC_ALL, "") == nullptr)
    {
        std::wcerr << L"Erro: Não foi possível configurar o locale padrão do sistema.\n";
        return 1;
    }
    else
    {
        std::wcout << L"Locale configurado para o padrão do sistema.\n";
    }

    double number = 1234567.89;
    exibirInformacoesLocale();
    std::wcout << L"Número no locale padrão: " << number << L"\n";

    // en_US.UTF-8
    configurarLocale("en_US.UTF-8", number,
                     L"Mensagem em inglês: Welcome to the program!");

    // pt_BR.UTF-8
    configurarLocale("pt_BR.UTF-8", number,
                     L"Mensagem em português: Bem-vindo ao programa! Açúcar, café e feijão são típicos do Brasil.");
    return 0;
}
