#include <bits/stdc++.h>
using namespace std;
int n, m;
array<int, 500000> tree{};
array<int, 500000> numtree{};
array<int, 200001> A{};
array<int, 200001> numA{};
int group;
int treemax;

//(1,0,n-1)
// 1,1,n

void build(int node, int start, int end) {
  if (start == end) {
    tree[node] = A[start];
  } else {
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
  }
}


void buildnum(int node, int start, int end) {
  if (start == end) {
    numtree[node] = numA[start];
  } else {
    int mid = (start + end) / 2;
    buildnum(2 * node, start, mid);
    buildnum(2 * node + 1, mid + 1, end);
  }
}


int queryAndUpdate(int node, int lend) {
  if (2 * node > treemax) {
    tree[node] -= lend;
    return numtree[node];
  }
  int index = -1;
  if (tree[2 * node] >= lend) {
    index = queryAndUpdate(2 * node, lend);
  } else {
    index = queryAndUpdate(2 * node + 1, lend);
  }
  tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
  return index;
}

int gettreemax(){
  for(int i=1; i<=200001; ++i){
    if(numtree[i] == n){
      return i;
    }
  }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
    numA[i] = i;
  }
  build(1, 1, n);
  buildnum(1,1,n);
  treemax = 1 << (ceil(log2(n)) +1) ;
  cout << treemax << '\n';
  for(int i=0; i<=treemax; ++i){
    cout << numtree[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> group;
    if(group > tree[1]){
      cout << 0 << ' ';
    }else{
      cout << queryAndUpdate(1, group) << ' ';
    }
  }
  
}
