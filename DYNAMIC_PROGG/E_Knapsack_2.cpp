#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define fo(i,s,e) for(int i=s; i<=e; i++)
#define rfo(i,e,s) for(int i=e; i>=s; i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

int dp[105][100005];
int n, w;
int wt[105]; int val[1005];

int func(int ind, int curval) // returns minimum weight for a particular value
{
    if(curval == 0 ) return 0;
    if(ind < 1) return 1e15;    // hypothetical wieght for the "min" condition

    if(dp[ind][curval] != -1) return dp[ind][curval];

    int ans = func(ind - 1, curval);

    if(curval - val[ind] >= 0)
        ans = min(ans, wt[ind] + func(ind - 1, curval - val[ind]));

    return dp[ind][curval] = ans;
}

void solve()
{
    cin >> n >> w;
    fo(i,1,n) cin >> wt[i] >> val[i];

    memset(dp, -1, sizeof(dp));

    for(int i = 100005; i >= 0; i--)
    {
        if(func(n, i) <= w)
        {
            cout << i;
            break;
        }
    }
}

int32_t main()
{fast
    solve();
    return 0;
}