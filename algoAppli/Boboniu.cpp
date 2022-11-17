#include <bits/stdc++.h>
using namespace std;



int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  array<int, 200> an ;
  array<int, 200> bm ;
  
  for(int i=0; i<n; ++i){
    cin >> an[i]; 
  }
  for(int i=0; i<m; ++i){
    cin >> bm[i];
  }
  array<set<int>, 200> possible;
  for(int i=0; i<n; ++i){
    for(int j=0; j<m; ++j){
      possible[i].insert(an[i] & bm[j]);
    }
  }
  int ret =0;
  for(int i=256; i>0; i=i/2){
    array<set<int>, 200> backup = possible;
    for(int j=0; j<n; j++){
      set<int> tempset;
      for(auto aut : possible[j]){
        if(i & aut) tempset.insert(aut);
      }
      for(auto aut : tempset){
        possible[j].erase(aut);
      }
      if(possible[j].empty()){
        possible = backup;
        ret = ret | i;
        break;
      }
    }
  }
  cout << ret;

}