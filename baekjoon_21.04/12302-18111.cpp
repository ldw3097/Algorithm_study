#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N, M, B;
  cin >> N >> M >> B;
  map<int, int> mp;
  for (int n = 0; n < N * M; ++n) {
    mp[*istream_iterator<int>(cin)]++;
  }
  int lowest = mp.begin()->first;
  int hightest = prev(mp.end())->first;
  int firsttime = 0;

  for (auto Pair : mp) {
    firsttime += Pair.second * (Pair.first - lowest) * 2;
  }
  int inv = B + firsttime / 2;
  int lowestTime = firsttime;
  int lowestHeight = mp.begin()->first;

  auto iter = ++mp.begin();
  while (iter != mp.end()) {
    int diff = iter->first - prev(iter)->first;
    for (auto itr3 = iter; itr3 != mp.end(); ++itr3) {
      firsttime -= itr3->second * diff * 2;
      inv -= itr3->second * diff;
    }
    for (auto itr2 = mp.begin(); itr2 != iter; ++itr2) {
      firsttime += itr2->second * (iter->first - itr2->first);
      inv -= itr2->second * (iter->first - itr2->first);
    }

    if (inv < 0) break;
    if (firsttime <= lowestTime) {
      lowestTime = firsttime;
      lowestHeight = iter->first;
    }
    ++iter;
  }
  cout << lowestTime << ' ' << lowestHeight;
}