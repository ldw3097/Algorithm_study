#include <bits/stdc++.h>
using namespace std;
array<array<array<int, 102>, 102>, 102> tomato;
int M, N, H;

struct yx {
  int z;
  int y;
  int x;
};

void check(int z, int y, int x, vector<struct yx>& added) {
  if (tomato[z][y][x] == 0) {
    added.push_back({z, y, x});  // struct의 vector에 원소를 추가하는법
    tomato[z][y][x] = 1;
  }
}

int solve() {
  vector<struct yx> added;
  vector<struct yx> addedclone;
  int ret = 0;
  bool thereis0;
  for (int h = 1; h <= H; ++h) {
    for (int n = 1; n <= N; ++n) {
      for (int m = 1; m <= M; ++m) {
        if (tomato[h][n][m] == 1) {
          added.push_back({h, n, m});
        }
      }
    }
  }
  
  while (!added.empty()) {
    ++ret;
    addedclone = added;
    added.clear();
    for (auto aut : addedclone) {
      check(aut.z, aut.y, aut.x + 1, added);
      check(aut.z, aut.y, aut.x - 1, added);
      check(aut.z, aut.y + 1, aut.x, added);
      check(aut.z, aut.y - 1, aut.x, added);
      check(aut.z - 1, aut.y, aut.x, added);
      check(aut.z + 1, aut.y, aut.x, added);
    }
  }
  --ret;

  for (int h = 1; h <= H; ++h) {
    for (int n = 1; n <= N; ++n) {
      for (int m = 1; m <= M; ++m) {
        if (tomato[h][n][m] == 0) {
          return -1;
        }
      }
    }
  }
  return ret;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  fill(&tomato[0][0][0], &tomato[101][101][101], -1);  // 3차원배열을 모두 fill하는 방법
  cin >> M >> N >> H;
  for (int h = 1; h <= H; ++h) {
    for (int n = 1; n <= N; ++n) {
      for (int m = 1; m <= M; ++m) {
        cin >> tomato[h][n][m];
      }
    }
  }
  cout << solve();
}