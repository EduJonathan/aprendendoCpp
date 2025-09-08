#include <iostream>
#include <string>
#include "class_prototipo.hpp"
// #include "implementacao.cpp"

/**
 * Em C++ orientado a objetos (POO), é recomendada a separação de declarações e implementações
 * em dois arquivos distintos: o arquivo `.hpp` (cabeçalhos) para declarações e o `.cpp`
 * (implementação) para a lógica dos métodos.
 *
 * A utilização do `#include "implementacao.cpp"` deve ser evitada, apesar de funcionar,
 * por várias razões:
 *
 * ---------------------
 *
 * 1. **Manutenção difícil**: O código se torna grande e desorganizado, dificultando mudanças
 * e depuração.
 *
 * 2. **Reutilização limitada**: Ao incluir o `arquivo.cpp`, a classe não pode ser facilmente
 * reutilizada em outros arquivos.
 *
 * 3. **Perda de desempenho**: Compilação separada permite otimizações de tempo, o que é
 * perdido ao incluir `.cpp`.
 *
 * 4. **Trabalho em equipe**: A abordagem dificulta a colaboração entre diferentes desenvolvedores.
 *
 * 5. **Problemas de compilação**: Incluir `arquivo.cpp` pode levar a múltiplas definições
 * das mesmas funções, gerando erros de linking e aumentando o tempo de compilação.
 *
 * 6. **Dificuldade de testes**: Testar a classe se torna mais complicado, pois não é possível
 * compilar apenas o arquivo de teste.
 *
 * ---------------------
 *
 * Você pode estar pensando: "Se funciona, por que não usar?".
 *
 * Embora essa abordagem funcione, ela não é recomendada e pode causar problemas no futuro.
 * Para iniciantes, a ideia de `compilar` e `executar` o código várias vezes pode ser
 * entediante, mas é fundamental seguir boas práticas de programação desde o início
 * para evitar dores de cabeça futuras.
 *
 * Usar `#include "arquivo.cpp"` pode sim ser utilizado e útil para testes rápidos
 * ou projetos pequenos, mas essa prática não é ideal para projetos maiores.
 * Além disso, lembre-se do `Makefile`, que automatiza a compilação e execução sem
 * a necessidade de recompilação manual.
 */

int main(int argc, char **argv)
{
    Prototipo words;

    const std::vector<std::string> palavras1 = {"bananaapplecherry", "cherrybananaap", "applebananacherry", "apple", "banana"};
    const std::vector<std::string> palavras2 = {"ap", "ban", "cherry"};

    std::cout << "======= INÍCIO DO TESTE =======\n";

    std::vector<std::string> resultado = words.wordSubsets(palavras1, palavras2);

    std::cout << "\n======= SUBCONJUNTOS ENCONTRADOS =======\n";

    for (const auto &word : resultado)
        std::cout << word << ' ';
    std::cout << '\n';

    /**
     * Compile e execute o programa com:
     * > g++ -std=c++17 .\main_prototipo.cpp .\implementacao.cpp -o nome_do_executavel
     * > .\nome_do_executavel.exe
     */

    return 0;
}
