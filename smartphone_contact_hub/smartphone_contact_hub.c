// Filename: smartphone_contact_hub.c
// Author: Jessica McCarty
// Date: September 30, 2024

#include <stdio.h>

// Define Constants
#define MAX_CONTACTS 100
#define MAX_CONTACT_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 15
#define MAX_EMAIL_ADDRESS_LENGTH 50

// Hold contact info
typedef struct {
    char name[MAX_CONTACT_NAME_LENGTH];
    char phone[MAX_PHONE_NUMBER_LENGTH];
    char email[MAX_EMAIL_ADDRESS_LENGTH];
} Contact;

// Function prototypes
int loadContacts(Contact contacts[], const char *filename);
void displayContacts(Contact contacts[], int contactCount);
void selectContact(Contact contacts[], int contactCount);
void callContact(const Contact *contact);
void sendemail(const Contact *contact);

int main() {
    Contact contacts[MAX_CONTACTS];
    int contactCount = 0;
    int userInput;

    // Load CSV file
    contactCount = loadContacts(contacts, "phone_contacts.csv");
    if (contactCount == -1) {
        printf("Error opening phone contacts file.\n");
        return 1;
    }

    do {
        printf("\nSmartphone Contact Hub\n");
        printf("1. List Contacts\n");
        printf("2. Select Contact\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &userInput);

        switch (userInput) {
            case 1:
                displayContacts(contacts, countactCount);
                break;
            case 2:
                selectContact(contacts, contactCount);
                break;
            case 3:
                printf("Exiting the Smartphone Contact Hub.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (userInput != 3);
    
    return 0;selectContact
}