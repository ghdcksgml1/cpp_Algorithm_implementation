#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#define MAX 18

using namespace std;

int N,M;
int parent[100001][MAX];
int depth[100001];
vector<int> adj[100001];

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // 간선 정보 받아오기
    cin>>N;
    for(int i=0;i<N-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v); // 양방향으로 설정
        adj[v].push_back(u);
    }

    memset(parent,-1,sizeof(parent));
    fill(depth,depth+N+1,-1); // depth를 -1로 초기화한다.
    depth[1] = 0;
    // DFS를 통해 깊이를 저장한다.
    stack<int> st;
    st.push(1);
    while(!st.empty()){
        int cur = st.top();st.pop();
        for(auto next: adj[cur]){
            if(depth[next] == -1){
                parent[next][0] = cur; // 2^0 일때 1만큼 떨어져있는 부모
                depth[next] = depth[cur] + 1;
                st.push(next);
            }
        }
    }

    // 2^j 부모를 저장한다.
    for(int j=0;j<MAX-1;j++){
        for(int i=2;i<=N;i++){
            if(parent[i][j] != -1)
                parent[i][j+1] = parent[parent[i][j]][j]; // 2^j+1에 부모의 2^j를 넣는다.
        }
    }

    cin>>M;
    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;

        // v가 u보다 깊다면 바꾸기
        if(depth[u] < depth[v]) swap(u,v);
        int diff = depth[u] - depth[v];

        // 최대한 깊이 차이 줄이기 2^0 => 2^1 => 2^2 ...
        for(int j=0;diff;j++){
            if(diff%2 == 1) u=parent[u][j];
            diff /= 2;
        }

        // u와 v가 다르다면
        if(u != v){
            for(int j=MAX-1;j>=0;j--){
                // 부모가 같아질때까지 줄여나간다.
                if(parent[u][j] != -1 && parent[u][j] != parent[v][j]){
                    u = parent[u][j];
                    v = parent[v][j];
                }
            }
            u = parent[u][0];
        }
        cout<<u<<'\n';
    }

    return 0;
}