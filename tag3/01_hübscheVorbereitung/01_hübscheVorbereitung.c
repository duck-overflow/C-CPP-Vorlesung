#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct name
{
    char *firstname;
    char *lastname;
    int age;
};

struct name * create(char *n, char *v, int a)
{
    struct name *newElement = (struct name *)malloc(sizeof(struct name));
    newElement->lastname = (char *)malloc(sizeof(char) * 128);
    newElement->firstname = (char *)malloc(sizeof(char) * 128);
    strcpy(newElement->lastname, n);
    strcpy(newElement->firstname, v);
    newElement->age = a;

    return newElement;
}

void delete(struct name *s)
{
    free(s->lastname);
    free(s->firstname);
    free(s);
}

void output(struct name *s)
{
    printf("Lastname: %s/ Firstname: %s/ Age: %d\n", s->lastname, s->firstname, s->age);
}

int main(void)
{
    struct name *n1 = create("Mustermann", "Max", 42);
    output(n1);
    delete(n1);

    return 0;
}