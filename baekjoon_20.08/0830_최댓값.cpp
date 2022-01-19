#include <bits/stdc++.h>
using namespace std;

int main(){
    int biggest = 0;
    int loc = 0;
    int temp;
    for(int i = 1; i < 10; i++){
        cin >> temp;
        if(temp > biggest){
            biggest = temp;
            loc = i;
        }
    }
    cout<<biggest <<endl;
    cout<<loc<<endl;

    return 0;
}