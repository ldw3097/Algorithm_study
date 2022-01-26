#include <bits/stdc++.h>
using namespace std;
int N, r, c;

void rec(int y, int x, int before, int wide) {
  if (wide == 1) {
    cout << before;
    return;
  }
  int half = wide / 2;
  int zsize = half * half;
  int newy, newx;
  if (r >= y + half) {
    newy = y + half;
    before += zsize * 2;
  } else
    newy = y;
  if (c >= x + half) {
    newx = x + half;
    before += zsize;
  } else
    newx = x;
  rec(newy, newx, before, half);
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N >> r >> c;
  int wide;
  wide = 1 << N;
  rec(0,0,0,wide);
}