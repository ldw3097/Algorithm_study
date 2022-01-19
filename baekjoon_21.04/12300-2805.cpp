#include <bits/stdc++.h>
using namespace std;

bool cut(vector<unsigned>& vec, unsigned height, unsigned target){
  unsigned ret = 0;
  for(unsigned u : vec){
    if(u > height) ret += u-height;
    if(ret >= target) return true;
  }
  return false;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  unsigned N, M;
  cin >> N >> M;
  vector<unsigned> tree;
  tree.reserve(N);
  for(unsigned i=0; i<N; ++i){
    tree.push_back(*istream_iterator<unsigned>(cin));
  }
  unsigned high =  *max_element(tree.begin(), tree.end())-1;
  unsigned low = 0;
  while(high != low){
    unsigned mid = (high+low)/2 +1;
      if(cut(tree, mid, M)){
        low = mid;
      }else high = mid-1;
  }
  cout << high;
}