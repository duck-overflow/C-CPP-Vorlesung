#include <stdio.h>

void plus(int *c, int a, int b)
{
    (*c) = a * b;
    a = 100; // Ändert Variable nur lokal, keine generelle Änderung lol
    b = 200;
}

void plusp(int *c, int *a, int *b)
{
    (*c) = (*a) * (*b);
    *a = 300;  // Pointer ändert Ursprungswert; Zeigt auf Variable an der Stelle
    *b = 400;
}

int main(void)
{
    int l=3, m=4, n=5, o=6, p=7, q=5;

    plus(&n, l, m);
    plusp(&q, &p, &o);

    printf("l=%d\n", l);
    printf("m=%d\n", m);
    printf("n=%d\n", n);
    printf("o=%d\n", o);
    printf("p=%d\n", p);
    printf("q=%d\n", q);
}