#include "GenericArray.h"
#include <iostream>

int main() {
    GenericArray<int> intArray; // Creates a GenericArray made of integers
    intArray.addElement(10);  // Adds the  elemnts into the array
    intArray.addElement(20);
    intArray.addElement(30);
    intArray.addElement(40);
    intArray.addElement(50);

    std::cout << "Size: " << intArray.size() << std::endl; // Prints the size of the array
    std::cout << "Sum: " << intArray.sum() << std::endl; // Prints the sum of the array
    std::cout << "Max value: " << intArray.max() << std::endl;  // Print the max and min values
    std::cout << "Min value: " << intArray.min() << std::endl;

// Slice array and print results
    try { 
        int *slicedArray = intArray.slice(1, 3); // Sliceindex 1 to 3
        std::cout << "Sliced: ";
        for (int i = 0; i < 3; i++) { //3 elements in the slice (end -begin + 1)
            std::cout << slicedArray[i] << " ";
        }
        std::cout << std::endl;

        // Free the sliced array
        delete[] slicedArray;
    } catch (const std::exception &e) {
        std::cerr << "Error: "  << e.what() << std::endl;
    }

    return 0;
}
