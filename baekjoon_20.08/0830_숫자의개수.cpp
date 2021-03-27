#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    size_t input=1;
    for(int i = 0; i < 3; i++){
        input *= *istream_iterator<size_t>(cin);

    }
    
    array<int, 10> count{}; //괄호사이에 0을 넣어도 되고 0, 도됨
    
    int digit = log10(input)+1; //자릿수 구하기
    for(int i = 0; i < digit; i++){
        ++count.at(input/(int)pow(10,i)%10); 

    }
    for(int i = 0; i<10; i++){
        cout << count.at(i)<<endl;
    }
    return 0;
}