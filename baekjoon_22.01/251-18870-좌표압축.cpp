#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N;
  cin >> N;
  map<int, vector<int>> numbers;
  int inp;
  for (int i = 0; i < N; ++i) {
    cin >> inp;
    numbers[inp].push_back(i);
  }
  array<int, 1000000> result;
  auto iter = numbers.begin();
  int namer = 0;
  while (iter != numbers.end()) {
    for (int i : (*iter).second) {
      result[i] = namer;
    }
    ++namer;
    ++iter;
  }
  for (int n = 0; n < N; ++n) {
    cout << result[n] << ' ';
  }
}