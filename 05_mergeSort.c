#include <stdio.h>
// 시간복잡도 O(N*logN)
// 반반씩 나눈다는 점에서 항상 O(N * logN) 보장!!
// 일단 반으로 나누고 나중에 정 렬 피벗값 x

int number = 8;
int sorted[8]; // 정렬 배열은 꼭 전역변수로 선언

void merge(int a[], int m, int middle, int n) {
	int i = m;
	int j = middle + 1;
	int k = m;
	// 작은 순서대로 배열에 삽입
	while (i <= middle && j <= n) {
		if (a[i] <= a[j]) {
			sorted[k] = a[i];
			i++;
		}
		else {
			sorted[k] = a[j];
			j++;
		}
		k++;
	}
	// 남은 데이터도 삽입
	if (i > middle) {
		for (int t = j; t <= n; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	else {
		for (int t = i; t <= middle; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	//정렬된 배열 삽입
	for (int t = m; t <= n; t++) {
		a[t] = sorted[t];
	}
}
 
void mergeSort(int a[], int m, int n) {
	// 크기가 1보다 큰 경우
	if (m < n) {
		int middle = (m + n) / 2;
		mergeSort(a, m, middle);
		mergeSort(a, middle + 1, n);
		merge(a, m, middle, n);
	}
}

int main(void) {
	int array[8] = { 7,6,5,8,3,5,9,1 };
	mergeSort(array, 0, 8 - 1);
	for (int i = 0; i < 8; i++) {
		printf("%d ", array[i]);
	}
}
