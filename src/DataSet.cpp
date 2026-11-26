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
