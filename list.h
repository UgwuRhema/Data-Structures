#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

struct List;
struct List *insert(struct List *, int);
void print_list(struct List *);

struct List
{
    int data;
    struct List *next;
    struct List *prev;
};

struct List *
insert(struct List *head, int data)
{
    struct List *newList = (struct List *)malloc(sizeof(struct List));
    if (!newList)
        return head;
    newList->data = data;
    newList->next = NULL;
    newList->prev = NULL;

    if (head == NULL)
        return newList;

    struct List *current = head;
    while (current->next != NULL)
        current = current->next;

    current->next = newList;
    newList->prev = current;

    return head;
}

void
print_list(struct List *l)
{
    if (l != NULL)
    {
        printf("%d\n", l->data);
        print_list(l->next);
    }
}

#endif
