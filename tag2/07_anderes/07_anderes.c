#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void output(char *v, char *m, char *l){
    printf("%20s {%p} %20s {%p} %20s {%p}\n", v, v, m, m, l, l);
}

int main(void)
{
    char *vname = NULL;
    char *mname = NULL;
    char *lname = NULL;

    vname = (char *) malloc(sizeof(char) * 13);
    mname = (char *) malloc(sizeof(char) * 13);
    lname = (char *) malloc(sizeof(char) * 13);

    strcpy(vname, "Hans");
    strcpy(mname, "Erik");
    strcpy(lname, "Mustermann");

    output(vname, mname, lname);

    mname = (char *) realloc(mname, sizeof(char) * 10);
    output(vname, mname, lname);

    mname = (char *) realloc(mname, sizeof(char) * 20);
    output(vname, mname, lname);

    char *newmem = (char *) malloc(sizeof(char) * 8);
    strcpy(newmem, "Max");
    printf("Neuer Speicher: %s {%p}\n", newmem, newmem);

    free(vname);
    free(mname);
    free(lname);

    return 0;
}