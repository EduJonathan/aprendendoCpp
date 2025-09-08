#include <iostream>
#include <string>

/**
 * NAMESPACES: são um recurso usado para organizar o código em grupos lógicos, evitando
 * conflitos de nomes entre identificadores (como funções, classes ou variáveis) e melhorando
 * a legibilidade e manutenção do código. Eles permitem que você agrupe entidades relacionadas
 * sob um nome específico, criando um escopo próprio para essas entidades.
 *
 * Quando usar namespaces:
 * 1. Evitar conflitos de nomes: Use em projetos grandes ou com bibliotecas
 * externas para evitar colisões entre identificadores com o mesmo nome.
 *
 * 2. Organizar código por módulos: Agrupe funcionalidades relacionadas
 * (ex.: Matematica, Interface) para refletir a estrutura do projeto.
 *
 * 3. Projetos colaborativos: Facilite a manutenção em equipes, separando o código por escopos lógicos.
 *
 * 4. Integração com bibliotecas: Encapsule funcionalidades de bibliotecas em namespaces
 * para evitar poluição do escopo global.
 *
 * 5. Suporte a sobrecarga de operadores: Use namespaces para organizar funções como
 * operator+ ou operator<<, mantendo-as no contexto correto.
 */

using std::cout; // Usando o cout do namespace std
using std::endl; // Usando o endl do namespace std

namespace imprimir
{
    std::string imprimirMensagem()
    {
        return "Olá, Mundo!";
    }
}

namespace min_max
{
    template <typename T>
    class MinMax
    {
        T contador;
        T min;
        T max;

    public:
        // Construtor: recebe valorInicial, valor mínimo e valor máximo
        MinMax(T valorInicial, T minVal, T maxVal) : min(minVal), max(maxVal)
        {
            // Inicializa o contador:
            // Se o valor inicial for menor ou igual ao mínimo, usa ele;
            // caso contrário, usa o valor mínimo como padrão
            contador = (valorInicial <= min) ? valorInicial : min;
        }

        // Método para redefinir o valor do contador
        void reset(T novoValor)
        {
            // Só atualiza o contador se o novo valor for menor ou igual ao mínimo
            if (novoValor <= min)
                contador = novoValor;
        }

        // Executa uma ação baseada no valor do contador
        T run()
        {
            // Se o contador for maior que o valor máximo:
            // retorna o valor atual de contador e depois decrementa (-- pós-fixado)
            if (contador > max)
                return contador--;

            // Caso contrário, retorna o valor máximo
            return max;
        }
    };
}

namespace Matematica
{
    class Vetor
    {
    public:
        double x, y;
        Vetor(double x = 0, double y = 0) : x(x), y(y) {}

        // Sobrecarga de + (membro)
        Vetor operator+(const Vetor &outro) const
        {
            return Vetor(x + outro.x, y + outro.y);
        }

        // Sobrecarga de << (friend)
        friend std::ostream &operator<<(std::ostream &os, const Vetor &v);
    };

    // Definição de << no namespace Matematica
    std::ostream &operator<<(std::ostream &os, const Vetor &v)
    {
        os << '(' << v.x << ", " << v.y << ')';
        return os;
    }
}

int main(int argc, char **argv)
{
    // Exemplo de uso do namespace imprimir
    cout << imprimir::imprimirMensagem() << endl;

    // Exemplo com int
    min_max::MinMax<int> exemploInt(5, 2, 10);
    std::cout << "Resultado int: " << exemploInt.run() << '\n';

    // Exemplo com float
    min_max::MinMax<float> exemploFloat(7.5f, 3.2f, 10.0f);
    std::cout << "Resultado float: " << exemploFloat.run() << '\n';

    // Exemplo com double
    min_max::MinMax<double> exemploDouble(12.8, 5.5, 20.0);
    std::cout << "Resultado double: " << exemploDouble.run() << '\n';

    Matematica::Vetor v1(1.0, 2.0), v2(3.0, 4.0);
    Matematica::Vetor resultado = v1 + v2;
    std::cout << "Soma: " << resultado << '\n'; // Saída: (4, 6)
    return 0;
}
