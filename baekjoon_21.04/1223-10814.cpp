#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N;
    multimap<int,string> map;
    string a;
    int b;

    for(int i=0; i<N; i++){

        map.emplace(  *istream_iterator<int>(cin), *istream_iterator<string>(cin) );
    }
    for(auto p : map){
        cout << p.first << ' ' << p.second << '\n';
    }
}