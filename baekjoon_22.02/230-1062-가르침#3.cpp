#include <bits/stdc++.h>
using namespace std;
int N, K;
int maxval = 0;
vector<array<bool, 21>> toteach;

bool included(array<bool, 21>& teached, array<bool, 21>& newteach) {
  for (int i = 0; i < 21; ++i) {
    if (newteach[i] == 1 && teached[i] == 0) {
      return false;
    }
  }
  return true;
}

void addOrNot(int target, int remain, array<bool, 21> teached) {
  if (remain == 0) {
    int ret = 0;
    for (array<bool, 21>& eachone : toteach) {
      if (included(teached, eachone)) ++ret;
    }
    if (ret > maxval) maxval = ret;
    return;
  }
  if (target >= 21) return;
  addOrNot(target + 1, remain, teached);
  --remain;
  teached[target] = 1;
  addOrNot(target + 1, remain, teached);
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N >> K;
  if (K < 5) {
    cout << 0;
    return 0;
  }
  for (int i = 0; i < N; ++i) {
    array<bool, 21> word{};
    string inp;
    cin >> inp;
    for (char c : inp) {
      if (c == 'b')
        word[0] = 1;
      else if (c > 'c' && c < 'i')
        word[c - 99] = 1;
      else if (c > 'i' && c < 'n')
        word[c - 100] = 1;
      else if (c > 'n' && c < 't')
        word[c - 101] = 1;
      else if (c > 't')
        word[c - 102] = 1;
    }
    toteach.push_back(word);
  }
  array<bool, 21> teached{};
  addOrNot(0, K - 5, teached);
  cout << maxval;
}