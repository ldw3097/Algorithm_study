#include <bits/stdc++.h>
using namespace std;
int N;
array<int, 100> tree;

int oyabun(int x) {
  while (tree[x] != x) {
    x = tree[x];
  }
  return x;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N;
  for (int i = 0; i < 100; ++i) {
    tree[i] = i;
  }
  bool inp;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> inp;
      if (inp) {
        int big = max(i, j);
        int smol = min(i, j);
        tree[big] = smol;
      }
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cout << (oyabun(i) == oyabun(j)) << ' ';
    }
    cout << '\n';
  }
}