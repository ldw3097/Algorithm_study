#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N, M;
  cin >> N >> M;
  map<int, string> intmap;
  map<string,int> stringmap;
  string temp;
  for(int i=1; i<=N; ++i){
    cin >> temp;
    intmap.emplace(i, temp);
    stringmap.emplace(temp, i);
  }
  for(int i=0; i<M; ++i){
    cin >> temp;
    if(isdigit(temp[0])){
      cout << intmap.at(stoi(temp)) << '\n';
    }else{
      cout << stringmap.at(temp) << '\n';
    }
  }
}