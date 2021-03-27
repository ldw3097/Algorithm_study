// https://www.algospot.com/judge/problem/read/PICNIC
#include <bits/stdc++.h>
using namespace std;
int calcPos(const vector<pair<int, int>> inp, const int m, const vector<bool> students, const int np2)
{
    if (np2 == 0)
    {
        for (bool i : students)
        {
            if (i == 0)
            {
                return 0;
            }
        }
        return 1;
    }
    int ret = 0;
    for (int i = 0; i < m; i++)
    {

        if (students[inp.at(i).first] == 0 && students[inp.at(i).second] == 0)
        {
            vector<bool> tempstudents = students;
            tempstudents[inp.at(i).first] = 1;
            tempstudents[inp.at(i).second] = 1;
            vector<pair<int, int>> tmpinp(m - 1);

          //  if (i > 0)
           //     copy(&inp[0], &inp[i], tmpinp.begin());
            if (i + 1 <= m - 1)
                copy(&inp[i + 1], &inp[m], &tmpinp[i]);
            ret += calcPos(tmpinp, m - 1, tempstudents, np2 - 1);
        }
    }
    return ret;
}
int factorial(int a)
{
    int ret = 1;
    for (int i = a; i > 1; i--)
    {
        ret *= i;
    }
    return ret;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int C, n, m;
    cin >> C;
    for (int c = 0; c < C; c++)
    {
        cin >> n >> m;
        //pair<int, int> sets[m];
        vector<pair<int, int>> sets(m);
        vector<bool> students(n);
        for (int i = 0; i < m; i++)
        {
            int temp1, temp2;
            cin >> temp1 >> temp2;

            // sets[i] = make_pair(temp1, temp2);
            sets.at(i) = make_pair(temp1, temp2);
        }

        if (m < n / 2)
            cout << "0\n";
        else
            cout << calcPos(sets, m, students, n / 2)  << "\n";
    }
    return 0;
}