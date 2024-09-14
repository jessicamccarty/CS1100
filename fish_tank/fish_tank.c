// fish_tank.c 14 September 2024 by Jess
// Description: compute the amount of water needed to fill a fish tank
// Note: there are 231 cubic inches in 1 gallon
// Input: length to nearest 0.5 inches, width to the nearest 0.5 inches, heigh to the nearest 0.5 inches
// Output: print the user input values length width, height to half an inch or 1 decimal place resolution. print the cubic inches of volume computed. print the number of gallons needed to 2 places.

#include <math.h>
#include <stdio.h>

int main(void)
{
	float length, width, height;
	float volume_cubic_inches, amount_in_gallons;

	printf("Enter the length of the fish tank (to the nearest half inch): ");
	scanf("%f", &length);

	printf("Enter the width of the fish tank (to the nearest half inch): ");
	scanf("%f", &width);

	printf("Enter the height of the fish tank (to the nearest half inch): ");
	scanf("%f", &height);

	// Calculate the volume in cubic inches
	volume_cubic_inches = length * width * height;

	// Convert volume to gallones using the known 231 cubic inches in a gallone
	amount_in_gallons = volume_cubic_inches / 231;

	// Repeat the user's input and display the volume in inches
	printf("The volume of a fish tank having length =%.1f with = %.1f nad heigh = %.1f is %.2f cubic inches\n", length, width, height, volume_cubic_inches);

	// Display the amount of gallones
	printf("The amount of water needed to fill the fish tank = %.2f gallons\n", amount_in_gallons);

	// Display the result of the round() math.h function
	printf("The amount of water needed using the round function = %.2f gallons\n", round(amount_in_gallons));

	return 0;
}

