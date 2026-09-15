#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

struct Tree;
struct Tree *makeTree(int, struct Tree *, struct Tree *);
void destroyTree(struct Tree *);
struct Tree *insertTree(struct Tree *, int);
void emit_tree(struct Tree *);

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

/*recursion will become like breathing when working with
 * binary trees */
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

struct Tree *
insertTree(struct Tree *parent, int val)
{
    if (parent == NULL)
    {
        parent = (struct Tree *)malloc(sizeof(struct Tree));
        parent->data = val;
        parent->left = parent->right = NULL;
        return parent;
    }

    if (val < parent->data)
    {
        parent->left = insertTree(parent->left, val);
    } else {
        parent->right = insertTree(parent->right, val);
    }

    return parent;
}

void
emit_tree(struct Tree *parent)
{
    if (parent != NULL)
    {
        printf("Root: %d\n", parent->data);
        if (parent->left != NULL)
            printf("\tLeft: %d\n", parent->left->data);
        else
            printf("\tLeft: NULL\n");

        if (parent->right != NULL)
            printf("\tRight: %d\n", parent->right->data);
        else
            printf("\tRight: NULL\n");

        emit_tree(parent->left);
        emit_tree(parent->right);
    }

    return;
}

#endif
