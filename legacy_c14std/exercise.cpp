#include <bits/stdc++.h>
using namespace std;

int main()
{
    string strset[] {"abc", "def", "gh"};
    auto strsetIter = begin(strset);
    for(; strsetIter != end(strset); ++strsetIter)
    {
        cout << *strsetIter <<endl;
    }
    return 0;
}