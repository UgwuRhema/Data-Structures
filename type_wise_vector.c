#include <stdlib.h>

#define vector(type) \
	typedef struct { \
		type *data; \
		size_t capacity; \
		size_t size; \
	} vector_##type;

#define vector_init(T, V, C) \
		

vector(int)

int
main(void)
{
	vector_int v1;
	(void)v1;
	return 0;
}
