#include<iostream>
using namespace std;

int main()
{
    int x,y,z;
    cin>>x>>y>>z;

    int dist = (max(x,max(y,z)) - min(x,min(y,z)));

    cout << dist << endl;
}