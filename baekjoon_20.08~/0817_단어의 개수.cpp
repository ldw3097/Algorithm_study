#include<bits/stdc++.h>
using namespace std;

int main(){
    string input;
    int count = 0;
    int frontorback=0;
    getline(cin, input);    //
    if(input.front() == ' ') frontorback++;     
    if(input.back() == ' ') frontorback++;
    for(auto iter = begin(input);iter != end(input); ++iter)
    {
        if(*iter == ' ') count++;
        
        
    }
    cout << count+1-frontorback<<endl;
    return 0;
}

/*
<https://blockdmask.tistory.com/338>
    #str1.size()
    str1.length()와 같음
    #str1.capacity()

    #str1.front()
    #str1.back()

    # str1.c_str() 
    c++ 스타일의 string문자열을 C스타일의 문자열로 변경

    size_t에 -1이 들어오면 제일 큰값을 뜻함

*/