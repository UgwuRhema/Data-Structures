#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

struct Tree;
struct Tree *makeTree(int, struct Tree *, struct Tree *);
void destroyTree(struct Tree *);

struct Tree
{
    int data;
    struct Tree *left;
    struct Tree *right;
};

struct Tree *
makeTree(int d, struct Tree *l, struct Tree *r)
{
    struct Tree *newTree = (struct Tree *)malloc(sizeof(struct Tree));
    (*newTree).data = d;
    (*newTree).left = l;
    newTree->right = r;
    return newTree;
}

void
destroyTree(struct Tree *head)
{
    if (head != NULL)
    {
        destroyTree(head->left);
        destroyTree(head->right);
        free(head);
    }
}

#endif
