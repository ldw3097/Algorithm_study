#include <bits/stdc++.h>
using namespace std;

pair<int, int> operator+(const pair<int, int> p1, const pair<int, int> p2) {
  return pair<int, int>(p1.first + p2.first, p1.second + p2.second);
}

bool issqr(bool** loc, int range, pair<int, int> start) {
  bool head = loc[start.first][start.second];
  for (int i = 0; i < range; ++i) {
    for (int j = 0; j < range; ++j) {
      if (loc[start.first + i][start.second + j] != head) return 0;
    }
  }
  return 1;
}

pair<int, int> nums(bool** loc, int range, pair<int, int> start) {
  if (range == 1) {
    if (loc[start.first][start.second] == 0)
      return pair<int, int>(1, 0);
    else
      return pair<int, int>(0, 1);
  }
  int half = range / 2;
  pair<int, int> ret(0, 0);

  if (issqr(loc, half, start)) {
    if (loc[start.first][start.second])
      ret.second += 1;
    else
      ret.first += 1;
  } else {
    ret = ret + nums(loc, half, start);
  }
  start.second += half;
  if (issqr(loc, half, start)) {
    if (loc[start.first][start.second])
      ret.second += 1;
    else
      ret.first += 1;
  } else {
    ret = ret + nums(loc, half, start);
  }
  start.first += half;
  if (issqr(loc, half, start)) {
    if (loc[start.first][start.second])
      ret.second += 1;
    else
      ret.first += 1;
  } else {
    ret = ret + nums(loc, half, start);
  }
  start.second -= half;
  if (issqr(loc, half, start)) {
    if (loc[start.first][start.second])
      ret.second += 1;
    else
      ret.first += 1;
  } else {
    ret = ret + nums(loc, half, start);
  }
  return ret;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N;
  cin >> N;
  bool** sqr = new bool*[N];
  for (int i = 0; i < N; ++i) {
    sqr[i] = new bool[N];
    for (int j = 0; j < N; ++j) {
      cin >> sqr[i][j];
    }
  }
  pair<int, int> ret(0, 0);
  if (issqr(sqr, N, pair<int, int>(0, 0))) {
    if (sqr[0][0])
      ret.second += 1;
    else
      ret.first += 1;
  } else
    ret = nums(sqr, N, pair<int, int>(0, 0));
  cout << ret.first << '\n' << ret.second;
}