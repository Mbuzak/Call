#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int key;
	struct Node *parent, *left, *right;
};

struct Node* nodeInit(int);

struct Node* nodeMin(struct Node*);
void nodeInorderPrint(struct Node*);
struct Node* nodeSearch(struct Node*, int);

void nodeDestroy(struct Node*);


struct BST {
	struct Node* head;
};

struct BST bstInit();

void bstInsert(struct BST*, int);
void bstInorderPrint(struct BST*);
void bstSearch(struct BST*, int);
void bstRemove(struct BST*, int);

void bstDestroy(struct BST*);

#endif
