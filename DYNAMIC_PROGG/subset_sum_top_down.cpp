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

int dp[105][100005];

void func(int ind, int sum, int *a)
{
    for(int i = 1; i <= ind; i++)
    {
        fo(j,1,sum)
        {
            if(j - a[i-1] >= 0)
            dp[i][j] = dp[i-1][j] | dp[i-1][j - a[i-1]];

            else
            dp[i][j] = dp[i-1][j];
        }
    }
    
}

void solve()
{
    int n, sum; cin >> n >> sum;
    int a[n]; fo(i,0,n-1) cin >> a[i];

    //initialization of dp
    fo(i,1,sum)
        dp[0][sum] = 0;

    fo(i,0,n)
        dp[i][0] = 1;

    func(n,sum, a);

    if(dp[n][sum]) cout << "YES\n";
    else cout << "NO\n";
}

int32_t main()
{fast
    solve();
    return 0;
}