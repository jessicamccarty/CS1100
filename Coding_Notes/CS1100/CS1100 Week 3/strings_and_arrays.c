// Class Notes
// September 17, 2024
// Strings and Arrays

// An array is....

#include <stdio.h>
#include <stdlib.h>

// Declare array of int
// int int_array1[16];

// Declare array of float
// float float_array1[16];

// Array declarations with initializer lists
int fibnums[8] = { 1, 1, 2, 3, 5, 8, 13, 21 };

// Access array members by indec (counting from zero)
int first_fibnum = fibnums[0];
int fifth_fibnum = fibnums[4];
int fib_index; 
{
    for (fib_index = 0; fib_index < 8; fib_index++) 
    {
        printf("fibnums[%d] = %d\n", fib_index, fibnums[fib_index]);
    }
}
// NOT COMPILING. FIGURE OUT PROBLEM. 




// Strings

// A string in C programming is a sequence of characters terminated with a null character '\0'. The string is stored as an array of characters.
// The difference between a character array and a C string is that the string in C is terminated with a unique character '\0'.

// Declare a string as an empty array
// Single quotes in c is for wrapping a single character.
char string1[6]; = {'H', 'e', 'l', 'l', 'o', '\0'};
// Can input as many characters as you want but only 5 will show. 
// Best practice is to use final slot for null terminator. 
// Set null terminator to keep program frrom crashing. 

// Why declare the number if we are going to null terminate? Syntax not typically used. Just shown for example.

// Initialize 'char' array with string literal
char string2[6] = "Hello";
char string3[] = "Hello"; // Most typical way to input. 

// Manipulate juust like any array

int string_index = 0;

while (string3[string_index] != "\0")
{
    printf("%c\n", string3[string_index]);
    ++string_index;
}

// Buffering
char file_path_buf[4096];





// POINTERS
// Store the memory address of another variable 
// Reference information without having to recall it fully


// Declare a point to an 'int'
int *x_pointer;

// Take the address of another variable and assign to a pointer
int x = 42;
x_pointer = &x;

// Dereference the value from the pointer
int y = *x_pointer;

// Pointer arithmetic with an array

char qwerty[] = "QWERTY";
char *qwerty_ptr = &qwerty[0];

while (*qwerty_ptr != '\0')
{
    printf("%c\n", *qwerty_ptr);
    ++qwerty_ptr;
}

return 0;