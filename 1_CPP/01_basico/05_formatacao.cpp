#include <iostream>
#include <iomanip> // Biblioteca para controle de formato de saída de dados
#include <bitset>  // Biblioteca para conversão e exibição em binário
#include <cstdint> // Biblioteca para tipos de dados inteiros com tamanho fixo (Relacionado ao stdint.h ou inttypes.h do C)

/**
 * Este código demonstra como formatar saídas em C++ utilizando as bibliotecas
 * <iomanip>, <bitset> e <cstdint>.
 *
 * ------------------------------------------------------------------------------------
 * BIBLIOTECA <iomanip> — Manipulação de Formatação de Saída:
 *
 * - std::hex → Exibe valores inteiros no formato hexadecimal.
 * - std::oct → Exibe valores inteiros no formato octal.
 * - std::dec → Retorna à exibição no formato decimal (padrão).
 * - std::showbase → Adiciona prefixo: "0x" para hex e "0" para octal.
 * - std::setw(n) → Define a largura mínima do campo de saída como 'n' caracteres.
 * - std::setfill(c) → Define o caractere 'c' como preenchimento para campos menores.
 * - std::fixed → Exibe números de ponto flutuante com casas decimais fixas.
 * - std::setprecision(n) → Define o número de casas decimais ou dígitos significativos.
 * - std::scientific → Exibe números de ponto flutuante em notação científica.
 * - std::defaultfloat → Retorna à exibição padrão de ponto flutuante.
 * - std::showpos → Exibe o sinal '+' para números positivos.
 * - std::noshowpos → Não exibe o sinal '+' para números positivos.
 * - std::uppercase → Exibe letras maiúsculas em hexadecimais e notação científica.
 * - std::nouppercase → Exibe letras minúsculas em hexadecimais e notação científica.
 * - std::boolalpha → Exibe valores booleanos como 'true' ou 'false'.
 * - std::noboolalpha → Exibe valores booleanos como '1' ou '0'.
 * - std::left → Alinha o texto à esquerda dentro do campo.
 * - std::right → Alinha o texto à direita dentro do campo.
 * - std::internal → Alinha o texto à direita, mas mantém o sinal à esquerda.
 *
 * ------------------------------------------------------------------------------------
 * BIBLIOTECA <bitset> — Representação Binária:
 *
 * - std::bitset<N>(valor) → Converte e exibe o número em binário com N bits.
 *
 * ------------------------------------------------------------------------------------
 * BIBLIOTECA <cstdint> — Tipos Inteiros com Tamanhos Fixos:
 *
 * - reinterpret_cast<std::uintptr_t>(ptr)
 * → Converte um ponteiro para um inteiro sem sinal com o mesmo tamanho do ponteiro,
 * de forma segura e portável (ideal para exibir endereços de memória em formato numérico).
 */

int main(int argc, char **argv)
{
    // 1. FORMATAÇÃO BINÁRIA
    std::cout << "\n------------------------------------------------\n";
    std::cout << "\tFormatação de Saída Binária\n";
    std::cout << "--------------------------------------------------\n";

    int valor_binario = 42;

    std::cout << "Decimal: \t\t" << valor_binario << '\n';
    std::cout << "Binário (16 bits): \t" << std::bitset<16>(valor_binario) << '\n';
    
    // O bitset é formatado como string, então setw e setfill só afetam o padding externo
    std::cout << "Binário (8 bits): \t0b" << std::bitset<8>(valor_binario) << '\n';
    std::cout << "Binário (32 bits): \t" << std::bitset<32>(valor_binario) << '\n';

    std::cout << std::dec << std::noshowbase; // Reset
    std::cout << "Valor original em decimal: " << valor_binario << '\n';

    // 2. FORMATAÇÃO HEXADECIMAL
    std::cout << "\n------------------------------------------------\n";
    std::cout << "\tFormatação de Saída Hexadecimal\n";
    std::cout << "--------------------------------------------------\n";

    int valor_hex = 255;

    std::cout << "Decimal: \t\t" << std::dec << valor_hex << '\n';
    std::cout << "Hex (Minúsculo): \t" << std::hex << valor_hex << '\n';
    std::cout << "Hex (c/ 0x): \t\t" << std::showbase << valor_hex << '\n';    // showbase adiciona 0x
    std::cout << "Hex (Maiúsculo): \t" << std::uppercase << valor_hex << '\n'; // Deixa F maiúsculo

    // Exemplo de preenchimento (setw/setfill): Note que o 0x conta na largura (8)
    std::cout << "Hex Formatado (fill '0'): " << std::setw(8) << std::setfill('0') << valor_hex << '\n';

    // OBRIGATÓRIO: Resetar flags globais para evitar poluir as próximas saídas
    std::cout << std::dec << std::noshowbase << std::nouppercase;
    std::cout << "Valor resetado (Decimal): " << valor_hex << '\n';

    // 3. FORMATAÇÃO OCTAL
    std::cout << "\n------------------------------------------------\n";
    std::cout << "\tFormatação de Saída Octal\n";
    std::cout << "--------------------------------------------------\n";

    int valor_octal = 64;

    std::cout << "Decimal: \t" << std::dec << valor_octal << '\n';
    std::cout << "Octal: \t\t" << std::oct << valor_octal << '\n';
    std::cout << "Octal (c/ 0): \t" << std::showbase << valor_octal << '\n'; // showbase adiciona 0
    std::cout << std::dec << std::noshowbase;                                // Reset
    std::cout << "Valor resetado (Decimal): " << valor_octal << '\n';
    
    // 4. FORMATAÇÃO DE PONTEIROS
    std::cout << "\n------------------------------------------------\n";
    std::cout << "\tFormatação de Ponteiros\n";
    std::cout << "--------------------------------------------------\n";

    int num = 42;
    int *ptr = &num;

    // Usamos uintptr_t para garantir um inteiro grande o suficiente para o endereço
    auto endereco = reinterpret_cast<std::uintptr_t>(ptr);

    std::cout << "Endereço padrão: \t" << ptr << '\n';

    // Formatação de endereço como Hexadecimal
    std::cout << "Endereço formatado: \t" << std::showbase << std::hex
              << std::setfill('0') << std::setw(sizeof(void *) * 2 + 2) // Largura: 2 * bytes do ponteiro + "0x"
              << endereco << '\n';

    std::cout << std::dec << std::noshowbase; // Reset
    std::cout << "Valor da variável: \t" << num << '\n';
    std::cout << "Endereço da variável: \t" << ptr << '\n';
    std::cout << "Valor via ponteiro: \t" << *ptr << '\n';
    
    // 5. FORMATAÇÃO DE ALINHAMENTO E PREENCHIMENTO
    std::cout << "\n================================================\n";
    std::cout << "\t5. Alinhamento e Preenchimento\n";
    std::cout << "================================================\n";

    int valor_align = 123;
    int campo = 15;

    std::cout << std::setfill('*');

    std::cout << std::right << std::setw(campo) << valor_align << " (Direita)\n";
    std::cout << std::left << std::setw(campo) << valor_align << " (Esquerda)\n";

    // Internal: Sinal/Base à esquerda, valor à direita (precisa de showpos/showbase)
    std::cout << std::internal << std::showpos << std::setw(campo) << valor_align << " (Internal)\n";

    std::cout << std::noshowpos;    // Reset
    std::cout << std::setfill(' '); // Reset fill

    // 5. FORMATAÇÃO COM FLAGS
    std::cout << "\n------------------------------------------------\n";
    std::cout << "\tFormatação com Flags\n";
    std::cout << "--------------------------------------------------\n";

    // Sinal
    std::cout << "Mostrar sinal (+): \t" << std::showpos << 100 << " | (-): " << -100 << '\n';
    std::cout << "Sem sinal (padrão): \t" << std::noshowpos << 100 << " | " << -100 << '\n';

    // Booleano
    std::cout << "Booleano Numérico: \t" << std::noboolalpha << true << " | " << false << '\n';
    std::cout << "Booleano Literal: \t" << std::boolalpha << true << " | " << false << '\n';

    std::cout << std::noboolalpha; // Reset

    // 6. FORMATAÇÃO DE DECIMAIS
    std::cout << "\n------------------------------------------------\n";
    std::cout << "\tFormatação de Casas Decimais\n";
    std::cout << "--------------------------------------------------\n";

    double pi = 3.14159265358979;

    std::cout << "Padrão (defaultfloat): " << pi << '\n';
    std::cout << "Fixed (4 casas): \t" << std::fixed << std::setprecision(4) << pi << '\n';
    std::cout << "Científico (2 casas): \t" << std::scientific << std::setprecision(2) << pi << '\n';

    // Voltando ao padrão
    std::cout << std::defaultfloat;
    std::cout << "Voltando ao padrão: \t" << pi << '\n';
    return 0;
}
