// atoi (const char *str): ACII to int

#include <stdio.h>
#include <stdlib.h>

int main() {
    char num_str[] = "43";
    int outnum = atoi(num_str);
    printf("The string \"%s\" is converted to integer value %d\n", num_str, outnum);
    return 0;
}