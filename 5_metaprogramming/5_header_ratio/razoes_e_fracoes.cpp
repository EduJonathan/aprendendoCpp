#include <iostream>
#include <ratio>

using Half = std::ratio<1, 2>;
using Third = std::ratio<1, 3>;

int main(int argc, char **argv)
{
    using r1 = std::ratio<1, 3>;
    using r2 = std::ratio<2, 5>;
    using soma = std::ratio_add<r1, r2>;
    std::cout << "Soma de 1/3 + 2/5 = " << soma::num << '/' << soma::den << '\n';

    std::cout << std::boolalpha;
    std::cout << "Half == Third? " << std::ratio_equal<Half, Third>::value << '\n'; // false
    return 0;
}
