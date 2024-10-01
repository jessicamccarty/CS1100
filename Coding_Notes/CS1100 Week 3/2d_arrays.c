#include <stdio.h> // Include stdio.h header file for input/output operations

#define ROWS 3 // Define constants to represent the numbers of rows and columns
#define COLS 4

int main() {
    int matrix[ROWS][COLS] = { // Declare a 2D integer array matrix with dimensions ROWS x COLS and initialize it with values
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Print the 2D array
    for ( int i = 0; i < ROWS; i++) { // Use nester loops to iterate over the rows and columns of the 2D array.The outer loop iterates over the rows using the variable i.
        for (int j = 0; j < COLS; j++) { // The inner loop iterates over the oclumns using the variable j. 
            printf("%d ", matrix[i][j]); // Inside the nested loops, we print each element of the 2D array using printf() and the indices i and j to acces the elements.
        }                                
        printf("\n"); // After each row is printed we move to the next line using printf("\n")
    }

    return 0;
}

// The output should be:
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12