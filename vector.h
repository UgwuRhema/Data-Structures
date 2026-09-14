#pragma once
#include <stdio.h>
#include <stdlib.h>

struct Vector;
struct Vector *makeVector();
void destroyVector(struct Vector *);

/* for now our vector only stores integers */
struct Vector
{
    int *data;
    size_t capacity;
    size_t size;
};

struct Vector *
makeVector(void)
{
    struct Vector *vec = (struct Vector *)malloc(sizeof(struct Vector));
    /* we will use the concept of polymorphism so that we will also be able to allocate
     * memory upon creating the vector, function overloading */
    (*vec).data = NULL;
    vec->capacity = 0;
    vec->size = 0;
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
