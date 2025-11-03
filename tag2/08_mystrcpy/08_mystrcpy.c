#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mystrcpy(char *dest, const char *src)
{
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

void mystrcats(char *dest, char *src)
{
    mystrcpy(dest += strlen(dest), src);
}


int main(void)
{
    char *vname = NULL;

    vname = (char *) malloc(sizeof(char) * 32);

    mystrcats(vname, "Name: ");
    mystrcpy(vname, "Max");
    mystrcats(vname, " Mustermann");

    printf("Ausgabe: %s {%p}\n", vname, vname);

    free(vname);

    return 0;
}