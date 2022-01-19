#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N;
  cin >> N;
  queue<int> que;
  int temp = 1;
  for (int i = 1; i <= N; ++i) {
    que.push(i);
  }
  if (que.size() == 1) {
    cout << que.front();
    return 0;
  }
  while (1) {
    que.pop();
    if (que.size() == 1) {
      cout << que.front();
      return 0;
    }
    que.push(que.front());
    que.pop();
  }
}