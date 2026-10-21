#include <stdlib.h>

#define vector(type) \
	typedef struct { \
		type *data; \
		size_t capacity; \
		size_t size; \
	} vector_##type;

#define vector_init(Type, Vec, Cap) \
	do { \
		if (Vec == NULL) exit(1); \
		(Vec)->data = (Type *)malloc((Cap) * (sizeof(Type))); \
		if ((Vec)->data == NULL) \
			exit(1); \
		(Vec)->capacity = Cap; \
		(Vec)->size = 0; \
	} while(0)

#define push(Type, Vec, Val) \
	do { \
		if (Vec == NULL) exit(1); \
		if ((Vec)->size >= (Vec)->capacity) \
		{ \
			(Vec)->capacity *= 2; \
			(Vec)->data = (Type *)realloc((Vec)->data, (Vec)->capacity * sizeof(Type)); \
		} else if ((Vec)->capacity == 0) { \
			(Vec)->capacity = 5; /*just enough for 5 elements*/ \
		} \
	} while(0)

vector(int)

int
main(void)
{
	vector_int v1;
	vector_init(int, &v1, 5);
	push(int, &v1, 10);
	return 0;
}
