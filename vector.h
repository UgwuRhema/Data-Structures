#pragma once
#include <stdio.h>
#include <stdlib.h>

struct Vector;
struct Vector *makeVector(size_t);
void destroyVector(struct Vector *);

/* for now our vector only stores integers */
struct Vector
{
    int *data;
    size_t capacity;
    size_t size;
};

struct Vector *
makeVector(size_t capacity)
{
    struct Vector *vec = (struct Vector *)malloc(sizeof(struct Vector));
    (*vec).data = (int *)malloc(capacity * sizeof(int));
    return vec;
}

void
destroyVector(struct Vector *v)
{
    if (v != NULL)
    {
        free((void*)v->data);
        free(v);
    }

    return;
}
