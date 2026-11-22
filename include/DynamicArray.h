#pragma once

class DynamicArray
{
public:
    // Preconditions: initialCapacity >= 0.
    // Postconditions: the array is empty and can hold at least initialCapacity elements.
    explicit DynamicArray(int initialCapacity = 0);

    // Postconditions: this array owns an independent copy of other.
    DynamicArray(const DynamicArray& other);

    // Postconditions: the array's owned storage is released.
    ~DynamicArray();

    // Postconditions: this array is an independent copy of other.
    // Self-assignment leaves the array unchanged.
    DynamicArray& operator=(const DynamicArray& other);

    // Postconditions: value is appended and size increases by one.
    void append(int value);

    // Preconditions: 0 <= index < size().
    // Postconditions: the array is unchanged; throws std::out_of_range if the index is invalid.
    int get(int index) const;

    // Preconditions: 0 <= index < size().
    // Postconditions: the element at index is value; throws std::out_of_range if invalid.
    void set(int index, int value);

    // Postconditions: returns the number of stored elements without modifying the array.
    int size() const noexcept;

    // Postconditions: returns the number of allocated element slots without modifying the array.
    int capacity() const noexcept;

private:
    int* elements;
    int currentSize;
    int currentCapacity;

    // Ensures at least requiredCapacity slots, growing geometrically when necessary.
    void ensureCapacity(int requiredCapacity);
};
