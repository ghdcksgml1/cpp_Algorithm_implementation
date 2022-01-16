#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll N,M,K;
ll arr[1000001];
vector<ll> tree;
vector<ll> lazy;

ll merge(ll left,ll right){
  return left+right;
}

void propagate(ll node,ll nodeLeft,ll nodeRight){
  if(lazy[node] != 0){
    tree[node] += (nodeRight-nodeLeft+1)*lazy[node];
    if(nodeLeft != nodeRight){
      lazy[node*2] += lazy[node];
      lazy[node*2+1] += lazy[node];
    }
    lazy[node] = 0;
  }
}

ll buildRec(ll node,ll nodeLeft,ll nodeRight){
  if(nodeLeft == nodeRight)
    return tree[node] = arr[nodeLeft];

  ll mid = (nodeLeft + nodeRight) / 2;
  ll leftVal = buildRec(node*2,nodeLeft, mid);
  ll rightVal = buildRec(node*2+1,mid+1,nodeRight);

  return tree[node] = merge(leftVal,rightVal);
}

ll queryRec(ll left,ll right,ll node,ll nodeLeft,ll nodeRight){
  propagate(node,nodeLeft,nodeRight); // 현재 계층까지 계산
  if(left > nodeRight || right < nodeLeft) return 0;
  if(left<=nodeLeft && nodeRight<=right) return tree[node];

  ll mid = (nodeLeft + nodeRight) / 2;
  ll leftVal = queryRec(left,right,node*2,nodeLeft,mid);
  ll rightVal = queryRec(left,right,node*2+1,mid+1,nodeRight);
  return merge(leftVal,rightVal);
}

void updateRec(ll left,ll right,ll newValue,ll node,ll nodeLeft,ll nodeRight){
  propagate(node,nodeLeft,nodeRight);
  if(left > nodeRight || right < nodeLeft) return;
  if(left<=nodeLeft && nodeRight<=right){
    tree[node] += (nodeRight-nodeLeft+1)*newValue;
    if(nodeLeft != nodeRight){
      lazy[node*2] += newValue;
      lazy[node*2+1] += newValue;
    }
    return;
  }
  ll mid = (nodeLeft + nodeRight) / 2;
  updateRec(left,right,newValue,node*2,nodeLeft,mid);
  updateRec(left,right,newValue,node*2+1,mid+1,nodeRight);
  tree[node] = merge(tree[node*2],tree[node*2+1]);
  return;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin>>N>>M>>K;
  for(int i=1;i<=N;i++){
    cin>>arr[i];
  }
  tree.resize(N*4,0);
  lazy.resize(N*4,0);
  buildRec(1,1,N);
  
  for(int i=0;i<M+K;i++){
    ll a,b,c,d;
    cin>>a;
    if(a==1){
      cin>>b>>c>>d;

      updateRec(b,c,d,1,1,N);
      
    }else{
      cin>>b>>c;
      cout<<queryRec(b,c,1,1,N)<<'\n';
    }
  }
}