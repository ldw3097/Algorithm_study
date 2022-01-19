#include <bits/stdc++.h>
using namespace std;

vector<bool> serial(vector<int>& vec) {
  vector<bool> ret;
  stack<int> stk;
  int toInsert = 2;
  ret.push_back(1);
  stk.push(1);
  for (int i : vec) {
    
    if (stk.empty() || stk.top() < i) {  // 해당숫자 만큼 푸시해서 주기
      if (toInsert > i) {
        ret[0] = 0;
        return ret;
      } else {
        do {
          stk.push(toInsert++);
          ret.push_back(1);
        } while (stk.top() < i);
        ret.push_back(0);
        stk.pop();
      }
    } else {  // 있는거 빼서 주기
      while (stk.top() > i) {
        stk.pop();
        if (stk.empty()) {
          ret[0] = 0;
          return ret;
        }
        ret.push_back(0);
      }
      if (stk.top() == i) {
        ret.push_back(0);
        stk.pop();
      } else {
        ret[0] = 0;
        return ret;
      }
    }
  }
  return ret;
}

int main() {
  int n;
  cin >> n;
  vector<int> vec;
  vec.reserve(n);
  for(int i=0; i<n; ++i){
    vec.push_back(*istream_iterator<int>(cin));
  }
  vector<bool> ret = serial(vec);
  if(ret[0] == 0) cout << "NO";
  else{
    for(bool b : ret){
      if(b) cout << "+\n";
      else cout << "-\n";
    }
  }
}