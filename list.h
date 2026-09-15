#include <stdio.h>
#include <stdlib.h>

struct List;
struct List *newList(int, struct List *);
void destroyList(struct List *);

struct List
{
    int data;
    struct List *next;
};

struct List *
newList(int d, struct List *n)
{
    struct List *new_l = (struct List *)malloc(sizeof(struct List));
    (*new_l).data = d;
    (*new_l).next = n;
    return new_l;
}

void
destroyList(struct List *l)
{
    if (l != NULL)
    {
        free((void*)l->next);
        free((void*)l);
    }
}
