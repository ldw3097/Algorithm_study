#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  array<int, 100> stud;
  for(int i=0; i<n; ++i){
    cin >> stud[i];
  }
  sort(&stud[0], &stud[n]);
  int sums = 0;
  for(int i=0; i<n; i+=2){
    sums += stud[i+1] - stud[i];
  }
  cout << sums;
}