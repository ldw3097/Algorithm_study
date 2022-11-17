#include<bits/stdc++.h>
using namespace std;
int T;
int k;


void test(){
  cin >> k;
  multiset<int> mset;
  for(int i=0; i<k; ++i){
    char inp;
    int num;
    cin >> inp >> num;
    if(inp=='I') mset.insert(num);
    else if(!mset.empty()){
      if(num == -1){
        mset.erase(mset.begin());
      }else{
        mset.erase(--mset.end());
      }
    }
  }
  if(mset.empty()){
    cout << "EMPTY\n";
  }else{
    cout << *(--mset.end()) << ' ' << *mset.begin() << '\n';
  }
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> T;
  for(int i=0; i<T; ++i){
    test();
  }
}