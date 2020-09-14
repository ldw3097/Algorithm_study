#include <bits/stdc++.h>
using namespace std;

int main()
{
    double data[] {2.5, 4.5, 6.5, 5.5, 8.5};
    cout << "배열 원소들:\n";
    for(auto iter = begin(data); iter != end(data); ++iter)
        cout << *iter << " ";
    auto total = accumulate(begin(data), end(data), 0.0);
    cout << "\n배열 원소들의 합계: " << total << endl;
    
}