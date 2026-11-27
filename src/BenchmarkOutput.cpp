#include "BenchmarkOutput.h"
#include "SortMetrics.h"

#include <iomanip>
#include <sstream>

void printBenchmarkHeader(std::ostream& output)
{
    std::ostringstream line;
    line << std::left
         << std::setw(18) << "Algorithm"
         << std::setw(18) << "Input Type"
         << std::right
         << std::setw(10) << "Size"
         << std::setw(14) << "Time (ms)"
         << std::setw(16) << "Comparisons"
         << std::setw(16) << "Swaps";

    output << line.str() << '\n';
}

void printBenchmarkRow(std::ostream& output, const char* algorithm, const char* inputType, int size, const SortMetrics& metrics)
{
    std::ostringstream line;
    line << std::left
         << std::setw(18) << algorithm
         << std::setw(18) << inputType
         << std::right
         << std::setw(10) << size
         << std::setw(14) << std::fixed << std::setprecision(3)
         << metrics.elapsedMilliseconds()
         << std::setw(16) << metrics.comparisonCount()
         << std::setw(16) << metrics.swapCount();

    output << line.str() << '\n';
}