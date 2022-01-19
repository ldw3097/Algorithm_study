#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, C;
  cin >> N >> C;
  vector<int> uni;
  uni.reserve(N + 1);
  for (int i = 0; i <= N; ++i) {
    uni.push_back(i);
  }
  for (int i = 0; i < C; ++i) {
    int a, b;
    cin >> a >> b;
    int smol = min(uni[a], uni[b]);
    int big = max(uni[a], uni[b]);
    for (int j = 1; j <= N; ++j) {
      if (uni[j] == big) uni[j] = smol;
    }
  }
  int ret = 0;
  for (int i = 2; i <= N; ++i) {
    if (uni[i] == 1) ++ret;
  }
  cout << ret;
}