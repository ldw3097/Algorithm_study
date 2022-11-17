#include <bits/stdc++.h>
using namespace std;
int T;

void testcase() {
  string rds;
  cin >> rds;
  int nums;
  cin >> nums;
  cin.get();
  cin.get();
  char inp = 0;
  int temp = -1;
  deque<int> numlist;
  while (inp != ']') {
    inp = cin.get();
    if (isdigit(inp)) {
      if (temp == -1) {
        temp = inp - 48;
      } else {
        temp = temp * 10 + (inp - 48);
      }
    } else {
      if(temp != -1){
        numlist.push_back(temp);
      }
      temp = -1;
    }
  }
  bool reverse = 0;
  for (char c : rds) {
    if (c == 'R') {
      reverse = !reverse;
    } else if(c == 'D') {
      if (numlist.empty()) {
        cout << "error\n";
        return;
      } else {
        if (reverse) {
          numlist.pop_back();
        } else {
          numlist.pop_front();
        }
      }
    }
  }
  string ret = "[";
  if (reverse) {
    auto iter = numlist.rbegin();
    while (iter != numlist.rend()) {
      ret += to_string(*iter++) + ',';
    }
  } else {
    auto iter = numlist.begin();
    while (iter != numlist.end()) {
      ret += to_string(*iter++) + ',';
    }
  }
  if(ret.back() == ','){
    ret.pop_back();
  }
  ret += ']';
  cout << ret << '\n';
  return;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> T;
  for (int i = 0; i < T; ++i) {
    testcase();
  }
}