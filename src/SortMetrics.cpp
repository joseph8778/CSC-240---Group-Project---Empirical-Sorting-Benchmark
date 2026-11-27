#include "SortMetrics.h"

void SortMetrics::resetCounters() noexcept
{
    comparisons = 0;
    swaps = 0;
}

void SortMetrics::recordComparison() noexcept
{
    ++comparisons;
}

void SortMetrics::recordSwap() noexcept
{
    ++swaps;
}

unsigned long long SortMetrics::comparisonCount() const noexcept
{
    return comparisons;
}

unsigned long long SortMetrics::swapCount() const noexcept
{
    return swaps;
}

void SortMetrics::startTimer()
{
    startTime = Clock::now();
}

void SortMetrics::stopTimer()
{
    stopTime = Clock::now();
}

double SortMetrics::elapsedMilliseconds() const
{
    const std::chrono::duration<double, std::milli> elapsedMs = stopTime - startTime;
    return elapsedMs.count();
}

void SortMetrics::insertionSort(DynamicArray& data)
{
    resetCounters();
    startTimer();

    for (int index = 1; index < data.size(); ++index)
    {
        int position = index;
        const int value = data.get(index);

        while (position > 0)
        {
            const int previous = data.get(position - 1);
            recordComparison();
            if (previous <= value)
            {
                break;
            }

            data.set(position, previous);
            data.set(position - 1, value);
            recordSwap();
            --position;
        }
    }

    stopTimer();
}
