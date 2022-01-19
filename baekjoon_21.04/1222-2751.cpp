#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N;
    vector<int> arr;
    arr.reserve(N);
    for(int i=0; i<N; ++i){
        arr.push_back(*istream_iterator<int>(cin));
    }
    sort(arr.begin(), arr.end());
    for(int i=0; i<N; ++i){
        cout << arr[i] << '\n';
    }
    return 0;

}