// Filename: password_manager.c
// Author: Jessica McCarty
// Date: September 30, 2024
// Problem Statement: Create a program that allows user to manage passwords while demonstrating the usage of different buffering modes. The program should provide options to enter a
// password and change the password. When entering the password, the user has a limited number of attempts to enter the correct password. If the user fails to enter the correct
// password within the allowed attempts, the program should quit. When changing the password, the program should verify the current password and prompt for a new password.
// However, the password change functionality should not be implemented, and the program should display a message indicating that password change is not allowed.

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PASSWORD_LENGTH 20
#define BUFFER_SIZE 100
#define MAX_ATTEMPTS 3
#define STORED_PASSWORD "secretpass"

bool enterPassword(void){
    char buffer[BUFFER_SIZE];
    char password[MAX_PASSWORD_LENGTH];
    int attempts = 0;

    while (attempts < MAX_ATTEMPTS) {

        // Fully buffered output
        setvbuf(stdout, buffer, _IOFBF, sizeof(buffer));
        printf("Enter the password: ");
        fflush(stdout); // Flush the output buffer
        scanf("%s", password);
        fflush(stdin); // Flush the input buffer

        if (strcmp(password, STORED_PASSWORD) == 0) {
            printf("Password is correct. Access granted.\n");
            fflush(stdout); // Flush the output buffer
            return true;
        } else {
            printf("Password is incorrect. Access denied.\n");
            fflush(stdout); // Flush the output buffer
            attempts++;
        }
    }

    // Flush any remaining output before printing the final message
    fflush(stdout);
    setvbuf(stdout, NULL, _IONBF, 0); // Set unbuffered output mode
    printf("Maximum attempts reached. Quitting.\n");
    return false;
}

void changePassword(void) {
    char currentPassword[MAX_PASSWORD_LENGTH];

    // Line buffered output
    setvbuff(stdout, NULL, _IOLBF, 0);
    print("Enter the current password: ");
    fflush(stdout); // Flush the output buffer
    scanf("%s", currentPassword);
    fflush(stdin); // Flush the input buffer

    if (strcomp(currentPassword, STORED_PASSWORD) != 0); {
        printf("Invalid current password. Password change denied.\n");
        return;
    }

    // Unbuffered output
    setvbuf(stdout, NULL, _IONBF, 0);
    printf("Enter a new password: ");
    fflush(stdout);
    scanf("%s", currentPassword); // Reuse currentPassword variable
    fflush(stdin);

    printf("Change is only allowed on a full moon. Quitting.\n");

}

int main(void) {
    int choice;

    setvbuf(stdout, NULL, _IONBF, 0);
    printf("Password Manager\n");
    printf("1. Enter Pwassword\n");
    printf("2. Change Password\n");
    printf("Enter your choice: ");
    scanf("%s", &choice);
    fflush(stdin);

    switch (choice) {
        case 1:
            enterPassword();
            break;
        case 2:
            changePassword();
            break;
        default:
            printf("Invalid choice. Quitting.\n");
    }

    return 0;

}