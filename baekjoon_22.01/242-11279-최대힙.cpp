#include<bits/stdc++.h>
using namespace std;

struct cmp{
  bool operator()(int a, int b) const{
    if(abs(a) == abs(b)) return a > b;
    return abs(a) > abs (b);
  }
};

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N;
  cin >> N;
  priority_queue<int, vector<int>, cmp> que; 
  for(int i=0; i<N; ++i){
    int inp;
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