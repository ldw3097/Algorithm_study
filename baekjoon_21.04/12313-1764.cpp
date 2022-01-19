#include <bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N, M;
  cin >> N >> M;
  set<string> mp;
  set<string> mp2;
  for(int i=0; i<N; ++i){
    mp.insert(*istream_iterator<string>(cin));
  }
  string temp;
  for(int i=0; i<M; ++i){
    cin >> temp;
    if(mp.find(temp) != mp.end()){
      mp2.insert(temp);
    }
  }
  cout <<mp2.size() << '\n';
  for(string s : mp2){
    cout << s << '\n';
  }
}