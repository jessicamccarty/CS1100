


// Include necessary header files
#include <stdio.h>   // Provides input/output functions
#include <string.h>  // Provides string manipulation functions

// Define constants for clothing item prices using macros
#define SHIRT_PRICE 19.99
#define SHOE_PRICE 49.99
#define PANTS_PRICE 29.99

// Define shipping costs
#define USA_STANDARD_SHIPPING 5.99
#define USE_EXPEDITED_SHIPPING 9.99
#define MEXICO_STANDARD_SHIPPING 7.99
#define MEXICO_EXPEDIATED_SHIPPING 12.99
#define CANADA_STANDARD_SHIPPING 6.99
#define CANADA_EXPEDITED_SHIPPING 11.99

// Define tax rates
#define USA_TAX_RATE 0.08
#define MEXICO_TAX_RATE 0.16
#define CANADA_TAX_RATE 0.12


int main(void) {
    // Declare variables
    char userInput[20];  // Array to store user input for clothing type
    int shirtQuantity = 0, shoeQuantity = 0, pantsQuantity = 0;  // Variables to store quantities of each clothing item
    float subtotal = 0.0, shipping_cost = 0.0, tax = 0.0, total_cost = 0.0;  // Variables to store total costs
    
    do {
        // Display menu options to the user
        printf("Enter the type of clothing needed (shirt, shoes, pants).\n");
        printf("Type 'exit' to quit and calculate the total cost.\n");

        // Read user input for clothing type
        scanf("%s", userInput);

        // Check user input and prompt for quantity based on clothing type  CHANGE TO SWITCH STATEMENT TO MEET ASSIGNMENT REQUIREMENTS
       
switch (expression)
{
case /* constant-expression */:
    /* code */
    break;

default:
    break;
}       
        
switch (expression)
{
case 's':
    if (strcmp(userInput, "shirt") == 0) {
            printf("Enter the quantity of shirts needed: ");
            scanf("%d", &shirtQuantity);
    }
    break;

case 'h':
    else if (strcmp(userInput, "shoes") == 0) {
            printf("Enter the quantity of shoes needed: ");
            scanf("%d", &shoeQuantity);
    }
    break;

case 'p':
    else if (strcmp(userInput, "pants") == 0) {
            printf("Enter the quantity of pants needed: ");
            scanf("%d", &pantsQuantity);
    }
    break;

default:
    printf("Invalid clothing type. Please enter 'shirt', 'shoes', or 'pants'.\n");
    break;
}

        // If user input is not 'exit', display a success message for adding the clothing item
        if (strcmp(userInput, "exit") != 0) {
            printf("Clothing item '%s' added successfully.\n", userInput);
        }
    } while (strcmp(userInput, "exit") != 0);  // Repeat the loop until user enters 'exit'

    // Calculate subtotal
    subtotal = (shirtQuantity * SHIRT_PRICE) + (shoeQuantity * SHOE_PRICE) + (pantsQuantity * PANTS_PRICE);

    // Prompt for shipping destination and method
    printf("Enter the shipping destination (USA, Mexico, Canada): ");
    scanf("%s", destination);
    printf("Enter the shipping method (standard, expedited): ");
    scanf("%s", method);


    // Calculate shipping cost FINISH THIS
    if (strcasecmp(destination, "usa") == 0) {
        shipping_cost = (strcasecmp(method, "standard") == 0)  
    } else if (strcasecmp(destination, "mexico") == 0) {
        shipping_cost = (strcasecmp(method, "standard") == 0)
    } else (strcasecmp(destination, "canada") == 0) {
        shipping_cost = (strcasecmp(method, "canada" == 0))
    }

    // Calculate tax
    if (strcasecmp(destination, "usa") == 0) {
        tax = subtotal * USA_TAX_RATE
    }
    else if (strcasecmp(destination, "mexico") == 0) {
        tax = subtotal * MEXICO_TAX_RATE
    }
    else if (strcasecmp(destination, "canada") == 0) {
        tax = subtotal * CANADA_TAX_RATE
    } 
    

    // Calculate total cost
    float total_cost = subtotal + shipping_cost + tax;


    // Display the formatted bill
    printf("\nClothing Item\tQuantity\tPrice\t\tTotal\n");
    printf("-------------------------------------------------------\n");
    printf("Shirts\t\t%d\t\t$%.2f\t\t$%.2f\n", shirtQuantity, SHIRT_PRICE, shirtQuantity * SHIRT_PRICE);
    printf("Shoes\t\t%d\t\t$%.2f\t\t$%.2f\n", shoeQuantity, SHOE_PRICE, shoeQuantity * SHOE_PRICE);
    printf("Pants\t\t%d\t\t$%.2f\t\t$%.2f\n", pantsQuantity, PANTS_PRICE, pantsQuantity * PANTS_PRICE);
    printf("-------------------------------------------------------\n");
    printf("Subtotal:\t\t\t\t\t$%.2f\n", subtotal);
    printf("Shipping Destination: \n");
    printf("Shipping Method: \n");
    printf("Shipping Cost:\t\t\t\t\t$%.2f\n", shipping_cost);
    printf("Tax (%%):\t\t\t\t\t$%.2f\n", tax);
    printf("-------------------------------------------------------\n");
    printf("Total Cost (including tax and shipping):\t\t\t\t\t$%.2f\n", total_cost);

    return 0;  // Indicate successful program execution
}



