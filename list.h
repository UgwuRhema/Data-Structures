#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

struct List;
struct List *insert(struct List *, int);
void destroyList(struct List *);

struct List
{
    int data;
    struct List *next;
    struct List *prev;
};

struct List *
insert(struct List *head, int data)
{
    if (head == NULL)
        head = (struct List *)malloc(sizeof(struct List));

    struct List *current = head;
    struct List *newList = (struct List *)malloc(sizeof(struct List));
    newList->data = data;
    newList->next = NULL;
    newList->prev = current;
    current->next = newList;
    return current;
}

void
destroyList(struct List *l)
{

}

#endif
