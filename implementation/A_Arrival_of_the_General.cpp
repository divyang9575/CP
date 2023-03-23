#include<bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define lli long long int
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define pb push_back
#define pi pair<int,int>
#define ff first
#define ss second
#define fo(i,s,e) for(int i=s; i<=e; i++)
#define rfo(i,e,s) for(int i=e; i>=s; i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

int main()
{fast
    int n;
    cin >> n;

    int a[n];
    fo(i,0,n-1) cin>> a[i];

    int max = a[0];
    int maxpos = 1;

    int min = a[0];
    int minpos = 1;

    fo(i,1,n-1)
    {
        if(a[i] > max)
        {
            max = a[i];
            maxpos = i+1;
        }
        if(a[i] <= min)
        {
            min = a[i];
            minpos = i+1;
        }    
    }

    if(minpos < maxpos) minpos++;

    int totalswaps = (maxpos - 1) + (n - minpos);

    cout << totalswaps<< endl;

    return 0;
}