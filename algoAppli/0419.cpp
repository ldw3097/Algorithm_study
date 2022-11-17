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

  //priority_queue<int, vector<int>, greater<int>> pq;
  queue<int> pq;
  array<int, 100001> dist;
  fill(dist.begin(), dist.end(), 987654321);
  dist[1] = 0;
  
  pq.push(1);
  while(!pq.empty()){
    int front = pq.front();
    pq.pop();
    for(auto pr : arr[front]){
      int newdist = dist[front] + pr.second;
      if(newdist < dist[pr.first]){
        dist[pr.first] = newdist;
        pq.push(pr.first);
      }
    }
  }
  int ans = 0;
  bool thereisans = true;
  for(int i = 1; i<=n; ++i){
    if(dist[i] == 987654321) {
      cout << "IMPOSSIBLE";
      thereisans = false;
      break;
    }
    ans += dist[i];
  }
  if(thereisans){
    cout << ans;
  }

}