#pragma once

#include "DynamicArray.h"

// OWNER: Each returned DynamicArray owns its own backing buffer.
// OBSERVERS: DataSet stores no pointers or references to dataset elements.
class DataSet
{
public:
    // Preconditions: size > 0.
    // Postconditions: returns a sequence of size random integers.
    static DynamicArray generateRandom(int size);

    // Preconditions: size > 0.
    // Postconditions: returns size integers with 90% in ascending order.
    static DynamicArray generateNearlySorted(int size);

    // Preconditions: size > 0.
    // Postconditions: returns size integers in descending order.
    static DynamicArray generateReverseSorted(int size);

    // Postconditions: returns an independent copy of source.
    static DynamicArray clone(const DynamicArray& source);
};
