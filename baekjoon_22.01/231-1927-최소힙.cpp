#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N;
  cin >> N;
  priority_queue<unsigned, vector<unsigned>, greater<unsigned>> que;  // 커스텀 순서를 쓰려면 세개 다 써야됨
  for(int i=0; i<N; ++i){
    unsigned inp;
    cin >> inp;
    if(inp == 0){
      if(que.size() == 0) cout << 0 << '\n';
      else{
        cout << que.top() << '\n';
        que.pop();
      }
    }else{
      que.push(inp);
    }
  }

}