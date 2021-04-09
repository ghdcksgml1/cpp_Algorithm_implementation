#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// 평균 속도 : O(N*logN)
int number = 10;
int data[10] = { 10,1,5,8,7,6,4,3,2,9 };

void quickSort(int* data, int start, int end) {
	if (start >= end) { // 원소가 1개인 경우
		return;
	}
	int key = start; //pivot 값
	int i = start + 1; //시작하는값
	int j = end; // 뒤에서 시작하는값
	int temp; // 임시변수

	while(i <= j) { // 엇갈릴때까지 반복 (i>j)일때까지
		while (data[i] <= data[key]) { // 키 값보다 큰값을 만날때까지 오른쪽으로 이동
			i++;
		}
		while (data[j] >= data[key]&&j>start) { // 키 값보다 작은값을 만날때까지 왼쪽으로 이동
			j--; // start보다는 커야함
		}
		if (i > j) { // 현재 엇갈린 상태면 키 값과 교체
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		else {
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	quickSort(data, start, j - 1);
	quickSort(data, j+1, end);
}
int main(void) {
	quickSort(data, 0, number - 1);
	for (int i = 0; i < number; i++) {
		printf("%d ", data[i]);
	}


	return 0;
}
