#include <>

#define vector(type) \
	typedef struct { \
		type *data; \
		size_t capacity; \
		size_t size; \
	} vector_##type
