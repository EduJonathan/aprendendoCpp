#ifndef POLICIES_HPP
#define POLICIES_HPP

#include <string>
#include <string_view>
#include <array>
#include <utility>

struct StandardRomanPolicy
{
    std::string to_roman_impl(int value) const
    {
        if (value < 1 || value > 3999)
            return {};

        constexpr std::array<std::pair<int, const char *>, 13> table{
            {{1000, "M"},
             {900, "CM"},
             {500, "D"},
             {400, "CD"},
             {100, "C"},
             {90, "XC"},
             {50, "L"},
             {40, "XL"},
             {10, "X"},
             {9, "IX"},
             {5, "V"},
             {4, "IV"},
             {1, "I"}}};

        std::string result;
        for (auto [val, sym] : table)
        {
            while (value >= val)
            {
                result += sym;
                value -= val;
            }
        }
        return result;
    }

    int from_roman_impl(std::string_view s) const
    {
        auto valueOf = [](char c)
        {
            switch (c)
            {
            case 'M':
                return 1000;

            case 'D':
                return 500;

            case 'C':
                return 100;

            case 'L':
                return 50;

            case 'X':
                return 10;

            case 'V':
                return 5;

            case 'I':
                return 1;

            default:
                return 0;
            }
        };

        int result = 0;
        for (std::size_t i = 0; i < s.size(); ++i)
        {
            int v1 = valueOf(s[i]);
            if (i + 1 < s.size() && v1 < valueOf(s[i + 1]))
            {
                result += valueOf(s[i + 1]) - v1;
                ++i;
            }
            else
            {
                result += v1;
            }
        }
        return result;
    }
};

struct AdditiveRomanPolicy
{
    std::string to_roman_impl(int value) const
    {
        if (value < 1 || value > 3999)
            return {};

        constexpr std::array<std::pair<int, const char *>, 7> table{
            {{1000, "M"},
             {500, "D"},
             {100, "C"},
             {50, "L"},
             {10, "X"},
             {5, "V"},
             {1, "I"}}};

        std::string result;

        for (auto [val, sym] : table)
        {
            int count = value / val;
            result.append(count, sym[0]);
            value %= val;
        }
        return result;
    }

    int from_roman_impl(std::string_view s) const
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
};

#endif
