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
        scaf("%d", &userInput);

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
    
    return 0;
}

// Load contacts
int loadContacts(Contact contacts[], const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return -1; // Open file error
    }

    int i = 0;
    while (fscanf(file, "%[^,],%[^,],%s\n", contacts[i].name, contacts[i].phone, contacts[i].email) != EOF) {
        i++;
        if (i >= MAX_CONTACTS) {
            break;
        }
    }

    fclose(file);
    return i; // Return number of contacts loaded
}

// List all contacts
void listContacts(Contact contacts[], int contactCount) {
    printf("\nPhone Contacts:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d. Name: %s\n   Phone: %s\n   Email: %s\n", i + 1, contacts[i].name, contacts[i].phone, contacts[i].email);
    }
}

// Select a contact and perform actions
void selectContact(Contact contacts[], int contactCount) {
    int index;
    printf("Enter the contact index: ");
    scanf("%d", &index);

    if (index < 1 || index > contactCount) {
        printf("Invalid contact index. Please try again.\n");
        return;
    }

    Contact selectedContact = contacts[index - 1];
    printf("\nSelected Contact:\n");
    printf("Name: %s\nPhone: %s\nEmail: %s\n", selectedContact.name, selectedContact.phone, selectedContact.email);

    performAction(selectedContact);
}

// Perform an action on a selected contact
void performAction(Contact contact) {
    int action;
    printf("\nWhat would you like to do?\n");
    printf("1. Call\n2. Send Email\n");
    printf("Enter your choice: ");
    scanf("%d", &action);

    if (action == 1) {
        printf("Calling %s...\n", contact.name);
    } else if (action == 2) {
        printf("Sending email to %s...\n", contact.email);
    } else {
        printf("Invalid choice.\n");
    }
}