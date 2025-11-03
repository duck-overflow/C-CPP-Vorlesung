#include <stdio.h>

int main(void)
{
    int l1 = 6;
    int *lp1 = NULL;
    lp1 = &l1;

    printf("Ausgabe Wert: %d\n", l1);
    printf("Ausgabe Wert von Pointer: %d\n", *lp1);

}