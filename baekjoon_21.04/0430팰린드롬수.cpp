#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string inp;
    int half;
    bool tempflag = 1;
    cin >> inp;
    stack<char> thestack;
    while (inp != "0")
    {
        thestack = {};
        half = inp.size() / 2;

        auto itr = inp.begin();
        for (int i = 0; i < half; i++)
        {

            thestack.emplace(*itr++);
        }
        if (inp.size() % 2 == 1)
            itr++;
        for (int i = 0; i < half; i++)
        {

            if (thestack.top() != *itr++)
            {
                cout << "no\n";
                tempflag = 0;
                break;
            }
            thestack.pop();
        }
        if (tempflag == 0)
        {
            tempflag = 1;
        }
        else
            cout << "yes\n";
        inp.clear();
        cin >> inp;
    }
    return 0;
}