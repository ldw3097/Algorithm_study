#include<bits/stdc++.h>
using namespace std;

class pep{
    public:
    int a_, b_;  // 클래스 멤버는 기본적으로 private 이다.
    pep(int a, int b) : a_(a), b_(b) {}
    pep(){}
    bool operator<(pep p){
        if(a_ < p.a_ && b_ < p.b_) return true;
        else return false;
    }
};


int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int N;
    cin >> N;
    pep* peps = new pep[N];
    for(int i = 0; i<N; ++i){
        peps[i] = pep(*istream_iterator<int>(cin), *istream_iterator<int>(cin));
    }
    
    for(int i=0; i<N; ++i){
        int rank = 1;
        for(int j = 0; j< i; ++j){
            if(peps[i] < peps[j]) ++rank;
        }
        for(int j = i+1; j<N; ++j){
            if(peps[i] < peps[j]) ++rank;
        }
        cout << rank << ' ';
    }



}

