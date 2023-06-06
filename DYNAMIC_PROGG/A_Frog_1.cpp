#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
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

const int N = 1e5 + 10;
int dp[N];

int minCost(int * h, int n, int k)
{
    if(dp[n] != -1)
    {
        return dp[n];
    }

    if(n <= 1)
    {
        return 0;
    }
    
    int cost = INT_MAX;

    for(int j = 1; j <= k; j++)
    {
        if(n - j >= 1)
        cost = min( cost , abs(h[n] - h[n-j]) + minCost(h,n-j,k));
    }
    return dp[n] = cost;
    
}

void solve()
{
    int n, k ; cin >> n >> k;
    int h[n+1]; fo(i,1,n) cin >> h[i];
    h[0] = 0;

    cout << minCost(h,n, k);
}

int32_t main()
{fast

memset(dp, -1, sizeof(dp));
    solve();
    return 0;
}