#include <bits/stdc++.h>
using namespace std;
array<bool, 1001> dfscheck{};
array<bool, 1001> bfscheck{};

void dfs(array<set<int>, 1001>& arr, int start) {
  if (dfscheck[start]) return;
  dfscheck[start] = 1;
  cout << start << ' ';
  for (int i : arr[start]) {
    dfs(arr, i);
  }
}

void bfs(array<set<int>, 1001>& arr, int start) {
  queue<int> que;
  que.push(start);
  while (!que.empty()) {
    int top = que.front();
    cout << top << ' ';
    bfscheck[top] = 1;
    que.pop();

    for (int i : arr[top]) {
      if (bfscheck[i] == 0) {
        bfscheck[i] = 1;
        que.push(i);
      }
    }
  }
}

int main() {
  int N, M, V;
  cin >> N >> M >> V;
  array<set<int>, 1001> arr{};
  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    arr[a].insert(b);
    arr[b].insert(a);
  }
  dfs(arr, V);
  cout << '\n';
  bfs(arr, V);
}