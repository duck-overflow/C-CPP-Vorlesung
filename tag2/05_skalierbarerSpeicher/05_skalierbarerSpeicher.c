#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void output(char *s){
    while (*s!='\0')
    {
        printf("%c", *s);
        s++;
    }
}

int main() {
    char *p = NULL;
    p = (char *) malloc(sizeof(char) * 128);

    p[0] = 'a';
    p[1] = 'b';
    p[2] = 'c';
    p[3] = 'd';
    p[4] = 'e';
    p[5] = 'f';
    p[6] = 'g';
    p[7] = 'h';
    p[8] = 'i';
    p[9] = 'j';
    p[10] = 'k';
    p[11] = '\0';

    output(p);
    printf("\n");

    free(p);
    return 0;
}