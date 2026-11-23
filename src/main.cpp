#include "DynamicArray.h"
#include "DynamicArray.cpp"
#include <iostream>
#include <stdexcept>

int main()
{
    DynamicArray arr1(1);
    std::cout << "Created DynamicArray with capacity 1.\n";


    try
    {
        DynamicArray invalidArray(0);
        std::cerr << "Error: zero capacity was accepted.\n";
        return 1;
    }
    catch (const std::invalid_argument& error)
    {
        std::cout << "Rejected invalid capacity: " << error.what() << '\n';
    }



    return 0;
}