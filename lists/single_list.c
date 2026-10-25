#include <stdio.h>
#include <stdlib.h>

struct node_t;
struct node_t *node_make(int);
void plist(struct node_t *);
void smoove(struct node_t *);

struct node_t
{
	struct node_t *next;
	int val;
};

int
main(int argc, char *argv[])
{
	/*let's just use a pointer to a function to make things easier*/
	struct node_t *(*nmk)(int) = &node_make;
	struct node_t *head = NULL;
	struct node_t *node1, *node2, *node3;
	node1 = nmk(2); node2 = nmk(4); node3 = nmk(6);
	/*manual linking*/
	node1->next = node2; node2->next = node3; node3->next = NULL;
	head = node1;
	plist(head);
	smoove(head);
	return 0;
}

struct node_t *
node_make(int v)
{
	struct node_t *nn = (struct node_t *)malloc(sizeof(struct node_t));
	nn->val = v;
	nn->next = NULL;
	return nn;
}

void
plist(struct node_t *head)
{
	struct node_t *curr = head;
	while (curr)
	{
		printf("%d->", curr->val);
		curr = curr->next;
	}
	if (!curr)
		printf("NULL");
	return;
}

void
smoove(struct node_t *h)
{
	struct node_t *c = h;
	while (c)
	{
		struct node_t *n = c->next;
		free(c);
		c = n;
	}
	return;
}
