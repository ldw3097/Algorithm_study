#include <bits/stdc++.h>
using namespace std;
array<array<int, 502>, 502> arr;
int N, M;
vector<array<pair<int, int>, 3>> tetra = {
    {{{0, 1}, {0, 2}, {0, 3}}},   {{{1, 0}, {2, 0}, {3, 0}}},
    {{{1, 0}, {1, 1}, {0, 1}}},   {{{1, 0}, {2, 0}, {2, 1}}},
    {{{1, 0}, {2, 0}, {2, -1}}},  {{{0, 1}, {0, 2}, {1, 2}}},
    {{{1, 0}, {1, -1}, {1, -2}}}, {{{0, 1}, {1, 1}, {2, 1}}},
    {{{1, 0}, {1, 1}, {1, 2}}},   {{{1, 0}, {0, 1}, {0, 2}}},
    {{{1, 0}, {2, 0}, {0, 1}}},   {{{1, 0}, {1, 1}, {2, 1}}},
    {{{1, 0}, {1, -1}, {2, -1}}}, {{{0, 1}, {1, 1}, {1, 2}}},
    {{{0, 1}, {1, 0}, {1, -1}}},  {{{0, 1}, {1, 1}, {0, 2}}},
    {{{1, 0}, {1, 1}, {2, 0}}},   {{{1, 0}, {1, -1}, {2, 0}}},
    {{{1, 0}, {1, 1}, {1, -1}}}};

int result(int y, int x, array<pair<int, int>, 3> tet) {
  int ret = arr[y][x];
  for (auto pr : tet) {
    if (arr[y + pr.first][x + pr.second] < 0) return -1;
    ret += arr[y + pr.first][x + pr.second];
  }
  return ret;
}

int maxAtPos(int y, int x) {
  int ret = -1;
  for (auto arr : tetra) {
    ret = max(ret, result(y, x, arr));
  }
  return ret;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  fill(&arr[0][0], &arr[501][501], -987654321);
  cin >> N >> M;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      cin >> arr[i][j];
    }
  }
  int ret = -1;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      ret = max(ret, maxAtPos(i, j));
    }
  }
  cout << ret;
}