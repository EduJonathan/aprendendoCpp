#include <iostream>
#include <string>
#include <cstring>

/**
 * @brief Classe que representa uma pessoa com nome e idade.
 */
class Pessoa
{
private:
    char name[20]; ///< Nome da pessoa (limite de 19 caracteres + '\0')
    int idade;     ///< Idade da pessoa

public:
    /**
     * @brief Define o nome e a idade da pessoa.
     *
     * @param strName Nome da pessoa (como string C-style).
     * @param age Idade da pessoa.
     */
    void setPessoa(const char *strName, int age)
    {
        strncpy(name, strName, sizeof(name) - 1);
        name[sizeof(name) - 1] = '\0'; // Garante terminação nula da string
        this->idade = age;
    }

    /**
     * @brief Retorna a pessoa mais velha entre a pessoa atual e a pessoa recebida.
     *
     * - Se uma for maior de idade (idade >= 18) e a outra não, retorna a que for maior de idade.
     *
     * - Se ambas forem maiores ou ambas forem menores, retorna a de maior idade.
     *
     * @param person Pessoa a ser comparada com a atual.
     * @return Uma cópia da pessoa considerada "mais velha" segundo os critérios definidos.
     *
     * @note Ao usar `*this`, estamos desreferenciando esse ponteiro e retornando
     * uma `cópia` do objeto atual. Isso é necessário porque o retorno da função
     * é por valor (`Pessoa`), não um ponteiro ou referência.
     */
    Pessoa maior_de_idade(const Pessoa &person) const
    {
        bool PessoaAdulta = this->idade >= 18;
        bool outraPessoaAdulta = person.idade >= 18;

        if (PessoaAdulta != outraPessoaAdulta)
        {
            return PessoaAdulta ? *this : person;
        }

        // Ambas são adultas ou ambas são menores
        return (this->idade >= person.idade) ? *this : person;
    }

    /**
     * @brief Exibe os dados da pessoa: nome, idade e se é maior de idade.
     */
    void print_pessoa(void) const
    {
        std::cout << "Nome: " << name << '\n';
        std::cout << "Idade: " << idade << '\n';
        std::cout << name << " é maior de idade? " << (idade >= 18 ? "Sim" : "Não") << '\n';
    }
};

int main(int argc, char **argv)
{
    Pessoa Alice, Bob;
    Alice.setPessoa("Alice", 27);
    Bob.setPessoa("Bob", 16);

    Pessoa maior_de_idade = Alice.maior_de_idade(Bob);
    maior_de_idade.print_pessoa();

    std::cout << "-----------------------------------\n";

    Pessoa *Eduardo = new Pessoa();
    Pessoa *Matheus = new Pessoa();

    Matheus->setPessoa("Matheus", 15);
    Eduardo->setPessoa("Eduardo", 25);

    maior_de_idade = Eduardo->maior_de_idade(*Matheus);
    maior_de_idade.print_pessoa();

    std::cout << "-----------------------------------\n";

    Pessoa *Leticia = new Pessoa();
    Pessoa *Mariana = new Pessoa();

    Mariana->setPessoa("Mariana", 17);
    Leticia->setPessoa("Leticia", 17);

    maior_de_idade = Leticia->maior_de_idade(*Mariana);
    maior_de_idade.print_pessoa();

    std::cout << "-----------------------------------\n";

    maior_de_idade = Mariana->maior_de_idade(*Leticia);
    maior_de_idade.print_pessoa();

    delete Eduardo;
    delete Matheus;
    delete Leticia;
    delete Mariana;
    return 0;
}
