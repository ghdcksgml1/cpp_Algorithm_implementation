// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 9156 KB , 시간 : 168 ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#include <math.h>
#define SIZE 100001

using namespace std;

struct Query{
    int idx,start,end;
    Query(int idx,int start,int end){
        this->idx = idx;
        this->start = start;
        this->end = end;
    }
};

vector<Query> q;
int sqrt_N;
int arr[SIZE];
int mo_res[SIZE];
int cnt_num[SIZE];

// mo's 알고리즘
bool compare(Query a, Query b){
    int x = a.start / sqrt_N;
    int y = b.start / sqrt_N;
    if(x==y) return a.end < b.end;
    return x < y;
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N; sqrt_N = sqrt(N);
    for(int i=1;i<=N;i++){
        cin>>arr[i];
    }

    int M; cin>>M;
    for(int i=0;i<M;i++){
        int a,b; cin>>a>>b;
        q.push_back({i,a,b});
    }

    sort(q.begin(),q.end(),compare);

    int cnt=0;
    int st=q[0].start, en=q[0].end;
    for(int i=st;i<=en;i++){
        if(cnt_num[arr[i]]==0) cnt+=1;
        cnt_num[arr[i]]++;
    }
    mo_res[q[0].idx] = cnt;

    for(int i=1;i<M;i++){
        cnt = 0;
        while (st > q[i].start){
            st--;
            if(cnt_num[arr[st]]==0) cnt+=1;
            cnt_num[arr[st]]++;
        }
        while (st < q[i].start){
            cnt_num[arr[st]]--;
            if(cnt_num[arr[st]]==0) cnt-=1;
            st++;
        }
        while (en > q[i].end){
            cnt_num[arr[en]]--;
            if(cnt_num[arr[en]]==0) cnt-=1;
            en--;
        }
        while (en < q[i].end){
            en++;
            if(cnt_num[arr[en]]==0) cnt+=1;
            cnt_num[arr[en]]++;
        }
        mo_res[q[i].idx] = mo_res[q[i-1].idx] + cnt;
    }

    for(int i=0;i<M;i++){
        cout<<mo_res[i]<<'\n';
    }

    return 0;
}