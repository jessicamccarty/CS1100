// Filename: matric_logic.c
// Requirements:
// User only your knowledge of scanf(), printf(), if/else statements, do/while loops, and logical operators to implement this program.
// Display a welcome message to introduce the user to the "Matric of Logic" game.
// Present the user with a menu of choices: red pill (which user can select with r), blue pill (selectable with b), white pill (selectable with w), or black pill (selectable with
// k). Prompt the user to enter their choice.
// Generate random binary values (0 or 1) for two variables, p and q, using a suitable random number generator.
// Display the generated binary values for p and q to the user. 
// Based on the user's pill choice, demonstrate the corresponding logical operation:
// Red pill: Logical AND (&&) operation between p and q.
// Blue pill: Logical XOR (^) operation between p and q.
// White pill: Logical OR (||) operation between p and q. 
// Black pill: Logical NOT (!) operation on both p and q.
// Display the result of the logicl operation to the user.
// Allow the user to keep playing the game by presenting the menu of chocies again until the user chooses to quit by selecting q or Q.
// Display a message to confirm that the user has chosen to quit the game.
// Implemenet appropriate input validation to handle invalid pill coices and display an error message if the user enters an invalid choice.
// Use meaningful variable names and include comments to enhance the readability an error message if the user enters an invalid choice.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char choice;
    int p, q;

    // Seed random number generator
    srand(time(NULL));

    // Welcome message
    printf("Welcome to the Matric of Logic!\n");

    do {
        //Display choices
        printf("You have a chocie to make:\n");
        printf("Take the red pill (r), blue pill (b), white pill (w), or black pill (k): ");
        scanf(" %c", &choice);

        // Generate random binary value for p and q
        p = rand() % 2; // Randomly generates 0 or 1
        q = rand() % 2; // Randomly generates 0 or 1
        printf("Binary dice roll: p = %d, q = %d\n", p, q);

        // Execute logic based on the user's choice
        if (choice == 'r') {
            printf("You took the red pill. Demonstrating LOGICAL AND: %d && %d - %d\n", p, q, p && q);
        } else if ( choice == 'b') {
            printf("You took the blue pill. Demonstrating LOGICAL XOR: %d ^ %d = %d\n", p, q, p ^ q);
        } else if ( choice == 'w') {
            printf("You took the white pill. Demonstrating LOGICAL OR: %d || %d = %d\n", p, q, p || q);
        } else if ( choice == 'k') {
            printf("You took the black pill. Demonstrating LOGICAL NOT: !%d and !%d = %d\n", p, !p, q, !q);
        } else if ( choice == 'q') {
            printf("Quitting!\n");
            break; // Exit the loop
        } else {
            printf("Invalid choice! Please try again.\n");
        }
        
    } while (1); // Continue until the user chooses to quit

    return
    
}