#include <stdlib.h>

#define vector(type) \
	typedef struct { \
		type *data; \
		size_t capacity; \
		size_t size; \
	} vector_##type;

#define vector_init(Type, Vec, Cap) \
	do { \
		(Vec)->data = (Type *)malloc((Cap) * (sizeof(Type))); \
		if ((Vec)->data) \
			exit(1); \
		(Vec)->capacity = Cap; \
		(Vec)->size = 0; \
	} while(0)		

vector(int)

int
main(void)
{
	vector_int v1;
	vector_init(int, &v1, 5);
	(void)v1;
	return 0;
}
