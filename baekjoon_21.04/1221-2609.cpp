#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  unsigned a, b;
  cin >> a >> b;
  unsigned aa = a;
  unsigned bb = b;
  unsigned temp;
  unsigned gcd = 1, lcm = 1;
  bool again = true;
  while (again) {
    temp = 2;
    while (1) {
      if (aa % temp == 0 && bb % temp == 0){
        gcd *= temp;
        aa /= temp; bb/=temp;
        break;
      }else if (aa < temp || bb < temp) {
        again = false;
        break;
      }
      ++temp;
    }
  }
  cout << gcd << '\n' << a/gcd*b;
  return 0;
}