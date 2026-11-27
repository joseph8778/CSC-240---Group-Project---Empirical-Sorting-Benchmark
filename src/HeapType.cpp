#include "HeapType.h"
#include "SortMetrics.h"

void HeapType::reheapUp(int index, SortMetrics& metrics)
{
    while (index > 0)
    {
        const int parent = parentIndex(index);
        const int value = elements.get(index);
        const int parentValue = elements.get(parent);

        metrics.recordComparison();
        if (parentValue >= value)
        {
            break;
        }

        elements.set(parent, value);
        elements.set(index, parentValue);
        metrics.recordSwap();
        index = parent;
    }
}

void HeapType::reheapDown(int index, SortMetrics& metrics)
{
    while (hasLeftChild(index))
    {
        int largerChild = leftChildIndex(index);
        if (hasRightChild(index))
        {
            const int right = rightChildIndex(index);

            metrics.recordComparison();
            if (elements.get(right) > elements.get(largerChild))
            {
                largerChild = right;
            }
        }

        const int value = elements.get(index);
        const int childValue = elements.get(largerChild);

        metrics.recordComparison();
        if (value >= childValue)
        {
            break;
        }

        elements.set(index, childValue);
        elements.set(largerChild, value);
        metrics.recordSwap();
        index = largerChild;
    }
}