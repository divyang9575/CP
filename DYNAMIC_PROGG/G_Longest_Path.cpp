#include<bits/stdc++.h>
using namespace std;

#define nl '\n'
#define int long long int
#define vi vector<int>
#define take(a,n) for(int j=1;j<=n;j++) cin>>a[j]
#define fo(i,s,e) for(int i=s; i<=e; i++)
#define rfo(i,e,s) for(int i=e; i>=s; i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

const int N = 1e5+5;
vector<vector<int>> adj(N);
int vis[N] = {false};

int dp[N] = {-1};

void dfs(int node){
    vis[node] = true;
    int length = 0;
    for(auto elem : adj[node]){
        if(!vis[elem]) dfs(elem);
        length = max( length , 1 + dp[elem] );
    }
    dp[node] = length;
}


void solve()
{
    int n, m; cin  >> n >> m;
    fo(i,0,m-1){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    fo(i,1,n){
        if(!vis[i])
            dfs(i);
    }
  
    int ans = 0;
    fo(i,1,n){
        ans = max(dp[i], ans);
    }
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