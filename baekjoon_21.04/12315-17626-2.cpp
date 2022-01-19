#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  set<int> s1;
  for (int i = 1; i <= 223; ++i) {
    s1.insert(i * i);
  }
  if (s1.count(n)) {
    cout << 1;
    return 0;
  }

  set<int> s2;
  auto iter1 = s1.begin();
  auto iter2 = s1.begin();
  auto iter3 = s1.upper_bound(25000);
  while (iter1 != iter3) {
    iter2 = iter1;
    while (iter2 != s1.end()) {
      int temp = *iter1 + *iter2;
      if (temp > 50000) break;
      s2.insert(temp);
      ++iter2;
    }
    ++iter1;
  }
  if (s2.count(n)) {
    cout << 2;
    return 0;
  }

  set<int> s3;
  iter1 = s1.begin();
  while (iter1 != s1.end()) {
    iter2 = s2.begin();
    while (iter2 != s2.end()) {
      int temp = *iter1 + *iter2;
      if (temp > 50000) break;
      s3.insert(temp);
      ++iter2;
    }
    ++iter1;
  }
  if (s3.count(n)) {
    cout << 3;
    return 0;
  } else {
    cout << 4;
    return 0;
  }
}