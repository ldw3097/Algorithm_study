#include <bits/stdc++.h>
using namespace std;
int N;
array<array<bool, 64>, 64> inp;

bool isSame(int y, int x, int length) {
  bool start = inp[y][x];
  for (int i = y; i < y + length; ++i) {
    for (int j = x; j < x + length; ++j) {
      if (inp[i][j] != start) return false;
    }
  }
  return true;
}

void solve(int y, int x, int length) {
  if (length == 1) {
    cout << inp[y][x];
    return;
  }
  if (isSame(y, x, length)) {
    cout << inp[y][x];
  } else {
    int half = length / 2;
    cout << '(';
    solve(y, x, half);
    solve(y, x + half, half);
    solve(y + half, x, half);
    solve(y + half, x + half, half);
    cout << ')';
  }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N;
  cin.get();
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      inp[i][j] = cin.get()-48;  // cin.get()을 char만 읽음. '0'의 아스키코드는 48.
    }
    cin.get();  // '\n'하나 건너뛰기
  }
  solve(0,0,N);

}