#include <stdio.h>
// 시간복잡도 : O(N * log N)

int number = 9;
int heap[9] = { 7,6,5,8,3,5,9,1,6 };

int main(void) {
	// 먼저 전체 트리 구조를 최대 힙 구조로 바꿉니다.
	for (int i = 1; i < number; i++) {
		int c = i; // 자식
		do {
			int root = (c - 1) / 2; // 부모
			if (heap[root] < heap[c]) { // 자식의 값이 부모의 값보다크면 둘이 교체
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			c = root; // 자식이 부모로 이동
		} while (c != 0);
	}
	// 크기를 줄여가며 반복적으로 힙을 구성
	for (int i = number - 1; i >= 0; i--) {
		int temp = heap[0]; // 가장 큰 값을 맨 뒤로 보내주기
		heap[0] = heap[i]; 
		heap[i] = temp;
		int root = 0;
		int c = 1;
		do {
			c = 2 * root + 1; // 자식
			//자식중에 더 큰 값을 찾기
			if (heap[c] < heap[c + 1] && c < i - 1) {
				c++;
			}
			// 루트보다 자식이 더 크다면 교환
			if (heap[root] < heap[c] && c < i) {
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			root = c;
		} while (c < i);
	}
	for (int i = 0; i < number; i++) {
		printf("%d ", heap[i]);
	}
}
