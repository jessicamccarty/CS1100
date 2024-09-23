// Filename: greeter.c
// Problem Statement: The program aims to greet the user in their preferred language by displaying the "Hello, World!" message in English, Spanish, French, or German.
// It prompts the user to enter their name and choose and language from the available options. The program validates the user's language input and displays the corresponding
// greeting. If the user enters an invalid language, the program prompts them to enter a valid language until a correct input is provided.
// Requirements:
// 1. The program should greet the user by asking for their name and displaying a personalized greeting message.
// 2. The program should support multiple languages for the "Hello, World!" greeting.
// 3. The supported languages should include English, Spanish, French, and German.
// 4. The program should propt the user to enter a language from the supported languages.
// 5. If the user enters a valid language, the program should display the corresponding "Hello, World!" greeting in that language.
// 6. If the user enters and invalid language, the program should prompt the user to enter a valid language until a correct input is provided.

#include <stdio.h>
#include <stdlib.h>

#define LANG_NOT_VALID 0 // for flag, language is not valid or false or 0
#define LANG_IS_VALID 1 // for flag, language is valid or true or 1

int main(void) {
    char greetings[][20] = {"Hello, world!", "Hola, mundo!", "Bonjour, monde!", "Hallo, Welt!"};
    char languages[][10] = {"English", "Spanish", "French", "German"};
    char input_name[20];
    char input_language[20];
    int validLanguage = LANG_NOT_VALID ; //flag variable for whether language string is valid

    printf("Enter your name: ");
    scanf("%s", input_name);

    char greeting[30] = "Hello, ";
    strcat(greeting, input_name);
    strcat(greeting, "!");
    printf("%s\n", input_language);

    // check the language string input by the user and wait for a valid input language
    while (LANG_NOT_VALID == validLanguage) {
        printf("\nEnter a valid language (English, Spanish, French, German): ");
        scanf("%s", input_language);

        for (int i = 0; i < 4; i++) {
            if (strcmp(input_language, languages[i]) == 0) {
                printf("In %s, \"Hello, World!\" is \"%s\"\n", languages[i], greetings[i]);
                validLanguage = LANG_IS_VALID;
            }
        }

        if (LANG_NOT_VALID == validLanguage) {
            printf("Invalid language. Please try again.\n");
    
        }
    }

    return 0;


}