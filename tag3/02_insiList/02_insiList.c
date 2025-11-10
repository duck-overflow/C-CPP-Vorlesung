#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct names
{
    int nr;
    char *firstname;
    char *lastname;
    struct names *next;
};

/* globale variablen */

struct names *firstE = NULL, *lastE = NULL;

struct names *CreateElement(int, char*, char*);
void AddElement(int, char*, char*);
void InsertElement(int, char*, char*);
void Output(); 
void CleanUp();
void SwapElements();
void Sort();

int main(void)
{
    AddElement(1, "Hans", "Mustermann");
    AddElement(2, "Gabi", "Fischer");
    AddElement(3, "Johann", "Meier");
    AddElement(11, "Tobias", "Ester");
    InsertElement(77, "Diana", "Schmidt");
    InsertElement(42, "Franz", "Schmidt");

    Output();
    CleanUp();
    return 0;
}

/* Funktionen */

struct names *CreateElement(int n, char* f, char* l) {
  
    struct names *newE = NULL;
    newE = (struct names *)malloc(sizeof(struct names));

    // Speicherplatz für die Strings reservieren
    newE->firstname = (char *)malloc(sizeof(char) * strlen(f) + 1);
    newE->lastname = (char *)malloc(sizeof(char) * strlen(l) + 1);

    // Werte im Struct beschreiben
    newE->nr = n;
    strcpy(newE->firstname, f);
    strcpy(newE->lastname, l);
    newE->next = NULL;

    return newE;
}

void AddElement(int n, char* f, char* l)
{
    struct names *newE = NULL;
    newE = CreateElement(n, f, l);
    if (firstE == NULL)
    {
        firstE = newE;
    }
    else
    {
        struct names *tempE = firstE;
        while (tempE->next != NULL) tempE = tempE->next;
        tempE->next = newE;
    }
}

void InsertElement(int n, char* f, char* l)
{
    if (firstE==NULL) AddElement(n, f, l);
    else
    {
        struct names *newE = NULL;
        newE = CreateElement(n, f, l);

        newE ->next = firstE;
        firstE = newE;
        
    }
    
}

void Output() {
    struct names *tempE = firstE;
    for(; tempE != NULL; tempE=tempE->next)
      printf("Nr: %d/ Firstname: %s/ Lastname: %s\n", tempE->nr, tempE->firstname, tempE->lastname);
}

void CleanUp() {
    while(firstE!=NULL) {
        struct names *tempENext = firstE->next;

        free(firstE->firstname);
        free(firstE->lastname);
        free(firstE);
        firstE = tempENext;
    }
    lastE=firstE=NULL;
}

void Sort() 
{
    struct names *tempE = firstE;

    while (tempE->next != NULL)
    {
        if (tempE -> nr < tempE->next -> nr) 
        {
            SwapElements(tempE);
            tempE = firstE;
        }
        else
            tempE = tempE->next;
    }
}

void SwapElement(struct names *e)
{
    // Anfang der Liste
    // Mitte der Liste
    // Ende der Liste

    struct names *nE = e->next;
    if (nE == NULL) return;
    
    struct names *nnE = nE->next;

    if (e == firstE)
    {
        nE->next = e;
        e->next = nnE;
        firstE = nE;
    }
    else
    {
        struct names *pE = firstE;
        while (pE->next != e) 
        {
            pE = pE->next;
            if (pE == NULL) return;
        }
    }
    

}