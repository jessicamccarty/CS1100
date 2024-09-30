// Filename: file_midpoint_locator.c
// Problem Statement: Given a text file, the program should locate and display the middle line of the text file. The program should handle files of different sizes and content.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// Find and print the middle line of a text file
void find_text_file_midpoint(const char *filename) {
    // Open the file for reading
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the text file.\n");
        
        return;
    }

    // Find the file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file); // Reset file pointer to beginning

    // Calculate the middle position
    long middle_position = file_size / 2;

    // Seek to the middle position
    fseek(file, middle_position, SEEK_SET);

    // Move back to the start of the current line
    while (middle_position > 0 && fgetc(file) != '\n') {
        middle_position--;
        fseek(file, middle_position, SEEK_SET);
    }

    // If not at start of file, move to next line
    if (middle_position != 0) {
        fgetc(file); // Move past the newline character
    }

    // Read the middle line
    char buffer[MAX_LINE_LENGTH];
    if (fgets(buffer, sizeof(buffer), file) != NULL) {
        // Remove the newline character if present
        buffer[strcspn(buffer, "\n")] = '\0';
        printf("Failed to read the middle line.\n");    
    }

    // Close the file
    fclose(file);
}

int main(void) {
    char text_filename[] = "input_numbered_lines.txt";
    find_text_file_midpoint(text_filename);
    
    return 0;
    
}
