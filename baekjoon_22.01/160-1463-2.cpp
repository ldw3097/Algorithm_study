#include <bits/stdc++.h>
using namespace std;
#define limit 1000000

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N;
  cin >> N;
  array<int, 1000001> mp{};
  map<int,int> pure;
  int multipl3 = 1;
  int multipl2;

  for (int i = 0; i <= 12; ++i) {
    multipl2 = multipl3;
    for (int j = 0; j <= 19; ++j) {
      if (multipl2 > limit) break;
      mp[multipl2] = i + j;
      pure[multipl2] = i+j;
      multipl2 *= 2;
    }
    multipl3 *= 3;
  }

  for (int i = 5; i <= limit; ++i) {
    if (mp[i] == 0) {
      int newnum = mp[i - 1] + 1;
      mp[i] = newnum;
      for (auto pr : pure) {
        int temp = i * pr.first;
        if (temp > limit) break;
        mp[temp] = newnum + pr.second;
      }
    }
  }
  cout << mp.at(N);
}