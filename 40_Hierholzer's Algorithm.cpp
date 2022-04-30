// 오일러 회로
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;

struct Edge{
    int i,j;
    int cnt;
};

vector<Edge> edges;
vector<int> adj[1001];
vector<int> ans;

void dfs(int i){
    while(adj[i].size()){
        int ei = adj[i].back(); // ei는 edges의 인덱스
        if(edges[ei].cnt){
            edges[ei].cnt--;
            dfs(edges[ei].i + edges[ei].j - i);
        }else{
            adj[i].pop_back();
        }
    }
    ans.push_back(i);
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int v,e; cin>>v>>e;
    for(int i=0;i<e;i++){
        int tmp_a,tmp_b; cin>>tmp_a>>tmp_b;
        edges.push_back({tmp_a,tmp_b,1});
        adj[tmp_a].push_back(edges.size()-1); // edge의 인덱스 저장
        adj[tmp_b].push_back(edges.size()-1); // edge의 인덱스 저장
    }

    dfs(1);

    for(int a: ans){
        cout<<a<<' ';
    }

    return 0;
}