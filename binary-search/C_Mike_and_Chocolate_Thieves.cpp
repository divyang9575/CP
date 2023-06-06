#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define int long long int
#define vi vector<int>
#define a(all) a.begin(), a.end()
#define vpi vector<pair<int,int>>
#define pb push_back
#define pi pair<int,int>
#define ff first
#define ss second
#define fo(i,s,e) for(int i=s; i<=e; i++)
#define rfo(i,e,s) for(int i=e; i>=s; i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

 // binary search ? dp ? change observation.. 
 // edge cases ? overflow ? limits ? 

int func(int n)
{
    int ways = 0;
    for(int k = 2; k*k*k <= n; k++) // k < 1e6 also worked due to the break statement
    {
        int kcube = pow(k,3);
        int add = n / kcube;
        if(add == 0) break;
        ways += add;
    }
    return ways;
}

void solve()
{
    int m ; cin >> m;

    int ways = 0;
    int ans = -1;
    int s = 8, e = 1e18-1;
    while(s <= e)
    {
        int n = e-(e-s)/2;
        if(func(n) == m)
        {
            ans = n;
            e = n-1;
        }
        else if(func(n) < m)
        {
            s = n+1;
        }
        else{
            e = n-1;
        }

    }

    cout << ans;
}

int32_t main()
{fast
    solve();
    return 0;
}