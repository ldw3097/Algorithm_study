#include <bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  array<int, 500001> arr{};
  for(int i=1; i<=223; ++i){
    arr[i*i] = 1;
  }
  int a, b, low;
  for(int i=2; i<=50000; ++i){
    if(arr[i] == 1) continue;
    low = 4;
    a= i-1;
    b=1;
    while(a >= b){
      if(arr[a] + arr[b] < low) low = arr[a] + arr[b]; 
      --a; ++b;
    }
    arr[i] = low;
  }
  cout << arr[n];
}