#include <iostream>
#include <string>
#include <cctype>

/**
 * @brief Função que retorna a frequência de cada caractere
 *
 * @param str String a ser verificada
 *
 * @note O `&` passa diretamente a referência à variável, ou seja, a variável original é
 * manipulada diretamente. Não há necessidade de usar o operador de desreferência (*)
 * dentro da função, modifica diretamente a variável original.
 *
 * O uso do `&` deve ser feita eficiente de passar parâmetros, especialmente quando o
 * objetivo é evitar cópias ou quando você deseja modificar a variável original.
 */
void frequenciaDeCaracteres(const std::string &str)
{
    // Criamos um vetor para armazenar as frequências dos caracteres (26 letras)
    int frequencia[26] = {0};

    // Conta a frequência de cada caractere, convertendo para minúsculo
    for (char caracteres : str)
    {
        // Converte para minúsculo antes de contar a frequência
        caracteres = std::tolower(caracteres); // Converte para minúsculo

        // Verifica se o caractere é uma letra
        if (caracteres >= 'a' && caracteres <= 'z')
        {
            // Incrementa a contagem para o caractere
            frequencia[caracteres - 'a']++;
        }
    }

    // Exibe a frequência de cada caractere
    std::cout << "Frequência dos caracteres:" << '\n';
    for (int i = 0; i < 26; ++i)
    {
        if (frequencia[i] > 0)
        {
            char caractere = 'a' + i; // Converte o índice de volta para o caractere
            std::cout << caractere << ": " << frequencia[i] << " vez(es)" << '\n';
        }
    }
}

/**
 * @brief Função que retorna a soma dos números pares
 *
 * @param arr Array de inteiros
 * @param tamanho Tamanho do array
 * @return Referência para a variável soma
 */
int &somaDosPares(int *arr, std::size_t tamanho)
{
    // Variável estática para manter o valor da soma entre chamadas
    static int soma = 0;

    // Percorre o array e soma os números pares
    for (std::size_t i = 0ull; i < tamanho; ++i)
    {
        if (arr[i] % 2 == 0)
        {                   // Verifica se o número é par
            soma += arr[i]; // Soma o número par
        }
    }

    return soma; // Retorna a referência para a variável soma
}

int main(int argc, char **argv)
{
    int numInt = 10;
    float numFloat = 78.23;

    // Passa as variáveis por referência
    int &referenciaParaNumInt = numInt;
    float &referenciaParaNumFloat = numFloat;

    // Exibe os valores das variáveis
    std::cout << "numInt: " << numInt << '\n';
    std::cout << "numFloat: " << numFloat << '\n';

    // Exibe os valores das referências
    std::cout << "referenciaParaNumInt: " << referenciaParaNumInt << '\n';
    std::cout << "referenciaParaNumFloat: " << referenciaParaNumFloat << '\n';

    std::cout << "-------------------------------\n";

    std::string str = "Paralelepipedo"; // Exemplo de string
    frequenciaDeCaracteres(str);        // Passa a string por referência

    std::cout << "-------------------------------\n";

    int arr[] = {2, 6, 7, 8, 9, 1, 0, 2, 4};
    std::size_t tamanho = sizeof(arr) / sizeof(arr[0]);

    // Chama a função e exibe a soma dos números pares
    int &resultado = somaDosPares(arr, tamanho);
    std::cout << "Soma dos números pares: " << resultado << '\n';

    return 0;
}
