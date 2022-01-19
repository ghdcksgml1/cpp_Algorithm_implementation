#include <iostream>

using namespace std;

int LCS[1001][1001];

void init(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
}

int main(void){
  init();
  string a="";string b="";
  cin>>a>>b;
  int Max = 0;
  for(int i=0;i<=a.length();i++){
    for(int j=0;j<=b.length();j++){
      if(i==0 || j==0)
        LCS[i][j] = 0;
      else if(a[i-1]==b[j-1])
        LCS[i][j] = LCS[i-1][j-1] + 1;
      else
        LCS[i][j] = 0;
      Max = max(Max, LCS[i][j]);
    }
  }
  cout<<Max<<'\n';
  return 0;
}