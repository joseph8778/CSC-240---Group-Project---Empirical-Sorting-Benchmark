#include "DynamicArray.h"
#include "DataSet.h"
#include "SortMetrics.h"
#include <chrono>
#include <iostream>
#include <stdexcept>
#include <thread>
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
        std::cout << "Passed dataset checks for N = " << size << ".\n";
    }

    SortMetrics metrics;
    metrics.resetCounters();
    metrics.recordComparison();
    metrics.recordComparison();
    metrics.recordSwap();

    metrics.startTimer();
    std::this_thread::sleep_for(std::chrono::milliseconds(10)); // Creates gap in time to measure
    metrics.stopTimer();

    const double elapsed = metrics.elapsedMilliseconds();
    if (metrics.comparisonCount() != 2 || metrics.swapCount() != 1 || elapsed <= 0.0)
    {
        std::cerr << "SortMetrics test failed.\n";
        return 1;
    }

    cout << "SortMetrics test passed.\n"
              << "Comparisons: " << metrics.comparisonCount() << '\n'
              << "Swaps: " << metrics.swapCount() << '\n'
              << "Elapsed: " << elapsed << " ms\n";

    return 0;
}