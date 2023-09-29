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

void dfs(int node, vi &vis, vi &money, vi adj[], vi &cost, vi &free){
    vis[node] = 1;
    if(free[node]) {
        money[node] = 0;
        return;
    }

    int rupiya = 0;
    bool leaf = true;
    for(auto child : adj[node]){
        leaf = false;
        if(!vis[child]){
            dfs(child, vis, money, adj, cost, free);
        }
        rupiya += money[child];
    }
    if(leaf == true){
        money[node] = cost[node];
    } 
    else {
        money[node] = min(cost[node], rupiya);
    }
}

void solve()
{
    int n, k; cin >> n >> k;
    vi cost(n); 
    for(int i=0; i<n; i++){
        cin >> cost[i];
    }

    vi free(n, 0);
    for(int i=0; i<k; i++){
        int x; cin >> x; x--;
        free[x] = 1;
    }

    vi adj[n];
    for(int i=0; i<n; i++){
        int m; cin >> m;
        for(int j = 0; j<m; j++){
            int e; cin >>e; e--;
            adj[i].push_back(e);
        }
    }

    vi vis(n, 0);
    vi money(n, 1e9);
    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i, vis, money, adj, cost, free);
        }
    }
    give(money, money.size());
    
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