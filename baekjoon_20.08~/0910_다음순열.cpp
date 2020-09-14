#include<bits/stdc++.h>
using namespace std;

int main(){
    
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int testcase;
    cin >> testcase;
    vector<int> arr;
    for(int i=0; i<testcase; ++i){
        arr.push_back(*istream_iterator<int>(cin));
    }

    if(!next_permutation(arr.begin(), arr.end())){  //
        cout << -1 <<endl;
    }else{
        auto fromStart = arr.begin();
        for(int i=0; i<testcase; i++){
            cout << *fromStart <<" ";
            advance(fromStart ,1);  //
        }
    }
    return 0;

}