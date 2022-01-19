#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    unsigned N;
    cin >> N;
    array<int, 10001> arr{};
    for(unsigned i = 0; i<N; ++i){
        ++arr[*istream_iterator<int>(cin)];
    }
    for(int i = 1; i<=10000; ++i){
        for(int j = 0; j < arr[i]; ++j){
            cout << i <<'\n';
        }
    }
    return 0;
}