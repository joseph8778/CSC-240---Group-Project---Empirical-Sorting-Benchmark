#pragma once

#include "DynamicArray.h"

// OWNER: The caller owns the output array, which owns its backing buffer.
// OBSERVERS: DataSet uses output by reference during the call only.
// REMOVAL: The caller controls the lifetime of output.
class DataSet
{
public:
    // Preconditions: size > 0.
    // Postconditions: returns a sequence of size random integers.
    static DynamicArray generateRandom(int size);
    
    // Preconditions: size >= 0 and output is empty.
    // Postconditions: output contains the values 1 through size in ascending
    // order, with the middle two values swapped in each complete block of 20.
    static void generateNearlySorted(int size, DynamicArray& output);

    // Preconditions: size >= 0 and output is empty.
    // Postconditions: output contains the values size through 1 in descending order.
    static void generateReverseSorted(int size, DynamicArray& output);
};
