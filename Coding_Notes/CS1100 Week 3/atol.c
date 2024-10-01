// ataol (const char *str): ACII to long int

#include <stdio.h>
#include <stdlib.h>

int main() {
    char long_str[] = "1234567890";
    long outnum = atol(long_str);
    printf("The string \"%s\" is converted to long int value %ld\n", long_str, outnum);
    return 0;  
}