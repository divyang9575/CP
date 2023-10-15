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

 // binary search ? dp ? change observation.. 
 // edge cases ? overflow ? limits ? 
const int N = 2e5 + 5;
int dp[N] ;
int n;

void childDFS(int v, int p, vi &childs, vi tree[]){
    for(auto u : tree[v]){
        if(u == p) continue;
        childDFS( u, v, childs, tree);
        childs[v] += childs[u];
    }
}

void DFS(int v, int p, vi &childs, vi tree[], vi &arr){
    for(auto u : tree[v]){
        if(u == p) continue;
        DFS(u, v, childs, tree, arr) ;
        dp[v] += (dp[u] + (arr[v] ^ arr[u]) * childs[u] ) ;
    }
}

void AnsDFS(int v, int p, vi &childs, vi tree[], vi &arr, vi &ans){
    for(auto u : tree[v]){
        if(u == p) continue;
        
        dp[v] -= (dp[u] + (arr[v] ^ arr[u]) * childs[u] ) ;
        dp[u] += (dp[v] + (arr[v] ^ arr[u]) * (n - childs[u])) ;
        ans[u] = dp[u] ;

        AnsDFS(u, v, childs, tree, arr, ans) ;
        // correct all values
        dp[u] -= (dp[v] + (arr[v] ^ arr[u]) * (n - childs[u])) ;
        dp[v] += (dp[u] + (arr[v] ^ arr[u]) * childs[u] ) ;
    }
}

void solve()
{
    cin >> n;
    vi arr(n); 
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    vi tree[n] ;
    for(int i=1; i<=n-1; i++){
        int u, v; cin >> u >> v;
        u--, v-- ;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    // store counts of childs
    vi childs(n, 1) ;
    childDFS(0, -1, childs, tree) ;

    // pre calculate dp for one root
    memset(dp, 0, sizeof dp) ;
    DFS(0, -1, childs, tree, arr) ;

    vi ans(n) ;
    ans[0] = dp[0] ;

    // calculating for all roots
    AnsDFS(0, -1, childs, tree, arr, ans) ;
    give(ans, ans.size()) ;
    
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