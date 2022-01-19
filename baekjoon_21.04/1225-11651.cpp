#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> a, pair<int,int> b ){
    if(a.second == b.second){
        return a.first < b.first;
    }else return a.second < b.second;

    
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
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