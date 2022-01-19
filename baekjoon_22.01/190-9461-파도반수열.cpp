#include<bits/stdc++.h>
using namespace std;


int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int T;
  cin >> T;
  array<unsigned long ,100> arr{1, 1, 1, 2, 2, 3, 4, 5, 7, 9};
  for(int i = 10; i<100; ++i){
    arr[i] = arr[i-1] + arr[i-5];
  }
  for(int i = 0; i<T; ++i){
    int inp;
    cin >> inp;
    cout << arr[inp-1] << '\n';
  }
}