#include <iostream>
#include <string>

/**
 * std::substr(): Na linguagem C++, a função substr é um método da classe std::string
 * que permite extrair uma substring (ou seja, uma parte de uma string maior).
 * É muito útil quando você precisa manipular strings e trabalhar apenas com uma porção
 * específica delas.
 *
 * SINTAXE: inline std::__1::string std::__1::string::substr(size_t __pos, size_t __n) const;
 *
 * @param pos A posição inicial da substring na string original (baseado em zero).
 * @param len O comprimento da substring que você deseja extrair. Se omitido ou maior que
 * o restante da string, ele pega até o final.
 * @return Retorna uma nova string que contém a substring especificada.
 */

int main(int argc, char **argv)
{
    std::string texto = "Aprendendo C++ é divertido!";

    // Extraindo a palavra "C++"
    std::string sub = texto.substr(11, 3); // Começa na posição 11 e pega 3 caracteres
    std::cout << "Substring: " << sub << '\n';

    std::cout << "------------------------------------" << '\n';

    std::string email = "usuario@example.com";

    // Encontrar a posição do '@'
    std::size_t pos = email.find("@");

    // Extrair o domínio
    std::string dominio = email.substr(pos + 1);

    std::cout << "Domínio do e-mail: " << dominio << '\n';

    std::cout << "------------------------------------" << '\n';

    std::string numero = "1234567890";

    // Extraindo os últimos 4 dígitos
    std::string ultimos_digitos = numero.substr(numero.size() - 4);

    std::cout << "Últimos 4 dígitos: " << ultimos_digitos << '\n';

    std::cout << "------------------------------------" << '\n';

    std::string numeroTelefonico = "+55 (86) 99876-5432";

    // Extraindo o código do país, Pega os 3 primeiros caracteres
    std::string codigo_pais = numeroTelefonico.substr(0, 3);

    // Extraindo o código de área, Pega os 2 caracteres após o '('
    std::string codigo_area = numeroTelefonico.substr(5, 2);

    // Extraindo o número principal (excluindo código país e área), Pega tudo a partir do índice 9
    std::string numero_principal = numeroTelefonico.substr(9);

    std::cout << "Código do país: " << codigo_pais << '\n';
    std::cout << "Código de área: " << codigo_area << '\n';
    std::cout << "Número principal: " << numero_principal;
    return 0;
}
