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
		if (!(Vec)->data) \
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
	int a = 0;
	(void)a; /*I want to debug with gdb, i just needed another line of code here*/
	return 0;
}
