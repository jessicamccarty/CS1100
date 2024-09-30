#!/bin/bash

# Get the user's age
read -p "Enter your age: " age

# Check if the user is an adult
if [ "$age" -ge 18 ]; then
	echo "You are an adult."
else
	echo "You are not yet an adult."
fi

# Check if a number is positive, negative, or zero
read -p "Enter a number: " number

if [ "$number" -gt 0 ]; then
	echo "The number is positive."
elif [ "$number" -lt 0 ]; then
	echo "The number is negative."
else
	echo "The number is zero."
fi
