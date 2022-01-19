#include <bits/stdc++.h>
using namespace std;

bool is666(unsigned i){
    while(i>=666){
        if(i %1000 == 666) return true;
        i /= 10;
    }
    return false;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    unsigned n;
    cin >> n;
    unsigned start = 666;
    for(unsigned i = 1; i < n; i++){
        ++start;
        while(!is666(start)) ++start;
    } 
    cout << start;
    return 0;
}