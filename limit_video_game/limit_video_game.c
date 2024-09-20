// Filename: limit_video_game.c
// Problem Statement: Create a program that simulates a video game high score system. The program should alalow the user to enter points earned and update the current score
// accordingly. It should handle invalid input, such as negative pointst, and prevent integer overflow by setting a maximum high score limit. The program should continue
// to promopt the user for points until the maximum high score is reached or the user chooses to exit.
// Requirements:
// 1. The program should prompt the user to enter points earned.
// 2. The user should be able to enter positive integer values for points earned.
// 3. The program should handle invalid input, such as negative points, and display an appropriate error message.
// 4. the program should update the current score by adding the poinits earned to it.
// 5. The program should detect and prevent integer overflow by setting a maximum high score limit.
// 6. If the current score reaches or exceeds the maximum high score, the program should display a congratulatory message and end the game.
// 7. The program should allow the user to choose to exit the game by entering a specific value (e.g. 0).
// 8. The program should continue to prompty the user for points until the game ends or the user chooses to exit.


#include <stdio.h> // Include the standard input/output library
#include <limits.h> // Include the library for integer limits
#include <stdlib.h> // Include the library for atoi

#define MAX_HIGH_SCORE 1000000 // Define the maximum high score as a constant
#define GAME_RUNNING 0 // Define a constant to represent the game running state
#define GAME_OVER 1 // Define a constant to represent the game over state

int main(void) {
    int current_score = 0; // Initialize the current score to 0
    int points_earned; // Declare a variable to store the points earned
    int game_status = GAME_RUNNING; // Initialize the game status to running
    char points_earned_str[20];

    do {
        
        // Prompt the user to enter points earned.
        printf("Enter points earned (0 to exit): ");
        scanf("%s", points_earned_str); // Read the points earned from the user
        points_earned = atoi(points_earned_str); // Convert point string to integer

        if (points_earned == 0) {
            game_status = GAME_OVER; // if the user enters 0, set the game status to game over
        } else if (points_earned < 0) {
            // If the user enters a negative value, print an error message
            printf("Invalid input. Points earned cannot be negative.\n");   
        } else if (current_score > INT_MAX - points_earned) {
            // If adding points earned to the current score would cause integer overflow, print an error message indicating that the score cannot exceed the maximum high score.
            printf("Error. Integer overflow detected. Score cannot exeed %d\n:", MAX_HIGH_SCORE);
        } else {
            current_score += points_earned; // Add the points earned to the current score
            printf("Current score: %d\n", current_score); // Print the updated current score
        
            if (current_score >= MAX_HIGH_SCORE){
                // If the current score reaches or exceeds the maximum high score, print a congratulatory message and set the game status to game over.
                printf("Congratulations! You have reached the maximum high score of %d.\n", MAX_HIGH_SCORE);
                game_status = GAME_OVER;
            }        
        
        }

        } while (game_status == GAME_RUNNING); // continue the loop while the game status if running

        return 0; // return 0 to indicate successful program execution

    }









