#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    long long ans = 1;
    long long div = 1;
    for(int i = 0; i < K; i++ ){
        ans *= N-i; 
        div *= i+1;
    }
    ans /= div;
    cout << ans;

    
}