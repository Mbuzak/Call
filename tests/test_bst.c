#include "bst.h"

int main() {
	struct BST bst = bstInit();
	int array[] = {18, 11, 6, 30, 21, 19, 8, 22, 23, 5, 20, 26, 17};

	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
		bstInsert(&bst, array[i]);
	}

	bstInorderPrint(&bst);

	bstRemove(&bst, 1);
	bstRemove(&bst, 8);
	bstRemove(&bst, 30);
	bstRemove(&bst, 18);
	//bstRemove(&bst, 11);

	bstInorderPrint(&bst);

	bstSearch(&bst, 25);
	bstSearch(&bst, 26);
	bstSearch(&bst, 30);

	bstDestroy(&bst);

	return 0;
}
