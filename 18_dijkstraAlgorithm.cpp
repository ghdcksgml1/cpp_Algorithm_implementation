// 다익스트라 알고리즘
// 다이나믹 프로그래밍을 활용한 대표적인 최단 경로 탐색 알고리즘
// 인공위성 GPS 소프트웨어 등에서 가장많이사용
// 특정한 하나의 정점에서 다른 모든 정점으로 가는 최단 경로를 알려줌

// 1. 출발 노드를 설정합니다.
// 2. 출발 노드를 기준으로 각 노드의 최소 비용을 저장합니다.
// 3. 방문하지 않은 노드 중에서 가장 비용이 적은 노드를 선택합니다.
// 4. 해당 노드를 거쳐서 특정한 노드로 가는 경우를 고려하여 최소 비용을 갱신합니다.
// 5. 위 과정에서 3번~4번을 반복합니다.
// 2차원 배열형태로 처리
// 특정행에서 열로 가는 비용
#include <stdio.h>

int number = 6;
int INF = 1000000000;

// 전체 그래프를 초기화합니다.
int a[6][6] = {
	{0,2,5,1,INF,INF},
	{2,0,3,2,INF,INF},
	{5,3,0,3,1,5},
	{1,2,3,0,1,INF},
	{INF,INF,1,1,0,2},
	{INF,INF,5,INF,2,0}
};
bool v[6]; // 방문한 노드
int d[6]; // 최단거리

// 가장 최소 거리를 가지는 정점을 반환합니다.
int getSmallIndex() {
	int min = INF;
	int index = 0;
	for (int i = 0; i < number; i++) {
		if (d[i] < min && !v[i]) { // 방문하지 않은 노드들 중에서 거리값이 최소값보다 작은 노드를 찾으면
			min = d[i];
			index = i;
		}
	}
	return index;
}

// 다익스트라를 수행하는 함수입니다.
void dijkstra(int start) {
	for (int i = 0; i < number; i++) {
		d[i] = a[start][i];
	}
	v[start] = true;
	for (int i = 0; i < number - 1; i++) {
		int current = getSmallIndex();
		v[current] = true;
		for (int j = 0; j < 6; j++) {
			if (!v[j]) {
				if (d[current] + a[current][j] < d[j]) {
					d[j] = d[current] + a[current][j];
				}
			}
		}
	}
}

int main(void) {
	dijkstra(0);
	for (int i = 0; i < number; i++) {
		printf("%d ", d[i]);
	}
}
// 힙을 이용한 dijkstra구현
//https://blog.naver.com/ndb796/221234424646
