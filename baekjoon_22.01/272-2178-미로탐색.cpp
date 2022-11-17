#include <bits/stdc++.h>
using namespace std;
int N, M;
array<array<bool, 102>, 102> maze{};
array<array<int, 102>, 102> step;

bool changeable(int y, int x, int newstep) {
  if (maze[y][x] == 1 && step[y][x] > newstep) {
    return true;
  } else
    return false;
}

void bfs() {
  step[1][1] = 1;
  queue<pair<int, int>> que;
  que.emplace(1, 1);
  while (!que.empty()) {
    auto top = que.front();
    que.pop();
    int stepafter = step[top.first][top.second] + 1;
    if (changeable(top.first - 1, top.second, stepafter)) {
      step[top.first - 1][top.second] = stepafter;
      que.emplace(top.first - 1, top.second);
    }
    if (changeable(top.first + 1, top.second, stepafter)) {
      step[top.first + 1][top.second] = stepafter;
      que.emplace(top.first + 1, top.second);
    }
    if (changeable(top.first, top.second - 1, stepafter)) {
      step[top.first][top.second - 1] = stepafter;
      que.emplace(top.first, top.second - 1);
    }
    if (changeable(top.first, top.second + 1, stepafter)) {
      step[top.first][top.second + 1] = stepafter;
      que.emplace(top.first, top.second + 1);
    }
  }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N >> M;
  cin.get();
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      maze[i][j] = cin.get() - 48;
    }
    cin.get();
  }
  for (auto& a : step) {
    a.fill(987654321);
  }
  bfs();
  cout << step[N][M];
}