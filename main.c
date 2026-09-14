#include <stdio.h>
#include "vector.h"

int
main(void)
{
    struct Vector *v1 = makeVector();
    push_back(v1, 10);
    push_back(v1, 50);
    push_back(v1, 90);
    push_back(v1, 50);
    push_back(v1, 10);
    printf("The current size of vector v1: %zu\n", v_size(v1));
    printf("The element at index 2 is: %d\n", get_back(v1, 2));
    printf("Is is empty? %s\n", is_empty(v1) ? "Yes" : "No");
    printf("All the elements in the vector are: ");
    printv(v1);
    destroyVector(v1);
    return 0;
}
