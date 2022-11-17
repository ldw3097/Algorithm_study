#include <bits/stdc++.h>
using namespace std;
array<int, 1000000> hashed{};
string m;
string n;
int mleng;
int nleng;
int occur;

void sethash() {
  occur = nleng - mleng + 1;
  int addednum = 0;
  for (int j = 0; j < mleng; ++j) {
    addednum += n[j];
  }
  hashed[0] = addednum;

  for(int i=1; i<occur; ++i){
    int newhash = hashed[i-1] - n[i-1];
    newhash += n[i+mleng-1];
    hashed[i] = newhash;
  }


/*
  for (int i = 0; i < occur; ++i) {
    int addednum = 0;
    for (int j = 0; j < mleng; ++j) {
      addednum = addednum * A;
      addednum += n[i + j];
      addednum %= B;
    }
    hashed[i] = addednum;
  }
  */
}

int findmatch() {
  int addednum = 0;
  for (int j = 0; j < mleng; ++j) {
    addednum += m[j];
  }
  int ret = 0;

  for (int i = 0; i < occur; ++i) {
    if (hashed[i] == addednum) {
      
      if (m.compare(n.substr(i, mleng)) == 0) {
        ret++;
      }
      
    }
  }
  return ret;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  mleng = m.length();
  nleng = n.length();
  sethash();
  cout << findmatch();
}