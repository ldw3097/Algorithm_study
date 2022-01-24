#include <bits/stdc++.h>
using namespace std;

int ret = 0;

struct compp {
  bool operator()(const pair<unsigned, unsigned> p1,
                  const pair<unsigned, unsigned> p2) {
    if (p1.first == p2.first) {
      return p1.second < p2.second;
    }
    return p1.first < p2.second;
  }
};

multimap<unsigned, unsigned, compp> endstart;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    unsigned start, end;
    cin >> start >> end;
    endstart.emplace(end, start);
  }

  while (!endstart.empty()) {
    auto front = endstart.begin();
    unsigned firstOfFront = (*front).first;
    endstart.erase(front);
    ++ret;
    auto iter = endstart.begin();
    auto tempiter = iter;
    while (iter != endstart.end()) {
      if ((*iter).second < firstOfFront) {
        tempiter = next(iter);
        endstart.erase(iter);
        iter = tempiter;
      } else {
        break;
      }
    }
  }
  cout << ret;
}