// Filename: animal_id.c
// Problem Statement: Create a program that prompts the user to enter an animal name and determines whether the entered animal is a canine, feline, or rodent. The program should
// continue to prompt the user for animal names until the user enters exit to quit the program. The program should provide appropriate output messages indicating the category of
// the animal or if the animal does not belong to any of the specific categories.
// Requirements: 
// 1. The program should have predefined arrays of animal names for canines, felines, and rodents.
// 2. The program should prompt the user to enter an animal name.
// 3. The program should compare the user input with the predefined animal names to determine the category of the animal.
// 4. The program should output the matching array.
// 5. If the entered animal is not found in any of the arrays, the program should put that the animal is not a canine, feline, or rodent.
// 6. The program should use a do/while loop to repeatedly prompt the user for input until the exit condition is met.
// 7. The program should use logical operators and the sizeof operator to determine the number of elements in each animal array.
// 8. The program should use string comaprison functions to compare the user input with the predefined animal names.

#include <stdio.h>
#include <string.h>

#define ANIMAL_FOUND 1
#define ANIMAL_NOT_FOUND 0

int main() {

    // Define arrays of animal names for each category
    char *canines[] = {"dog", "wolf", "fox", "coyote"};
    char *felines[] = {"cat", "lion", "tiger", "leopard"};
    char *rodents[] = {"mouse", "rat", "squirrel", "hamster"};

    // Calculate the number of elements in each array using sizeof operator
    int numCanines = sizeof(canines) / sizeof(canines[0]);
    int numFelines = sizeof(felines) / sizeof(felines[0]);
    int numRodents = sizeof(rodents) / sizeof(rodents[0]);

    // Declare a character array to store the user input
    char animalName[20];

    // Start a do/while loop to repeatedly prompt the user for input
    do {

        // Prompt the user to enter an animal name or 'exit' to quit
        printf("\nEnter an animal name (or 'exit' to quit): ");
        scanf("%s", animalName);

        // Check if the user entered 'exit' to quit the program
        if (strcmp(animalName, "exit") == 0) {
            break;
        }

        // Initialize a flag to track if the animal is found in any category
        int found = ANIMAL_NOT_FOUND;

        // Check if the animal is a canine
        for ( int i = 0; i < numCanines; i++) {
            if (strcmp(animalName, canines[i]) == 0) {
                printf("%s is a canine. \n", animalName);
                found = ANIMAL_FOUND;
                break;
            }
        }

        // Check if the animal is a feline if not found in canines
        if (found == ANIMAL_NOT_FOUND) {
            for (int i = 0; i < numFelines; i++) {
                if (strcmp(animalName, felines[i]) == 0) {
                    printf("%s is a feline.\n", animalName);
                    found = ANIMAL_FOUND;
                    break;
                }
            }
        }

        // Check if the animal is a rodent if not found in canines or felines
        if (found == ANIMAL_NOT_FOUND) {
            for ( int i = 0; i < numRodents; i++) {
                if (strcmp(animalName, rodents[i]) == 0) {
                    printf("%s is a rodent.\n", animalName);
                    found = ANIMAL_FOUND;
                    break;
                }
            }
        }

        // If the animal is not found in any category, print a message
        if (found == ANIMAL_NOT_FOUND) {
            printf("%s is not a canine, feline, or rodent.\n", animalName);
        }
    
    } while (1);

    // Print a message when the user chooses to exit the program.
    printf("Exiting the program.\n");

    return 0;

}


