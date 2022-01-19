#include <bits/stdc++.h>
using namespace std;

void isEq(string str) {
  auto iter = str.begin();
  stack<char> stk;
  while (iter != str.end()) {
    if (*iter == '(')
      stk.push(*iter);
    else if (*iter == '[')
      stk.push(*iter);
    else if (*iter == ')') {
      if (stk.empty() || stk.top() == '[') {
        cout << "no" << '\n';
        return;
      } else
        stk.pop();  
    } else if (*iter == ']') {
      if (stk.empty() || stk.top() == '(') {
        cout << "no" << '\n';
        return;
      } else {
        stk.pop();
      }
    }
    ++iter;
  }
  if (!stk.empty()) {
    cout << "no" << '\n';
  } else
    cout << "yes" << '\n';
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  string str;
  while (cin.peek() != '.') {
    getline(cin, str);
    isEq(str);
  }
}