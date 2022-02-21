#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int number = 6;
int INF = 1000000000;

vector<pair<int, int>> a[7]; // 간선 정보입니다.
int d[7]; // 최소 비용입니다.

void dijkstra(int start) {
	d[start] = 0;
	priority_queue<pair<int, int>> pq; // 힙 구조 입니다.
	pq.push(make_pair(0, start)); // 본인은 0
	// 가까운 순서대로 처리하므로 큐를 사용합니다.
	while (!pq.empty()) {
		int current = pq.top().second;
		// 짧은 것이 먼저 오도록 음수화(-)합니다.
		int distance = -pq.top().first;
		pq.pop();
		// 최단 거리가 아닌경우 스킵합니다.
		if (d[current] < distance) continue;
		for (int i = 0; i < a[current].size(); i++) {
			// 선택된 노드의 인접 노드
			int next = a[current][i].second;
			// 선택된 노드를 인접 노드로 거쳐서 가는 비용
			int nextDistance = distance + a[current][i].first;
			// 기존의 최소 비용보다 더 저렴하다면 교체합니다.
			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push(make_pair(-nextDistance, next));
			}
		}
	}
}
int main(void) {
	// 기본적으로 연결되지 않은 경우 비용은 무한입니다.
	for (int i = 1; i <= number; i++) {
		d[i] = INF;
	}

	a[1].push_back(make_pair(2, 2));
	a[1].push_back(make_pair(5, 3));
	a[1].push_back(make_pair(1, 4));

	a[2].push_back(make_pair(2, 1));
	a[2].push_back(make_pair(3, 3));
	a[2].push_back(make_pair(2, 4));

	a[3].push_back(make_pair(5, 1));
	a[3].push_back(make_pair(3, 2));
	a[3].push_back(make_pair(3, 4));
	a[3].push_back(make_pair(1, 5));
	a[3].push_back(make_pair(5, 6));

	a[4].push_back(make_pair(1, 1));
	a[4].push_back(make_pair(2, 2));
	a[4].push_back(make_pair(3, 3));
	a[4].push_back(make_pair(1, 5));

	a[5].push_back(make_pair(1, 3));
	a[5].push_back(make_pair(1, 4));
	a[5].push_back(make_pair(2, 6));

	a[6].push_back(make_pair(5, 3));
	a[6].push_back(make_pair(2, 5));

	dijkstra(1);

	// 결과를 출력합니다.
	for (int i = 1; i <= number; i++) {
		printf("%d ", d[i]);
	}
}

// ------------------------ 다른 버전 -------------------------------

// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#include <queue>

using namespace std;

#define X first
#define Y second

int v,e,st;

// {비용, 정점 번호}
vector<pair<int,int>> adj[20005];
const int INF = 1e9+10;
int d[20005];

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>v>>e>>st;
    fill(d,d+v+1,INF);

    while(e--){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({w,v});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    d[st] = 0;
    pq.push({d[st],st});

    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(d[cur.Y] != cur.X) continue; // 거리가 다르면 원소를 버린다.
        for(auto nxt: adj[cur.Y]){
            if(d[nxt.Y] <= d[cur.Y]+nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y],nxt.Y});
        }
    }

    for(int i=1;i<=v;i++){
        if(d[i] == INF) cout << "INF\n";
        else cout<<d[i]<<"\n";
    }

    return 0;
}
