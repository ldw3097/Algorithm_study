#include<bits/stdc++.h>
using namespace std;
array<int, 2000001> zarray{};

int compare(string& str, int pos1, int pos2){
  int ret = 0;
  for(int n=0; n + pos2 <str.length(); ++n){
    if(str[n+pos1] == str[n+pos2]) ++ret;
    else break;
  }
  return ret;
}

void constructz(string& str){
  int x = 0;
  int y = 0;
  for(int k=1; k< str.length(); ++k){
    if(y < k){
      zarray[k] = compare(str, 0, k);
      if(zarray[k] != 0){
        x = k;
        y = x + zarray[k] -1;
      }
    }else{
      int i = k-x;
      if(zarray[i] < y-k+1){
        zarray[k] = zarray[i];
      }else{
        x = k;
        zarray[k] = y -x + compare(str, y-x, y);
        y = x + zarray[k] -1;
      }
    }
  }
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  string N, M;
  cin >> N >> M;
  int nleng = N.length();
  int mleng = M.length();
  string composit = M + '#' + N;
  constructz(composit);
  int ret = 0;
  for(int i = mleng; i < composit.length(); ++i){
    if(zarray[i] == mleng) ++ret;
  }
  cout << ret;
}