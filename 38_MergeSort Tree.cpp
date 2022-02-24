// 언어 : C++ , (성공/실패) : 1/2 , 메모리 : 23380 KB , 시간 : 252ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#define SIZE 100001

using namespace std;

vector<int> mst[SIZE*4];
int arr[SIZE];

void buildRec(int node,int start,int end){
    vector<int> &cur = mst[node];
    if(start == end){
        cur.push_back(arr[start]);
        return;
    }
    int mid = (start + end) / 2;
    buildRec(node*2,start,mid);
    buildRec(node*2+1,mid+1,end);

    vector<int> &left = mst[node*2], &right = mst[node*2+1];
    cur.resize(left.size() + right.size());
    merge(left.begin(),left.end(),right.begin(),right.end(),cur.begin());
}

//int queryRec(int left,int right,int node,int start,int end,int target){
//    if(left>end || right<start) return 0;
//    if(left<=start && end<=right){
//        return mst[node].size()-(upper_bound(mst[node].begin(),mst[node].end(),target)-mst[node].begin());
//    }
//    int mid = (start + end) / 2;
//    return queryRec(left,right,node*2,start,mid,target) + queryRec(left,right,node*2+1,mid+1,end,target);
//}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;
    for(int i=1;i<=N;i++){
        cin>>arr[i];
    }

    buildRec(1,1,N);


    return 0;
}