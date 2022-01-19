#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int M, N;
  cin >> M >> N;
  array<bool, 1000001> arr{};
  for (int i = 2; i <= N; ++i) {
    if (arr[i] == 1) continue;
    if (i >= M) cout << i << '\n';
    for (int j = i * 2; j <= N; j += i) {
      arr[j] = 1;
    }
  }
}