#include<bits/stdc++.h>
#include<debug.cpp>
using namespace std;

 // binary search ? dp ? change observation.. 
 // edge cases ? overflow ? limits ? 
const int N = 2e5+5;
int dp[N];
vpi adj[N];
// bool visited[N];

void dfs(int u, int ind , int p ){
    // visited[u] = true;

    for(auto elem : adj[u])
    {
        if(elem.ff == p) continue;
        int v = elem.ff, i = elem.ss;
        dp[v] = dp[u] + (i < ind); // if i < ind that mean one more iteration.
        dfs(v, i, u);
    }
}

void solve()
{
    int n; cin >> n;
    debug(n)

    fo(i,0,n){
        // visited[i] = false;
        dp[i] = 0;
        adj[i].clear();
    }
    dp[1] = 1;

    
    fo(i,0,n-2){
        int u, v; cin >> u >> v;
        adj[u].pb({v, i});
        adj[v].pb({u, i});
    }

    dfs(1, -1, 0);
    int ans = 0;
    fo(i,1,n){
        ans = max(ans, dp[i]);
    }
    cout << ans <<nl;
    
}

int32_t main()
{fast
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("error.txt", "w", stderr);
#endif

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}