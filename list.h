#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

struct List;
struct List *insert(struct List *, int);
void printList(struct List *);

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
printList(struct List *l)
{
    if (l != NULL)
    {
        printf("%d\n", l->data);
        printList(l->next);
    }
}

void
destroyList(struct List *head)
{
    struct List *curr = head; 
    while (curr->next != NULL)
    {
        struct List *tmp = curr->next;
        free(curr);
        curr = tmp;
    }

    head = NULL;
}

#endif
