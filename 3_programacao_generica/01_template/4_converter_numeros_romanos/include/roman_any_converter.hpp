#ifndef ROMAN_ANY_CONVERTER_HPP
#define ROMAN_ANY_CONVERTER_HPP

#include <string>
#include <string_view>
#include <memory>

class RomanAnyConverter
{
public:
    template <typename Converter>
    RomanAnyConverter(const Converter &conv);

    std::string toRoman(int v) const;
    int fromRoman(std::string_view s) const;

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
        explicit Model(const T &conv) : converter(conv) {}
        std::string toRoman(int v) const override;
        int fromRoman(std::string_view s) const override;
    };

    std::shared_ptr<const Concept> self;
};

#endif // ROMAN_ANY_CONVERTER_HPP
