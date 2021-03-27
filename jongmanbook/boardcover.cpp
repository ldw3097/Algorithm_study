//https://www.algospot.com/judge/problem/read/BOARDCOVER
#include <bits/stdc++.h>
const int possible1[4][4] = {{0,1,1,1}, {1,0,1,1}, {1,0,1,-1}, {1,0,0,1}};
using namespace std;
pair<int, int> nextPosition(int H, int W, const int originalW)
{
    ++W;
    if (W == originalW)
    {
        W = 0;
        H++;
    }
    return move(make_pair(H, W));
}

bool isIntherange(int H, int W, const int *possible, int originalH, int originalW)
{
    if (H + possible[0] >= 0 && W + possible[1] >= 0 && H + possible[2] >= 0 && W + possible[3] >= 0)
    {
        if (H + possible[0] < originalH && W + possible[1] < originalW && H + possible[2] < originalH && W + possible[3] < originalW)
        {
            return 1;
        }
    }
    return 0;
}

vector<const int *> possibleOutcome(bool **tableset, int H, int W, int originalH, int originalW)
{
    vector<const int *> ret;
    for (int i = 0; i < 4; ++i)
    {
        if (isIntherange(H, W, possible1[i], originalH, originalW) && tableset[H + possible1[i][0]][W + possible1[i][1]] == 1 && tableset[H + possible1[i][2]][W + possible1[i][3]] == 1)
        {

            ret.emplace_back(possible1[i]);
        }
    }
    return ret;
}
int recursive_search(bool **tableset, int H, int W, const int originalH, const int originalW, const int remainWhite)
{
    if (remainWhite == 0)
        return 1;
    if (H >= originalH || W >= originalW)
        return 0;
    while (tableset[H][W] == 0)
    {
        pair<int, int> temp = nextPosition(H, W, originalW);
        H = temp.first;
        W = temp.second;
        if (H >= originalH || W >= originalW)
            return 0;
    }
    int ret = 0;
    vector<const int *> Outcomes = possibleOutcome(tableset, H, W, originalH, originalW);
    pair<int, int> tempnext = nextPosition(H, W, originalW);
    for (int i = 0; i < Outcomes.size(); ++i)
    {
        bool **temptableset;
        temptableset = (bool **)malloc(sizeof(bool *) * originalH);
        for (int j = 0; j < originalH; j++)
        {
            temptableset[j] = (bool *)malloc(sizeof(bool) * originalW);
        }

        for (int j = 0; j < originalH; j++)
        {
            memcpy(temptableset[j], tableset[j], originalW);
        }

        temptableset[H][W] = 0;
        temptableset[H + Outcomes[i][0]][W + Outcomes[i][1]] = 0;
        temptableset[H + Outcomes[i][2]][W + Outcomes[i][3]] = 0;

        ret += recursive_search(move(temptableset), tempnext.first, tempnext.second, originalH, originalW, remainWhite - 1);
    }
    return ret;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int C, H, W;
    cin >> C;
    for (int c = 0; c < C; ++c)
    {
        cin >> H >> W;
        bool **tableset;
        tableset = (bool **)malloc(sizeof(bool *) * H);
        for (int i = 0; i < H; i++)
        {
            tableset[i] = (bool *)malloc(sizeof(bool *) * W);
        }
        char tmp;
        int whiteNum = 0;
        for (int i = 0; i < H; ++i)
        {
            for (int j = 0; j < W; ++j)
            {
                cin >> tmp;
                if (tmp == '#')
                    tableset[i][j] = 0; // #은 0
                else
                {
                    tableset[i][j] = 1;
                    whiteNum++;
                }
            }
        }
        if (whiteNum % 3 != 0)
        {
            cout << "0\n";
            continue;
        }
        whiteNum /= 3;
        cout << recursive_search(tableset, 0, 0, H, W, whiteNum) << "\n";
    }
    return 0;
}

//2차원 malloc https://codeng.tistory.com/8

//stl container에는 array를 저장할수 없다 https://stackoverflow.com/questions/2392308/c-vector-of-char-array/2392319#2392319
//The things that standard library containers store must be copyable and assignable, and arrays are neither of these.