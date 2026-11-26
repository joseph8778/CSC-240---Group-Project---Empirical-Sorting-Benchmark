#pragma once

#include "DynamicArray.h"

// OWNER: The caller owns each returned DynamicArray and its backing buffer.
// OBSERVERS: DataSet stores no pointers or references to generated elements.
class DataSet
{
public:
    // Preconditions: size > 0.
    // Postconditions: returns a sequence of size random integers.
    static DynamicArray generateRandom(int size);

    // Preconditions: size > 0.
    // Postconditions: returns values 1 through size, with one random adjacent
    // pair swapped in each complete block of 20.
    static DynamicArray generateNearlySorted(int size);

    // Preconditions: size > 0.
    // Postconditions: returns values size through 1 in descending order.
    static DynamicArray generateReverseSorted(int size);
};
