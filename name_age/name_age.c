#include <stdio.h>
#include <stdlib.h> // For atoi function

int main () 
{
	char input_name[20]; // Declare a name string
	char age_str[4]; // Declare an age string
	int age; // Declare an integer variable to store the converted age

	// Get user input for name
	printf("What's your name? ");
	scanf("%s", input_name);

	// Get user input for age
	printf("How old are you? ");
	scanf("%s", age_str);

	// Convert age string to an integer using atoi
	age = atoi(age_str);

	// Print the result
	printf("%s is %d years old.\n", input_name, age);

	return 0;
}


