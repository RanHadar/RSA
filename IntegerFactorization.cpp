#include <iostream>
#include "GFNumber.h"
#include "GField.h"

/**
 *Main methods - Responsible for running the program
 */
int main()
{
    GFNumber a, b;
    std::cin >> a >> b;
    std::cout << a + b;
    std::cout << a - b;
    std::cout << b - a;
    std::cout << a * b;
    a.printFactors();
    b.printFactors();
}
