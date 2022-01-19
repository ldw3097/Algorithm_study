#include<bits/stdc++.h>
using namespace std;

int main(){
  bool* bools = new bool[3];
  bools[1] = 1;
  bools[0] = 0;
  bools[2] = 0;
  cout << *(bools+1);
}