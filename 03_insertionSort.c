#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// 시간복잡도 O(N^2)
// 정렬이 되어있다고 가정

int main(void) {
	int i, j, temp;
	int array[10] = { 1,10,5,8,7,6,4,3,2,9 };
	for (i = 0; i < 9; i++) {
		j = i;
		while (array[j] > array[j + 1]) {
			temp = array[j];
			array[j] = array[j + 1];
			array[j + 1] = temp;
			j--;
		}
	}

	for (int i = 0; i < 10; i++) {
		printf("%d\n", array[i]);
	}
	return 0;

}

