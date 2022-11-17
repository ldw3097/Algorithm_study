#include <bits/stdc++.h>
using namespace std;
int a, b, c;


void ret(){
  if(c % gcd(a,b) == 0){
    cout << "Yes";
    return;
  }else{
    cout << "No";
    return;
  }
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> a >> b >> c;
  ret();
}