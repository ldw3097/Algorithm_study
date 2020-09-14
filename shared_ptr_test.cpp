#include<bits/stdc++.h>
using namespace std;

int main(){
    array<int,10> *pppdata = new array<int,10>;
    unique_ptr<int[]> pdata{new int[10]};
    unique_ptr<array<int,10>> ppdata(pppdata);
    shared_ptr<array<int,10>> sdata(ppdata.get());
    cout << *ppdata<<endl << pppdata << endl << sdata.get()<<endl;
}