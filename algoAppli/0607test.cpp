#include <bits/stdc++.h>
using namespace std;

#define x real()
#define y imag()

typedef long long C;
typedef complex<C> Point;

bool cmp(const Point& a, const Point& b){
  if(a.x == b.x) return a.y < b.y;
  else return a.x < b.y;
}

int main(){
  Point a = {3,1};
  Point b = {4,1};
  cout << cmp(a,b);
}