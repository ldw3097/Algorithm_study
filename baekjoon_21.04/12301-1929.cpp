#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int M, N;
  cin >> M >> N;
  set<int> lst;
  for (int i = 2; i <= N; ++i) {
    lst.insert(i);
  }
  auto iter = lst.begin();
  auto iter2 = iter;
  while (iter != lst.end()) {
    iter2 = next(iter);
    while (iter2 != lst.end()) {
      if (*iter2 % *iter == 0) {
        iter2 = lst.erase(iter2);
      } else
        ++iter2;
    }
    ++iter;
  }

  iter = lst.lower_bound(M);
  for(; iter != lst.end(); ++iter){
    cout << *iter << '\n';
  }
}