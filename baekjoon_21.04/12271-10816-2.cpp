#include <bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N, M;
  cin >> N;
  map<int,int> mp;
  int temp;
  auto itr = mp.begin();
  for(int i= 0; i<N;++i){
    cin >> temp;
    mp[temp] = mp[temp] +1;
  }
  cin >> M;
  for(int i=0;i<M;++i){
    cin >> temp;
    cout << mp[temp] << ' ';
  }
}