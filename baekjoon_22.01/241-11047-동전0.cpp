#include<bits/stdc++.h>
using namespace std;
int N, K;
int ans = 0;
int main(){
  cin >> N >> K;
  array<int, 10> money;
  for(int i= 0; i<N; ++i){
    cin >> money[i];
  }
  for(int i = N-1; i>=0; --i){
    while(K-money[i] >= 0){
      K -= money[i];
      ++ans;
    }
  }
  cout << ans;
}