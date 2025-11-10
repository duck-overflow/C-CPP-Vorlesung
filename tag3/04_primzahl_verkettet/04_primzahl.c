#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    long val;
    struct Node *next;
} Node;

int main(void)
{
    long found = 2;
    long search = 4;

    Node *head = malloc(sizeof(Node));
    head->val = 2;
    head->next = malloc(sizeof(Node));
    head->next->val = 3;
    head->next->next = NULL;
    Node *tail = head->next;

    for (; search > 0; search++)
    {
        int is_composite = 0;
        long operations = 0;

        for (Node *n = head; n != NULL; n = n->next)
        {
            if (n->val * n->val > search)
                break;
            operations++;
            if (search % n->val == 0)
            {
                is_composite = 1;
                break;
            }
        }

        if (!is_composite)
        {
            Node *newn = malloc(sizeof(Node));
            newn->val = search;
            newn->next = NULL;
            tail->next = newn;
            tail = newn;
            found++;
            double prozent = (double)found / (double)search * 100.0;
            printf("Primzahl: %ld, gefundene Nummer: %ld, Prozentzahl: %f, Operationszahl: %ld\n",
                   search, found, prozent, operations);
        }

        if (found > 9998)
            break;
    }

    /* Liste freigeben */
    Node *cur = head;
    while (cur)
    {
        Node *tmp = cur->next;
        free(cur);
        cur = tmp;
    }

    return 0;
}