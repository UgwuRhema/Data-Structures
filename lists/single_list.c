#include <stdio.h>
#include <stdlib.h>

struct node_t;
void insert(struct node_t **, int);
void insert_at(struct node_t **, int, int);
struct node_t *reverse(struct node_t **);
void printlist(struct node_t *);
void delete_at(struct node_t *, int);

/*singly linked lists*/
struct node_t
{
	int val;
	struct node_t *next;
};

/*a mini helper function*/
struct node_t *
traverse_to(struct node_t *head, int offset)
{
	struct node_t *curr = head;
	int count = 0;
	while (curr)
	{
		count++;
		if (count == offset)
			return curr;
		curr = curr->next;
	}
	return NULL;
}

void
cleanlist(struct node_t *head)
{
	if (!head) return;
	struct node_t *curr = head;
	while (curr)
	{
		struct node_t *next = curr->next;
		free((void *)curr);
		curr = next;
	}
	return;
}

int
main(int argc, char *argv[])
{
	struct node_t *head = NULL;
	insert(&head, 6);
	insert(&head, 7);
	insert(&head, 12);
	printlist(head);
	printlist(head);
	cleanlist(head);
	return 0;	
}

void
insert(struct node_t **head, int val)
{
	struct node_t *nn = (struct node_t *)malloc(sizeof(struct node_t));
	nn->val = val;
	nn->next = *head;
	*head = nn;
}

void
printlist(struct node_t *head)
{
	if (!head) return;
	struct node_t *curr = head;
	while (curr)
	{
		printf("%d->", curr->val);
		curr = curr->next;
	}
	if (!curr)
		printf("NULL\n");
}
