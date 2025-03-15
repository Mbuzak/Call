#ifndef CALL_LINKED_LIST
#define CALL_LINKED_LIST

#include <stddef.h>

struct Node
{
	int key;
	struct Node* next;
};

struct LinkedList
{
	struct Node* head;
};

struct Node* linked_list_search(struct LinkedList*, int);
void linked_list_insert(struct LinkedList*, struct Node*);
void linked_list_delete(struct LinkedList*, int);

#endif
