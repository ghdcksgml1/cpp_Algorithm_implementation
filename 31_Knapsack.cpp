#include <iostream>
#include <vector>

using namespace std;

int dp[1000][10000];
vector<pair<int,int>> infor;

int main(void){
  int N,M;
  cin>>N>>M;
  infor.push_back({0,0});
  for(int i=0;i<N;i++){
    int v,c;
    cin>>v>>c;
    infor.push_back({v,c});
  }
  int Max = 0;
  for(int i=1;i<=infor.size();i++){
    for(int j=1;j<=M;j++){
      if(infor[i].first<=j) // j보다 무게가 낮을경우 즉, 배낭에 보석을 넣을 수 있을때
        dp[i][j] = max(dp[i-1][j],infor[i].second+dp[i-1][j-infor[i].first]);
      else // 무게가 높은경우에는 전에꺼 넣기
        dp[i][j] = dp[i-1][j];

      Max = max(Max,dp[i][j]);
    }
  }
  cout<<Max<<'\n';
}