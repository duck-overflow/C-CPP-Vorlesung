#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *lp1 = NULL; // setzt nur Nullen in den Stack (8 Byte)

    // Speicher reservieren
    lp1 = (int *) malloc(sizeof(int)); // reserviert 4 Byte Integergröße im Heap

    // Speicher beschreiben
    *lp1 = 14;

    // Speicherinhalt, Speicheradresse ausgeben
    printf("LP1 ist %d und steht an Adresse %p\n", *lp1, lp1);

    // Speicher freigeben
    free(lp1);

    // Speicherinhalt, Speicheradresse ausgeben
    printf("LP1 ist %d und steht an Adresse %p\n", *lp1, lp1);

    return 0;
}