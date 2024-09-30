#include <stdio.h>

// Description: A file create to understand different operands

int main(void) {
    int num1, num2
    char operand;

    printf("Please enter two whole numbers: ");
    scanf("%d %d", &num1, &num2);

    printf("What would you like to do with these numbers?\n+, -, *, /, or %%\n");
    scanf("%c", &operand);

    if (operand == '+') {
        printf("Result: %d\n", num1 + num2);
    }

    else if (operand == '-') {
        printf("Result: %d\n", num1 - num2);
    }

    else if (operand == '*') {
        printf("Result: %d\n", num1 * num2);
    }

    else if (operand == '/') {
        if (num2 != 0) {
            printf("Result: %d\n", num1 / num2);
        } else {
            printf("Error: Division by 0 is not allowed.");
        }    
    }

    else if (operand == '%') {
        printf("Result: %d\n", num1 % num2);
    }

    else {
        printf("Error: Not a valid operand.");
    }


    return 0;
    
}