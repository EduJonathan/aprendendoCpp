#include <iostream>
#include <string>
#include <fstream>

/**
 * @brief Exibe os dados de uma linha entre o último espaço anterior e uma posição específica.
 *
 * Esta função percorre a string `line` de trás para frente a partir de `position1`
 * até encontrar um espaço `' '`. Em seguida, imprime todos os caracteres entre esse
 * espaço e a posição `position1`, seguidos de uma quebra de linha.
 *
 * @param line A string de entrada que contém o texto a ser analisado.
 * @param position1 A posição na string onde a leitura deve parar (exclusiva).
 */
void exibirDados(const std::string &line, std::size_t position1)
{
    std::size_t temp = position1;

    // Retrocede até encontrar um espaço
    while (line[--temp] != ' ');

    // Exibe os caracteres entre o espaço e position1
    for (std::size_t i = temp + 1; i < position1; ++i)
    {
        std::cout << line[i];
    }
    std::cout << '\n';
}

/**
 * @brief Verifica condições em uma linha e exibe dados conforme critérios definidos.
 *
 * Esta função analisa a string `line` entre duas posições (`position1` e `position2`),
 * verificando a presença de espaços e parênteses. Dependendo da análise, chama
 * `exibirDados()` para mostrar uma parte específica da string.
 *
 * ### Lógica detalhada:
 * - Se o caractere após `position1` for `')'`, exibe diretamente os dados.
 * - Caso contrário, percorre o intervalo `(position1, position2)`:
 *   - Se encontrar algo diferente de espaço `' '` ou `')'`, define `flag = true`.
 * - Se `flag` continuar `false`, exibe os dados imediatamente e encerra.
 * - Caso contrário, recua até o espaço anterior e verifica se há outros espaços
 *   antes dele para decidir se exibe ou não os dados.
 *
 * @param line A string analisada, geralmente uma linha lida de um arquivo.
 * @param position1 Posição inicial da análise (normalmente antes de um delimitador).
 * @param position2 Posição final da análise (normalmente após um delimitador).
 *
 * @note Esta função depende da função auxiliar `exibirDados()` para mostrar os resultados.
 */
void checar(const std::string &line, std::size_t position1, std::size_t position2)
{
    bool flag = false;
    std::size_t temp = position1;

    // Caso especial: se o próximo caractere for ')', exibe os dados imediatamente
    if (line[position1 + 1] == ')')
    {
        exibirDados(line, position1);
        return;
    }

    // Verifica se há caracteres não vazios entre position1 e position2
    for (std::size_t i = position1 + 1; i < position2; ++i)
    {
        if (line[i] != ' ' || line[i] == ')')
        {
            flag = true;
        }
    }

    // Se não há caracteres relevantes, exibe os dados e retorna
    if (!flag)
    {
        exibirDados(line, position1);
        return; // evita repetição
    }

    // Retrocede até o espaço anterior
    while (line[--temp] != ' ');

    // Verifica se há espaços antes do delimitador encontrado
    for (std::size_t i = 0; i < temp; ++i)
    {
        if (line[i] == ' ')
        {
            flag = true;
        }
    }

    // Se ainda não encontrou inconsistências, exibe os dados
    if (!flag)
    {
        exibirDados(line, position1);
    }
}

int main(int argc, char **argv)
{
    std::string linha;

    // ifstream – abre o arquivo apenas para leitura
    std::ifstream arq_in("nomes.txt");
    if (arq_in.is_open())
    {
        // eof() - retorna true ao atingir o fim do arquivo
        while (!arq_in.eof())
        {
            std::getline(arq_in, linha);
            std::cout << linha << '\n';
        }
        arq_in.close();
    }
    else
    {
        std::cout << "ERRO: arquivo não foi aberto ou não existe" << '\n';
    }

    std::cout << "--------------------------------------\n";

    // Verifica se o arquivo foi informado como argumento
    if (argc < 2)
    {
        std::cerr << "Uso: ./ifstream <nome_do_arquivo>\n";
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo especificado: " << argv[1] << '\n';
        return 1;
    }

    std::cout << "Analisando conteúdo de: " << argv[1] << '\n';
    std::cout << "--------------------------------------\n";

    std::string line;
    while (std::getline(file, line))
    {
        // Ignora linhas com comentários
        if (line.find("/*") == std::string::npos)
        {
            // Verifica parêntese de abertura
            std::size_t position1 = line.find('(');
            if (position1 != std::string::npos)
            {
                // Verifica parêntese de fechamento
                std::size_t position2 = line.find(')');
                if (position2 != std::string::npos)
                {
                    // Verifica ausência de ponto e vírgula antes do parêntese
                    std::size_t position3 = line.find(';');

                    if ((position1 < position2) && (position3 == std::string::npos || position3 < position1))
                    {
                        checar(line, position1, position2);
                    }
                }
            }
        }
    }

    file.close();
    return 0;
}
