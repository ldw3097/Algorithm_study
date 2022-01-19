#include<bits/stdc++.h>
using namespace std;

int main(){
    short hour, minute;
    cin >> hour >> minute;
    hour += 24;
    if(minute < 45){
        hour--;
        minute += 60;
        minute -= 45;
    }
    else minute -= 45;

    cout << hour%24 << " " <<minute;
    return 0;
}

/*
나머지 구하기
    [예 5]  5 %  2 = 1
    [예 6] -5 % -2 = -1
    [예 7]  5 % -2 = 1
    [예 8] -5 %  2 = -1
    X % Y 를 연산할때 그 연산 결과의 부호는 X의 부호를 따라간다.
    쉽게말해 일단 부호가 모두 양수라고 보고 부호만 X 따라간다는것.

    또하나 중요한점은 나머지연산은 실수형에선 동작하지 않는다는것이다.
    즉, 
    5.0 % 2.0
    5 % 2.0
    5.0 % 2
    는 컴파일이 안된다는 것이다. 하고싶으면 fmod()써야됨.



*/