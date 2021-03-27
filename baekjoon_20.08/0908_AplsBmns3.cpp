#include<bits/stdc++.h>
using namespace std;

int main(){
    int cases = 0;
    cin >> cases;
    vector<short> solved;
    short a, b;
    for(int i = 0; i < cases; i++){
        cin >> a >> b;
        solved.push_back(a+b); //insert는 특정장소에 붙이고 push_back은 뒤에 붙힘
    }
    for(short s : solved){ //
        cout << s <<endl;
    }
    return 0;
}