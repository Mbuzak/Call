#include "linked_list.h"

struct Node* linked_list_search(struct LinkedList* list, int key)
{
	struct Node* x = list->head;

	while (x != NULL && x->key != key)
	{
		x = x->next;
	}

	return x;
}

void linked_list_insert(struct LinkedList* list, struct Node* x)
{
	x->next = list->head;
	list->head = x;
}

void linked_list_delete(struct LinkedList* list, int key)
{
	struct Node* node = list->head;

	if (node->key == key)
	{
		list->head = node->next;
		return;
	}

	while (node->next->next != NULL && node->next->key != key)
	{
		node = node->next;
	}

	if (node->next->next != NULL)
	{
		node->next = node->next->next;
	}
}
