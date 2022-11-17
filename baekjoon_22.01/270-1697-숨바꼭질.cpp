#include <bits/stdc++.h>
using namespace std;
#define ISVALID(x) (x >= 0 && x <= 100'000)
int N, K;
array<int, 100001> dots;

void bfs() {
  queue<int> que;
  que.push(N);
  int level;
  while (!que.empty()) {
    int target = que.front();
    level = dots[target] +1;
    que.pop();
    if (ISVALID(target - 1) && dots[target - 1] > level) {
      dots[target - 1] = level;
      que.push(target - 1);
    }
    if (ISVALID(target * 2) && dots[target * 2] > level) {
      dots[target * 2] = level;
      que.push(target * 2);
    }
    if (ISVALID(target + 1) && dots[target + 1] > level) {
      dots[target + 1] = level;
      que.push(target + 1);
    }
    ++level;
  }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N >> K;
  dots.fill(987654321);
  dots[N] = 0;
  bfs();
  cout << dots[K];
}