#include<bits/stdc++.h>
using namespace std;
array<vector<int>,100001> arr;  // 각 노드의 인접노드
array<int,100001> teams {}; // 각 노드의 팀

int dfs(int pupil, int nextteam){  // dfs로 모든 인접노드를 방문
  if(teams[pupil] != 0){  // 이미 방문한경우
    if(teams[pupil] != nextteam){ // 칠해져야 하는 색이 아니면 invalid
      return -1;
    }else{
      return 0;
    }
  }
  teams[pupil] = nextteam;
  for(int adj : arr[pupil]){
    if(dfs(adj, (nextteam == 1)? 2 : 1) == -1){ // 주변 노드를 방문하며 반대색을 칠함
      return -1;
    }
  }
  return 0;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  
  for(int i=0; i<m; ++i){   // 각 노드들의 관계를 저장함
    int a, b;
    cin >> a>>b;
    arr[a].emplace_back(b);
    arr[b].emplace_back(a);
  }
  bool isgood = 1;  // valid 여부
  for(int i=1; i<=n; ++i){  // 모든 노드를 돌면서 안칠해져있으면 dfs를 수행
    if(teams[i] != 0) continue; 
    int status = dfs(i,1);  
    if(status == -1){ 
      cout << "IMPOSSIBLE";
      isgood = 0;
      break;
    }
  }

  if(isgood){
    for(int i=1; i<=n; ++i){
      cout << teams[i] << ' ';
    }
  }
  

}