#include <bits/stdc++.h>
using namespace std;
array<vector<pair<int,int>>,100001> arr;



int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for(int i=0; i<m; ++i){
    int a, b, c;
    cin >> a >> b >> c;
    arr[a].push_back( make_pair(b, c));
    arr[b].push_back( make_pair(a, c));
  }
  
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>  ppq;  // 비용 , 노드
  array<int, 100001> dist;

  fill(dist.begin(), dist.end(), 987654321);
  dist[1] = 0;


  int ans = 0;
  ppq.push(make_pair(0,1));
  while(!ppq.empty()){
    auto front = ppq.top();
    ppq.pop();
    ans += front.first;
    for(auto pr : arr[front.second]){  // 주변 인접 노드
      if(pr.second < dist[pr.first]){
        dist[pr.first] = pr.second;
        
        ppq.push(make_pair(pr.second, pr.first ) );
      }
    }
  }
  
  bool thereisans = true;
  for(int i = 1; i<=n; ++i){
    if(dist[i] == 987654321) {
      cout << "IMPOSSIBLE";
      thereisans = false;
      break;
    }
  }
  if(thereisans){
    cout << ans;
  }

}