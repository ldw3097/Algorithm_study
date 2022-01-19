#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int K;
  cin >> K;
  stack<int> stk;
  int temp;
  for(int i=0; i<K; i++){
    cin >> temp;
    if(temp == 0) stk.pop();
    else stk.push(temp);
  }
  temp = 0;
  while(!stk.empty()){
    temp += stk.top();
    stk.pop();
  }
  cout << temp;
}