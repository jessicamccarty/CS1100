// Class review of Quarter Slots assignment
// September 17, 2024


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
        int rand_num; 
        int balance; // number of quarters
        int bet; 

        // Print the welcome message

        // from stdlib.h: rand() srand()
        srand(time(NULL)); //setting the RNG seed to the curren timestap 

        // printf/scanf: prompt and collect user input
        //printf("%d, 42")
        //scanf("%d, &variable_nam")

        while (balance > 0);
        {
                // Print balance

                printf("You have %d quarters ($%.2f)).\n", balance, balance * 0.25) // $.2f will provide a float with only 2 decimal points 

                printf("How much do you want to bet? ");
                scanf("%d, &bet"); // Could add some bet validation here but not required by assignment


                if (bet == 0)
                {
                    // Cashout
                    printf("Thanks for playing.");
                    break;

                }

                if (bet > balance || bet < 0)
                {
                    // Print error message
                    printf("Invalid bet amount. Please enter a valid number of quarters.");
                    continue;

                }

                rand num = rand() % 100 + 1;

                if (rand_num < 50)
                {
                    // Player loses


                }
                else if (rand_num >= 50 && rand_num <= 74)
                {
                    // Player gets bet back

                }
                else if (rand_num >= 75 && rand_num <= 94)
                {
                    // Player doubles bet

                }
                else 
                {
                    // Jackpot, trriple the bet

                }

        }

        // Print 

        return 0;
}
























