#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Vector;
struct Vector *makeVector();
void destroyVector(struct Vector *);
void push_back(struct Vector *, int);
void pop_back(struct Vector *);
_Bool is_empty(struct Vector *);
int get_back(struct Vector *, size_t);
size_t v_size(struct Vector *);
void printv(struct Vector *);

/* easier/shorter function pointers */
struct Vector *(*new_v)(void) = &makeVector;
void (*push)(struct Vector *, int) = &push_back;
void (*pop)(struct Vector *) = &pop_back;
void (*prv)(struct Vector *) = &printv;

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

/* removing an integer from the dynamic vector array(specifically the last one) */
void
pop_back(struct Vector *v)
{
    if ((*v).size > 0)
    {
        (*v).size--; /* just aggressively remove the last element from the heap array */
    }
}

/* check if vector is empty, very obvious function tbh */
_Bool
is_empty(struct Vector *v)
{
    return v->size == 0;
}

/* get back the element at a particular index 'i' */
int 
get_back(struct Vector *v, size_t i)
{
    if (i >= v->size)
    {
        fprintf(stderr,"Error: trying to access an element out of bounds. \n");
        return -1;
    }

    return v->data[i];
}

/* blah blah */
size_t
v_size(struct Vector *v)
{
    return v->size;
}

/* BLAH BLAH */
void
printv(struct Vector *v)
{
    for (size_t s = 0; s < v_size(v); ++s) /* i love how i used v_size here, hehe */
    {
        printf("%d ", v->data[s]);
    }

    printf("\n");
}
