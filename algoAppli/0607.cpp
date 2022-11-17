#include <bits/stdc++.h>
using namespace std;

#define x real()
#define y imag()

typedef long long C;
typedef complex<C> Point;

long long cross(const Point &O, const Point &A, const Point &B) {
  return (A.x - O.x) * (B.y - A.y) - (A.y - O.y) * (B.x - A.x);
}  // (A-O) X (B-A)  외적 구하기

bool cmp(const Point& a, const Point& b){  // 허수 비교하는 커스텀 비교함수
  if(a.x == b.x) return a.y < b.y;
  else return a.x < b.x;
}


vector<Point> convex_hull(vector<Point>& P) {
  size_t n = P.size(), k = 0;  // k가 '변경할 인덱스'임
  if (n <= 3) return P;
  vector<Point> H(2 * n);
  // Sort points lexicographically

  sort(P.begin(), P.end(), cmp);

  // Build Upper hull
  for (size_t i = 0; i < n; ++i) {  
    while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) > 0) k--;  
    // cross가 0이면 없애주는게 아니므로 '> 0'
    // cross가 0보다 작아서 반시계방향으로 가면 k를 1 줄여서 H[k-1]를 다음에 변경함
    H[k++] = P[i];
  }
  // Build Lower hull
  for (size_t i = n - 1, t = k + 1; i > 0; --i) {
    while (k >= t && cross(H[k - 2], H[k - 1], P[i - 1]) > 0) k--;
    H[k++] = P[i - 1];
  }
  H.resize(k - 1);
  return H;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int k;
  cin >> k;
  int a, b;
  vector<Point> points;
  for(int i=0; i<k; ++i){
    cin >> a>> b;
    points.emplace_back(a, b);
  }
  vector<Point> ret = convex_hull(points);
  cout << ret.size() << '\n';
  for(Point p : ret){
    cout << p.x << ' ' << p.y << '\n';
  }
}