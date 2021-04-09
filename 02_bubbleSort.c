#include <stdio.h>

int main(void) {
	int i, j, temp;
	int array[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };
	for (j = 9; j >= 0; j--) {
		for (i = 0; i < j; i++) {
			if (array[i] > array[i + 1]) {
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
		}
	}
	for (i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}

	return 0;
}