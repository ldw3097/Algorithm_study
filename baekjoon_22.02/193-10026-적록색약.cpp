#include <bits/stdc++.h>
using namespace std;
int N;
array<array<char, 102>, 102> normal;
array<array<char, 102>, 102> blind;

void recFill(array<array<char, 102>, 102>& picture, int y, int x) {
  char tofill = picture[y][x];
  picture[y][x] = 'n';
  if (picture[y][x - 1] == tofill) recFill(picture, y, x - 1);
  if (picture[y][x + 1] == tofill) recFill(picture, y, x + 1);
  if (picture[y - 1][x] == tofill) recFill(picture, y - 1, x);
  if (picture[y + 1][x] == tofill) recFill(picture, y + 1, x);
}

int solve(array<array<char, 102>, 102>& picture) {
  int ret = 0;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      if (picture[i][j] != 'n') {
        recFill(picture, i, j);
        ++ret;
      }
    }
  }
  return ret;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  fill(&normal[0][0], &normal[101][101], 'n');
  fill(&blind[0][0], &blind[101][101], 'n');
  cin >> N;
  cin.get();
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      char inp;
      inp = cin.get();
      if (inp == 'G') {
        blind[i][j] = 'R';
      } else {
        blind[i][j] = inp;
      }
      normal[i][j] = inp;
    }
    cin.get();
  }
  cout << solve(normal) << ' ' << solve(blind);
}