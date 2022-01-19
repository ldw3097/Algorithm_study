#include <iostream>
#include <iterator>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    //cout.tie(NULL);
    size_t caseN;
    cin >> caseN;
    short tmp;
    for(size_t i = 0; i < caseN; i++){
        cin >> tmp;
        cout << tmp + *istream_iterator<short>(cin) << '\n';
    }
    return 0;
}