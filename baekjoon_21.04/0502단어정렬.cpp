#include <bits/stdc++.h>
using namespace std;
struct comp
{
    bool operator()(const string a, const string b) const       //#1
    {
        if (a.size() == b.size())
            return a < b;
        else
            return a.size() < b.size();
    }
};          //#2

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    set<string, comp> inpu;      //#3
    for (int i = 0; i < N; i++)
    {
        inpu.insert(*istream_iterator<string>(cin));        
    }
    for (string s : inpu)
    {
        cout << s << "\n";
    }
    return 0;
}
