#include <bits/stdc++.h>
using namespace std;

int func(int N, int M){
  list<int> lst;
  int ret = 0;
  
  for(int i=0; i<N; ++i){
    lst.push_back(*istream_iterator<int>(cin) * 2);
  }
  auto iter = lst.begin();
  advance(iter, M);
  (*iter)++;
  
  for(int i = 9; i>=1; --i){
    iter = lst.begin();
    auto lastdel = lst.end();
    while(iter != lst.end()){
      if(*iter /2 == i){
        if(*iter%2 == 1){
          return ++ret;
        }else{
          iter = lst.erase(iter);
          lastdel = iter;
          ++ret;
        }
      }else ++iter;
    }
    if(lastdel != lst.end()){
      lst.insert(lst.end(), lst.begin(), lastdel);
      lst.erase(lst.begin(), lastdel);
    }
  }
  return -1;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int T;
  cin >> T;
  int N, M;
  
  for(int t=0; t<T; ++t){
    cin >> N >> M;
    cout << func(N, M) <<'\n';
  }
}