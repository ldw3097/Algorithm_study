#include <bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int T;
  cin >> T;
  map<int, pair<int,int>> number;
  number.insert({0, {1,0}});
  number.insert({1,{0,1}});
  for(int i = 2; i<=40; ++i){
    number.insert({i, {number[i-2].first+number[i-1].first, number[i-2].second+number[i-1].second}});
  }
  for(int i=0; i<T; ++i){
    int temp;
    cin >> temp;
    cout << number[temp].first << ' ' << number[temp].second << '\n';
  }
  return 0;
}