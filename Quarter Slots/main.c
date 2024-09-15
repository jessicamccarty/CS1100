// Filename: quarter_slots.c
// Description: Create a simple quarter-slot machine. Allow the player to place beters using quarters and spin the slot machine reel. The outcome of each spin is determined by a
// randomly generated number, and the plaayer can win or lose based on the number range. The game continues until the player chooses to cash out or runs out of quarters.

#include <stdio.h>
#include <stdlib.h> // For srand, rand
#include <time.h> // For time

// Functions

void displayBalance(int quarters);
int getBet(int balance);
void updateBalance(int *quarters, int bet, int outcome);

int main(void) {

	// Start Random Number Generator
	srand(time(NULL));

	// Start Gaame
	int quarters = 80; // 80 quarters = $20
	int bet = 0;
	int outcome = 0;

	// Calculate value of quarters
	double value = ( quarters * 0.25);	

	printf("Welcome to the Betting Game!\n");
	printf("You have $%.0f worth of quarters.\n\n", value);
	printf ("You have %d quarters ($%.2f).\n", quarters, value);	

	while (quarters > 0) {
		// Enter number of quarters to bet
		bet = getBet(quarters);

		// If player wants to cash out
		if (bet == 0) {
			printf("Cashing out. You ended with $%.2f.\n", quarters * 0.25);
			break;
		}

		// Deduct from balance
		quarters -+ bet;

		// Generate random number from 1 to 100
		outcome = rand() % 100 + 1;
		printf("Reel stopped on the number: %d\n", outcome);

		// Result of Bet
		updateBalance(&quarters, bet, outcome);

		// Updated Balance
		displayBalance(quarters); 
		
		// Zero Balance
		if (quarters == 0) {
			printf("Game over! You have run out of quarters.\n");
			break;
		}
	}

	return 0;

}

// Player Balance Function
void displayBalance(int quarters) {
	printf("You have %d quarters ($%.2f)\n", quarters, quarters * 0.25);
}

// Player Bet Function
int getBet(int balance) {
	int bet;
	do {
		void displayBalance(int quarters);
		printf("Enter the number of quarters to bet (or 0 to cash out): ");
		scanf("%d", &bet);
		if (bet < 0 || bet > balance) {
			printf("Invalid bet. Please enter a valid number of quarters.\n");
		}
	}
		while (bet < 0 || bet > balance);
		return bet;
}

// Update Balance Function
void updateBalance(int *quarters, int bet, int outcome) {
	if (outcome < 50) {
		printf("You lose!\n\n");
		// Not subtracting when losing.
		*quarters -= bet;
	} 
	
	else if (outcome <= 74) {
		printf("You get your money back!\n\n");
		*quarters += bet;
	}
	
	else if (outcome <= 94) {
		printf("You double your money!\n\n");
		*quarters += bet * 2;
	}
	else {
		printf("Jackpot! You triple your money!\n\n");
		*quarters += bet * 3;
	}
}


