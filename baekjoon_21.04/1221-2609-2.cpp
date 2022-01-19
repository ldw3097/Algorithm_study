#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  unsigned a, b;
  cin >> a >> b;
  unsigned gcd;
  for(int i = min(a,b); i>=1; --i){
    if(a%i == 0 && b%i == 0){
      gcd = i;
      break;
    }
  }

  cout << gcd << '\n' << a/gcd*b;
  return 0;
}