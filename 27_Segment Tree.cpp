// Segement Tree : 구간 합 쿼리, 원소 한개 업데이트 구현
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#define MAX 1000001

using namespace std;
typedef long long ll;

template <class T>
class Tree{
public:
    T value = 0;

    Tree(){
        this->value = 0;
    }

    Tree(T val){
        this->value = val;
    }
};

Tree<ll> tree[MAX*4];

ll arr[MAX];

// 세그먼트 트리 만들기
template <typename T>
T buildRec(T node,T start,T end){
    if(start == end){
        return tree[node].value = arr[start];
    }
    T mid = (start + end) / 2;
    return tree[node].value = buildRec(node*2,start,mid) + buildRec(node*2+1,mid+1,end);
}

// 구간 합
template <typename T>
T queryRec(T left,T right,T node,T start,T end){
    if(left>end || right<start) return 0;
    if(left<=start && end<=end){
        return tree[node].value;
    }
    T mid = (start + end) / 2;
    return queryRec(left,right,node*2,start,mid) + queryRec(left,right,node*2+1,mid+1,end);
}

// 구간 업데이트
template <typename T>
void updateRec(T target,T value,T node,T start,T end){
    if(target>end || target<start) {
        tree[node].value;
        return;
    }
    if(start == end){
        tree[node].value = value;
        return;
    }
    T mid = (start + end) / 2;
    updateRec(target,value,node*2,start,mid);
    updateRec(target,value,node*2+1,mid+1,end);

    tree[node].value = tree[node*2].value + tree[node*2+1].value;
    return ;
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll N; cin>>N;
    for(ll i=1;i<=N;i++){
        cin>>arr[i];
    }

    buildRec<ll>(1,1,N); // 트리 생성

    cout<<queryRec<ll>(1,N,1,1,N)<<'\n'; // 1~N까지의 구간합 출력
    updateRec<ll>(3,10,1,1,N); // 3번째 원소값을 10으로 변경
    cout<<queryRec<ll>(1,N,1,1,N)<<'\n'; // 1~N까지의 구간합 출력

    return 0;
}
