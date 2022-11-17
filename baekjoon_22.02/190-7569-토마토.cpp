#include <bits/stdc++.h>
using namespace std;
array<array<array<int, 102>, 102>, 102> tomato;
int M, N, H;

struct yx {
  int z;
  int y;
  int x;
};

bool istoadd(int h, int n, int m) {
  if (tomato[h][n][m - 1] == 1 || tomato[h][n][m + 1] == 1 ||
      tomato[h][n - 1][m] == 1 || tomato[h][n + 1][m] == 1 ||
      tomato[h - 1][n][m] == 1 || tomato[h + 1][n][m] == 1) {
    return 1;
  }else return 0;
}

int solve() {
  vector<struct yx> toadd;
  int ret = 0;
  bool thereis0 = false;
  while (1) {
    for (int h = 1; h <= H; ++h) {
      for (int n = 1; n <= N; ++n) {
        for (int m = 1; m <= M; ++m) {
          if (tomato[h][n][m] == 0) {
            thereis0 = true;
            if(istoadd(h,n,m)){
              toadd.push_back({h,n,m});
            }
          }
        }
      }
    }
    if(!thereis0){
      return ret;
    }else{
      if(toadd.empty()){
        return -1;
      }
      for(auto str : toadd){
        tomato[str.z][str.y][str.x] = 1;
      }
      toadd.clear();
      ++ret;
      thereis0 = 0;

    }
  }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  fill(&tomato[0][0][0], &tomato[101][101][101], -1);
  cin >> M >> N >> H;
  for (int h = 1; h <= H; ++h) {
    for (int n = 1; n <= N; ++n) {
      for (int m = 1; m <= M; ++m) {
        cin >> tomato[h][n][m];
      }
    }
  }
  cout << solve();
}