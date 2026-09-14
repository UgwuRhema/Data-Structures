#include <stdio.h>
#include "vector.h"

int
main(void)
{
    struct Vector *v1 = makeVector();
    destroyVector(v1);
    return 0;
}
