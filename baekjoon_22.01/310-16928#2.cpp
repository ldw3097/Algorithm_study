#include <bits/stdc++.h>
using namespace std;
int N, M;
array<int, 101> dp;
map<int, int> ladderXY;
map<int, int> snakeXY;



int solve() {
  queue<int> que;
  que.push(1);
  while(dp[100] == 987654321){
    int top = que.front();
    que.pop();
    for(int i=1; i<=6; ++i){
      int advance = top+i;
      if(advance > 100) break;
      if(ladderXY.count(advance)) advance = ladderXY[advance];
      else if(snakeXY.count(advance)) advance = snakeXY[advance];
      if(dp[top]+1 < dp[advance]){
        que.push(advance);
        dp[advance] = dp[top]+1;
      }
    }
  }
  return dp[100];
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N >> M;
  dp.fill(987654321);
  dp[1] = 0;
  for (int i = 0; i < N; ++i) {
    int x, y;
    cin >> x >> y;
    ladderXY.emplace(x, y);
  }
  for (int i = 0; i < M; ++i) {
    int x, y;
    cin >> x >> y;
    snakeXY.emplace(x, y);
  }
  cout << solve();
  
}