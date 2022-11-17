#include <bits/stdc++.h>
using namespace std;
vector<int> arr1[100001];
vector<int> arr2[100001];
int n, m;
int kingdom =1;
array<int, 100001> kingdoms {};  // 각 노드의 킹덤 종류

array<bool,100001> visited {};
array<bool,100001> visited2 {};
stack<int> st;  // 거꾸로된 그래프의 topological sort 
int r;

void DFS(int node){  // 처음에 거꾸로된 그래프에서 dfs로 연결된것 찾아서 st에 집어넣음
  if(visited[node] == 1) return;
  visited[node] =1;
  for(int child : arr2[node]){
    //cout << child << ' ';
    DFS(child);
  }
  st.push(node);
}

void DFS2(int node, int kingdom){  // st에서 하나 꺼내서 그 그래프에서 도달 가능한것 체크하면 강연결된 원소들이다.
  //cout << node<<" ";
  visited2[node] = 1;
  kingdoms[node] = kingdom;  
  for(int child: arr1[node]){
    if(visited2[child]!=1){
      DFS2(child, kingdom);
    }
  }
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int  x, y;
  cin >> n>>m;
  while(m--){
    cin >> x >> y;
    arr1[x].push_back(y);
    arr2[y].push_back(x);  // 거꾸로저장
  }
  for(int i=1; i <= n; ++i){  // 모든 노드를 돌아보면서 거꾸로된 그래프의 topological sort를 구함.
    DFS(i);
  }
  
  while(!st.empty()){
    int k=st.top();
    st.pop();
    if(visited2[k]!=1){
      r++;
      cout<<endl;
      DFS2(k, kingdom++);  // 한번의 DFS2 첫실행에는 같은 kingdom번호를 부여받음
    }
  }
  cout << r << '\n';
  for(int i=1; i<=n; ++i){
    cout << kingdoms[i] <<' ';
  }

}