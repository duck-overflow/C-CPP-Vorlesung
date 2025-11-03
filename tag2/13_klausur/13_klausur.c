#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mystrcpy(char *dst, char *src)
{
    dst = (char *)malloc(sizeof(char) * 128);
    int l;
    for(l = 0; l < strlen(src); l++) dst[l] = src[l];
    dst[l] = '\0';
}

int main(void)
{
    char *s1 = NULL;
    mystrcpy(s1, "Mustermann");

    printf("String ist: %s\n", s1);

    free(s1);
    return 0;
}