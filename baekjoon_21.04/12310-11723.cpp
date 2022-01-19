#include <bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  array<bool, 21> arr{};
  int M;
  cin >> M;
  string inp;
  int inp2;
  for(int i=0; i<M; ++i){
    cin >> inp;
    if(inp=="add"){
      cin >> inp2;
      arr[inp2] = 1;
    }else if(inp =="remove"){
      cin >> inp2;
      arr[inp2] = 0;
    }else if(inp == "check"){
      cin >> inp2;
      cout << arr[inp2] << '\n';
    }else if(inp == "toggle"){
      cin >> inp2;
      arr[inp2] = !arr[inp2];
    }else if(inp == "all"){
      arr.fill(1);
    }else{
      arr.fill(0);
    }
  }
}