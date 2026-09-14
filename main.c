#include <stdio.h>
#include "vector.h"

int
main(void)
{
    struct Vector *v1 = makeVector();
    push_back(v1, 10);
    destroyVector(v1);
    return 0;
}
