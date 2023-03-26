#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int p[n+1];
    for(int i=1;i<=n;i++) cin>>p[i];

    int a[n+1];

    for(int i=1;i<=n;i++){
        a[p[i]] = i;
    }

    for(int i=1; i<=n;i++) {
        cout << a[i] << " ";
    }
}