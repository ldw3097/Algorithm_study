#include <bits/stdc++.h>
using namespace std;

bool bfs(array<array<long long, 501>, 501> rGraph, int s, int t,
         array<long long, 501>& parent) {
  array<bool, 501> visited{};

  queue<long long> q;
  q.push(s);  // s부터 탐색을 시작함
  visited[s] = true;
  parent[s] = -1;

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int v = 1; v <= t; v++) {
      if (visited[v] == false && rGraph[u][v] > 0) {
        if (v == t) {  // t에 도달하면 1 리턴
          parent[v] = u;
          return true;
        }
        q.push(v);
        parent[v] = u;  // 각 vertex의 부모노드
        visited[v] = true;  // 한번 방문하면 다시 방문하지 않도록 처리
      }
    }
  }

  return false;
}

long long fordFulkerson(array<array<long long, 501>, 501> graph, int s, int t) {
  int u, v;
  array<array<long long, 501>, 501> rGraph{};  // Residual graph

  for (u = 1; u <= t; u++) {  // rGraph 초기화
    for (v = 1; v <= t; v++) {
      rGraph[u][v] = graph[u][v];
    }
  }
  array<long long, 501> parent{};  // s->t 경로가 존재하는 부모-자식노드 트리
  long long max_flow = 0;  // 리턴할 값. 매번 parent의 최소값이 추가됨
  while (bfs(rGraph, s, t,
             parent)) {  // s->t경로가 존재함을 보장하며 parent가 갱신됨
    long long path_flow = LLONG_MAX;
    for (v = t; v != s; v = parent[v]) {  // t로부터 역으로 진행하면 경로임
      u = parent[v];
      path_flow = min(path_flow, rGraph[u][v]);
    }
    for (v = t; v != s; v = parent[v]) {  // 최소값을 rgraph에 더하고 뺌
      u = parent[v];
      rGraph[u][v] -= path_flow;
      rGraph[v][u] += path_flow;
    }
    max_flow += path_flow;
  }
  return max_flow;
}

int main() {
  int n, m;
  cin >> n >> m;
  array<array<long long, 501>, 501> speed{};
  for (int i = 0; i < m; ++i) {
    int a, b;
    long long c;
    cin >> a >> b >> c;
    speed[a][b] +=
        c;  // 네트워크가 세로 제시되면 대역폭을 교체가 아니라 추가해야함
  }
  long long ret = fordFulkerson(speed, 1, n);
  cout << ret;
}