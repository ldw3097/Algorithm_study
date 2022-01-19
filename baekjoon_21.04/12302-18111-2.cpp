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
  int highest = prev(mp.end())->first;
  int firsttime = 0;

  for (auto Pair : mp) {
    firsttime += Pair.second * (Pair.first - lowest) * 2;
  }
  int inv = B + firsttime / 2;
  int lowestTime = firsttime;
  int lowestHeight = mp.begin()->first;

  
  for(int i = lowest +1; i<=highest; ++i){
    inv -= N*M;
    if(inv <0) break;
    for(auto iter = mp.begin(); iter->first < i; ++iter){
      firsttime += iter->second;
    }
    for(auto iter = mp.lower_bound(i); iter != mp.end(); ++iter){
      firsttime -= iter->second * 2;
    }
    if(firsttime <= lowestTime){
      lowestTime = firsttime;
      lowestHeight = i;
    }

  }
  cout << lowestTime << ' ' << lowestHeight;
}