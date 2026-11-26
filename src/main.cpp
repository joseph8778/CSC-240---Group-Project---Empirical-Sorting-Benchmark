#include "DynamicArray.h"
#include "DataSet.h"
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

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

    const int sizes[] = {1000, 10000, 100000};
    for (int size : sizes)
    {
        const DynamicArray randomData = DataSet::generateRandom(size);
        if (randomData.size() != size)
        {
            std::cerr << "Random dataset has an incorrect size.\n";
            return 1;
        }
    
        const DynamicArray nearlySortedData = DataSet::generateNearlySorted(size);
        if (nearlySortedData.size() != size)
        {
            std::cerr << "nearlySorted dataset has an incorrect size.\n";
            return 1;
        }

        const DynamicArray reversedData = DataSet::generateReverseSorted(size);
        if (reversedData.size() != size)
        {
            std::cerr << "Reversed dataset has an incorrect size.\n";
            return 1;
        }

        std::cout << "Passed dataset checks for N = " << size << ".\n";
    }

    return 0;
}