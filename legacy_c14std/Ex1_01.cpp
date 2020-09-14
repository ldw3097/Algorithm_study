#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << accumulate(istream_iterator<double>(cin),
    istream_iterator<double>(), 0.0)
    << endl;
}