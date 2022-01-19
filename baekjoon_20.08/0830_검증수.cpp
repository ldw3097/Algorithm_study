#include <bits/stdc++.h>
using namespace std;

int main(){
    int sumup = 0;
    int temp;

    for(int i = 0; i < 5; i++){
        cin >> temp;
        sumup += temp*temp;
    }
    sumup = sumup % 10;
    cout<<sumup;
    return 0;
}