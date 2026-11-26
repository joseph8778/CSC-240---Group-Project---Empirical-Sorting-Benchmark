#include "DataSet.h"

void DataSet::generateNearlySorted(int size, DynamicArray& output)
{
    for (int index = 0; index < size; ++index)
    {
        output.append(index + 1);
    }

    for (int block = 0; block < size / 20; ++block)
    {
        int left = block * 20 + 9;
        int firstValue = output.get(left);

        output.set(left, output.get(left + 1));
        output.set(left + 1, firstValue);
    }
}

void DataSet::generateReverseSorted(int size, DynamicArray& output)
{
    for (int value = size; value > 0; --value)
    {
        output.append(value);
    }
}