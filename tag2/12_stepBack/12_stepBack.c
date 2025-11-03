#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void output(char **s)
{
    for(; s != NULL; s++)
    {
        printf("%s\n", *s);
    }
}

void output2(char **s, int m)
{
    int l;
    for (l = 0; l < m; l++)
    {
        printf("%s\n", s[l]);
    }
}

int main(void)
{

    char **v = NULL;
    int l;

    v = (char **)malloc(sizeof(char *) * 4);

    for (l=0; l<4; l++) v[l] = NULL;

    for (l = 0; l<3; l++)
    {
        v[l] = (char *)malloc(sizeof(char) * 128);
    }

    strcpy(v[0], "Mustermann");
    strcpy(v[1], "Max");
    strcpy(v[2], "Musterstr.");

    output(v);

    for (l = 0; l<4; l++)
    {
        free(v[l]);
    }
    free(v);

    return 0;
}