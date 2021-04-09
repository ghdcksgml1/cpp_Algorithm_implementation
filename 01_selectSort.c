#include <stdio.h>
// 시간복잡도 O(N^2)
// N * (N+1) / 2  => O(N^2) (비효율적)
int main(void) {
	int i, j, min,index, temp;
	int array[10] = { 1,10,5,8,7,6,4,3,2,9 };
	
	for (i = 0; i < 10; i++) {
		min = 9999;
		for (j = i; j < 10; j++) {
			if (min > array[j]) {
				min = array[j];
				index = j;
			}
		}
		temp = array[i];
		array[i] = array[index];
		array[index] = temp;
	}

	for (i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
	return 0;
}