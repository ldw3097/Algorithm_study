#include <bits/stdc++.h>
using namespace std;
int N, K;
int maxval = 0;
vector<array<bool, 26>> toteach;

int needed(array<bool, 26>& teached, array<bool, 26>& newteach,
           array<bool, 26>& fusion) {
  int ret = 0;
  fusion = teached;
  for (int i = 0; i < 26; ++i) {
    if (newteach[i] == 1 && teached[i] == 0) {
      ++ret;
      fusion[i] = 1;
    }
  }
  return ret;
}

int includeOrNot(array<bool, 26> teached, int target, int remain) {
  if (target >= toteach.size()) return 0;
  array<bool, 26> fusion;
  int need = needed(teached, toteach[target], fusion);
  int notinclude = includeOrNot(teached, target + 1, remain);
  if (remain < need) {
    return notinclude;
  } else {
    return max(notinclude, 1 + includeOrNot(fusion, target + 1, remain - need));
  }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    array<bool, 26> word{};
    string inp;
    cin >> inp;
    for (char c : inp) {
      word[c - 97] = 1;
    }
    toteach.push_back(word);
  }
  for (int i = 0; i < N; ++i) {
    array<bool, 26> noteach{};
    maxval = max(maxval, includeOrNot(noteach, i, K));
  }
  cout << maxval;
}