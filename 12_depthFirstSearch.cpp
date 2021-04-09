#include <iostream>
#include <vector>

using namespace std;

int number = 7;
int c[8];
vector<int> a[8];

void dfs(int x) {
	if (c[x]) return; // 방문한 곳이면 나가기
	c[x] = true; // 방문했다는 표시
	cout << x << ' '; // 출력
	for (int i = 0; i < a[x].size(); i++) {
		int  y = a[x][i];
		dfs(y);
	}
}

int main(void) {
	a[1].push_back(2);
	a[2].push_back(1);
	a[1].push_back(3);
	a[3].push_back(1);
	a[2].push_back(3);
	a[3].push_back(2);
	a[2].push_back(4);
	a[4].push_back(2);
	a[2].push_back(5);
	a[5].push_back(2);
	a[4].push_back(5);
	a[5].push_back(4);
	a[3].push_back(6);
	a[6].push_back(3);
	a[3].push_back(7);
	a[7].push_back(3);
	a[6].push_back(7);
	a[7].push_back(6);
	dfs(1);
}

