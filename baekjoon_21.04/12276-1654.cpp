#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  unsigned K, N;
  cin >> K >> N;
  unsigned long n = N;
  vector<unsigned> arr;
  arr.reserve(K);
  for (int i = 0; i < K; ++i) {
    arr.push_back(*istream_iterator<unsigned>(cin));
  }
  int minimum = N / K + 1;
  unsigned long low_bound = *min_element(arr.begin(), arr.end()) / minimum;
  unsigned long high_bound =
      *max_element(arr.begin(), arr.end()) / (minimum - 1);
  unsigned long part = 0;

  bool flag;
  unsigned middle;
  while (low_bound != high_bound) {
    part = 0;
    flag = 0;
    middle = (low_bound + high_bound) / 2 + 1;
    for (int i = 0; i < K; ++i) {
      part += arr[i] / middle;
      if (part >= n) {
        low_bound = middle;
        flag = 1;
        break;
      }
    }
    if (flag) continue;
    high_bound = middle - 1;
  }
  cout << low_bound;
}