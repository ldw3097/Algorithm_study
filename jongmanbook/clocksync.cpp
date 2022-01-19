// https://algospot.com/judge/problem/read/CLOCKSYNC
#include <bits/stdc++.h>
using namespace std;
const array<vector<int>, 10> swiches = {{{0, 1, 2}, {3, 7, 9, 11}, {4, 10, 14, 15}, {0, 4, 5, 6, 7}, {6, 7, 8, 10, 12}, {0, 2, 14, 15}, {3, 14, 15}, {4, 5, 7, 14, 15}, {1, 2, 3, 4, 5}, {3, 4, 5, 9, 13}}};

struct onetry
{
    
    int topress;
    array<char, 16> clocks;
    array<char, 10> perswitch;
    int aftertrys;

    onetry(int a, array<char,16> b, array<char,10> c, int d)
        :topress(a), clocks(b), perswitch(c), aftertrys(d){}

};


bool checkclock(const array<char, 16> clock)
{
    for (int i : clock)
    {
        if (i != 4)
        {
            return false;
        }
    }
    return true;
}

int solve(array<char, 16> clock, array<char, 10> perswitch)
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
        
        
        array<char, 16> tmpclock = targettry.clocks;
        array<char,10> tmpperswitch = targettry.perswitch;
        for (int i : swiches.at(targettry.topress))
        {
            tmpclock.at(i) = tmpclock.at(i) % 4 + 1;
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
        array<char, 16> clocks;
        array<char, 10> perswitch = {0};
        for (int i = 0; i < 16; i++)
        {   
            
            clocks.at(i) = *istream_iterator<int>(cin)/3 ;

           
        }

        cout << solve(clocks, perswitch) << "\n";
        
    }
    return 0;
}

/*
array<set<int>,10> swiches =  {{ {0, 1, 2}, {3, 7, 9, 11}, {4, 10, 14, 15}, {0, 4, 5, 6, 7}, {6, 7, 8, 10, 12}, {0, 2, 14, 15}, {3, 14, 15}, {4, 5, 7, 14, 15}, {1, 2, 3, 4, 5}, {3, 4, 5, 9, 13}}};
vector<set<int>> swichesv = { {0, 1, 2}, {3, 7, 9, 11}, {4, 10, 14, 15}, {0, 4, 5, 6, 7}, {6, 7, 8, 10, 12}, {0, 2, 14, 15}, {3, 14, 15}, {4, 5, 7, 14, 15}, {1, 2, 3, 4, 5}, {3, 4, 5, 9, 13}};
array?Š” bracelet?´ 3ê°? ?•„?š”?•˜?‹¤. ì²«ë²ˆì§¸ëŠ” set, ?‘ë²ˆì§¸?Š” set?´ 10ê°œìˆ?Š” initializer list, ?„¸ë²ˆì§¸?Š” array?¸ê±°ê°™?‹¤.
*/