#include "bst.h"

struct Node* nodeInit(int value) {
	struct Node* node = malloc(sizeof(struct Node));
	node->key = value;
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;
	return node;
}

struct Node* nodeMin(struct Node* node) {
	while (node->left)
		node = node->left;
	return node;
}

void nodeInorderPrint(struct Node* node) {
	if (node->left)
		nodeInorderPrint(node->left);

	printf("%d ", node->key);

	if (node->right)
		nodeInorderPrint(node->right);
}

struct Node* nodeSearch(struct Node* w, int value) {
	while (w != NULL && w->key != value) {
		if (value < w->key) {
			w = w->left;
		}
		else {
			w = w->right;
		}
	}
	return w;
}

void nodeDestroy(struct Node* node) {
	if (node->left) {
		nodeDestroy(node->left);
	}

	if (node->right) {
		nodeDestroy(node->right);
	}

	free(node);
}

struct BST bstInit() {
	struct BST bst = {.head=NULL};
	return bst;
}

void bstInsert(struct BST* bst, int value) {
	struct Node* z = nodeInit(value);
	struct Node* y = NULL;
	struct Node* x = bst->head;

	while (x != NULL) {
		y = x;
		if (value < x->key) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}

	z->parent = y;
	if (y == NULL) {
		bst->head = z;
	}
	else if (value < y->key) {
		y->left = z;
	}
	else {
		y->right = z;
	}
}

void bstInorderPrint(struct BST* bst) {
	nodeInorderPrint(bst->head);
	puts("");
}

void bstSearch(struct BST* bst, int value) {
	struct Node* node = nodeSearch(bst->head, value);

	if (node == NULL) {
		printf("%d not found in tree!\n", value);
	}
	else {
		printf("%d is in tree!\n", value);
	}
}

void bstRemove(struct BST* bst, int value) {
	struct Node* x = bst->head;
	struct Node* w = nodeSearch(x, value);
	struct Node *y = NULL;

	if (w == NULL) {
		return;
	}

	if (!w->left && !w->right) {
		// puts("usuwam lisc - bez synow");
		if (w == bst->head)
			bst->head = NULL;
		else {
			if (w == w->parent->left)
				w->parent->left = NULL;
			else
				w->parent->right = NULL;
		}
	}
	else {
		if (w->left != NULL && w->right != NULL) {
			// puts("usuwam wezel majacy 2 synow");
			y = nodeMin(w->right);
			bstRemove(bst, y->key);
			w->key = y->key;
		}
		else {
			// puts("usuwam wezel majacy 1 syna");
			if (w->left) {
				w->left->parent = w->parent;
				if (w == bst->head)
					bst->head = w->left;
				else {
					if (w == w->parent->left)
						w->parent->left = w->left;
					else
						w->parent->right = w->left;
				}
			}
			else {
				w->right->parent = w->parent;
				if (w == bst->head)
					bst->head = w->right;
				else {
					if (w == w->parent->left)
						w->parent->left = w->right;
					else
						w->parent->right = w->right;
				}
			}
		}
	}
}

void bstDestroy(struct BST* bst) {
	nodeDestroy(bst->head);
}
