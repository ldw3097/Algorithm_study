#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int N;
    cin >> N;
    short* st = new short[N];
    multiset<short> set;
    for(int i = 0; i<N; i++){
        cin >> st[i];
        set.insert(st[i]);
    }
    cout << round(accumulate(st, st+N, 0.0) / N) << '\n' ;
    sort(st, st+N);
    cout << st[N/2] << '\n';
    cout << *max_element ( set.begin(), set.end(), [set](short a, short b) {return set.count(a) < set.count(b);} ) << '\n';
    cout << *max_element(set.begin(), set.end()) - *min_element(set.begin(), set.end());
}