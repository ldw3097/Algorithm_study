#include <bits/stdc++.h>
using namespace std;

bool solve(){
  int n, t;
  cin >> n >> t;
  if(n == 0) return 0;
  array<array<int, 50>, 50> time;
  array<array<int, 50>, 50> toll;
  for(int i=0; i<n; ++i){
    for(int j=0; j<n; ++j){
      cin >> time[i][j];
    }
  }
  for(int i=0; i<n; ++i){
    for(int j=0; j<n; ++j){
      cin >> toll[i][j];
    }
  }
  
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  
  while(solve()){
    
  }

}