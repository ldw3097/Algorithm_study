#include<bits/stdc++.h>
using namespace std;

int main(){
    string input;
    cin>>input;
    
    for(int i=0; i<input.size(); i++){
        input[i] = toupper(input[i]); //전부 대문자화
    }
    
    map<char, int> map1;
    for(int i=65; i<=90; ++i){ //A~Z
        map1.insert({i, 0} ); 
    }
    
    for(auto iter=begin(input); iter != end(input); ++iter){
        map1.find(*iter)->second++;  //단어 각각의 pair에 개수기록
    }

    char maxL = 63; 
    char maxV = 0;  
    bool identical = false; 
    for(auto iter=begin(map1); iter != end(map1); ++iter){
        if (maxV < iter->second){
            maxV = iter->second;
            maxL = iter->first;
            identical = false;
        } else if (maxV == iter->second)    
        {
            identical = true;
        }
    }

    if(identical == true) cout << "?" <<endl;
    else{
        cout << maxL <<endl;
        
    }
    return 0;
}

/*
아스키코드
    영문자 대문자 : 65~90 총 26개
    영문자 소문자 : 97~122 총 26개
    차이는 32

한글을 2바이트라서 printf("%c%c",a[0],a[1]); 이렇게 해야됨

for문에서 ++i가 i++보다 좀더 빠름

*map1.find(*iter)는 map.find()의 역참조임
*/