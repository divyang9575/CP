#include<bits/stdc++.h>
using namespace std;

#define nl '\n'
#define vi vector<int>
#define take(a,n) for(int j=1;j<=n;j++) cin>>a[j]
#define fo(i,s,e) for(int i=s; i<=e; i++)
#define rfo(i,e,s) for(int i=e; i>=s; i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

void solve()
{
    int n; cin >> n;
    vi a(n+1); take(a, n);
    
    int dp[n+1];
    dp[0] = dp[1] = 0;
    fo(i,2,n){
        if(i - 2 > 0)
        dp[i] = min(dp[i-1] + abs(a[i-1] - a[i]), dp[i-2] + abs(a[i-2] - a[i]));
        else
        dp[i] = dp[i-1] + abs(a[i-1] - a[i]);
    }
    cout << dp[n] << nl;
}

int32_t main()
{fast
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}