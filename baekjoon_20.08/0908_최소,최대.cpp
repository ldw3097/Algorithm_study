#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int cases;
    cin >> cases;
    int temp;
    int smallest = 1000000;
    int biggest = -1000000;
    for(int i = 0; i < cases ; i++){
        cin >> temp;
        if(smallest > temp) smallest = temp;
        if(biggest < temp) biggest = temp;

    }
    cout << smallest << " " << biggest <<endl;
    return 0;
}