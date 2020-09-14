#include<bits/stdc++.h>
using namespace std;

int main(){
    short first;
    bool isAscending;
    cin >> first;
    if(first == 1) isAscending = true;
    else if(first == 8) isAscending = false;
    else{
        cout << "mixed";
        return 0;
    }

    if(isAscending){
        for(int i=2; i<9; i++){
            if(i != *istream_iterator<int>(cin)){ 
                cout << "mixed";
                return 0;
            }
        }
        cout << "ascending"<<endl;
        return 0;
    }

    if(!isAscending){
        for(int i=7; i>0; i--){
            
            if(i != *istream_iterator<int>(cin)){

                cout << "mixed";
                return 0;
            }
            
        }
        cout << "descending"<<endl;
        return 0;
    }

    return 0;
}