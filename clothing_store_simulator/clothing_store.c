/*
 * File: clothing_store_simulator.c
 *
 * Description:
 *   This program simulates a clothing store experience where the user can interactively
 *   select clothing items (shirts, shoes, or pants) and specify the quantity of each item
 *   they want to purchase. The program continuously prompts the user to enter the clothing
 *   type and quantity until the user chooses to exit. Upon exiting, the program calculates
 *   the total cost of the selected items based on predefined prices and displays a formatted
 *   bill showing the quantity, price, and total cost for each clothing item, along with the
 *   overall total cost.
 *
 * Features:
 *   - Interactive menu-based interface for selecting clothing items and quantities
 *   - Supports three clothing types: shirts, shoes, and pants
 *   - Predefined prices for each clothing type
 *   - Validates user input for clothing type and handles invalid inputs
 *   - Calculates the total cost based on the selected quantities and predefined prices
 *   - Displays a formatted bill with detailed information for each clothing item and the total cost
 *
 * Usage:
 *   1. Run the program.
 *   2. Enter the desired clothing type (shirt, shoes, or pants) when prompted.
 *   3. Enter the quantity for the selected clothing type when prompted.
 *   4. Repeat steps 2-3 to add more clothing items as needed.
 *   5. Enter 'exit' when prompted to quit the program and view the generated bill.
 *
 * Author: Jessica McCarty
 * Date: September 21, 2024
 */

// Include necessary header files
#include <stdio.h>   // Provides input/output functions
#include <string.h>  // Provides string manipulation functions
#include <stdlib.h>
#include <ctype.h>

// Define constants for clothing item prices using macros
#define SHIRT_PRICE 19.99
#define SHOE_PRICE 49.99
#define PANTS_PRICE 29.99

// Define shipping costs
#define USA_STANDARD_SHIPPING 5.99
#define USA_EXPEDITED_SHIPPING 9.99
#define MEXICO_STANDARD_SHIPPING 7.99
#define MEXICO_EXPEDITED_SHIPPING 12.99
#define CANADA_STANDARD_SHIPPING 6.99
#define CANADA_EXPEDITED_SHIPPING 11.99

// Define tax rates
#define USA_TAX_RATE 0.08
#define MEXICO_TAX_RATE 0.16
#define CANADA_TAX_RATE 0.12


int main(void) {
    // Declare variables
    char userInput[20];  // Array to store user input for clothing type
    char destination[20], method[20]; // Shipping variables
    // char method_print[20], destination_print[20];
    int shirtQuantity = 0, shoeQuantity = 0, pantsQuantity = 0;  // Variables to store quantities of each clothing item
    float subtotal = 0.0, shipping_cost = 0.0, tax = 0.0, total_cost = 0.0, taxValue = 0.0;  // Variables to store total costs
    
    do {
        // Display menu options to the user
        printf("Enter the type of clothing needed (shirt, shoes, pants).\n");
        printf("Type 'exit' to quit and proceed to shipping details.\n");

        // Read user input for clothing type
        scanf("%s", userInput);

        // Check for exit condition first
        if (strcmp(userInput, "exit") == 0) {
            break; // Exit the loop if user inputs "exit"
    }

        // // Check user input and prompt for quantity based on clothing type  CHANGE TO SWITCH STATEMENT TO MEET ASSIGNMENT REQUIREMENTS
        // if (strcmp(userInput, "shirt") == 0) {
        //     printf("Enter the quantity of shirts needed: ");
        //     scanf("%d", &shirtQuantity);
        // } else if (strcmp(userInput, "shoes") == 0) {
        //     printf("Enter the quantity of shoes needed: ");
        //     scanf("%d", &shoeQuantity);
        // } else if (strcmp(userInput, "pants") == 0) {
        //     printf("Enter the quantity of pants needed: ");
        //     scanf("%d", &pantsQuantity);
        // } else if (strcmp(userInput, "exit") != 0) {
        //     // If user input is not a valid clothing type or 'exit', display an error message and continue the loop
        //     printf("Invalid clothing type. Please enter 'shirt', 'shoes', or 'pants'.\n");
        //     continue;
        // }

        // Determine clothing type using switch statement
        switch (userInput[2])
        {
        case 'i':
            if (strcmp(userInput, "shirt") == 0) {
                printf("Enter the quantity of shirts needed: ");
                scanf("%d", &shirtQuantity);
                printf("Clothing item '%s' successfully added to your cart.\n", userInput);
            } else {
                printf("Invalid clothing type. Please enter 'shirt', 'shoes', or 'pants'.\n");
            }
                break;
        case 'o':
            if (strcmp(userInput, "shoes") == 0) {
                printf("Enter the quantity of shoes needed: ");
                scanf("%d", &shoeQuantity);
                printf("Clothing item '%s' successfully added to your cart.\n", userInput);
            } else {
                printf("Invalid clothing type. Please enter 'shirt', 'shoes', or 'pants'.\n");
            }
                break;
        case 'n':
            if (strcmp(userInput, "pants") == 0) {
                printf("Enter the quantity of pants needed: ");
                scanf("%d", &pantsQuantity);
                printf("Clothing item '%s' successfully added to your cart.\n", userInput);
            } else {
                printf("Invalid clothing type. Please enter 'shirt', 'shoes', or 'pants'.\n");
            }
                break;

        default:
            printf("Invalid clothing type. Please enter 'shirt', 'shoes', or 'pants'.\n");
            break;
        }
     } while (strcmp(userInput, "exit") != 0); // Loop until 'exit' is entered

    //     // If user input is not 'exit', display a success message for adding the clothing item
    //     if (strcmp(userInput, "exit") != 0) {
    //         printf("Clothing item '%s' successfully added to your cart.\n", userInput);
    //     }
    

    // Calculate subtotal
    subtotal = (shirtQuantity * SHIRT_PRICE) + (shoeQuantity * SHOE_PRICE) + (pantsQuantity * PANTS_PRICE);

    // // Prompt for shipping destination and method
    // printf("\nEnter the shipping destination (USA, Mexico, Canada): ");
    // scanf("%s", destination);
    // printf("Enter the shipping method (Standard, Expedited): ");
    // scanf("%s", method);


    // // Calculate shipping cost FINISH THIS
    // if (strcasecmp(destination, "USA") == 0) {
    //     shipping_cost = (strcasecmp(method, "standard") == 0) ? USA_STANDARD_SHIPPING : USA_EXPEDITED_SHIPPING;  
    // } else if (strcasecmp(destination, "Mexico") == 0) {
    //     shipping_cost = (strcasecmp(method, "standard") == 0) ? MEXICO_STANDARD_SHIPPING : MEXICO_EXPEDITED_SHIPPING;
    // } else if (strcasecmp(destination, "Canada") == 0) {
    //     shipping_cost = (strcasecmp(method, "standard") == 0) ? CANADA_STANDARD_SHIPPING : CANADA_EXPEDITED_SHIPPING;
    // } else
    //     printf("Invalid shipping destination. Defaulting to USA standard shipping.");
    //     shipping_cost = USA_STANDARD_SHIPPING;

    // // Calculate tax
    // if (strcasecmp(destination, "USA") == 0) {
    //     tax = (subtotal * USA_TAX_RATE);  
    // } else if (strcasecmp(destination, "Mexico") == 0) {
    //     tax = (subtotal * MEXICO_TAX_RATE);  
    // } else if (strcasecmp(destination, "Canada") == 0) {
    //     tax = (subtotal * CANADA_TAX_RATE);  
    // }


    // // Calculate tax value
    // if (strcasecmp(destination, "USA") == 0) {
    //     taxValue = (USA_TAX_RATE * 100);  
    // } else if (strcasecmp(destination, "Mexico") == 0) {
    //     taxValue = (MEXICO_TAX_RATE * 100);   
    // } else if (strcasecmp(destination, "Canada") == 0) {
    //     taxValue = (CANADA_TAX_RATE * 100); 
    // }

// Prompt for shipping destination and method
    printf("\nEnter the shipping destination (USA, Mexico, Canada): ");
    scanf("%s", destination);
    printf("Enter the shipping method (standard, expedited): ");
    scanf("%s", method);
    method[0] = toupper(method[0]);


    // Calculate tax and shipping cost based on destination using switch statement
    switch (destination[0]) {
        case 'U':
        case 'u':
            tax = USA_TAX_RATE * subtotal;
            switch(method[0]) {
                case 'S':
                case 's':
                    shipping_cost= USA_STANDARD_SHIPPING;
                    // strcpy(method_print, "Standard");
                    // strcpy(destination_print, "USA");
                    break;
                case 'E':
                case 'e':
                    shipping_cost = USA_EXPEDITED_SHIPPING;
                    // strcpy(method_print, "Expedited");
                    // strcpy(destination_print, "USA");
                    break;    
            }
            break;
        case 'M':
        case 'm':
            tax = MEXICO_TAX_RATE * subtotal;
            switch (method[0]) {
                case 'S':
                case 's':
                    shipping_cost = MEXICO_STANDARD_SHIPPING;
                    // strcpy(method_print, "Standard");
                    // strcpy(destination_print, "Mexico");              
                        break;
                case 'E':
                case 'e':
                    shipping_cost = MEXICO_EXPEDITED_SHIPPING;
                    // strcpy(method_print, "Expedited");
                    // strcpy(destination_print, "Mexico");
                        break;
                }
            break;
        case 'C':
        case 'c':
                tax = CANADA_TAX_RATE * subtotal;
            switch (method[0]){
                    case 'S':
                    case 's':
                        shipping_cost = CANADA_STANDARD_SHIPPING;
                        // strcpy(method_print, "Standard");
                        // strcpy(destination_print, "Canada");
                        break;
                    case 'E':
                    case 'e':
                        shipping_cost = CANADA_EXPEDITED_SHIPPING;
                        // strcpy(method_print, "Expedited");
                        // strcpy(destination_print, "Canada");
                        break;
                }
            break;
        default:
            printf("Invalid shipping destination. Defaulting to USA standard shipping.\n");
                shipping_cost = USA_STANDARD_SHIPPING;
                    strcpy(method, "Standard");
                    strcpy(destination, "USA");

            return 1; // Exit with error
    }

    // Calculate total cost
    total_cost = subtotal + shipping_cost + tax;

    // Display the formatted bill
    printf("\nClothing Item\tQuantity\tPrice\t\tTotal\n");
    printf("-------------------------------------------------------\n");
    printf("Shirts\t\t%d\t\t$%.2f\t\t$%.2f\n", shirtQuantity, SHIRT_PRICE, shirtQuantity * SHIRT_PRICE);
    printf("Shoes\t\t%d\t\t$%.2f\t\t$%.2f\n", shoeQuantity, SHOE_PRICE, shoeQuantity * SHOE_PRICE);
    printf("Pants\t\t%d\t\t$%.2f\t\t$%.2f\n", pantsQuantity, PANTS_PRICE, pantsQuantity * PANTS_PRICE);
    printf("-------------------------------------------------------\n");
    printf("Subtotal:\t\t\t\t\t$%.2f\n", subtotal);
    printf("Shipping Destination: %s\n", destination);
    printf("Shipping Method: %s to %s\n", method, destination);
    printf("Shipping Cost:\t\t\t\t\t$%.2f\n", shipping_cost);
    printf("Tax (%.2f%%):\t\t\t\t\t$%.2f\n", (tax * 100) / subtotal, tax);
    printf("-------------------------------------------------------\n");
    printf("Total Cost (including tax and shipping):\t$%.2f\n", total_cost);

    return 0;  // Indicate successful program execution
}
