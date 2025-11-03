#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *src = NULL;

    src = (char *) malloc(sizeof(char) * 128);
    strcpy(src, "musterUser;Mustermann;Hans;Musterstr.");

    // Zerlegung mit strtok
    char *username = strtok(src, ";");
    printf("Benutzername: %s\n", username);

    char *nachname = strtok(NULL, ";");
    printf("Nachname: %s\n", nachname);

    char *vorname = strtok(NULL, ";");
    printf("Vorname: %s\n", vorname);

    char *strasse = strtok(NULL, ";");
    printf("Strasse: %s\n", strasse);

    printf("Mein Src ist: %s\n", src);
    free(src);

    return 0;
}