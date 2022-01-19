#include<bits/stdc++.h>
using namespace std;


int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  array<int, 1001> arr{0,1,2,3};
  for(int i =4; i<=1000; ++i){
    arr[i] = (arr[i-1]+arr[i-2])%10007;
  }
  cout << arr[n];
  
}