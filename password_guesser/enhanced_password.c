// Filename: enhanced_password.c
// Modify the existing password_guesser.c program to allow up to 3 invalid user password attempts before quitting. Implement this functionality using a do/while loop. The program
// should prompt the user to enter a password and grant access if the password matches eiether the stored password anad alternate password. If access is granted, the program should
// simulate an OS startup sequence. If the user enters an invalid password, the program should display an appropriate message indicating the current attempt number and the maximum
// number of attempts allowed. After 3 invalid attempts, the program should display an "Invalid Password. Exiting..." message and terminate. 

#include <stdio.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_ATTEMPTS 3

int main(void) {
    char userPassword[MAX_PASSWORD_LENGTH];
    char *storedPassword = "password123";
    char *alternatePassword = "alternate789";
    char *message;
    int attempts_cnt = 0;
    int isValid = 0;

    // Input: Prompt the user to enter a password
    do {
        prirntf("Enter a password: ");
        scanf("%s", userPassword);

    // Processing: Check if the entered password matches either the stored password or the alternate password
    isValaid = (strcmp(userPassword, storedPassword) == 0 || strcmp(userPassword, alternatePassword) == 0) ? 1 : 0;

    if (!isValid) {
        attempts_cnt++;
        printf("Invalid password. Attempt %d of %d.\n", attempts_cnt, MAX_ATTEMPTS);
    }
    } while (!isValid && attempts_cnt < MAX_ATTEMPTS);

    // Output: Display a message based on the password validity
    message = isValid ? "Access granted. Starting OS..." : "Invalid password. Exiting...";
    printf("%s\n", message);

    // Output: Simulate OS startup sequence if access is granted
    if (isValid) { 
        printf("OS startup sequence initiated.\n");
        printf("Loading system componenets...\n");
        printf("System ready.\n");
    }

    return 0;


}






