#include<bits/stdc++.h>
using namespace std;

#define nl '\n'
#define int long long int
#define vi vector<int>
#define take(a,n) for(int j=1;j<=n;j++) cin>>a[j]
#define fo(i,s,e) for(int i=s; i<=e; i++)
#define rfo(i,e,s) for(int i=e; i>=s; i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

int dp[3005][3005];

void solve()
{
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    //init
    fo(i,0,n)
        dp[i][0] = 0;
    fo(i,0,m) 
        dp[0][i] = 0;

    fo(i,1,n){
        fo(j,1,m){
            if(s[i-1] == t[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else    
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    // cout << dp[n][m] << nl;

    // Printing the longest common subsequence
    string ans = "";
    int i = n, j = m;
    while(i > 0 && j > 0)
    {
        if(s[i-1] == t[j-1]){
            ans += s[i-1];
            i--, j--;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << nl;
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

