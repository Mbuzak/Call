#include <assert.h>
#include "quicksort.h"

int main()
{
	int n = 11;
	int array[11] = {23, 6, 11, 12, 17, 19, 7, 18, 12, 14, 15};
	int sorted[11] = {6, 7, 11, 12, 12, 14, 15, 17, 18, 19, 23};
	quicksort(array, 0, n - 1);

	for (int i = 0; i < 11; i++)
		assert(array[i] == sorted[i]);

	return 0;
}
