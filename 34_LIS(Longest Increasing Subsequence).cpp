// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

#define ALL(x) begin(x), end(x)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define xx first
#define yy second
#define MAX 1000010

using namespace std;
typedef long long ll;

int arr[MAX];
int L[MAX];
int P[MAX];

vector<int> result;

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;

    int len = 0;
    int idx;
    for(int i=0;i<N;i++){
        cin>>arr[i];
        idx = lower_bound(L,L+len,arr[i]) - L;
        L[idx] = arr[i]; // 현재 숫자정보
        P[i] = idx; // 몇번재 인덱스인지
        if(idx == len) len++;
    }

    cout<<len<<'\n';
    
    // 인덱스 추적하기
    len--;

    for(int i=N-1;i>=0;i--){
        if(len < 0) break;
        if(P[i] == len){
            result.push_back(arr[i]);
            len--;
        }
    }

    for(int i=result.size()-1;i>=0;i--){
        cout<<result[i]<<' ';
    }

    return 0;
}
