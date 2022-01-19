#include <bits/stdc++.h>
using namespace std;

int main(){
  cout << int();
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N, M;
  cin >> N;
  map<int,int> mp;
  int temp;
  auto itr = mp.begin();
  for(int i= 0; i<N;++i){
    cin >> temp;
    itr = mp.find(temp);
    if(itr == mp.end()) mp.emplace(temp, 1);
    else ++mp.at(temp);
  }
  cin >> M;
  for(int i=0;i<M;++i){
    cin >> temp;
    itr = mp.find(temp);
    if(itr ==mp.end()) cout << "0 ";
    else cout << itr->second << ' ';
  }
}