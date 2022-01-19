#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    char chess[N][M];
    for (int i = 0; i < N; i++)
    {
        cin >> chess[i];
    }
    int smallest = INT32_MAX;
    int Nisupto = N-8;
    int Misupto = M-8;
    int tmpcount;
    for(int i = 0; i <= Nisupto; i++){
        for(int j = 0; j<= Misupto; j++){
            tmpcount = 0;
            for(int k=i; k<i+8; k++){
                for(int l=j; l<j+8; l++){
                    if(chess[k][l] != (((k+l)%2) ? 'B' : 'W')){
                        
                        tmpcount++;
                    }
                }
            }
            if(smallest> tmpcount) smallest = tmpcount;
            if(smallest> 64-tmpcount) smallest = 64-tmpcount;
        }
    }
    cout << smallest;

}