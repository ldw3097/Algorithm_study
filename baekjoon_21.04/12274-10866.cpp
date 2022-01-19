#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N;
  cin >> N;
  deque<int> deq;
  string tmp;
  for (int i = 0; i < N; ++i) {
    cin >> tmp;
    if (tmp == "push_front") {
      deq.push_front(*istream_iterator<int>(cin));
    } else if (tmp == "push_back") {
      deq.push_back(*istream_iterator<int>(cin));
    } else if (tmp == "pop_front") {
      if (deq.empty())
        cout << -1 << '\n';
      else {
        cout << deq.front() << '\n';
        deq.pop_front();
      }
    } else if (tmp == "pop_back") {
      if (deq.empty())
        cout << -1 << '\n';
      else {
        cout << deq.back() << '\n';
        deq.pop_back();
      }
    }
    else if (tmp == "size") {
      cout << deq.size() << '\n';
    } else if (tmp == "empty") {
      cout << deq.empty() << '\n';
    } else if (tmp == "front") {
      if (deq.empty())
        cout << -1 << '\n';
      else {
        cout << deq.front() << '\n';
      }
    } else {
      if (deq.empty())
        cout << -1 << '\n';
      else {
        cout << deq.back() << '\n';
      }
    }
  }
}