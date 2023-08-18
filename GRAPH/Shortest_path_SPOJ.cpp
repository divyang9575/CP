#include<bits/stdc++.h>
using namespace std;

#define cntbits(x) __builtin_popcount(x)
#define nl '\n'
#define sz(a) a.size()
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pair<int,int>>
#define pb push_back
#define pi pair<int,int>
#define ff first
#define ss second
#define fo(i,s,e) for(int i=s; i<=e; i++)
#define rfo(i,e,s) for(int i=e; i>=s; i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

 // binary search ? dp ? change observation.. 
 // edge cases ? overflow ? limits 

const int INF = 1e18; 
vvi vis(9, vi(9, false));
vvi level(9, vi(9, INF));

vpi moves = {
    {2, 1}, {2, -1},
    {-2, 1}, {-2 , -1},
    {1, 2}, {-1, 2},
    {1, -2}, {-1, -2}
};

bool isValid(pi c){
    return c.ff > 0 && c.ff <= 8 && c.ss > 0 && c.ss <= 8 ;
}

pi loc(string &s){
    return { s[0] - 'a' + 1, s[1] - '0'};
}

void reset(){
    fo(i,0,8) fo(j,0,8) vis[i][j] = 0;
    fo(i,0,8) fo(j,0,8) level[i][j] = INF;
}

int BFS(string s, string e){
    pi start = loc(s);
    pi dest = loc(e);

    queue<pi> q;
    q.push(start);
    vis[start.ff][start.ss] = 1;
    level[start.ff][start.ss] = 0;

    while(!q.empty()){
        pi cur = q.front();
        q.pop();
        for(auto move : moves){
            int x = move.ff, y = move.ss;
            pi child = {cur.ff + x, cur.ss + y};
            if(isValid(child)){
                q.push(child);
                vis[child.ff][child.ss] = 1;
                level[child.ff][child.ss] = level[cur.ff][cur.ss] + 1;
            }
        }

        if(level[dest.ff][dest.ss] != INF) break;
    }
    return level[dest.ff][dest.ss];
}

void solve()
{
    reset();

    string s , e;
    cin >> s >> e;

    int ans = BFS(s, e);
    cout << ans << nl;
    
}

int32_t main()
{fast

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}