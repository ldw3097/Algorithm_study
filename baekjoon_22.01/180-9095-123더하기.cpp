#include<bits/stdc++.h>
using namespace std;

int ways(int remain, int current){
  if(remain == 0) return 1;
  int ret = 0;
  ret += ways(--remain, 1);
  if(current < 3){
    ret += ways(remain, current+1);
  } 
  return ret;
}

int solve(int x){
  int dots = x-1;
  return ways(dots, 1);
}


int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int T;
  cin >> T;
  for(int i = 0; i<T; ++i){
    int n;
    cin >> n;
    cout << solve(n) << '\n';
  }
}