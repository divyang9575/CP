#include<bits/stdc++.h>
using namespace std;

#define nl '\n'
#define int long long int
#define vi vector<int>
#define take(a,n) for(int j=1;j<=n;j++) cin>>a[j]
#define fo(i,s,e) for(int i=s; i<=e; i++)
#define rfo(i,e,s) for(int i=e; i>=s; i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

const int M = 1e9 + 7;
int dp[1005][1005];

void solve()
{
    int n, m; cin >> n >> m;
    vector<vector<char>> grid(n+1, vector<char>(m+1));
    fo(i,1,n){
        fo(j,1,m){
            cin >> grid[i][j];
        }
    }

    if(grid[1][1] == '.') dp[1][1] = 1;
    else{
        cout << 0 << nl;
        return;
    }

    fo(i,1,n){
        fo(j,1,m){
            if(grid[i][j] == '.')
            {
                dp[i][j] += dp[i-1][j];
                dp[i][j] %= M;

                dp[i][j] += dp[i][j-1];
                dp[i][j] %= M;
            }
        }
    }

    cout << dp[n][m] << nl;
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