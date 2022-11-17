#include <bits/stdc++.h>
using namespace std;

class UFDS {
 private:
  vector<int> p, rank, setSizes;
  int numSets;
  int largest = -1;

 public:
  UFDS(int N) {
    numSets = N;
    rank.assign(N, 0);
    p.assign(N, 0);
    for (int i = 0; i < N; i++) p[i] = i;
    setSizes.assign(N, 1);
  }
  int findSet(int i) { return (p[i] == i) ? i : p[i] = findSet(p[i]); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) {
      int x = findSet(i), y = findSet(j);
      if (rank[x] > rank[y]) {
        setSizes[findSet(x)] += setSizes[findSet(y)];
        p[y] = x;
      } else {
        setSizes[findSet(y)] += setSizes[findSet(x)];
        p[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
      }
      numSets--;
    }
    if(largest < setSize(i)) largest = setSize(i);
  }
  int setSize(int i) { return setSizes[findSet(i)]; }
  int numDisjointSets() { return numSets; }
  int largestSize() {return largest;}
};

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  UFDS union1 = UFDS(n);
  for(int i=0; i<m; ++i){
    int a, b;
    cin >> a>>b;
    a--; b--;
    union1.unionSet(a, b);
    cout << union1.numDisjointSets() << ' ' << union1.largestSize()<< '\n';
  }
}