#include <bits/stdc++.h>
using namespace std;
int N, M;
array<int, 101> dp;
array<vector<int>, 101> dplog;
array<int, 101> dp2;
array<vector<int>, 101> dp2log;
map<int, int> ladderXY;
map<int, int> ladderYX;
map<int, int> snakeXY;

int randgen(int start, int end) {
  int ret = rand();
  ret %= end - start + 1;
  ret += start;
  if(ret == 0){
    cout << "zero! " << start << ' ' << end << '\n';
  }
  return ret;
}

void checkone(int index) {
  int dicemin = 987654321;
  int source;
  for(int i =1; i<=6; ++i){
    if(dicemin > dp2[index-i]){
      source = index-i;
      dicemin =dp2[index-i];
    }
  }
  ++dicemin;
  if (ladderYX.count(index) && dicemin > dp2[ladderYX[index]]) {
    source = ladderXY[index];
    dicemin = dp2[ladderYX[index]];
  }
  dp2[index] = dicemin;
  dp2log[index] = dp2log[source];
  dp2log[index].push_back(source);
}

void solve2() {
  for (int i = 8; i <= 100; ++i) {
    checkone(i);
    if (snakeXY.count(i)) {
      if (dp2[snakeXY[i]] > dp2[i]) {
        dp2[snakeXY[i]] = dp2[i];
        i = snakeXY[i];
      }
    }
  }
}

int solve() {
  queue<int> que;
  que.push(1);
  while (dp[100] == 987654321) {
    int top = que.front();
    if (dp[top] > 100) return 987654321;
    que.pop();
    for (int i = 1; i <= 6; ++i) {
      int advance = top + i;
      if (advance > 100) break;
      if (ladderXY.count(advance))
        advance = ladderXY[advance];
      else if (snakeXY.count(advance))
        advance = snakeXY[advance];
      if (dp[top] + 1 < dp[advance]) {
        que.push(advance);
        dp[advance] = dp[top] + 1;
        dplog[advance] = dplog[top];
        dplog[advance].push_back(top);
      }
    }
  }
  return dp[100];
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int repeat = 50;
  for (int r = 0; r < repeat; ++r) {
    N = randgen(1, 15);
    M = randgen(1, 15);
    dp.fill(987654321);
    dp2.fill(987654321);
    dplog.fill({});
    dp2log.fill({});
    ladderXY.clear();
    ladderYX.clear();
    snakeXY.clear();
    dp[1] = 0;
    for (int i = 0; i <= 1; ++i) {
      dp2[i] = 0;
    }
    for (int j = 2; j <= 7; ++j) {
      dp2[j] = 1;
    }
    for (int i = 0; i < N; ++i) {
      int x, y;
      x = randgen(2, 98);
      y = randgen(x + 1, 99);
      ladderXY.emplace(x, y);
      ladderYX.emplace(y, x);
    }
    for (int i = 0; i < M; ++i) {
      int x, y;
      y = randgen(2, 98);
      x = randgen(y+1, 99);
      snakeXY.emplace(x, y);
    }
    int answer = solve();
    if (answer == 987654321) continue;
    solve2();
    int answer2 = dp2[100];
    if (answer == answer2)
      cout << "pass" << '\n';
    else {
      cout << "Wrong! N: " << N << "M: " << M << '\n';
      for (auto aut : ladderXY) {
        cout << aut.first << ' ' << aut.second << '\n';
      }
      cout << "---------\n";
      for (auto aut : snakeXY) {
        cout << aut.first << ' ' << aut.second << '\n';
      }
      cout << "=========\n";
      cout << "correct " << dp[100] << " wrong " << dp2[100] << '\n';
      for(auto aut : dplog[100]){
        cout << aut << ' ';
      }
      cout << '\n';
      for(auto aut : dp2log[100]){
        cout << aut << ' ';
      }
      cout << '\n';
      break;
    }
  }
}