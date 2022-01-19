#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  vector<int> sums;
  sums.reserve(100001);
  sums.push_back(0);
  int N, M;
  cin >> N >> M;
  int j = 0;
  for(int i = 0; i<N; ++i){
    sums.push_back(sums.back() + *istream_iterator<int>(cin));
  }
  for(int i =0; i<M; ++i){
    int a, b;
    cin >> a>>b;
    cout << sums[b] - sums[a-1] << '\n';
  }
  cout << j;

}