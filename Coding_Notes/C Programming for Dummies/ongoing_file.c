#include <stdio.h> // Includes function prototype  for printf()

int main() {

    int a, b, c;

    printf("I am waiting for three characters: ");
    a = getchar();
    b = getchar();
    c = getchar();
    printf("I waited for the '%c', '%c', and '%c' characters.\n", a, b, c);


return 0;

}




