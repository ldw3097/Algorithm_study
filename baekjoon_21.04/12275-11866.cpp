#include <bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N, K;
  cin >> N >> K;
  list<int> lst;
  auto itr = lst.begin();
  for(int i = 1; i<=N; ++i){
    lst.push_back(i);
  }
  cout << '<';
  itr = lst.begin();
  while(!lst.empty()){
    for(int i =1;i<K;++i){
      advance(itr,1);
      if(itr == lst.end()) itr = lst.begin();
    }
    cout << *itr;
    if(lst.size() >1) cout << ", ";
    itr = lst.erase(itr);
    if(itr == lst.end()) itr = lst.begin();
  }
  cout << '>';
}