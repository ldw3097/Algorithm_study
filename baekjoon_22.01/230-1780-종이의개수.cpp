#include <bits/stdc++.h>
using namespace std;
array<array<int, 2187>, 2187> arr{};
int minusnum = 0;
int plusnum = 0;
int zeronum = 0;

void ADD(int start) {
  if (start == 0)
    ++zeronum;
  else if (start == 1)
    ++plusnum;
  else
    ++minusnum;
}

bool check(int y, int x, int num, int start) {
  for (int i = y; i < y + num; ++i) {
    for (int j = x; j < x + num; ++j) {
      if (arr[i][j] != start) return false;
    }
  }
  return true;
}

void rec(int y, int x, int num) { 
  int start = arr[y][x];
  if (num == 1) {
    ADD(start);
    return;
  }
  if (check(y, x, num, start)) {
    ADD(start);
  } else {
    num /= 3;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        rec(y + i * num, x + j * num, num);
      }
    }
  }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> arr[i][j];
    }
  }
  rec(0, 0, N);
  cout << minusnum << '\n' << zeronum << '\n' << plusnum;
}