#include<bits/stdc++.h>
using namespace std;

#define nl '\n'
#define int long long int
#define vi vector<int>
#define take(a,n) for(int j=1;j<=n;j++) cin>>a[j]
#define fo(i,s,e) for(int i=s; i<=e; i++)
#define rfo(i,e,s) for(int i=e; i>=s; i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

const int N = 2e5;
int dp[N][3];

void solve()
{
    int n; cin >> n;
    vector<vi> vac(n+1, vi(3, 0));
    fo(i,1,n){
        int a, b, c; cin >> a >> b >> c;
        vac[i] = {a, b, c};
    }

    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    fo(i, 1, n){
        fo(j,0,2){
            dp[i][0] = vac[i][0] + max(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = vac[i][1] + max(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = vac[i][2] + max(dp[i-1][0], dp[i-1][1]);
        }
    }
    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << nl;
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