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
    std::uniform_int_distribution<int> distribution(0, size - 1);

    for (int i = 0; i < size; ++i)
    {
        data.append(distribution(generator));
    }

    return data;
}

DynamicArray DataSet::generateNearlySorted(int size)
{
    if (size <= 0)
    {
        throw std::invalid_argument("Dataset size must be greater than zero.");
    }

    DynamicArray output(size);
    for (int index = 0; index < size; ++index)
    {
        output.append(index + 1);
    }

    const int blockSize = 20;
    std::random_device seedSource;
    std::mt19937 generator(seedSource());
    std::uniform_int_distribution<int> pairOffset(0, blockSize - 2);

    for (int blockStart = 0; blockStart <= size - blockSize; blockStart += blockSize)
    {
        const int left = blockStart + pairOffset(generator);
        const int leftValue = output.get(left);
        output.set(left, output.get(left + 1));
        output.set(left + 1, leftValue);
    }

    return output;
}

DynamicArray DataSet::generateReverseSorted(int size)
{
    if (size <= 0)
    {
        throw std::invalid_argument("Dataset size must be greater than zero.");
    }

    DynamicArray output(size);
    for (int value = size; value > 0; --value)
    {
        output.append(value);
    }

    return output;
}
