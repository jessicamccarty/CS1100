// Filename: string_processing_wizard.c
// Author: Jessica McCarty
// Date: September 26, 2024
// Create a program that demonstrates various string manipulation techniques using pointer aritmetic in C. It hsould take a string as a command-line argument and provide a menu-based
// interface for the user to perform different string processing operations. The program should utilize command-line arguments, switch statements, do-while loops, symbolic constants, and
// the fgets(), toupper(), and atoi() functions to implement its functionality.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Definitions
#define MAX_INPUT_SIZE 100
#define PALINDROME_FOUND 1
#define PALINDROME_NOT_FOUND 0

// Function prototypes
void countCharacters(char *str);
void reverseString(char *str);
void convertToUppercase(char *str);
int checkPalindrome(char *str);
void countOccurences(char *str);



int main(int argc, char *argv[]) {
    // Check command-line argument
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    // Make argument into variable
    char inputString[MAX_INPUT_SIZE];
    strncpy(inputString, argv[1], MAX_INPUT_SIZE -1);
    inputString[MAX_INPUT_SIZE - 1] = '\0'; // Null-termination

    int choice; // Menu selection variable
    do {
        // Menu options
        printf("\nString Processing Tool\n");
        printf("1. Count characters\n");
        printf("2. Reverse string\n"); 
        printf("3. Convert to uppercase\n"); 
        printf("4. Check palindrome\n"); 
        printf("5. Count occurrences of a character\n");
        printf("6. Exit\n");
        printf("Enter your input_selection: ");

        // Read selection
        char buffer[10];
        fgets(buffer, sizeof(buffer), stdin);
        choice = atoi(buffer); // Convert string input to integer

        // User input switch
        switch (choice) {
            case 1:
                countCharacters(inputString);
                break;
            case 2:
                reverseString(inputString);
                break;
            case 3:
                convertToUppercase(inputString);
                break;
            case 4:
                if (checkPalindrome(inputString) == PALINDROME_FOUND)
                    printf("%s is a palindrome\n", inputString);
                else
                    printf("%s is not a palindrome\n", inputString);
                    break;
            case 5:
                countOccurences(inputString);
                while(getchar() !='\n'); // TERMINATED INPUT TO FIX ERROR
                break;
            case 6:
                printf("Exiting the program.\n"); // Final test with 5/t/6 as inputs is giving incorrect output in grader but works properly when running the code. CORRECTED
                return 0; // Attempted to run with "break;" instead of "return 0;", no change in grader.
            default:
                printf("Invalid selection. Please try again.\n"); 
        } 

        if (choice != 6) {
            printf("Press Enter to continue...");
            fgets(buffer, sizeof(buffer), stdin);
        }
    
    } while (choice != 6); // Repeat until user chooses to exit

    return 0; // Exit
}

// Function to count characters
void countCharacters(char *str) {
    int count = 0;
    while (*(str + count) != '\0') {
        count++;
    }
    printf("Number of characters: %d\n", count);
}

// Function to reverse string
void reverseString(char *str) {
    int length = strlen(str); // Get length of string
    printf("Reversed string: ");
    for (int i = length -1; i >= 0; i--) { // Print in reverse
        putchar(*(str + i));
    }
    putchar('\n'); // New line
}

// Function to convert to uppercase
void convertToUppercase(char *str) {
    char upperStr[MAX_INPUT_SIZE]; // Array to hold uppercase string
    for (int i = 0; *(str + i) != '\0'; i++) {
        upperStr[i] = toupper(*(str + i)); // Convert each character to uppercase
    }
    upperStr[strlen(str)] = '\0'; // Null-terminate the uppercase string
    printf("Uppercase string: %s\n", upperStr);
}

// Function to check for palindrome
int checkPalindrome(char *str) {
    int length = strlen(str); // Get length of string
    for (int i = 0; i < length / 2; i++) { // Compare characters from both ends
        if (*(str + i) != *(str + length - 1 - i)) {
            return PALINDROME_NOT_FOUND; // Not a palaindrome
        }
    }
    return PALINDROME_FOUND; // Is a palindrome
}

// Function to count occurences of a character
void countOccurences(char *str) {
    char ch;
    printf("Enter a character to count: ");
    scanf(" %c", &ch);

    int count = 0;
    for (int i = 0; *(str + i) != '\0'; i++) {
        if (*(str + i) == ch) {
            count++;
        }
    }
    printf("Occurrences of '%c': %d\n", ch, count);
}
