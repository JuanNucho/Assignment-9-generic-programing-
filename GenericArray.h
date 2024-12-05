#ifndef GENERICARRAY_H
#define GENERICARRAY_H

#include <iostream>
#include <stdexcept>

template <typename T>
class GenericArray {
private:
    T *data; //pointer for the array elements
    int capacity; // Amount of elements in array

public:
    GenericArray() { // Constructor for nitializing an empty array
        data = nullptr;
        capacity = 0;
    }

    ~GenericArray() { // Destructor to free ujp the allocated memory
        delete[] data;
    }
    void addElement(T element) { // Adds element to the end of the array
        T *newData = new T[capacity + 1]; // create new array with +1 capacity
        for (int i = 0; i < capacity; i++ ) { // Copy ol elements into the new array
            newData[i] = data[i];
        }

        newData[capacity] = element; // Add new element to the end
        delete[] data; // Delete the old array and update pointer
        data = newData;
        capacity++; // Increase capacity
    }
    T at(int index) const { // Access elements by its index
        if (index < 0 || index >= capacity) {
            throw std::out_of_range("OUT OF BOUNDS!");
        }
        return data[index];
    }



    int size() const { // Gets size of array
        return capacity;
    }

    T sum() const { // Calculate the sum of elemebts
        T total = 0;
        for ( int i = 0; i  < capacity; i++) {
            total += data[i];
        }
        return total;
    }

   
    T max() const {  // Find max value
        if (capacity == 0) {
            throw std::runtime_error("ARRAY IS EMPTY!");
        }
        T maxValue = data[0];
        for (int i = 1; i < capacity; i++) {
            if (data[i] > maxValue) {
                maxValue = data[i];
            }
        }
        return maxValue;
    }

    T min() const { // Find min value
        if (capacity == 0) {
            throw std::runtime_error("ARRAY IS EMPTY!");
        }
        T minValue = data[0];
        for (int i = 1; i <  capacity; i++) {
            if (data[i] < minValue) {
                minValue = data[i];
            }
        }
        return minValue;
    }

    
    T *slice(int begin, int end) const { // Creates new array  sliced from the first array
        if (begin < 0 || end >= capacity || begin > end) {
            throw std::out_of_range("OUT OF RANGE");
        }

        int newSize = end - begin + 1;
        T *slicedArray = new T[newSize];

        for (int i = 0; i < newSize; i++) {
            slicedArray[i] = data[begin + i];
        }

        return slicedArray;
    }
};
#endif