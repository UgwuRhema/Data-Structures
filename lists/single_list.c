#include <stdio.h>
#include <stdlib.h>

struct node_t;
void insert(struct node_t **, int);
void insert_at(struct node_t **, int, int);
struct node_t *reverse(struct node_t **);
void printlist(struct node_t *);
void delete_at(struct node_t **, int);

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
	insert(&head, 1);
	insert(&head, 2);
	insert(&head, 3);
	insert(&head, 4);
	insert(&head, 5);
	head = reverse(&head);
	printlist(head);
	insert_at(&head, 67, 3);
	printlist(head);
	delete_at(&head, 2);
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

// a2 g7 b3 c4
void
insert_at(struct node_t **head, int val, int offset)
{
	struct node_t *nn = (struct node_t *)malloc(sizeof(struct node_t));
	nn->val = val;
	nn->next = NULL;
	struct node_t *temp = traverse_to(*head, offset - 1);
	struct node_t *nth = temp->next;
	temp->next = nn;
	nn->next = nth;
}

struct node_t *
reverse(struct node_t **head)
{
	struct node_t *curr, *prev;
	prev = NULL;
	curr = *head;
	while (curr)
	{
		struct node_t *next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

// head a1 b2 c3 d4
void
delete_at(struct node_t **head, int n)
{
	if (n == 1)
	{
		
	}
	struct node_t *temp = traverse_to(*head, n - 1);
	struct node_t *nth = temp->next;
	temp->next = nth->next;
	free(nth);
}
