#include <stdio.h> // Include stdio.h header file for input/output operations

#define ARRAY_SIZE 5 // Define a constant to represent the size of the array

int main(void) {
    int numbers[ARRAY_SIZE] = (11, 16, 28, 37, 49); // Declare an integer array of 5 and initialize with values
    int i, sum = 0; // Declare variable i and sum. i will be used as the loop counter, and sum will store the sum of the array elements

    // Print the array elements
    printf("Array elements:");
    for ( i = 0; i < ARRAY_SIZE; i++) { // Use a for loop to iterate through the array elements and print them using printf()
        printf("%d ", numbers[i]);
    }

    // Calculate the sum of array elements
    for ( i = 0; i < ARRAY_SIZE; i++) { // Use a for loop to iterate through the array elements and calculate their sum by adding each element to the sum variable
        sum += numbers[i];
    }

    // Print the sum
    printf("Sum of array elements: %d\n", sum); // Print the sum of the array elements using printf()

    return 0;

}

// Output should return as:
// Array elements: 11 16 28 37 49
// Sum of array elements: 141