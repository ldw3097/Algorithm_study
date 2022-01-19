#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int N;
    cin >> N;
    set<int> st;
    for(int i=0; i<N; ++i){
        st.insert(*istream_iterator<int>(cin));
    }
    int M;
    cin >> M;
    for(int i=0; i<M; i++){
        cout << st.count(*istream_iterator<int>(cin)) << '\n';
    }

}