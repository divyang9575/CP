#include<bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define int long long int
#define vi vector<int>
#define sort(a,all) sort(a.begin(), a.end())
#define vpi vector<pair<int,int>>
#define pb push_back
#define pi pair<int,int>
#define ff first
#define ss second
#define fo(i,s,e) for(int i=s; i<=e; i++)
#define rfo(i,e,s) for(int i=e; i>=s; i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

void solve()
{
    int n; cin >> n;

    if(n <= 2)
    {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";

    cout << (int)ceil((double)n/(double)2) <<  " " << n/2 << endl ;


    fo(i,1,n)
    {
        if(i%2 == 0)
        {
            cout << i << " ";
        }
    }
    
    fo(i,1,n)
    {
        if(i&1)
        {
            cout << i << " ";
        }
    }
}

int32_t main()
{fast
    solve();
    return 0;
}