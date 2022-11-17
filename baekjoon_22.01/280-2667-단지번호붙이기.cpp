#include <bits/stdc++.h>
using namespace std;
int N;
array<array<bool, 27>, 27> arr;
vector<int> rets;

int dfs(int y, int x) {
  if (arr[y][x] == 0) return 0;
  int ret = 1;
  arr[y][x] = 0;
  ret += dfs(y - 1, x) + dfs(y + 1, x) + dfs(y, x - 1) + dfs(y, x + 1);
  return ret;
}

void solve() {
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      int dfsret = dfs(i, j);
      if (dfsret != 0) rets.push_back(dfsret);
    }
  }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N;
  cin.get();
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      arr[i][j] = cin.get()-48;
    }
    cin.get();
  }
  solve();
  sort(rets.begin(), rets.end());  // 기본값은 std::less임
  cout << rets.size() << '\n';
  for (int ret : rets) {
    cout << ret << '\n';
  }
}