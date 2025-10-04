#include <iostream>
#include <string>

/**
 * CONSTRUTORES: Sao métodos especiais pois inicializa seus atributos os atributos de uma classe
 * ou estrutura (struct) quando um objeto da classe ou estrutura é criado. Eles ajudam a garantir
 * que os objetos sejam inicializados de maneira adequada e conveniente.
 * Normalmente sempre possuindo o mesmo nome da classe ou estrutura. Tendo ou não um bloco("{}").
 * E também possuindo ou não argumentos (Não sendo o mesmo nome que os atributos).
 *
 * VANTAGENS:
 * 1. Garantem a inicialização adequada e válida dos objetos, evitando estados inválidos.
 *
 * 2. Reduzem a repetição de código, centralizando a inicialização dos atributos no
 * momento da criação.
 *
 * 3. Facilitam a criação de objetos, tornando o código mais simples e legível.
 *
 * 4. Melhoram a organização do código, evitando a necessidade de chamadas manuais
 * de métodos para inicialização como métodos `setters`.
 *
 * 5. Permitem o uso de construtores parametrizados, adaptando a inicialização conforme
 * os parâmetros fornecidos.
 *
 * --------------------
 *
 * DESVANTAGENS:
 * 1. Limitação para inicializações complexas, que exigem lógica condicional ou múltiplos passos.
 *
 * 2. Sobrecarga de construtores pode gerar complexidade, especialmente se houver muitas combinações
 * de parâmetros.
 *
 * 3. Uma vez chamado, o construtor "congela" a inicialização, dificultando a modificação posterior.
 *
 * 4. Não são adequados para tipos compostos complexos, como objetos com ponteiros para grandes
 * estruturas de dados.
 *
 * 5. Dificultam testes em casos onde a lógica de inicialização não pode ser facilmente modificada
 * sem alterar o código do construtor.
 */

class Terreno
{
private:
    std::string dimensaoTerreno;
    std::string endereco;
    std::string cep;

public:
    // Construtor do terreno
    Terreno(const std::string &dimension, const std::string &adress, const std::string &cep)
    {
        // Usa-se this para diferenciar o atributo do parâmetro em construtors
        this->dimensaoTerreno = dimension;
        this->endereco = adress;
        this->cep = cep;
    };

    void exibirTerreno(void) const
    {
        std::cout << "Dimensao do terreno: " << dimensaoTerreno << '\n';
        std::cout << "Endereco: " << endereco << '\n';
        std::cout << "CEP: " << cep << '\n';
    }
};

int main(int argc, char **argv)
{
    Terreno atributosTerreno("14X30", "Rua Napoleão", "64089-000");
    atributosTerreno.exibirTerreno();
    return 0;
}
