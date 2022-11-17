#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define vc vector<char>
#define limit int

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  limit n;
  cin >> n;
  vi vectortest1;
  vc vectortest2;
  while(1){
    cout << n << ' ';
    if(n==1)break;
    if(n%2 == 1){
      n = n*3+1;
    }else{
      n = n/2;
    }
  }
}