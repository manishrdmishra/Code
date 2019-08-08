#include "complex.h"

#include <iostream>

experiment::complex<double> fixed_comp()
{
    experiment::complex<double> c(1.0, 2.4);
    return c;
}

int main(int argc, char* argv[])
{
//experiment::complex<int> c1;
//experiment::complex<int> c2(1, 3);
//experiment::complex<int> c3(std::move(c2));

experiment::complex<double> c = fixed_comp();
std::cout << c;
//c1 = std::move(c2);

return 0;
}