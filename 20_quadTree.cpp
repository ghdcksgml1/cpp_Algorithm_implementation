#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <memory.h>
int blue = 0;
int white = 0;

void quadTree(char** data, int beginX, int beginY, int size) {
	int is1 = 0;
	for (int y = beginY; y < beginY + size; y++) {
		for (int x = beginX; x < beginX + size; x++) {
			if (data[y][x] - 48 == 1) {
				is1++;
			}
		}
	}
	if (is1 == size * size) {
		blue++;
		return;
	}
	if (is1 == 0) {
		white++;
		return;
	}
	int halfSize = size / 2;
	quadTree(data, beginX, beginY, halfSize);
	quadTree(data, beginX + halfSize, beginY, halfSize);
	quadTree(data, beginX, beginY + halfSize, halfSize);
	quadTree(data, beginX + halfSize, beginY + halfSize, halfSize);
}
int main(void) {
	int dataSize = 0;
	scanf("%d", &dataSize);

	char** data = (char**)malloc(sizeof(char*) * dataSize);
	for (int i = 0; i < dataSize; i++) {
		data[i] = (char*)malloc(sizeof(char) * (dataSize + 1));
		memset(data[i], 0, sizeof(data[i])); // 0으로 초기화
	}
	for (int i = 0; i < dataSize; i++) {
		for (int j = 0; j < dataSize; j++) {
			scanf("%s", &data[i][j]);
		}
	}
	quadTree(data, 0, 0, dataSize);
	printf("%d\n%d\n", white, blue);
}