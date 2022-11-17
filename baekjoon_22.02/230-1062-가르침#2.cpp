#include <bits/stdc++.h>
using namespace std;
int N, K;
int maxval = 0;
vector<array<bool, 26>> toteach;

bool included(array<bool, 26>& teached, array<bool, 26>& newteach) {
  for (int i = 0; i < 26; ++i) {
    if (newteach[i] == 1 && teached[i] == 0) {
      return false;
    }
  }
  return true;
}

void addOrNot(int target, int remain, array<bool, 26> teached) {
  if (target > 26) return;
  if (remain == 0) {
    int ret = 0;
    for (array<bool, 26>& eachone : toteach) {
      if (included(teached, eachone)) ++ret;
    }
    if (ret > maxval) maxval = ret;
    return;
  }
  if (remain <= 25 - target) {
    addOrNot(target + 1, remain, teached);
  }
  teached[target] = 1;
  addOrNot(target + 1, remain - 1, teached);
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
  array<bool, 26> teached{};
  addOrNot(0, K, teached);
  cout << maxval;
}