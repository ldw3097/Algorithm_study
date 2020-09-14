#include <bits/stdc++.h>
using namespace std;

int main(){
    string strset[] {"abc", "def", "gh"};
    transform(begin(strset), end(strset), begin(strset), [](string curr) {
        transform(curr.begin(), curr.end(), curr.begin(), [](char alphabet) {if(alphabet=='a') alphabet = '*'; })
    ;} );

    auto strsetIter = begin(strset);
    for(; strsetIter != end(strset); ++strsetIter)
    {
        cout << *strsetIter <<endl;
    }
    return 0;
}