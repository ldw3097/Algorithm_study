#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  while (1) {
    cin >> a >> b;
    if (cin.fail())
      break;  //모든 입력이 소모되고 나서 cin을 한번 더 해야 eof가 읽혀
              //cin.eof()가 true가 됩니다.
    cout << a + b << '\n';
  }
  return 0;
}