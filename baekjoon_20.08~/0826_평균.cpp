#include <bits/stdc++.h>
using namespace std;

int main(){
    int testNum;
    cin >> testNum;
    int biggest = 0;
    double current = 0;
    int count = 0;
    int temp;

    for(int i = 0; i < testNum; i++){
        count++;
        cin >> temp;
        current += temp;
        if(biggest < temp) biggest = temp;

    }
    current = current/count*100/biggest;
    cout << current;

}