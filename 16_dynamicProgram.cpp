// 하나의 문제를 단 한번만 풀도록하는 알고리즘
// 가정 1. 큰 문제를 작은 문제로 나눌(분할) 수 있습니다.
// 가정 2. 작은 문제에서 구한 정답은 그것을 포함하는 큰 문제에서도 동일합니다.(중요)
// 이미 계산한 결과는 배열에 저장함으로써, 나중에 동일한 계산을 해야할 때에는 저장된 값을
// 단순히 반환하기만 하면 됩니다.

#include <stdio.h>

int d[100]={0, };

int fibonacci(int x) {
	if (x == 1) return 1;
	if (x == 2) return 1;
	if (d[x] != 0) return d[x];
	return d[x] = fibonacci(x - 1) + fibonacci(x - 2);
}

int main(void) {
	printf("%d\n", fibonacci(10));
}