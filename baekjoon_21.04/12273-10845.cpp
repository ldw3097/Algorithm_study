#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N;
  cin >> N;
  queue<int> que;
  string tmp;
  for (int i = 0; i < N; ++i) {
    cin >> tmp;
    if (tmp == "push") {
      que.push(*istream_iterator<int>(cin));
    } else if (tmp == "pop") {
      if (que.empty())
        cout << -1 << '\n';
      else {
        cout << que.front() << '\n';
        que.pop();
      }
    } else if (tmp == "size") {
      cout << que.size() << '\n';
    } else if (tmp == "empty") {
      cout << que.empty() << '\n';
    } else if (tmp == "front") {
      if (que.empty())
        cout << -1 << '\n';
      else {
        cout << que.front() << '\n';
      }
    } else {
      if (que.empty())
        cout << -1 << '\n';
      else {
        cout << que.back() << '\n';
      }
    }
  }
}