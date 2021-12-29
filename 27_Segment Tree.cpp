#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> tree; // segment tree

// 합 구하기
int merge(int left, int right){
  return left+right; // sum
}

// 구간의 합을 tree 벡터에 저장해줌
int buildRec(const int arr[],int node, int nodeLeft, int nodeRight){
  if(nodeLeft == nodeRight){
    return tree[node] = arr[nodeLeft];
  }
  int mid = nodeLeft + (nodeRight - nodeLeft)/2;
  int leftVal = buildRec(arr,node*2,nodeLeft,mid);
  int rightVal = buildRec(arr,node*2+1,mid+1,nodeRight);

  return tree[node] = merge(leftVal,rightVal);
}

// 빌더
int build(const int arr[], int size){
  tree.resize(size*4);
  
  return buildRec(arr,1,0,N-1);
}

// Query로 구간이 주어지면, 구간을 구간 안에 들어가는 segment를
// 찾아서 연산 결과를 구함
// (Build)와 마찬가지로 구간을 2개로 나눠 내려가면서 segment를 찾아나감
int queryRec(int left,int right,int node,int nodeLeft,int nodeRight){
  if(right<nodeLeft || nodeRight < left)
    return 0; // default value

  if(left<=nodeLeft && nodeRight <= right)
    return tree[node];
  
  int mid = nodeLeft + (nodeRight - nodeLeft)/2;
  return merge(queryRec(left, right, node*2, nodeLeft, mid),
              queryRec(left, right, node*2+1, mid+1, nodeRight));
}

//inclusive
int query(int left, int right){
  return queryRec(left, right, 1, 0, N-1);
}

int updateRec(int index,int newValue,int node,int nodeLeft,int nodeRight){
  if(index < nodeLeft || index > nodeRight)
    return tree[node];

  if(nodeLeft == nodeRight)
    return tree[node] = newValue;
  
  int mid = nodeLeft+(nodeRight-nodeLeft)/2;
  int leftVal = updateRec(index, newValue, node*2, nodeLeft, mid);
  int rightVal = updateRec(index, newValue, node*2+1, mid+1, nodeRight);
  return tree[node] = merge(leftVal,rightVal);
}

int update(int index,int newValue){
  return updateRec(index, newValue, 1, 0, N-1);
}

int main(void){
  N = 15;
  int arr[] = {1,3,11,6,7,10,14,9,18,16,5,4,2,8,19};

  cout<<build(arr,N);
  return 0;
}