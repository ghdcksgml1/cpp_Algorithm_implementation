#include <iostream>
#include <string.h>
#define MAXN 17
#define INF 987654321

using namespace std;

int N;
int cache[MAXN][1 << MAXN];
int W[MAXN][MAXN];

int dp(int here,int visited){
  int ret = cache[here][visited];
  if(ret != -1) return ret;

  ret = INF;
  if(visited == (1<<N)-1) // 모든 마을을 방문했을 때
    return ret = W[here][0]; // 0번 마을로 복귀
  
  for(int there=1;there<N;there++){
    if(!(visited & (1<<there))){
      int next_visited = visited | (1<<there);
      ret = min(ret, dp(there,next_visited)+W[here][there]);
    }
  }
  return ret;
}

int main() {
  cin>>N;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin>>W[i][j];
      if(W[i][j] == 0) W[i][j]=INF;
    }
  }
  memset(cache,-1,sizeof(cache));
  cout<<dp(0,1)<<'\n';
  return 0;
} 