// atof (const char *str): ACII to float

#include <stdio.h>
#include <stdlib.h>

int main() {
    char pi_str[] = "3.14159:";
    double outnum = atof(pi_str); // type conversion call
    printf("The string \"%s\" is converted to a double value %.5f\n", pi_str, outnum);
    return 0;
}
