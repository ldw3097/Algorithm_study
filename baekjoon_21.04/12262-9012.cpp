#include <bits/stdc++.h>
using namespace std;

void isEq(string str) {
  auto iter = str.begin();
  stack<char> stk;
  while (iter != str.end()) {
    if (*iter == '(')
      stk.push(*iter);
    else {
      if (stk.empty()) {
        cout << "NO" << '\n';
        return;
      } else
        stk.pop(); 
    }
    ++iter;
  }
  if (!stk.empty()) {
    cout << "NO" << '\n';
  } else
    cout << "YES" << '\n';
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int T;
  cin >> T;
  cin.rdbuf()->snextc();
  string str;
  for (int i = 0; i < T; ++i) {
    getline(cin, str);
    isEq(str);
  }
}