#ifndef POLICIES_HPP
#define POLICIES_HPP

#include <string>
#include <string_view>

struct StandardRomanPolicy
{
    std::string to_roman_impl(int value) const;
    int from_roman_impl(std::string_view s) const;
};

struct AdditiveRomanPolicy
{
    std::string to_roman_impl(int value) const;
    int from_roman_impl(std::string_view s) const;
};

#endif // POLICIES_HPP
