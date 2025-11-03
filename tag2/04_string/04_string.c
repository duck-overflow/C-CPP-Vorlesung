#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    // Variablen definieren
    char *s1 = NULL;
    char *s2 = NULL;

    // Speicher reservieren
    s1 = (char *) malloc(sizeof(char) * 1024); // reserviert 1024 Byte
    s2 = (char *) malloc(sizeof(char) * 1024); // reserviert 1024 Byte

    strcpy(s1, "Erster Text"); // String in s1 kopieren
    strcpy(s2, "Zweiter Text");

    // Speicher ausgeben
    printf("Erster Text: %s\nZweiter Text: %s\n", s2, s1);

    // Speicher freigeben
    free(s1);
    free(s2);

    return 0;
}