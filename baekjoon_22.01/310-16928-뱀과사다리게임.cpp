#include<bits/stdc++.h>
using namespace std;
int N, M;
array<int, 101> dp;
map<int, int> ladderYX;
map<int,int> snakeXY;

void checkone(int index){
  int dicemin = 987654321;
  for(int i =1; i<=6; ++i){
    dicemin = min(dicemin, dp[index-i]);
  }
  ++dicemin;
  if(ladderYX.count(index)){
    dicemin = min(dicemin, dp[ladderYX[index]]);
  }
  dp[index] = dicemin;
}

void solve(){
  for(int i = 8; i<=100; ++i){
    checkone(i);
    if(snakeXY.count(i)){
      if(dp[snakeXY[i]] > dp[i]){
        dp[snakeXY[i]] = dp[i];
        i = snakeXY[i];
      }
    }
  }
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N >> M;
  dp.fill(987654321);
  for(int i=0; i<=1; ++i){
    dp[i] = 0;
  }
  for(int i=2; i<=7; ++i){
    dp[i] = 1;
  }
  for(int i=0; i<N; ++i){
    int x,y;
    cin >> x >> y;
    ladderYX.emplace(y,x);
  }
  for(int i=0; i<M; ++i){
    int x,y;
    cin >> x >> y;
    snakeXY.emplace(x,y);
  }
  solve();
  cout << dp[100];
  
}