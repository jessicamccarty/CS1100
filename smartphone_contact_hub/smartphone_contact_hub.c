// Filename: smartphone_contact_hub.c
// Author: Jessica McCarty
// Date: October 2, 2024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Constants
#define MAX_CONTACTS 100
#define MAX_CONTACT_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 15
#define MAX_EMAIL_ADDRESS_LENGTH 50

// Data Structures
char contactNames[MAX_CONTACTS][MAX_CONTACT_NAME_LENGTH];
char contactPhones[MAX_CONTACTS][MAX_PHONE_NUMBER_LENGTH];
char contactEmails[MAX_CONTACTS][MAX_EMAIL_ADDRESS_LENGTH];
int contactCount = 0;

// Function prototypes
void readContactsFromFile();
void displayMenu();
void listContacts();
void selectContact();

// Read CSV File
void readContactsFromFile() {
    FILE *file = fopen("phone_contacts.csv", "r");
    if (file == NULL) {
        printf("Error opening phone contacts file.\n");
        return;
    }
    while (fscanf(file, "%49[^,],%14[^,],%49[^\n]\n", contactNames[contactCount], contactPhones[contactCount], contactEmails[contactCount]) == 3) {
        contactCount++;
    }

    fclose(file);
}

// Menu Interface
void displayMenu() {
    int menuChoice;

    do {
        printf("Smartphone Contact Hub\n");
        printf("1. List Contacts\n");
        printf("2. Select Contact\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &menuChoice);

        switch (menuChoice) {
            case 1:
                listContacts();
                break;
            case 2:
                selectContact();
                break;
            case 3:
                printf("Exiting the Smartphone Contact Hub.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");       
        }
    } while (menuChoice != 3);
}

// List Contacts Function
void listContacts() {
    printf("Phone Contacts:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d. Name: %s\n   Phone: %s\n   Email: %s\n\n", i + 1, contactNames[i], contactPhones[i], contactEmails[i]);
    }
}

// Select Contact Function
void selectContact() {
    int index;

    printf("Enter the contact index: ");
    scanf("%d", &index);

    if (index <1 || index >contactCount) {
        printf("Invalid contact index.\n");
        return;
    }

    index--; // Adjust to 0-based index
    printf("Selected Contact:\n");
    printf("Name: %s\nPhone: %s\nEmail: %s\n", contactNames[index], contactPhones[index], contactEmails[index]);

    int action;
    printf("What would you like to do?\n1. Call\n2. Send Email\n");
    printf("Enter your choice: ");
    scanf("%d", &action);

    if (action == 1) {
        printf("Calling %s...\n", contactNames[index]);
    } else if (action == 2) {
        printf("Sending email to %s...\n", contactEmails[index]);
    } else {
        printf("Invalid action. Please try again.\n");
    }
}

// Main Function
int main() {
    readContactsFromFile();
    if (contactCount == 0) {
        return 1; // Error opening file
    }
    displayMenu();
    return 0;
}
