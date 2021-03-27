// https://algospot.com/judge/problem/read/CLOCKSYNC
#include <bits/stdc++.h>
using namespace std;
const array<set<int>, 10> swiches = {{{0, 1, 2}, {3, 7, 9, 11}, {4, 10, 14, 15}, {0, 4, 5, 6, 7}, {6, 7, 8, 10, 12}, {0, 2, 14, 15}, {3, 14, 15}, {4, 5, 7, 14, 15}, {1, 2, 3, 4, 5}, {3, 4, 5, 9, 13}}};

/*
int solve(array<int,16> clock, array<int,10> perswitch){
    bool isAll12 = true;
    for(int i : clock){
        if(i != 12){
            isAll12 = false;
            break;
        }
    }
    if(isAll12 == true){
        return 1;
    }

    int ret = 0;
    bool allIsPressed = true;
    for(int i=0; i<10; ++i){
        if(perswitch.at(i) == 3) continue;
        allIsPressed = false;
        array<int,16> tempclock = clock;
        for(int s : swiches.at(i)){
            tempclock[s] = tempclock[s]%12 +3;
        }

    }
    if(allIsPressed == true) return -1;

}
*/
struct onetry
{
    int topress;
    array<int, 16> clocks;
    array<int, 10> perswitch;
    int aftertrys;
};
bool checkclock(array<int, 16> clock)
{
    bool isall12 = true;
    for (int i : clock)
    {
        if (i != 12)
        {
            isall12 = false;
            break;
        }
    }
    if (isall12)
        return true;
    return false;
}

int solve(array<int, 16> clock, array<int, 10> perswitch)
{
    //diagnose clock's already set
    if(checkclock(clock)) return 0;
    cout << "hi";
    queue<onetry> todolist;
    for (int i = 0; i < 10; i++)
    {
        onetry temptry{i, clock, perswitch, 1};
        todolist.emplace(move(temptry));
    }
    onetry *targettry;
    
    while (!todolist.empty())
    {
        targettry = &todolist.front();
        todolist.pop();
        array<int, 16> tmpclock = clock;
        array<int,10> tmpperswitch = perswitch;
        for (int i : swiches.at(targettry->topress))
        {
            tmpclock.at(i) = tmpclock.at(i) % 12 + 3;
            tmpperswitch.at(i)++;
        }
        if(checkclock(tmpclock)) return targettry->aftertrys;
        for(int j=0; j<10; j++){
            if(tmpperswitch.at(j) != 4)
                todolist.push({j, tmpclock, tmpperswitch, targettry->aftertrys+1}); 
        }
    }
    return -1;

}

int main()
{
    /*
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    */
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
array는 bracelet이 3개 필요하다. 첫번째는 set, 두번째는 set이 10개있는 initializer list, 세번째는 array인거같다.
*/