#include <bits/stdc++.h>
using namespace std;
array<array<int, 1002>, 1002> tomato;
int M, N;

struct yx {
  int y;
  int x;
};

void check(int y, int x, vector<struct yx>& added) {
  if (tomato[y][x] == 0) {
    added.push_back({y, x});  // struct의 vector에 원소를 추가하는법
    tomato[y][x] = 1;
  }
}

int solve() {
  vector<struct yx> added;
  vector<struct yx> addedclone;
  int ret = 0;
  bool thereis0;

  for (int n = 1; n <= N; ++n) {
    for (int m = 1; m <= M; ++m) {
      if (tomato[n][m] == 1) {
        added.push_back({n, m});
      }
    }
  }

  while (!added.empty()) {
    ++ret;
    addedclone = added;
    added.clear();
    for (auto aut : addedclone) {
      check(aut.y, aut.x + 1, added);
      check(aut.y, aut.x - 1, added);
      check(aut.y + 1, aut.x, added);
      check(aut.y - 1, aut.x, added);
    }
  }
  --ret;

  for (int n = 1; n <= N; ++n) {
    for (int m = 1; m <= M; ++m) {
      if (tomato[n][m] == 0) {
        return -1;
      }
    }
  }

  return ret;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  fill(&tomato[0][0], &tomato[1001][1001], -1);
  cin >> M >> N;
  for (int n = 1; n <= N; ++n) {
    for (int m = 1; m <= M; ++m) {
      cin >> tomato[n][m];
    }
  }
  cout << solve();
}