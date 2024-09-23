// Filename: password_guesser.c
// Problem Statement: In many secure systems, access is controlled through password verification. The program should prompt the user to enter a password and check if the entered
// password matches either a primary stored password or an alternate password. If the entered password is valid, the program should grant access and simulate a system startup
// sequence. If the entered password is invalid, the program should display and error message and exit.
// Requirements:
// 1. The program should simulate a password-based access control system.
// 2. The user should be prompted to enter a password.
// 3. The program should check if the entered password matches either the stored password or an alternate password.
// 4. If the entered password is valid, the program should grant access and simulate an OS startup sequence.
// 5. If the entered password is invalid, the program should display and error message and exit.

#include <stdio.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20

int main(void) {
    char userPassword[MAX_PASSWORD_LENGTH];
    char *storedPassword = "password123";
    char *alternatePassword = "alternate789";
    char *message;

    // Input: Prompt the user to enter a password
    printf("Enter the password: ");
    scanf("%s", userPassword);

    // Processing: Check if the entered password matches either the stored password or the alternate password
    int isValid = (strcmp(userPassword, storedPassword) == 0 || strcmp(userPassword, alternatePassword) == 0) ? 1 : 0;

    // Output: Display a message basaed on the password validity
    message = isValid ? "Access granted. Starting OS..." : "Invalid password. Exiting...";
    printf("%s\n", message);

    // Output: Simulate OS startup sequence if access is granted
    if (isValid) {
        printf("OS startup sequence initiated.\n");
        printf("Loading system components...\n");
        printf("System ready.\n");
    }

    return 0;

}