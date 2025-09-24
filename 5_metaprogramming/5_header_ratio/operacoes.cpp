#include <ratio>
#include <iostream>

using Half = std::ratio<1, 2>;
using Quarter = std::ratio<1, 4>;

using Result = std::ratio_add<
    std::ratio_multiply<Half, std::ratio<3, 1>>,
    std::ratio_multiply<Quarter, std::ratio<4, 1>>>; // (1/2 * 3) + (1/4 * 4)

int main(int argc, char **argv)
{
    std::cout << "Numerador do resultado: " << Result::num << '\n';   // 7
    std::cout << "Denominador do resultado: " << Result::den << '\n'; // 2
    return 0;
}
