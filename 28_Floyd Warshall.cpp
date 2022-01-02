// https://youtu.be/YiGxC9hAg4s?t=210
#include <iostream>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f;
vector<vector<int>> dist;
vector<pair<int,int>> edges[4];
int N=4;


void floydWarshall(){
  dist.assign(N,vector<int>(N,INF));

  for(int i=0;i<N;i++){
    dist[i][i] = 0;
    for(auto& e: edges[i])
    dist[i][e.first] = e.second;
  }
  for(int k=0;k<N;k++){
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        if(dist[i][j] > dist[i][k] + dist[k][j])
          dist[i][j] = dist[i][k] + dist[k][j];
      }
    }
  }
}

int main(void){
  edges[0].push_back({2,2});
  edges[0].push_back({1,-5});
  edges[1].push_back({2,4});
  edges[2].push_back({3,1});
  edges[3].push_back({0,3});

  floydWarshall();
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cout<<dist[i][j]<<' ';
    }
    cout<<'\n';
  }
}
// 실행결과
// 0 -5 -1 0 
// 8 0 4 5 
// 4 -1 0 1 
// 3 -2 2 0