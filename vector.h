#pragma once
#include <stdio.h>
#include <stdlib.h>

struct Vector;
struct Vector *makeVector();
void destroyVector(struct Vector *);
void push_back(struct Vector *, int);

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

/* how can i make this automatic like C++ vectors */
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

/* pushes an integer onto the dynamic vector array */
void
push_back(struct Vector *v, int val)
{
    if (v->data == NULL)
    {
        v->data = (int*)malloc(sizeof(int));
        v->capacity = 1;
    } else if (v->size >= v->capacity){
        v->capacity *= 2;
        /* so close */
        v->data = (int*)realloc(v->data, v->capacity * sizeof(int));
    }

    v->data[v->size] = val;
    v->size++;
}
