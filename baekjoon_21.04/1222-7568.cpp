#include <bits/stdc++.h>
using namespace std;

class pep {
 public:
  int a_, b_;  // 클래스 멤버는 기본적으로 private 이다.
  int seq_, rank_;
  pep(int a, int b, int seq) : a_(a), b_(b), seq_(seq) {}
  pep() {}
  void setrank(int i) { rank_ = i; }
  void print() { cout << rank_ << ' '; }
};

int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  int N;
  cin >> N;
  pep* peps = new pep[N];  // pep peps[N]은 N이 상수가 아니라서 불가
  for (int i = 0; i < N; ++i) {
    peps[i] = pep(*istream_iterator<int>(cin), *istream_iterator<int>(cin), i);
  }
  sort(peps, peps + N, [](pep a, pep b) { return a.a_ > b.a_; });
  int rank = 1;
  peps[0].rank_ = rank;
  for (int i = 0; i < N - 1; ++i) {
    if (peps[i].b_ > peps[i + 1].b_ && peps[i].a_ > peps[i + 1].a_) {
      rank = i + 2;
      peps[i + 1].rank_ = rank;
    } else
      peps[i + 1].rank_ = rank;
  }
  sort(peps, peps + N, [](pep a, pep b) { return a.seq_ < b.seq_; });
  for (int i = 0; i < N; ++i) {
    peps[i].print();
  }
}
