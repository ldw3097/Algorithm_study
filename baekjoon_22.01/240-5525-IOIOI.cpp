#include <bits/stdc++.h>
using namespace std;
int N, M;
set<int> starts;
array<int, 1000000> lengths{};

void findend(vector<bool>& S) {
  for (int i = 2; i < S.size(); ++i) {
    if (S[i] == 1 && S[i - 1] == 0 && S[i - 2] == 1) starts.insert(i);
  }
}

void findLength() {
  lengths[0] = 0;
  lengths[1] = 0;
  for (int i = 2; i < M; i += 2) {
    if (starts.count(i))
      lengths[i] = lengths[i - 2] + 1;
    else
      lengths[i] = 0;
  }
  for (int i = 3; i < M; i += 2) {
    if (starts.count(i))
      lengths[i] = lengths[i - 2] + 1;
    else
      lengths[i] = 0;
  }
}

int ret = 0;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N >> M;  // 이 상태에서 get하면 \n 남아있음
  cin.get();
  vector<bool> S;
  S.reserve(M);
  for (int i = 0; i < M; ++i) {
    char c = cin.get();
    if (c == 'I')
      S.push_back(1);
    else
      S.push_back(0);
  }
  findend(S);
  findLength();
  for (int i = 2; i < M; ++i) {
    if (lengths[i] >= N) ++ret;
  }
  cout << ret;
}