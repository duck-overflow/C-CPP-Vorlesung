#include <stdio.h>

int main(void)
{

    int l1=5, l2=10, l3=15;
    int *pl1=NULL, *pl2=NULL;

    pl1 = &l2;
    pl2 = &l1;

    *pl2 = 200;

    l1 = (*pl2) + 100;
    *pl2 = 1;
    l3 = (*pl1) * (*pl2);

    printf("l1: %d\n", l1); // = 300 (falsch)
    printf("l2: %d\n", l2); // = 10 (falsch)
    printf("l3: %d\n", l3); // = 2000 (falsch)
    printf("*pl1: %d\n", *pl1); // = 10 (richtig)
    printf("*pl2 %d\n", *pl2); // = 200 (falsch)

    return 0;
}