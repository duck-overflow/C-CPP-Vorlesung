#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct name
{
    char *vorname;
    char *nachname;
    int alter;
};

void output(struct name *sname)
{
    printf("Nachname: %s\n", sname->nachname);
    printf("Vorname: %s\n", sname->vorname);
    printf("Alter: %d\n", sname->alter);
}

int main(void)
{
    struct name *n1 = NULL;
    n1 = (struct name *)malloc(sizeof(struct name));
    n1->nachname=(char *)malloc(sizeof(char)*128);
    (*n1).vorname=(char *)malloc(sizeof(char)*128);

    strcpy((*n1).nachname, "Mustermann");
    strcpy(n1->vorname, "Max");
    
    n1->alter = 42;

    output(n1);

    free(n1->vorname);
    free(n1->nachname);
    free(n1);

    return 0;
}