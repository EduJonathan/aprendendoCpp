#ifndef ROMAN_ANY_CONVERTER_HPP
#define ROMAN_ANY_CONVERTER_HPP

#include <string>
#include <string_view>
#include <memory>

/**
 * @brief Classe de conversão genérica para números romanos.
 *
 * A classe `RomanAnyConverter` é uma implementação de um conversor de números romanos que pode ser configurado
 * com diferentes políticas de conversão. Ela utiliza o padrão de projeto "type erasure" para permitir a utilização
 * de diferentes tipos de conversores sem expor os detalhes de implementação.
 *
 * A classe é construída a partir de um objeto de conversão específico (como `StandardRomanPolicy` ou `AdditiveRomanPolicy`)
 * e fornece métodos para converter números inteiros para suas representações em números romanos e vice-versa.
 */
class RomanAnyConverter
{
public:
    /**
     * @brief Construtor genérico para `RomanAnyConverter`.
     *
     * O construtor é um template que aceita qualquer tipo de conversor que implemente os métodos `to_roman_impl` e `from_roman_impl`.
     * Ele cria uma instância do modelo de conversão correspondente ao tipo de conversor fornecido e armazena essa instância
     * em um ponteiro inteligente para permitir a manipulação polimórfica dos conversores.
     *
     * @tparam Converter O tipo do conversor a ser utilizado, que deve implementar os métodos `to_roman_impl` e `from_roman_impl`.
     * @param conv O objeto de conversão específico a ser utilizado para as operações de conversão de números romanos.
     */
    template <typename Converter>
    RomanAnyConverter(const Converter &conv);

    /**
     * @brief Converte um número inteiro para uma string representando o número romano.
     *
     * O método `toRoman` é responsável por realizar a conversão de um número inteiro para sua representação
     * em números romanos, utilizando a política de conversão configurada no construtor.
     *
     * @param v O número inteiro a ser convertido.
     * @return Uma string representando o número romano correspondente ao valor inteiro fornecido.
     */
    std::string toRoman(int v) const;

    /**
     * @brief Converte uma string representando um número romano para um número inteiro.
     *
     * O método `fromRoman` é responsável por realizar a conversão de uma string representando um número romano
     * para seu valor inteiro correspondente, utilizando a política de conversão configurada no construtor.
     *
     * @param s A string representando o número romano a ser convertido.
     * @return O valor inteiro correspondente à string de número romano fornecida.
     */
    int fromRoman(std::string_view s) const;

private:
    // O `Concept` é uma estrutura base que define a interface para os modelos de conversão de números romanos.
    // Ele contém métodos virtuais puros que devem ser implementados pelos modelos específicos de conversão,
    // permitindo a manipulação polimórfica dos conversores.
    struct Concept
    {
        // Destrutor virtual para permitir a limpeza adequada dos recursos alocados pelos modelos de conversão específicos.
        virtual ~Concept() = default;

        /**
         * @brief Métodos virtuais puros para conversão de números romanos.
         *
         * O `Concept` define a interface que os modelos de conversão devem implementar, com métodos virtuais puros
         * para a conversão de números inteiros para números romanos e vice-versa. Os modelos de conversão específicos
         * (como `Model<StandardRomanPolicy>` e `Model<AdditiveRomanPolicy>`) implementam esses métodos de acordo com a
         * política de conversão que representam.
         *
         * @param int O número inteiro a ser convertido para número romano.
         * @return Uma string representando o número romano correspondente ao valor inteiro fornecido.
         */
        virtual std::string toRoman(int) const = 0;

        /**
         * @brief Método virtual puro para conversão de números romanos para inteiros.
         *
         * O método `fromRoman` é um método virtual puro que deve ser implementado pelos modelos de conversão específicos.
         * Ele é responsável por realizar a conversão de uma string representando um número romano para seu valor inteiro correspondente.
         *
         * @param s A string representando o número romano a ser convertido.
         * @return O valor inteiro correspondente à string de número romano fornecida.
         */
        virtual int fromRoman(std::string_view) const = 0;
    };

    // O `Model` é uma estrutura template que implementa a interface definida pelo Concept para um tipo específico de conversor.
    template <typename T>
    struct Model : Concept
    {
        // O objeto de conversão específico a ser utilizado para as operações de conversão de números romanos,
        // que é armazenado como um membro do `Model` para ser utilizado na implementação dos métodos virtuais definidos no `Concept`.
        T converter;

        /**
         * @brief Construtor para o Model de conversão.
         *
         * O construtor do `Model` é responsável por inicializar o objeto de conversão específico (converter) com o valor fornecido.
         * Ele é chamado a partir do construtor genérico da classe RomanAnyConverter, que cria uma instância do `Model` correspondente
         * ao tipo de conversor fornecido. O `Model` implementa os métodos virtuais definidos no `Concept`,
         * utilizando o objeto de conversão específico para realizar as operações de conversão de números romanos.
         *
         * @param conv O objeto de conversão específico a ser utilizado para as operações de conversão de números romanos,
         * que é passado para o construtor do `Model` para inicializar o membro converter.
         *
         * @return Uma instância do `Model` de conversão configurada com o objeto de conversão específico fornecido,
         * que implementa a interface definida pelo `Concept` para realizar as operações de conversão de números romanos.
         */
        explicit Model(const T &conv) : converter(conv) {}

        /**
         * @brief Implementação do método `toRoman` para o `Model` de conversão.
         * O método `toRoman` é implementado no `Model` para realizar a conversão de um número inteiro
         * para sua representação em números romanos, utilizando o objeto de conversão específico (converter)
         * para realizar a operação de conversão de acordo com a política de conversão representada pelo tipo `T`.
         *
         * @param v O número inteiro a ser convertido para número romano.
         * @return Uma string representando o número romano correspondente ao valor inteiro fornecido,
         * obtida através do método `to_roman_impl` do objeto de conversão específico (converter).
         */
        std::string toRoman(int v) const override;

        /**
         * @brief Implementação do método `fromRoman` para o `Model` de conversão.
         * O método `fromRoman` é implementado no `Model` para realizar a conversão de uma string representando um número romano
         * para seu valor inteiro correspondente, utilizando o objeto de conversão específico (converter) para
         * realizar a operação de conversão de acordo com a política de conversão representada pelo tipo `T`.
         *
         * @param s A string representando o número romano a ser convertido.
         * @return O valor inteiro correspondente à string de número romano fornecida, obtido através do método
         * `from_roman_impl` do objeto de conversão específico (converter).
         */
        int fromRoman(std::string_view s) const override;
    };

    // Ponteiro inteligente para a implementação do conversor específico, permitindo a manipulação polimórfica dos conversores.
    std::shared_ptr<const Concept> self;
};

#include "../src/RomanAnyConverter.tpp" // Inclui as implementações dos métodos template da classe RomanAnyConverter

#endif // ROMAN_ANY_CONVERTER_HPP
