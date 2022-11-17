#include <bits/stdc++.h>
using namespace std;
int N;
int from100;
set<int> available = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int digit(int n) {
  int ret = 0;
  do {
    ++ret;
    n /= 10;
  } while (n > 0);
  return ret;
}

set<int> needed(int n) {
  set<int> ret;
  do {
    int toadd = n % 10;
    ret.insert(toadd);
    n /= 10;
  } while (n > 0);
  return ret;
}

int minimal() {
  int plusminus = 1;
  int temp = N;
  int total = 987654321;
  set<int> tempset;

  tempset = needed(temp);
  if (includes(available.begin(), available.end(), tempset.begin(),
               tempset.end())) {
    total = digit(temp);
  } else {
    while (plusminus < from100) {
      temp = max(0, N - plusminus);
      tempset = needed(temp);
      if (includes(available.begin(), available.end(), tempset.begin(),
                   tempset.end())) {
        total = plusminus + digit(temp);
        break;
      }
      temp = N + plusminus;
      tempset = needed(temp);
      if (includes(available.begin(), available.end(), tempset.begin(),
                   tempset.end())) {
        total = plusminus + digit(temp);
        break;
      }
      ++plusminus;
    }
  }
  return min(from100, total);
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N;
  int M;
  cin >> M;
  for (int i = 0; i < M; ++i) {
    int inp;
    cin >> inp;
    available.erase(inp);
  }
  from100 = abs(N - 100);
  cout << minimal();
}