#include<bits/stdc++.h>
using namespace std;

#define M 1000000007
#define PI 3.1415926535897932384626433832795
#define nl '\n'
#define sz(a) a.size()
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define all(a) a.begin(), a.end()
#define vpi vector<pair<int,int>>
#define pb push_back
#define pi pair<int,int>
#define ff first
#define ss second
#define fo(i,s,e) for(int i=s; i<=e; i++)
#define rfo(i,e,s) for(int i=e; i>=s; i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
// template <class T, class V> void _print(multimap <T, V> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T, class V> void _print(multimap <T, V> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

 // binary search ? dp ? change observation.. 
 // edge cases ? overflow ? limits ? 

vi adj[200005]; //2d vector
int childs[200005];
bool visited[200005];

void dfs(int i)
{
    visited[i] = true;
    if(adj[i].size() == 1 && i != 1) 
        childs[i] = 1;

    for(auto ele : adj[i])
    {
        if(visited[ele] == true) continue;
        dfs(ele);
        childs[i] += childs[ele];
    }
}

void solve()
{
    int n; cin >> n; // vertices
    debug(n) 
    //for every testcase we have to clear the global arrays
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        visited[i] = false;
        childs[i] = 0;
    }

    fo(i,0,n-2) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1);

    int q; cin >> q;
    fo(i,1,q) {
        int x, y; cin >> x >> y;

        int ans = int64_t(childs[x] * childs[y]);
        cout << ans << endl;
    }

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