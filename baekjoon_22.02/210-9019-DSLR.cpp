#include <bits/stdc++.h>
using namespace std;
int T;
array<string, 10000> strs;  // string은 클래스라서 {} 안해줘도 초기화됨
int n, target;

int D(int N) {
  int addr = (N * 2) % 10000;
  if (strs[addr].empty()) {
    strs[addr] = strs[N] + 'D';
    return addr;
  } else
    return -1;
}

int S(int N) {
  int addr = N - 1;
  if (addr == -1) addr = 9999;
  if (strs[addr].empty()) {
    strs[addr] = strs[N] + 'S';
    return addr;
  } else {
    return -1;
  }
}

int L(int N) {
  int addr = N * 10;
  int d1 = N / 1000;
  addr %= 10000;
  addr += d1;
  if (strs[addr].empty()) {
    strs[addr] = strs[N] + 'L';
    return addr;
  } else {
    return -1;
  }
}

int R(int N) {
  int d4 = N % 10;
  int addr = N / 10;
  addr += d4 * 1000;
  if (strs[addr].empty()) {
    strs[addr] = strs[N] + 'R';
    return addr;
  } else {
    return -1;
  }
}

void testcase() {
  strs.fill("");  // array에 clear같은건 없다
  cin >> n >> target;
  queue<int> que;
  que.push(n);
  strs[n] = "A";
  while (strs[target].empty()) {
    int poped = que.front();
    que.pop();
    int temp;
    temp = D(poped);
    if (temp != -1) que.push(temp);
    temp = S(poped);
    if (temp != -1) que.push(temp);
    temp = L(poped);
    if (temp != -1) que.push(temp);
    temp = R(poped);
    if (temp != -1) que.push(temp);
  }
  strs[target].erase(0,1);  // 0번부터 1개 삭제하기
  cout << strs[target] << '\n';
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> T;
  for(int i=0; i<T; ++i){
    testcase();
  }
}