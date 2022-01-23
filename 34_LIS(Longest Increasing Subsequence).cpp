#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h> // memset

using namespace std;

int N;
int arr[1000010];
int L[1000010];
int P[1000010];
vector<int> result;


int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N;

    int len = 0;
    int idx;
    for(int i=0;i<N;i++){
        cin>>arr[i];
        int st = 0,en=len,target=arr[i];
        while(st < en){
            int mid = (st+en) / 2;
            if(L[mid] >= target) en = mid;
            else st = mid+1;
        }
        idx = st;
        L[idx] = arr[i];
        P[i] = idx;
        if(idx == len) {
            len++;
        }
    }

    cout<<len<<'\n';
    len-=1;
    string res = "";
    for(int i=N-1;i>=0;i--){
        if(P[i] == len){
            result.push_back(arr[i]);
            len -= 1;
        }
        if(len == -1) break;
    }

    for(int i=result.size()-1;i>=0;i--){
        cout<<result[i]<<' ';
    }
    return 0;
}