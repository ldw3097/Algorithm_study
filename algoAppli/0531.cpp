#include <bits/stdc++.h>
using namespace std;
array<int, 1000000> prefixHash{};
string n;
string m;
const int A = 31;
const int B = 524287;
int nLeng;
int mLeng;
int occur;
int pOfN;

void sethash() {
  prefixHash[0] = n[0];
  for (int i = 1; i < nLeng; ++i) {
    prefixHash[i] = (prefixHash[i - 1] * A + n[i]) % B;
    //cout << i << " n is " << 0+n[i] << ' ';
    //cout << i << " hash is " << prefixHash[i] << '\n';
  }
}

int findmatch() {
  int mHash = m[0];
  for (int i = 1; i < mLeng; ++i) {
    mHash = (mHash * A + m[i]) % B;
  }
  cout << "mHash is " << mHash << '\n';
  int ret = 0;
  if (prefixHash[mLeng - 1] == mHash) {
    if (n.compare(0, mLeng, m) == 0) {
      ++ret;
      cout << 0 << '\n'; 
    }
  }

  for (int i = mLeng; i < nLeng; ++i) {
    int partialHash = (prefixHash[i] - (prefixHash[i - mLeng] * pOfN)%B) % B;
   cout << i << " partialHash is " << partialHash << " from " << prefixHash[i] <<" and " << prefixHash[i - mLeng] << '\n';

    
    if (partialHash == mHash) {
      if (n.compare(i - mLeng + 1, mLeng, m) == 0) {
        ++ret;
        cout << i-mLeng+1 << '\n'; //
      }
    }
  }
  return ret;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  nLeng = n.length();
  mLeng = m.length();
  occur = nLeng - mLeng + 1;
  pOfN = 1;
  for (int i = 0; i < mLeng; ++i) {
    pOfN = (pOfN * A) % B;
  }
 cout << "pOfN is " << pOfN << '\n';
  sethash();
  cout << findmatch();
}