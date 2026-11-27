#pragma once

#include "DynamicArray.h"

class SortMetrics;

// OWNER: HeapType owns its backing DynamicArray.
// OBSERVERS: No external pointers or references into the backing array are stored.
class HeapType
{
public:
    HeapType() = default;

    // Postconditions: value is added to the max-heap.
    // Heap comparisons and swaps are recorded in metrics.
    void insert(int value, SortMetrics& metrics);

    // Preconditions: the heap is not empty.
    // Postconditions: removes and returns the largest value.
    // Heap comparisons and swaps are recorded in metrics.
    int extractMax(SortMetrics& metrics);

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

    // Preconditions: index is a valid active heap element. Heap order may
    // be violated only between that element and its parent.
    // Postconditions: restores heap order toward the root and records
    // key comparisons and swaps in metrics.
    void reheapUp(int index, SortMetrics& metrics);

    // Preconditions: index is a valid active heap element and its child
    // subtrees are already max-heaps.
    // Postconditions: restores heap order toward the leaves and records
    // key comparisons and swaps in metrics.
    void reheapDown(int index, SortMetrics& metrics);
};