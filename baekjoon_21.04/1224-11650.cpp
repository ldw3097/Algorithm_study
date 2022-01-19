#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> a, pair<int,int> b ){
    if(a.first == b.first){
        return a.second < b.second;
    }else return a.first < b.first;

    
}

int main(){
    int N;
    cin >> N;
    pair<int,int>* ps = new pair<int,int>[N];
    int tmp1, tmp2;
    for(int i=0;i<N;++i){
        cin >> tmp1 >> tmp2;
        ps[i] = pair<int,int> {tmp1,tmp2};
    }
    sort(ps, ps+N, comp);
    for(int i = 0 ;i<N; ++i){
        cout << ps[i].first << ' ' << ps[i].second <<'\n';
    }

}