#include <bits/stdc++.h>
using namespace std;

void traverse(array<array<bool,50>,50>& arr, int x, int y){
  arr[x][y] = 0;
  if(x > 0 && arr[x-1][y] == 1){
    traverse(arr, x-1, y);
  }
  if(x < 49 && arr[x+1][y] == 1){
    traverse(arr, x+1, y);
  }
  if(y > 0 && arr[x][y-1] == 1){
    traverse(arr, x, y-1);
  }
  if(y < 49 && arr[x][y+1] == 1){
    traverse(arr, x, y+1);
  }
}

int solve() {
  int M, N, K;
  cin >> M >> N >> K;
  int ret = 0;
  array<array<bool,50>,50> arr{};
  for (int i = 0; i < K; ++i) {
    int x, y;
    cin >> x >> y;
    arr[x][y] = 1;
  }
  for(int i=0; i<50; ++i){
    for(int j= 0; j<50; ++j){
      if(arr[i][j] == 1){
        ++ret;
        traverse(arr, i, j);
      }
    }
  }
  return ret;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int T;
  cin >> T;
  for(int i =0; i<T; ++i){
    cout << solve() << '\n';
  }
}