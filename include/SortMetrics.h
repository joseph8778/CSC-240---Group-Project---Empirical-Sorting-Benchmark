#pragma once

#include <chrono>

// OWNER: SortMetrics owns its timing and counter state.
class SortMetrics
{
public:
    // Postconditions: both operation counters are zero.
    void resetCounters() noexcept;

    // Postconditions: records the start time for a sort.
    void startTimer();

    // Preconditions: startTimer() has been called.
    // Postconditions: records the stop time for a sort.
    void stopTimer();

    // Preconditions: stopTimer() has been called after startTimer().
    // Postconditions: returns elapsed time in milliseconds.
    double elapsedMilliseconds() const;

    // Postconditions: increments the key-comparison count by one.
    void recordComparison() noexcept;

    // Postconditions: increments the element-swap count by one.
    void recordSwap() noexcept;

    // Postconditions: returns the recorded number of key comparisons.
    unsigned long long comparisonCount() const noexcept;

    // Postconditions: returns the recorded number of element swaps.
    unsigned long long swapCount() const noexcept;

private:
    using Clock = std::chrono::high_resolution_clock;

    unsigned long long comparisons = 0;
    unsigned long long swaps = 0;
    Clock::time_point startTime{};
    Clock::time_point stopTime{};
};