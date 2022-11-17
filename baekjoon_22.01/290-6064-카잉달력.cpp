#include<bits/stdc++.h>
using namespace std;
int T;
int M, N, x, y;

int solve(){
  int diff = y-x;
  int max = lcm(N,M);  // c++17부터 가능. gcd()도
  while(diff<max){
    if(diff%M == 0) return diff+x;
    else diff += N;
  }
  return -1;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> T;
  for(int i=0; i<T; ++i){
    cin >> M >> N >> x >> y;
    cout << solve() << '\n';
  }
}