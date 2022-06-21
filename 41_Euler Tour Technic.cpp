// 출처 : https://david0506.tistory.com/55
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;

int st[500001],en[500001], cnt=0;
vector<int> adj[500001];

void dfs(int x,int par){
    st[x] = ++cnt;
    for(int next : adj[x]){
        if(next == par) continue;
        dfs(next,x);
    }
    en[x] = cnt;
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    return 0;
}