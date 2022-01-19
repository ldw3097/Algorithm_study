#include <bits/stdc++.h>
using namespace std;
#define limit 1000000

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N;
  cin >> N;
  queue<int> que;
  array<int,1000001> mp{};
  que.push(1);
  mp.at(1) = 0;
  while(!que.empty()){
    int temp = que.front();
    que.pop();
    int temp3 = temp*3;
    int temp2 = temp*2;
    int temp1 = temp +1;
    int comparer = mp.at(temp)+1;
    if(temp3 <= limit){
      if(mp.at(temp3)==0 || mp.at(temp3) > mp.at(temp)+1){
        que.push(temp3);
        mp[temp3] = mp.at(temp)+1;
      }
    }
    if(temp2 <= limit){
      if(mp.at(temp2)==0 || mp.at(temp2) > mp.at(temp)+1){
        que.push(temp2);
        mp[temp2] = mp.at(temp)+1;
      }
    }
    if(temp1 <= limit){
      if(mp.at(temp1)==0 || mp.at(temp1) > mp.at(temp) +1){
        que.push(temp1);
        mp[temp1] = mp.at(temp) +1;
      }
    }
  }
  cout << mp.at(N);

}