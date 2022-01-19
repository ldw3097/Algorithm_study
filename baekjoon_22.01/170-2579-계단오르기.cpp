#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N;
  cin>> N;
  vector<int> vec(N);
  for (int i = 0; i < N; ++i) {
    cin >> vec[i];
  }
  if (N == 1) {
    cout << vec[0];
    return 0;
  } else if (N == 2) {
    cout << vec[0] + vec[1];
    return 0;
  }
  vector<int> x(N);
  vector<int> xo(N);
  vector<int> xoo(N);
  x[2] = vec[0] + vec[1];
  xo[2] = vec[0] + vec[2];
  xoo[2] = vec[1] + vec[2];
  for (int i = 3; i < N; ++i) {
    x[i] = max({xo[i - 1], xoo[i - 1]});
    xo[i] = x[i - 1] + vec[i];
    xoo[i] = xo[i - 1] + vec[i];
  }
  cout << max({xo[N - 1], xoo[N - 1]});
}