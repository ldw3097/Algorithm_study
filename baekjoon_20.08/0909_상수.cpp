#include<bits/stdc++.h>
using namespace std;

int main(){
    char a[4]; //마지막에 \0 있어야되서 [3]으로 하면 안되는듯.
    char b[4];
    cin >> a >> b;
    //reverse(begin(a), end(a)-1); 
    swap(a[0], a[2]);
    //reverse(begin(b), end(b)-1);
    swap(b[0], b[2]);
    int aa = stoi(a); //
    int bb = stoi(b);
    if(aa > bb) cout << aa<<endl;
    else cout << bb<<endl;
    return 0;
}