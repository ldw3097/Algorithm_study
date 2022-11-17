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
  int pos = 0;
  while(pos < n){
    int tempprice = price[pos];
    int temppage = page[pos];
    ++pos;
    if(tempprice > x) continue;
    for(int i=x-tempprice; i>0; i--){
      if(arr[i] != 0){
        if(arr[i+tempprice] < temppage + arr[i]){
          //cout << "i: " << i << "arr[i]: " << arr[i] << "to";
          arr[i+tempprice] = temppage + arr[i];
          //cout << "tempprice: " << tempprice << "result: " << arr[i+tempprice] << '\n';
        }
      }
    }
    if(arr[tempprice] < temppage){
      arr[tempprice] = temppage;
    }
  }

  int biggest = -1;
  for(int i = x; i>0; --i){
    if(arr[i] > biggest){
      biggest = arr[i];
    }
  }
  cout << biggest;
}