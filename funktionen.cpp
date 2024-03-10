#include <iostream>
#include <iomanip>

int main()
{
    double a = 2;
    double b = 3;

    double result = a / b;

    std::cout << std::setprecision(10) << std::fixed << result << '\n';

    return 0;
}