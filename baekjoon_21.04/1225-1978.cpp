#include <bits/stdc++.h>
using namespace std;

bool isPrime(int num){
    if(num == 0 || num == 1) return 0;
    for(int i=2; i<= num/2; ++i){
        if(num % i == 0) return 0;
    }
    return 1;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int N;
    cin >> N;
    int ret = 0;
    for(int i=0; i < N; i++){
        ret += isPrime(*istream_iterator<int>(cin));
    }
    cout << ret;
}