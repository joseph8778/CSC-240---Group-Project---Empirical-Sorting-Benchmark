#include "DynamicArray.h"
#include <stdexcept>

DynamicArray::DynamicArray(int initialCapacity) : elements(nullptr), currentSize(0), currentCapacity(initialCapacity) {
    if(initialCapacity < 1) {
        throw std::invalid_argument("Capacity cannot be less than 1.");
    }

    elements = new int[initialCapacity];
}

DynamicArray::~DynamicArray() {
    delete[] elements;
}


void DynamicArray::ensureCapacity(int requiredCapacity) {
    if(currentCapacity >= requiredCapacity) return;

        int newCapacity = currentCapacity;
        
        while(newCapacity < requiredCapacity) {
            newCapacity = newCapacity * 2;
        }

        int* newElements = new int[newCapacity];
        
        for(int i = 0; i < currentSize; ++i) {
            newElements[i] = elements[i];
        }

        delete[] elements;
        elements = newElements;
        currentCapacity = newCapacity;

}

void DynamicArray::append(int value)
{
    ensureCapacity(currentSize + 1);
    elements[currentSize] = value;
    ++currentSize;
}

int DynamicArray::get(int index) const
{
    if (index < 0 || index >= currentSize)
    {
        throw std::out_of_range("DynamicArray index is out of range.");
    }

    return elements[index];
}

void DynamicArray::set(int index, int value)
{
    if (index < 0 || index >= currentSize)
    {
        throw std::out_of_range("DynamicArray index is out of range.");
    }

    elements[index] = value;
}

int DynamicArray::size() const noexcept
{
    return currentSize;
}

int DynamicArray::capacity() const noexcept
{
    return currentCapacity;
}