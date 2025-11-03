#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define dbname "db.txt"

int main(void)
{
    FILE *fd = fopen(dbname, "r");

    if (fd == NULL)
    {
        printf("Cant open file %s\n", dbname);
        return -4;
    }

    char *puffer = (char *) malloc(sizeof(char) * 1024);

    printf("%-20s | %-20s | %-20s\n", "User", "Nachname", "Vorname");

    while (fgets(puffer, 1024, fd) != NULL)
    {
        char* user = strtok(puffer, ";");
        char* surname = strtok(NULL, ";");
        char* name = strtok(NULL, ";");

        printf("%-20s | %-20s | %-20s\n", user, surname, name);
    }
    
    free(puffer);
    fclose(fd);

    return 0;
}