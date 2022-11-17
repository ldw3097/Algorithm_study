#include <bits/stdc++.h>
using namespace std;
int N;
int shark = 2;
int ate = 0;
int ret = 0;
pair<int, int> pos;
pair<int, int> target;
array<array<int, 20>, 20> arr{};
array<array<int, 20>, 20> reach;

bool isValid(int y, int x) {
  if (y < 0 || y >= N) return 0;
  if (x < 0 || x >= N) return 0;
  return 1;
}

void checkPos(int y, int x, queue<pair<int, int>>& bfs, int newReach) {
  if (!isValid(y, x))
    return;
  else if (arr[y][x] > shark)
    return;
  else if (arr[y][x] == shark || arr[y][x] == 0) {
    if (reach[y][x] > newReach) {
      reach[y][x] = newReach;
      bfs.push(make_pair(y, x));
    }
    return;
  } else {
    if (reach[y][x] > newReach) {
      reach[y][x] = newReach;
      bfs.push(make_pair(y, x));
      if (target.first == -1 || reach[target.first][target.second] > newReach) {
        target = make_pair(y, x);
      } else if (reach[target.first][target.second] == newReach) {
        if (target.first > y) {
          target = make_pair(y, x);
        } else if (target.first == y && target.second > x) {
          target = make_pair(y, x);
        }
      }
    }
    return;
  }
}

void Reachs() {
  fill(&reach[0][0], &reach[N - 1][N], 987654321);  // 마지막꺼는 포함이 안됨.
  target.first = -1;
  reach[pos.first][pos.second] = 0;
  queue<pair<int, int>> bfs;
  bfs.push(pos);
  while (!bfs.empty()) {
    pair<int, int> before = bfs.front();
    int newReach = reach[before.first][before.second] + 1;
    bfs.pop();
    checkPos(before.first - 1, before.second, bfs, newReach);
    checkPos(before.first, before.second - 1, bfs, newReach);
    checkPos(before.first + 1, before.second, bfs, newReach);
    checkPos(before.first, before.second + 1, bfs, newReach);
  }
}

void grow() {
  ++ate;
  if (ate == shark) {
    ++shark;
    ate = 0;
  }
}

void solve() {
  while (1) {
    Reachs();
    if (target.first == -1) {
      cout << ret;
      return;
    }
    pos = target;
    arr[target.first][target.second] = 0;
    ret += reach[target.first][target.second];
    grow();
  }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N;
  for (int y = 0; y < N; ++y) {
    for (int x = 0; x < N; ++x) {
      int inp;
      cin >> inp;
      if (inp == 9) {
        pos.first = y;
        pos.second = x;
      } else {
        arr[y][x] = inp;
      }
    }
  }
  solve();
}