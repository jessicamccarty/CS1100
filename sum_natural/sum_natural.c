// File Name: sum_natural.c
// Description: Computes sum of N natural numbers using 3 different methods.

#include <stdio.h>

// Function Prototypes
int sumOfNaturalNumbers_needs_Prototype(int);
void sumOfNaturalNumbers_usesGlobalvariables(void);

// Global Variables
int nGlobal = 0;
int sumGlobal = 0;

// Function Definitions
int sumOfNaturalNumbers_noPrototype(int n) {
	int sum = (n * (n + 1)) / 2;
	return sum;
}

void sumOfNaturalNumbers_usesGlobalvariables(void) {
	sumGlobal = (nGlobal * (nGlobal + 1)) / 2;
}

int sumOfNaturalNumbers_needs_Prototype(int n) {
	int sum = (n * (n + 1)) / 2;
	return sum; 
}

int main(void) {
	int n = 0;
	int sum = 0;

	printf("Enter a natural number: ");
	scanf("%d", &n);

	sum = sumOfNaturalNumbers_noPrototype(n);
	printf("Sum of natural numbers (no prototype) from 1 to %d: %d\n", n, sum);

	sum = sumOfNaturalNumbers_needs_Prototype(n);
	printf("Sum of natural numbers (with prototype) from 1 to %d: %d\n", n, sum);

	nGlobal = n;
	sumOfNaturalNumbers_usesGlobalvariables();
	printf("Sum of natural numbers (using global variables) from 1 to %d: %d\n", nGlobal, sumGlobal);

	return 0;
}


