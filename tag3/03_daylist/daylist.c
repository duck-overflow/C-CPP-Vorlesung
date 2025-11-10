#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct names
{
    int nr;
    char *fname;
    char *lname;
    struct names *next;
    struct names *prev;
};

struct list
{
    struct names *firstElement;
    struct names *lastElement;
};

/* Typedefs */
typedef struct names names;
typedef struct list list;

/* Funktionen */
struct names *CreateElement(int, char*, char*);
void AddElement(list*, int, char*, char*);
void InsertElement(list*, int, char*, char*);
void Output(list*);
void CleanUp(list*);
void Sort(list*);
names *Swap(names*);

int main(void)
{

    list *li = (list*) malloc(sizeof(list));
    li->firstElement = NULL;
    li->lastElement = NULL;

    AddElement (li, 45, "Max", "Mustermann");
    InsertElement(li, 69, "Werner", "Herzog");
    AddElement( li, 12, "Anna", "Schmidt");
    InsertElement(li, 5, "Zoe", "Zimmermann");
    AddElement( li, 90, "Peter", "Fischer");
    InsertElement(li, 2, "Laura", "Meier");
    AddElement( li, 6, "Lena", "Bauer");
    InsertElement(li, 34, "Tom", "Schulz");

    Output(li);
    printf("-----------------------\n");
    Sort(li);
    Output(li);

    CleanUp(li);
    free(li);

    return 0;
}

names *CreateElement(int n, char* f, char* l)
{
    names *newElement = (names*) malloc(sizeof(names));
    newElement->lname = (char*) malloc(sizeof(char) * (strlen(l) + 1));
    newElement->fname = (char*) malloc(sizeof(char) * (strlen(f) + 1));
    strcpy(newElement->lname, l);
    strcpy(newElement->fname, f);
    newElement->nr = n;
    newElement->prev = NULL;
    newElement->next = NULL;
    return newElement;
}
void AddElement(list* li, int n, char* f, char* l)
{

    names *newElement = CreateElement(n, f, l);
    if (li->firstElement == NULL)
    {
        li->firstElement = newElement;
        li->lastElement = newElement;
    } else 
    {
        li->lastElement-> next = newElement;
        newElement->prev = li->lastElement;
    }

    li->lastElement = newElement;

}
void InsertElement(list* li, int n, char* f, char* l)
{
    if (li->firstElement == NULL)
    {
        AddElement(li, n, f, l);
    } else 
    {
        names *newElement = CreateElement(n, f, l);
        li->firstElement->prev = newElement;
        newElement->next = li->firstElement;
        li->firstElement = newElement;
    }
}
void Output(list* li)
{
    names *temp = li->firstElement;
    for (; temp != NULL; temp = temp->next)
    {
        printf("Nr: %d/ Firstname: %s/ Lastname: %s\n", temp->nr, temp->fname, temp->lname);
    }
}
void CleanUp(list* li)
{
    while (li->firstElement!=NULL)
    {
        names *tempNext = li->firstElement->next;
        free(li->firstElement->fname);
        free(li->firstElement->lname);
        free(li->firstElement);
        li->firstElement = tempNext;
    }
    li->firstElement = li->lastElement = NULL;
    
}
void Sort(list *li) {
    if (li->firstElement == NULL) {
        return;
    }

    int sorted = 0;
    while (!sorted) {
        sorted = 1;
        names *current = li->firstElement;

        while (current->next != NULL) {
            if (current->nr > current->next->nr) {
                names *newCurrent = Swap(current);
                if (current == li->firstElement) {
                    li->firstElement = newCurrent;
                }
                current = newCurrent;
                sorted = 0;
            }
            current = current->next;
        }
    }

    names *temp = li->firstElement;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    li->lastElement = temp;
}

names *Swap(names *li) {
    names *first = li;
    names *second = li->next;

    first->next = second->next;
    if (second->next != NULL) {
        second->next->prev = first;
    }
    second->prev = first->prev;
    second->next = first;
    first->prev = second;

    if (second->prev != NULL) {
        second->prev->next = second;
    }

    return second;
}