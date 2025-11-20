#ifndef ROMAN_ANY_CONVERTER_HPP
#define ROMAN_ANY_CONVERTER_HPP

#include <string>
#include <string_view>
#include <memory>

class RomanAnyConverter
{
public:
    // construtor genérico (aceita qualquer converter)
    template <typename Converter>
    RomanAnyConverter(const Converter &conv)
        : self(std::make_shared<Model<Converter>>(conv)) {}

    std::string toRoman(int v) const
    {
        return self->toRoman(v);
    }

    int fromRoman(std::string_view s) const
    {
        return self->fromRoman(s);
    }

private:
    struct Concept
    {
        virtual ~Concept() = default;
        virtual std::string toRoman(int) const = 0;
        virtual int fromRoman(std::string_view) const = 0;
    };

    template <typename T>
    struct Model : Concept
    {
        T converter;

        Model(const T &conv) : converter(conv) {}

        std::string toRoman(int v) const override
        {
            return converter.toRoman(v);
        }

        int fromRoman(std::string_view s) const override
        {
            return converter.fromRoman(s);
        }
    };

    std::shared_ptr<const Concept> self;
};

#endif
