#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

struct Tree
{
    int data;
    struct Tree *left;
    struct Tree *right;
};



#endif
#include "binary_tree.h"

struct Tree *makeTree(int d, struct Tree *l, struct Tree *r)
{
    struct Tree *newTree = (struct Tree *)malloc(sizeof(struct Tree));
    (*newTree).data = d;
    (*newTree).left = l;
    newTree->right = r;
    return newTree;
}
