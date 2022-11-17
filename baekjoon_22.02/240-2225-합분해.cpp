#include <bits/stdc++.h>
using namespace std;
int N, K;
array<long, 201> dp{};
array<long, 201> dp2{};

void addone(bool todp2) {
  if (todp2)
    dp2.fill(0);
  else
    dp.fill(0);

  for (int i = 0; i <= N; ++i) {
    for (int j = 0; j <= N - i; ++j) {
      if (todp2) {
        dp2[i + j] += dp[i];
      } else {
        dp[i + j] += dp2[i];
      }
    }
  }
  if (todp2) {
    for (int n = 0; n <= N; ++n) {
      dp2[n] %= 1000000000;  // 중간값에 모듈러 연산을 하자
    }
  }else{
    for (int n = 0; n <= N; ++n) {
      dp[n] %= 1000000000;
    }
  }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N >> K;
  for (int n = 0; n <= N; ++n) {
    dp[n] = 1;
  }
  bool todp2 = 1;
  for (int k = 1; k < K; ++k) {
    addone(todp2);
    todp2 = !todp2;
  }
  if (todp2) {
    cout << dp[N] % 1'000'000'000;
  } else {
    cout << dp2[N] % 1'000'000'000;
  }
}