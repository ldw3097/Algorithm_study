#include <bits/stdc++.h>
using namespace std;

int main(){
    int testcase;
    cin >> testcase;

    
    pair<int, string>* cases = new pair<int,string>[testcase];
    for(int i = 0; i<testcase; i++){
        cases[i].first = *istream_iterator<int>(cin); //
        cases[i].second = *istream_iterator<string>(cin);

    }

    int tmpCase;
    unsigned tmpCaseSize;
    char targetChar;
    for(int i= 0; i<testcase; i++){
        tmpCase = cases[i].first;
        tmpCaseSize = cases[i].second.size();
        for(size_t j = 0; j<tmpCaseSize; j++){
            targetChar = cases[i].second[j];
            for(size_t k = 0; k<tmpCase; k++){
                cout << targetChar;
            }
        }
        cout <<endl;
    }
    return 0;

}