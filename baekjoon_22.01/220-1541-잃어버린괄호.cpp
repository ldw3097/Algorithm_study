#include <bits/stdc++.h>
using namespace std;
int main() {
  char inp;
  vector<int> nums;
  vector<bool> ops;  // 1 is plus
  int numstack = 0;
  while (1) {
    inp = cin.get();
    if (inp == '\n') {
      nums.push_back(numstack);
      break;
    }
    if (isdigit(inp)) {
      numstack = numstack * 10 + (inp - 48);
    } else {
      nums.push_back(numstack);
      numstack = 0;
      if (inp == '+')
        ops.push_back(1);
      else
        ops.push_back(0);
    }
  }

  int startofminus = nums.size();
  for (int nextop = 0; nextop < ops.size(); ++nextop) {
    if (ops[nextop] == 0) {
      startofminus = nextop+1;
      break;
    }
  }
  int ret = accumulate(nums.begin(), nums.begin() + startofminus, 0);
  if(startofminus != nums.size()){
    ret -= accumulate(nums.begin() + startofminus, nums.end(), 0);
  }
  cout << ret;
}