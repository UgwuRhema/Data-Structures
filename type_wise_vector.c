#include <stdlib.h>
#include <stdio.h>

#define vector(type) \
	typedef struct { \
		type *data; \
		size_t capacity; \
		size_t size; \
	} vector_##type;

#define vector_init(Type, Vec, Cap) \
	do { \
		if (Vec == NULL) exit(1); \
		(Vec)->data = (Type *)calloc(Cap, (sizeof(Type))); \
		if ((Vec)->data == NULL) \
			exit(1); \
		(Vec)->capacity = Cap; \
		(Vec)->size = 0; \
	} while(0)

#define push(Type, Vec, Val) \
	do { \
		if (Vec == NULL || (Vec)->data == NULL) exit(1); \
		if ((Vec)->size >= (Vec)->capacity) \
		{ \
			(Vec)->capacity *= 2; \
			(Vec)->data = (Type *)realloc((Vec)->data, (Vec)->capacity * sizeof(Type)); \
		} else if ((Vec)->capacity == 0) { \
			(Vec)->capacity = 5; /*just enough for 5 elements*/ \
		} \
		(Vec)->data[(Vec)->size++] = (Type)Val; /*this is actually bad*/ \
	} while(0)
/*the obvious next thing*/
#define pop(Vec) \
	do { \
		if (Vec != NULL) \
			(Vec)->size--;/*aggressively remove the last element*/ \
		else { \
			fprintf(stderr, "Vector is NULL\n"); \
			exit(1); \
		} \
	} while(0)

#define vec_print(Vec) \
	do { \
		if (Vec == NULL || (Vec)->data == NULL) { \
			fprintf(stderr, "Vector or Value is NULL\n"); \
			exit(1); \
		} \
		int i = 0; \
		while (i < (Vec)->size){ \
			printf(); \
		} \
	} while(0)

vector(int)

int
main(void)
{
	vector_int v1;
	vector_init(int, &v1, 3);
	push(int, &v1, 10);
	push(int, &v1, 15);
	push(int, &v1, 12);
	push(int, &v1, 23);/*the vector 'v' capacity should increase on this!*/
	return 0;
}
