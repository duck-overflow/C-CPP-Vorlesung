#include <stdio.h>

int main(int argc, char **argv)
{
    int i = 0;
    for (; i < argc; i++)
    {
        printf("Parameter %d ist %s\n, i, argv[i]");
    }

    char **temp = argv;
    while (*temp != NULL) 
    {
        printf("Par ist %s\n", *temp);
        *temp++;
    }
}