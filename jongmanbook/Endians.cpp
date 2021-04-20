#include<bits/stdc++.h>
using namespace std;
union endian{
    unsigned int inp;
    char cinp[4];
};

int main(){
    int C;
    cin >> C;
    unsigned int inp;
    endian blank;
    for(int i=0; i<C; i++){
        cin >>inp;
        blank.inp = inp;
        swap(blank.cinp[1], blank.cinp[2]);
        swap(blank.cinp[0], blank.cinp[3]);
        cout << blank.inp << "\n";
    }
}

