#include <bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N,M;
  cin >> N >> M;
  map<string, string> mp;
  string tmp1;
  string tmp2;
  for(int i=0; i<N; ++i){
    cin >> tmp1 >> tmp2;
    mp.emplace(tmp1, tmp2);
  }
  for(int i=0; i<M; ++i){
    cout << mp[*istream_iterator<string>(cin)] << '\n';
  }
}