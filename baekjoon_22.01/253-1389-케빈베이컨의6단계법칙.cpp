#include <bits/stdc++.h>
using namespace std;
array<array<int, 101>, 101> relation;
array<int, 101> ret{};
int N, M;

void floyd() {
  int newmin;
  for (int k = 1; k <= N; ++k) {
    for (int i = 1; i <= N; ++i) {
      for (int j = i + 1; j <= N; ++j) {
        newmin = relation[i][k] + relation[k][j];
        if (newmin < relation[i][j]) {
          relation[i][j] = newmin;
          relation[j][i] = newmin;
        }
      }
    }
  }
}

void solve() {
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      if (i == j) continue;
      ret[i] += relation[i][j];
    }
  }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  for (auto& a : relation) {  // &을 써야 레퍼런스 사용함
    a.fill(987654321);
  }

  cin >> N >> M;
  int a, b;
  for (int i = 0; i < M; ++i) {
    cin >> a >> b;
    relation[a][b] = 1;
    relation[b][a] = 1;
  }
  floyd();
  solve();
  auto iter = min_element(ret.begin()+1, ret.begin()+N+1);
  cout << iter - ret.begin();  // iterator의 index를 알수있다
}