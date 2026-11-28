#include "DynamicArray.h"
#include "DataSet.h"
#include "SortMetrics.h"
#include <chrono>
#include <iostream>
#include <stdexcept>
#include <thread>
#include <vector>

using namespace std;

void runInsertionBenchmark(const char* distribution, int size, DynamicArray& data)
{
    SortMetrics metrics;
    metrics.insertionSort(data);

    std::cout << "Insertion | " << distribution
              << " | N=" << size
              << " | ms=" << metrics.elapsedMilliseconds()
              << " | comparisons=" << metrics.comparisonCount()
              << " | swaps=" << metrics.swapCount() << '\n\n';
}

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





    // 3 DataSet size testing
    const int sizes[] = {1000, 10000, 100000};
    for (int size : sizes)
    {
        DynamicArray randomData = DataSet::generateRandom(size);
        if (randomData.size() != size)
        {
            std::cerr << "Random dataset has an incorrect size.\n";
            return 1;
        }
    
        DynamicArray nearlySortedData = DataSet::generateNearlySorted(size);
        if (nearlySortedData.size() != size)
        {
            std::cerr << "nearlySorted dataset has an incorrect size.\n";
            return 1;
        }

        DynamicArray reversedData = DataSet::generateReverseSorted(size);
        if (reversedData.size() != size)
        {
            std::cerr << "Reversed dataset has an incorrect size.\n";
            return 1;
        }

        std::cout << "Passed dataset checks for N = " << size << endl << endl;

        

        runInsertionBenchmark("Random", size, randomData);
        runInsertionBenchmark("Nearly-sorted", size, nearlySortedData);
        runInsertionBenchmark("Reversed", size, reversedData);
    }

   


    return 0;
}