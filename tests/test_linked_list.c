#include <assert.h>
#include <stddef.h>
#include "linked_list.h"

int main()
{
	struct LinkedList list = {.head=NULL};

	// test insert
	struct Node node = {.key=7, .next=NULL};
	linked_list_insert(&list, &node);
	assert(list.head->key == 7);

	const int n = 5;
	int keys[5] = {3, 5, 8, 1, 2};

	for (int i = 0; i < n; i++)
	{
		struct Node node = {.key=keys[i], .next=NULL};
		linked_list_insert(&list, &node);
	}

	// test search
	struct Node n1 = {.key=8, .next=NULL};
	assert(linked_list_search(&list, 8) == &n1);
	assert(linked_list_search(&list, 4) == NULL);

	// test delete
	linked_list_delete(&list, 8);
	assert(linked_list_search(&list, 8) == NULL);

	return 0;
}
