#include <iostream>
#include <math.h>

int main()
{
    std:: cout << "Enter a number:";
    float num;
    std::cin >> num;

    if (floor(num) == num) {
        if (!((int)num % 2))
            std::cout << "Even number\n";
        else std::cout << "odd Number\n";
    }
    else std::cout << "Fraction\n";

    return 0;
}