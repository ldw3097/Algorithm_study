#include<bits/stdc++.h>
using namespace std;

int main(){
    int testcase;
    int Ospree;
    int total;
    char current[79];
    cin >> testcase;

    for(int i=0; i<testcase; i++){
        cin >> current;
        Ospree = 0;
        total = 0;
        for(int j=0; current[j] != '\0'; j++){  //
            if(current[j]=='O') total += ++Ospree;  //
            else Ospree=0;
            
        }
        cout << total << endl;
    }
    return 0;
}