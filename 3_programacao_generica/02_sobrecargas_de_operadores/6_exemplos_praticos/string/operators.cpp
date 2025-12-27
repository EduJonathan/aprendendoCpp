#include "string.hpp"
#include <cstring>
#include <string>

std::ostream &operator<<(std::ostream &out, const Str &str)
{
    return out << str.c_str();
}

std::istream &operator>>(std::istream &in, Str &str)
{
    std::string temp;
    in >> temp;
    if (in)
        str = Str(temp.c_str());
    return in;
}

std::istream &getline_str(std::istream &in, Str &str)
{
    std::string temp;
    std::getline(in, temp);
    if (in)
        str = Str(temp.c_str());
    return in;
}

bool operator==(const Str &lhs, const Str &rhs)
{
    return std::strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator!=(const Str &lhs, const Str &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const Str &lhs, const Str &rhs)
{
    return std::strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator<=(const Str &lhs, const Str &rhs)
{
    return !(rhs < lhs);
}

bool operator>(const Str &lhs, const Str &rhs)
{
    return rhs < lhs;
}

bool operator>=(const Str &lhs, const Str &rhs)
{
    return !(lhs < rhs);
}
