#include <bits/stdc++.h>
using namespace std;
int N;
array<array<bool, 100>, 100> tree;

void augment(int y) {
  queue<int> que;
  for (int i = 0; i < N; ++i) {
    if (tree[y][i]) que.push(i);
  }
  while (!que.empty()) {
    int poper = que.front();  // front임
    que.pop();
    for (int i = 0; i < N; ++i) {
      if (tree[poper][i] && !tree[y][i]) {
        que.push(i);
        tree[y][i] = 1;
      }
    }
  }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N;
  bool inp;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> inp;
      tree[i][j] = inp;
    }
  }
  for (int i = 0; i < N; ++i) {
    augment(i);
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cout << tree[i][j] << ' ';
    }
    cout << '\n';
  }
}