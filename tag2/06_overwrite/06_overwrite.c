#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s1 = NULL;
    char *s2 = NULL;

    s1 = (char *) malloc(sizeof(char) * 11);
    s2 = (char *) malloc(sizeof(char) * 5);

    s1[0] = 'M';
    s1[1] = 'u';
    s1[2] = 's';
    s1[3] = 't';
    s1[4] = 'e';
    s1[5] = 'r';
    s1[6] = 'm';
    s1[7] = 'a';
    s1[8] = 'n';
    s1[9] = 'n';
    s1[10] = ' ';
    s1[11] = ' ';
    s1[12] = 'P';
    s1[13] = 'r';
    s1[14] = 'o';
    s1[15] = 'g';
    s1[16] = 'r';
    s1[17] = 'a';
    s1[18] = 'm';
    s1[19] = 'm';
    s1[20] = 'e';
    s1[21] = ' ';
    s1[22] = 's';
    s1[23] = 'o';
    s1[24] = ' ';
    s1[25] = 's';
    s1[26] = 'e';
    s1[27] = 'h';
    s1[28] = 'r';
    s1[29] = ' ';
    s1[30] = 'y';
    s1[31] = 'a';
    s1[32] = '\0';

    s2[0] = 'H';
    s2[1] = 'a';
    s2[2] = 'n';
    s2[3] = 's';
    s2[4] = '\0';


    printf("s1: %s [%p]\n", s1, s1);
    printf("s2: %s [%p]\n", s2, s2);
    
    free(s2);
    free(s1);

    return 0;
}