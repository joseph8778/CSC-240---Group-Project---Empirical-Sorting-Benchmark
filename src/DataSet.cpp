#include "DataSet.h"

#include <limits>
#include <random>
#include <stdexcept>

DynamicArray DataSet::generateRandom(int size)
{
    if (size <= 0)
    {
        throw std::invalid_argument("Dataset size must be greater than zero.");
    }

    DynamicArray data(size);
    std::random_device seedSource;
    std::mt19937 generator(seedSource());
    std::uniform_int_distribution<int> distribution(
        std::numeric_limits<int>::min(),
        std::numeric_limits<int>::max());

    for (int i = 0; i < size; ++i)
    {
        data.append(distribution(generator));
    }

    return data;
}
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
