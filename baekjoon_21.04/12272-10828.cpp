#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N;
  cin >> N;
  stack<int> stk;
  string tmp;
  for (int i = 0; i < N; ++i) {
    cin >> tmp;
    if (tmp == "push") {
      stk.push(*istream_iterator<int>(cin));
    } else if (tmp == "pop") {
      if (stk.empty())
        cout << -1 << '\n';
      else {
        cout << stk.top() << '\n';
        stk.pop();
      }
    } else if (tmp == "size") {
      cout << stk.size() << '\n';
    } else if (tmp == "empty") {
      cout << stk.empty() << '\n';
    } else {
      if (stk.empty())
        cout << -1 << '\n';
      else {
        cout << stk.top() << '\n';
      }
    }
  }
}