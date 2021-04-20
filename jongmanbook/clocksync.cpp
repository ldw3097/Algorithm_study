// https://algospot.com/judge/problem/read/CLOCKSYNC
#include <bits/stdc++.h>
using namespace std;
const array<vector<int>, 10> swiches = {{{0, 1, 2}, {3, 7, 9, 11}, {4, 10, 14, 15}, {0, 4, 5, 6, 7}, {6, 7, 8, 10, 12}, {0, 2, 14, 15}, {3, 14, 15}, {4, 5, 7, 14, 15}, {1, 2, 3, 4, 5}, {3, 4, 5, 9, 13}}};

struct onetry
{
    
    int topress;
    array<int, 16> clocks;
    array<int, 10> perswitch;
    int aftertrys;

    onetry(int a, array<int,16> b, array<int,10> c, int d)
        :topress(a), clocks(b), perswitch(c), aftertrys(d){}

};


bool checkclock(const array<int, 16> clock)
{
    for (int i : clock)
    {
        if (i != 12)
        {
            return false;
        }
    }
    return true;
}

int solve(array<int, 16> clock, array<int, 10> perswitch)
{
    //diagnose clock is already set
    if(checkclock(clock)) return 0;
    queue<onetry> todolist ;
    for (int i = 0; i < 10; i++)
    {
       todolist.emplace(i, clock, perswitch, 1 );
    }
    onetry targettry = todolist.front();
    
    while (!todolist.empty())
    {
        targettry = todolist.front();
        
        
        array<int, 16> tmpclock = targettry.clocks;
        array<int,10> tmpperswitch = targettry.perswitch;
        for (int i : swiches.at(targettry.topress))
        {
            tmpclock.at(i) = tmpclock.at(i) % 12 + 3;
        }
        tmpperswitch.at(targettry.topress)++;
        if(checkclock(tmpclock)){
            
            return targettry.aftertrys;
        } 
        for(int j=targettry.topress; j<10; j++){
            if(tmpperswitch.at(j) < 4){
                todolist.emplace(j, move(tmpclock), move(tmpperswitch), targettry.aftertrys+1); 
            }
        }
        if(targettry.aftertrys > 9 ) cout << "broken";
        todolist.pop();
        
    }
    return -1;

}

int main()
{
    
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int C;
    cin >> C;
    for (int c = 0; c < C; c++)
    {
        array<int, 16> clocks;
        array<int, 10> perswitch = {0};
        for (int i = 0; i < 16; i++)
        {   
            
            clocks.at(i) = *istream_iterator<int>(cin);

           
        }

        cout << solve(clocks, perswitch) << "\n";
        
    }
}

/*
array<set<int>,10> swiches =  {{ {0, 1, 2}, {3, 7, 9, 11}, {4, 10, 14, 15}, {0, 4, 5, 6, 7}, {6, 7, 8, 10, 12}, {0, 2, 14, 15}, {3, 14, 15}, {4, 5, 7, 14, 15}, {1, 2, 3, 4, 5}, {3, 4, 5, 9, 13}}};
vector<set<int>> swichesv = { {0, 1, 2}, {3, 7, 9, 11}, {4, 10, 14, 15}, {0, 4, 5, 6, 7}, {6, 7, 8, 10, 12}, {0, 2, 14, 15}, {3, 14, 15}, {4, 5, 7, 14, 15}, {1, 2, 3, 4, 5}, {3, 4, 5, 9, 13}};
array?�� bracelet?�� 3�? ?��?��?��?��. 첫번째는 set, ?��번째?�� set?�� 10개있?�� initializer list, ?��번째?�� array?��거같?��.
*/