#include <bits/stdc++.h>
using namespace std;
int a, b, c;


bool ret(){  // 완전탐색
  int cax = c;
  while(cax >= 0){  // cax에서 a만큼 빼면서 b로 나뉘어지는지 확인함
    if(cax%b == 0) return true;
    cax -= a;
  }
  return false;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> a >> b >> c;
  if(ret()){
    cout << "Yes";
  }else{
    cout << "No";
  }
}