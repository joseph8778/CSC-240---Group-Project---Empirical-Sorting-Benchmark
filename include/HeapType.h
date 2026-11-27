#pragma once

#include "DynamicArray.h"

// OWNER: HeapType owns its backing DynamicArray.
// OBSERVERS: No external pointers or references into the backing array are stored.
class HeapType
{
public:
    HeapType() = default;

    // Postconditions: value is added to the max-heap.
    void insert(int value);

    // Preconditions: the heap is not empty.
    // Postconditions: removes and returns the largest value.
    int extractMax();

    // Postconditions: returns the number of active heap elements.
    int size() const noexcept;

    // Postconditions: returns whether the heap contains no elements.
    bool isEmpty() const noexcept;

private:
    DynamicArray elements;
    int heapSize = 0;

    // Preconditions: index > 0.
    // Postconditions: returns the parent index for a zero-based heap.
    int parentIndex(int index) const noexcept
    {
        return (index - 1) / 2;
    }

    // Preconditions: index >= 0.
    // Postconditions: returns the left child index for a zero-based heap.
    int leftChildIndex(int index) const noexcept
    {
        return 2 * index + 1;
    }

    // Preconditions: index >= 0.
    // Postconditions: returns the right child index for a zero-based heap.
    int rightChildIndex(int index) const noexcept
    {
        return 2 * index + 2;
    }

    // Preconditions: index is a valid active heap element.
    // Postconditions: returns whether index has an active left child.
    bool hasLeftChild(int index) const noexcept
    {
        return leftChildIndex(index) < heapSize;
    }

    // Preconditions: index is a valid active heap element.
    // Postconditions: returns whether index has an active right child.
    bool hasRightChild(int index) const noexcept
    {
        return rightChildIndex(index) < heapSize;
    }

    // Preconditions: index is a valid active heap element.
    // Postconditions: restores heap order toward the root.
    void reheapUp(int index);

    // Preconditions: index is a valid active heap element.
    // Postconditions: restores heap order toward the leaves.
    void reheapDown(int index);
};