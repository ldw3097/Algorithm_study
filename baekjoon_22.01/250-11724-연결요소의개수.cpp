#include <bits/stdc++.h>
using namespace std;
array<int, 1001> arr;
int find(int n){
  if(arr[n] == n) return n;
  else return find(arr[n]);
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N, M;
  cin >> N >> M;
  for(int i= 1; i<=N; ++i){
    arr[i] = i;
  }
  for(int i=0; i<M; ++i){
    int a, b;
    cin >> a >> b;
    int am, bm;
    am = find(a);
    bm = find(b);
    if(am > bm) arr[am] = bm;
    else if(am < bm) arr[bm] = am;
  }
  int ret = 0;
  for(int i = 1; i<= N; ++i){
    if(arr[i] == i) ++ret;
  }
  cout << ret;
}