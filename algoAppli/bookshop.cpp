#include <bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, x;
  cin >> n >> x;
  array<int, 100001> arr {};
  array<int, 1000> price {};
  array<int, 1000> page {} ;
  for(int i=0; i<n; i++){
    cin >> price[i];
  }
  for(int i=0; i<n; i++){
    cin >> page[i];
  }
  queue<int> changed;
  changed.emplace(0);
  while(!changed.empty()){
    int prechanged = changed.front();
    changed.pop();
    for(int i=0; i<n; ++i){
      if(price[i]+prechanged > x) continue;
      if(page[i] + arr[prechanged] > arr[prechanged+price[i]] ){
        arr[prechanged+price[i]] = page[i] + arr[prechanged];
        changed.emplace(prechanged+price[i]);
        cout << prechanged+price[i] << ' ' << arr[prechanged+price[i]] <<'\n';
      }
    }
  }

  for(int i = x; i>0; --i){
    if(arr[i] != 0){
      cout << arr[i];
      break;
    }
  }
}