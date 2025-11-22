#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <stdexcept>

class PorExtenso
{
private:
    static constexpr long long MAX_VALOR = 999999999999999LL;
    static constexpr long long MIN_VALOR = -999999999999999LL;

    long long valor;
    bool monetario;

    static const std::vector<std::string> UNIDADES;
    static const std::vector<std::string> DEZ_A_DEZENOVE;
    static const std::vector<std::string> DEZENAS;
    static const std::vector<std::string> CENTENAS;

    void validarValor() const
    {
        if (valor < MIN_VALOR || valor > MAX_VALOR)
        {
            throw std::out_of_range("Valor fora da faixa suportada");
        }
    }

    std::string juntarPartes(const std::vector<std::string> &partes,
                             const std::string &separador = " ") const
    {
        std::ostringstream oss;
        for (std::size_t i = 0; i < partes.size(); ++i)
        {
            if (i > 0)
                oss << separador;
            oss << partes[i];
        }
        return oss.str();
    }

    std::string ate_999(int n) const
    {
        if (n <= 0 || n > 999)
            return "";
        if (n == 100)
            return "cem";

        std::vector<std::string> partes;
        int centenas = n / 100;
        int resto = n % 100;
        int dezenas = resto / 10;
        int unidades = resto % 10;

        if (centenas > 0)
            partes.push_back(CENTENAS[centenas]);

        if (resto == 10)
        {
            partes.push_back("dez");
        }
        else if (resto >= 11 && resto <= 19)
        {
            partes.push_back(DEZ_A_DEZENOVE[resto - 10]);
        }
        else
        {
            if (dezenas > 0)
                partes.push_back(DEZENAS[dezenas]);

            if (unidades > 0)
                partes.push_back(UNIDADES[unidades]);
        }

        return juntarPartes(partes, " e ");
    }

    std::string converterGrandeza(long long &valor_restante, long long divisor,
                                  const std::string &singular, const std::string &plural) const
    {
        if (valor_restante < divisor)
            return "";

        std::ostringstream oss;
        long long quantidade = valor_restante / divisor;
        valor_restante %= divisor;

        if (quantidade > 0)
        {
            oss << ate_999(quantidade);
            oss << " " << (quantidade == 1 ? singular : plural);
        }

        return oss.str();
    }

    std::string converteParteInteira() const
    {
        long long n = std::abs(valor);
        if (n == 0)
            return "zero";

        long long resto = n;
        std::vector<std::string> partes;

        if (resto >= 1000000000LL)
            partes.push_back(converterGrandeza(resto, 1000000000LL, "bilhão", "bilhões"));

        if (resto >= 1000000)
            partes.push_back(converterGrandeza(resto, 1000000LL, "milhão", "milhões"));

        if (resto >= 1000)
        {
            std::string milhares = converterGrandeza(resto, 1000LL, "mil", "mil");
            if (milhares == "um mil")
                milhares = "mil";
            partes.push_back(milhares);
        }

        if (resto > 0)
            partes.push_back(ate_999(resto));

        return juntarPartes(partes, " e ");
    }

    std::string converte() const
    {
        validarValor();

        if (valor == 0)
            return monetario ? "zero reais" : "zero";

        std::string parte_inteira = converteParteInteira();

        if (!monetario)
        {
            return valor < 0 ? "menos " + parte_inteira : parte_inteira;
        }

        long long abs_valor = std::abs(valor);
        long long reais = abs_valor / 100;
        int centavos = abs_valor % 100;

        std::ostringstream resultado;

        if (reais > 0)
        {
            resultado << parte_inteira << (reais == 1 ? " real" : " reais");
        }

        if (centavos > 0)
        {
            if (reais > 0)
                resultado << " e ";
            resultado << ate_999(centavos)
                      << (centavos == 1 ? " centavo" : " centavos");
        }

        std::string saida = resultado.str();
        if (valor < 0)
            saida = "menos " + saida;

        return saida;
    }

public:
    explicit PorExtenso(long long v, bool moeda = false) : valor(v), monetario(moeda) {}

    // Sobrecarga do operador de fluxo de saída
    friend std::ostream &operator<<(std::ostream &os, const PorExtenso &pe)
    {
        os << pe.converte();
        return os;
    }

    explicit operator std::string() const
    {
        return converte();
    }
};

// Definições estáticas
const std::vector<std::string> PorExtenso::UNIDADES = {
    "zero", "um", "dois", "três", "quatro", "cinco",
    "seis", "sete", "oito", "nove"};

const std::vector<std::string> PorExtenso::DEZ_A_DEZENOVE = {
    "dez", "onze", "doze", "treze", "quatorze",
    "quinze", "dezesseis", "dezessete", "dezoito", "dezenove"};

const std::vector<std::string> PorExtenso::DEZENAS = {
    "", "dez", "vinte", "trinta", "quarenta", "cinquenta",
    "sessenta", "setenta", "oitenta", "noventa"};

const std::vector<std::string> PorExtenso::CENTENAS = {
    "", "cento", "duzentos", "trezentos", "quatrocentos",
    "quinhentos", "seiscentos", "setecentos", "oitocentos", "novecentos"};

// Auxiliares para facilitar o uso
PorExtenso extenso(long long n)
{
    return PorExtenso(n);
}

PorExtenso reais(double valor)
{
    long long centavos = std::llround(valor * 100.0);
    return PorExtenso(centavos, true);
}

std::string extensoSeguro(long long n)
{
    try
    {
        return std::string(extenso(n));
    }
    catch (...)
    {
        return "valor fora da faixa";
    }
}

std::string reaisSeguro(double valor)
{
    try
    {
        return std::string(reais(valor));
    }
    catch (...)
    {
        return "valor monetário inválido";
    }
}

int main(int argc, char **argv)
{
    std::cout << "=== TESTES BÁSICOS ===\n";
    std::cout << extenso(0) << '\n';
    std::cout << extenso(14) << '\n';
    std::cout << extenso(123) << '\n';
    std::cout << extenso(100) << '\n';
    std::cout << extenso(1000) << '\n';
    std::cout << extenso(1001) << '\n';
    std::cout << extenso(4521) << '\n';
    std::cout << extenso(1000000) << '\n';
    std::cout << extenso(25347801) << "\n\n";

    std::cout << "=== TESTES MONETÁRIOS ===\n";
    std::cout << reais(4000.00) << '\n';
    std::cout << reais(1234.50) << '\n';
    std::cout << reais(1.01) << '\n';
    std::cout << reais(0.01) << '\n';
    std::cout << reais(0.45) << '\n';
    std::cout << reais(0) << '\n';

    std::cout << "\n=== CASOS ESPECIAIS ===\n";
    std::cout << "Valor: " << extenso(987654) << '\n';
    std::cout << "Pagamento: " << reais(5789.99) << '\n';
    std::cout << "Negativo: " << extenso(-123) << '\n';
    std::cout << "Monetário negativo: " << reais(-123.45) << '\n';

    std::cout << "\n=== TESTES DE SEGURANÇA ===\n";
    std::cout << extensoSeguro(999999999999999LL) << '\n';
    std::cout << extensoSeguro(1000000000000000LL) << '\n';

    return 0;
}
