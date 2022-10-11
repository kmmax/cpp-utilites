#include <iostream>

#include "calc.h"


using namespace std;


int main()
{
    cout << "Hello World!" << endl;
    Mb::Calc::Numbers numbers = {
        {3, 1},
        {25, 2},
        {7, 1},
        {26, 2},
        {216, 4},
        {216, 1},
        {126, 2}
    };
    cout << numbers;
    Mb::Calc::Ranges ranges = Mb::Calc::update_ranges(numbers, 10);
    cout << ranges << endl;
//    ranges.push_back(std::pair(0, 7));
//    ranges.push_back(std::pair(10, 21));
//    ranges.push_back(std::pair(33, 67));

//    Mb::Calc calc{};
//    std::cout << calc << endl;
//    std::cout << ranges << endl;

    return 0;
}
