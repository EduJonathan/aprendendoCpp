#include <iostream>
#include "template_soma.hpp"

int main(int argc, char **argv)
{
    std::cout << sum(1, 2, 3) << '\n';          // 6
    std::cout << sum(1.5, 2.5, 3.0) << '\n';    // 7.0
    std::cout << sum(10, -5, 7, 8, 20) << '\n'; // 40
    return 0;
}
