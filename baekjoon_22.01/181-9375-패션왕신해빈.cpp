#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int T;
  cin >> T;
  
  for(int i = 0; i<T; ++i){
    int n;
    cin >> n;
    map<string, int> types;
    string type, name;
    for(int j = 0; j<n; ++j){
      cin >> name >> type;
      types[type]++;
    }
    int ret = 1;
    for(auto aut : types){
      ret *= (aut.second+1);
    }
    ret -=1;
    cout << ret << '\n';
  }
}