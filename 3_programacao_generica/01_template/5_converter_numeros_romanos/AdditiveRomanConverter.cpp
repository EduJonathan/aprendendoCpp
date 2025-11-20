#include "AdditiveRomanConverter.hpp"
#include <utility>
#include <array>

std::string AdditiveRomanConverter::toRoman(int value) const
{
    if (value < 1 || value > 3999)
        return {};

    constexpr std::array<std::pair<int, const char *>, 7> table{{{1000, "M"}, {500, "D"}, {100, "C"}, {50, "L"}, {10, "X"}, {5, "V"}, {1, "I"}}};

    std::string result;
    for (auto [val, sym] : table)
    {
        int count = value / val;
        result.append(count, sym[0]);
        value %= val;
    }
    return result;
}

int AdditiveRomanConverter::fromRoman(std::string_view s) const
{
    int result = 0;
    for (char c : s)
    {
        switch (c)
        {
        case 'M':
            result += 1000;
            break;

        case 'D':
            result += 500;
            break;

        case 'C':
            result += 100;
            break;

        case 'L':
            result += 50;
            break;

        case 'X':
            result += 10;
            break;

        case 'V':
            result += 5;
            break;

        case 'I':
            result += 1;
            break;
        }
    }
    return result;
}
