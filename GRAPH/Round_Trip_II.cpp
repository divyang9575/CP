#include<bits/stdc++.h>
using namespace std;


#ifndef ONLINE_JUDGE
#define db(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define db(x)
#endif
void _print(int t) {cerr << t;}
void _print(long long int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(multimap <T, V> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(multimap <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define M 1000000007
#define PI 3.1415926535897932384626433832795
#define cntbits(x) __builtin_popcount(x)
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define all(a) a.begin(), a.end()
#define precise(i) cout<<fixed<<setprecision(i)
#define take(a,n) for(int j=0;j<n;j++) cin>>a[j]
#define give(a,n) for(int j=0;j<n;j++) cout<<a[j]<<' '; cout << endl;
#define vpi vector<pair<int,int>>
#define pi pair<int,int>
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

void modsum(int &a, int b) { a = (a%M + b%M + M )%M ;}
void modmul(int &a, int b) { a = (a%M * b%M )%M ;}

 // binary search ? dp ? change observation.. 
 // edge cases ? overflow ? limits ? 
int n, m;
vi adj[100005];
vi vis(100005, 0);
vi stac(100005, 0); // present in the stack or not
vi par(100005, 0);

vector<int> ans;
void printCycle(int u){
    for(int i = u; ; i = par[i]){
        ans.push_back(i);
        if(i == u && ans.size() > 1) break;
    }
}

bool universal = false;

bool dfs(int u, int p=-1){
    if(universal) return true;
    vis[u] = 1;
    bool f = false;
    for(int v : adj[u]){
        if(stac[v] && universal == false){
            universal = true;
            par[v] = u;
            printCycle(v);
            f = true;
            return true;
        }
        if(!vis[v]){
            par[v] = u;
            stac[v] = 1;
            f |= dfs(v);
            stac[v] = 0;
        }
    }
    return f;
}

void solve()
{
    cin >> n >> m;
    while(m--){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    bool f = false;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            stac[i] = 1;
            f |= dfs(i);
            stac[i] = 0;
            if(f) break;
        }
    }

    if(f) {
        cout << ans.size() << endl;
        reverse(all(ans));
        give(ans, ans.size());
    }
    else cout << "IMPOSSIBLE\n";
    
}

int32_t main()
{fast
// #ifndef ONLINE_JUDGE
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
// freopen("error.txt", "w", stderr);
// #endif

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}