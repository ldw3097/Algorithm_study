#include <bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int twos = 0;
  int fives= 0;
  int N;
  cin >> N;
  int temp;
  for(int i=2; i<=N; ++i){
    temp = i;
    while(temp%2 == 0){
      ++twos;
      temp /= 2;
    }
    while (temp%5 == 0){
      ++fives;
      temp /= 5;
    }
  }
  cout << min(twos, fives);
}