#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t testcase, M, N, K;
    cin >> testcase >> M>>N>>K;
    bool bat[M][N]{false};

    int tmp1, tmp2;
    for(int i=0; i<K; i++){
        cin >> tmp1 >> tmp2;
        bat[tmp1][tmp2] = true;
    }
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(bat[i][j]){
                int tmpi=i;
                int tmpj=j;
                
            }
        }
    }
}