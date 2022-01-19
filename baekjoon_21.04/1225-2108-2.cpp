#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int N;
    cin >> N;
    int* st = new int[N];
    array<int, 8001> arr{};
    for(int i = 0; i<N; i++){
        cin >> st[i];
        ++arr[st[i]+4000];
    }
    cout << floor( (double) accumulate(st, st+N, 0) / N +0.5 ) << '\n' ;
    sort(st, st+N);
    cout << st[N/2] << '\n';

    int biggest = INT_MIN;
    for(int i = 0; i<=8000; ++i){
        if(biggest < arr[i]) biggest = arr[i];
    }
    set<int> intset;
    for(int i = 0; i<=8000; ++i){
        if(biggest == arr[i]) intset.insert(i);
    }
    if(intset.size() >1) cout << *++intset.begin() -4000;
    else cout << *intset.begin() -4000;


    cout << '\n' << st[N-1] - st[0] << '\n';
}